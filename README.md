# VirtualFS

A **Virtual File System simulation** written in modern C++ — completely in-memory, with a command-line interface that mimics real OS filesystem commands.

---

## What is VirtualFS?

VirtualFS is a clean, lightweight file system simulator that lets you create files, folders, and symbolic links — all as C++ objects using polymorphism. It’s not touching your real disk; everything lives virtually in RAM.

It’s perfect for understanding file system architecture, practicing OOP and design patterns in C++, or building a base for more advanced OS-related projects.

---

## Features

- Create and manage **files** and **directories**
- Support for **symbolic links** pointing to any file or directory
- Basic file operations: `open`, `write`, `remove`, `rename`
- Directory navigation with `cd`, including `cd ..`
- List contents with `ls`
- Command-line interface mimicking common shell commands
- Polymorphic design with a clean class hierarchy

---

## Supported Commands

| Command            | Description                              |
|--------------------|----------------------------------------|
| `mkf NAME`         | Create a new folder (directory)        |
| `mkfl NAME`        | Create a new file                       |
| `cd NAME`          | Change directory into `NAME`            |
| `cd ..`            | Go up one directory                     |
| `ls`               | List contents of current directory      |
| `rm NAME`          | Remove file or directory named `NAME`  |
| `rename OLD NEW`   | Rename file or folder from OLD to NEW  |
| `write NAME TEXT`  | Write TEXT to file NAME (overwrite)    |
| `open NAME`        | Open a file or directory named NAME    |
| `pwd`              | Show current directory path             |
| `help`             | Show this help message                  |
| `exit`             | Exit the program                        |

---

## Usage

Build with your favorite C++17 (or later) compiler.  
Run the executable, then enter commands to manipulate the virtual file system.

Example:

```bash
root> mkf docs
root> cd docs
docs> mkfl notes.txt
docs> write notes.txt Hello VirtualFS!
docs> open notes.txt
Hello VirtualFS!
docs> pwd
/root/docs
