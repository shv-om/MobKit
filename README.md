# MobKit
MobKit (Modern Linux Kernel Rootkit)

MobKit is designed for the latest Linux Kernels.

# Features
## Linux Kernel Rootkit:
  -  Hooks Kill Syscall and provide extra signals to work with.
  -  Hide and Unhide from lsmod.
  -  Granting root permissions to shells by updating root credentials.
  -  Creating and executing the reverse shell/backdoor.
  -  Execute and Kill the ongoing payload process.
  -  Schedule checks to get status of Payload execution. Automatic execution of payload if not found.

## FT Help
  -  Designed for Modern Linux Headers Generic.
  -  Gets Syscall name & address from Kernel Symbol Table.
  -  Provide base functionality to register and unregister hooks for any syscalls. 
  -  Prevent recursions using the Instruction pointer and Parent ID checks.
  -  Base functionality to Hook multiple syscalls.

# USAGE
  -  Use the Makefile to build the module. (Compiled Successfully? Proceed)
  -  Install module in target system using command: `sudo insmod mob.ko`
  -  Now if you use command `kill`. Rootkit will hook this and check for the provided signal.
     `kill -61 1`
  -  Signal 61 -> Toggle between Execute payload or Kill the Payload process using pid.
  -  Signal 63 -> Toggle between Hide and Unhide the module from Kernel Module List (lsmod).
  -  Signal 64 -> Acquire Root for the current shell.
