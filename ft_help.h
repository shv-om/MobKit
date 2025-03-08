#ifndef FT_HELP_H
#define FT_HELP_H

#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/ftrace.h>
#include <linux/kprobes.h>
#include <linux/ptrace.h>

#define USE_FENTRY_OFFSET 0

/* x64 has to be special and require a different naming convention */
#ifdef PTREGS_SYSCALL_STUBS
#define SYSCALL_NAME(name) ("__x64_" name)
#else
#define SYSCALL_NAME(name) (name)
#endif

// Hook Structure
struct ftrace_hook {
    const char *name;
    void *function;
    void *original;

    unsigned long address;
    struct ftrace_ops ops;
};

#define HOOK(_name, _hook, _orig) \
{   .name = SYSCALL_NAME(_name), \
    .function = (_hook), \
    .original = (_orig), \
}

unsigned long lookup_name(const char *name);
int install_hook(struct ftrace_hook *hook);
void remove_hook(struct ftrace_hook *hook);

asmlinkage void hook_handler(unsigned long ip, unsigned long parent_ip,
                             struct ftrace_ops *ops, struct ftrace_regs *regs);

unsigned long (*real_kallsyms_lookup_name)(const char *name);
static asmlinkage int (*orig_kill)(const struct pt_regs *);

unsigned long lookup_name(const char *name) {
    if (!real_kallsyms_lookup_name) {
        struct kprobe kp = {.symbol_name = "kallsyms_lookup_name"};

        if (register_kprobe(&kp) < 0) {
            return 0;
        }
        real_kallsyms_lookup_name = (void *)kp.addr;
        unregister_kprobe(&kp);
    }
    return real_kallsyms_lookup_name ? real_kallsyms_lookup_name(name) : 0;
}

int install_hook(struct ftrace_hook *hook) {
    int err;
    hook->address = lookup_name(hook->name);

    if (!hook->address) {
        return -ENOENT;
    }

    *((unsigned long *)hook->original) = hook->address;
    printk(KERN_DEBUG "mob: Hooking %s at address: %px with handler %px\n", hook->name, (void *)hook->address, hook->function);

    hook->ops.func = (ftrace_func_t)hook_handler;
    hook->ops.flags = FTRACE_OPS_FL_SAVE_REGS | FTRACE_OPS_FL_RECURSION | FTRACE_OPS_FL_IPMODIFY;

    err = ftrace_set_filter_ip(&hook->ops, hook->address, 0, 0);
    if (err) {
        return err;
    }

    err = register_ftrace_function(&hook->ops);
    if (err) {
        return err;
    }

    return 0;
}

void remove_hook(struct ftrace_hook *hook) {
    int err = unregister_ftrace_function(&hook->ops);
    if (err) {
    }

    if (hook->address) {
        err = ftrace_set_filter_ip(&hook->ops, hook->address, 1, 0);
        if (err) {
        }
    }
}

asmlinkage void hook_handler(unsigned long ip, unsigned long parent_ip,
                             struct ftrace_ops *ops, struct ftrace_regs *regs) {
    struct ftrace_hook *hook = container_of(ops, struct ftrace_hook, ops);

    if (!hook || !hook->function) {
        return;
    }

    struct pt_regs *pt_regs = ftrace_get_regs(regs);

    #if USE_FENTRY_OFFSET
        instruction_pointer_set(pt_regs, (unsigned long)hook->function);
    #else
        if (!within_module(parent_ip, THIS_MODULE)) {
            instruction_pointer_set(pt_regs, (unsigned long)hook->function);
        } else {
            return;
        }
    #endif
}

#endif