# MobKit
MobKit (Modern Linux Kernel Rootkit): Designed & Compiled for the latest Linux Kernels.

# Features
## Linux Kernel Rootkit:
  -  Hooks Kill Syscall and provide extra signals to work with.
  -  Hide and Unhide from lsmod.
  -  Granting root permissions to shells by updating root credentials.
  -  Creating and executing the reverse shell/backdoor.
  -  Execute and Kill the ongoing payload process.
  -  Schedule checks to get status of Payload execution. Automatic execution of payload if not found.

## FT Help (Function Tracer Helper)
  -  Designed for Modern Linux Headers Generic.
  -  Gets Syscall name & address from Kernel Symbol Table.
  -  Provide base functionality to register and unregister hooks for any syscalls. 
  -  Prevent recursions using the Instruction pointer and Parent ID checks.
  -  Base functionality to Hook multiple syscalls.

# USAGE
  -  Use the Makefile to build the module. (Compiled Successfully? Proceed)
  -  Install module in target system using command: `sudo insmod mob.ko`
  -  Now if you use command `kill`. Rootkit will hook this and check for the provided signal.
     `kill <SIG> <PID>`
  -  `kill -61 1` -> Toggle between Execute payload or Kill the Payload process using pid.
  -  `kill -63 1` -> Toggle between Hide and Unhide the module from Kernel Module List (lsmod).
  -  `kill -64 1` -> Acquire Root for the current shell.

## Payloads
  -  The payload associated with the module is for testing purposes only.
  -  `hsjajsnsjd.py` -> Reverse Shell Payload.
  -  `ahsjendhah.txt` -> Reverse Shell Encoded Hex Bytes.
  -  `dheysjdnsj.py` -> Decodes the Hex Bytes and creates the reverse shell payload file.
