# OS-Project

An educational, Unix-like operating system written in C and x86 Assembly. This project is designed to explore the core concepts of operating systems including process management, file systems, memory, and system calls. It’s inspired by MIT's xv6 and developed for learning and experimentation.


## 🧠 Project Overview

This project simulates a basic OS kernel with a command-line interface (shell), multitasking capabilities, file system support, and user-space programs. It runs on emulators like QEMU and Bochs and is ideal for operating systems coursework or self-study.


## ✨ Features

- Custom bootloader and kernel entry in assembly
- Process creation, scheduling, and termination
- Shell interface with built-in utilities (`ls`, `cat`, `echo`, `grep`, etc.)
- System call interface for user/kernel communication
- Simple file system with directories, inodes, and disk block management
- Virtual memory and paging (basic)
- Device drivers: keyboard, disk (IDE), serial port (UART)
- Multiprocess testing (`forktest`, `stressfs`, `usertests`)

## File Structure

OS-Project/
├── bootasm.S        # Bootloader
├── entry.S          # Kernel entry point
├── main.c           # Kernel init
├── syscall.c        # System call interface
├── proc.c           # Process management
├── user/            # User programs (sh, cat, ls, etc.)
├── fs/              # File system logic
├── kalloc.c         # Kernel memory allocator
├── Makefile         # Build rules
├── .bochsrc         # Bochs config
└── README.md        # You're here!
