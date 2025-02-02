# Minishell

## Introduction
Minishell is a project that involves creating a simple shell similar to Bash. This project is designed to deepen your understanding of processes, file descriptors, and command-line interfaces. By implementing a functional shell, you will explore how operating systems handle user commands, manage execution flow, and process input/output operations.

## Features
Minishell includes the following features:
- A command prompt that allows user input.
- A working command history.
- Execution of external commands using absolute, relative, or `$PATH` variables.
- Handling of environment variables.
- Implementation of built-in shell commands:
  - `echo` with `-n` option.
  - `cd` with absolute or relative paths.
  - `pwd` with no options.
  - `export` with no options.
  - `unset` with no options.
  - `env` with no arguments.
  - `exit` with no options.
- Handling of input and output redirections:
  - `<` for input redirection.
  - `>` for output redirection.
  - `<<` (here-document) for multi-line input.
  - `>>` for appending output.
- Implementation of pipes (`|`) to chain commands.
- Support for `$?` to retrieve the exit status of the last executed command.
- Proper handling of `Ctrl+C`, `Ctrl+D`, and `Ctrl+\` for shell control.

## Bonus Features
If the mandatory part is implemented perfectly, the following bonus features can be added:
- Logical operators `&&` and `||` with parentheses for priority handling.
- Support for wildcard `*` expansion in the current directory.

## Requirements
- The project must be written in C and follow coding norms.
- Proper memory management to prevent memory leaks.
- Use of `readline()` for input handling.
- Implementation must not use more than one global variable for signal handling.
- Submission via Git repository with a proper Makefile.

## Compilation
To compile Minishell, use the provided Makefile:
```sh
make
```
To clean up object files:
```sh
make clean
```
To remove all compiled files:
```sh
make fclean
```
To recompile:
```sh
make re
```

## Usage
Run the shell using:
```sh
./minishell
```
Interact with the shell by entering commands as you would in Bash.

## Learning Outcomes
By completing this project, you will gain knowledge in:
- Process creation and management using `fork()` and `execve()`.
- Inter-process communication using pipes.
- File descriptor manipulation.
- Signal handling and process control.
- String and memory management in C.
- Writing a structured and maintainable C project.

## License
This project is created for educational purposes and follows the requirements of the Minishell project guidelines.

---



