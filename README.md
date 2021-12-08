
simple_shell
=======
# simple_shell


## Table of Contents
* [Description](#description)
* [File Structure](#file-structure)
* [Requirements](#requirements)
* [Installation](#installation)
* [Usage](#usage)
* [Example of Use](#example-of-use)
* [Bugs](#bugs)
* [Authors](#authors)
* [License](#license)

## Description
The simple_shell is a project about create our command line interpreter, or shell.
This shell is intentionally minimalistic, yet includes the basic functionality of a traditional Unix-like command line user interface. 
Standard functions and system calls employed in simple_shell include:
   `access, execve, exit, fork, free, stat, getline, malloc, stat, wait, write.`

## File Structure
* [AUTHORS](AUTHORS) - List of contributors to this repository
* [man_1_simple_shell](man_1_simple_shell) - Manual page for the simple_shell
* [shell.h](shell.h) - header file
* [path.c](path.c) - functions related to executing commands
* [simple_shell.c](simple_shell.c) - essential functions to the shell
  * `main` - the main function of the program
* [strfunc.c](strfunc.c) - functions related to string manipulation
* [tokenize.c](tokenize.c) - tokenizing function
  * `tokenize` - creates an array of tokens from a buffer with a specified delimiter

## Requirements

Our simple_shell is designed to run in the `Ubuntu 14.04 LTS` linux environment and to be compiled using the GNU compiler collection v. `gcc ` with flags`-Wall, -Werror, -Wextra, -pedantic -std=gnu89 `

## Installation

   - Clone this repository: `git clone "https://github.com/JorgeCal123/simple_shell.git"`
   - Change directories into the repository: `cd simple_shell`
   - Compile: `gcc -Wall -Werror -Wextra -pedantic *.c -o hsh`
   - Run the shell in interactive mode: `./hsh`

## Usage

The simple_shell is designed to execute commands in a similar manner to sh, however with more limited functionality. The development of this shell is ongoing. The below features will be checked as they become available (see man page for complete information on usage):

### Features
- [x] uses the PATH
- [ ] implements builtins
- [x] handles command line arguments
- [x] custom strtok function
- [ ] uses exit status
- [ ] shell continues upon Crtl+C (**^C**)
- [ ] handles comments (#)
- [ ] handles **;**
- [ ] custom getline type function
- [ ] handles **&&** and **||**
- [ ] aliases
- [ ] variable replacement


### Builtins

- [ ] exit
- [ ] env
- [ ] setenv
- [ ] unsetenv
- [ ] cd
- [ ] help
- [ ] history

## Example of Use
Run the executable in your terminal after compiling:
```
$ ./hsh
My_Shell_& 

```

## Bugs
At this time, there are some known bugs.

## Authors
Jorge Calambas | [GitHub](https://github.com/JorgeCal123) | [Twitter](https://twitter.com/OrlandoConda)

Andres Catano | [GitHub](https://github.com/andrescatagno) | [Twitter](https://twitter.com/ac4digital)

## License
simple_shell is open source and therefore free to download and use without permission.

