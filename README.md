# 0x10. C - printf

### Low-level programming & Algorithms

~Max Stuart and Sergii Garkusha~

Based on the ["Secrets of printf"](http://www.cypress.com/file/54761/download) scientific paper by Professor Don Colton

#### Requirements

* Authorized functions and macros:
	* `write 	(man 2 write)`
	* `malloc 	(man 3 malloc)`
	* `free 	(man 3 free)`
	* `va_start 	(man 3 va_start)`
	* `va_end 	(man 3 va_end)`
	* `va_copy 	(man 3 va_copy)`
	* `va_arg 	(man 3 va_arg)`

* If the task does not specify what to do with an edge case, do the same as `printf`
* The main.c file is shown as example and for the test purpose

#### Style guides
* Allowed editors: vi, vim, emacs
* All files should end with a new line
* The code should use the [Betty style](https://github.com/holbertonschool/Betty)
* Global variables are not allowed
* No more than 5 functions per file

#### Headers
* The prototypes of all functions should be included in header file called holberton.h
* All header files should be include guarded

#### Compilation
* All files will be compiled on Ubuntu 14.04 LTS
* Programs and functions will be compiled with gcc 4.8.4 using the flags `-Wall -Werror -Wextra and -pedantic`
* code will be compiled this way: `gcc -Wall -Werror -Wextra -pedantic *.c`

#### Tests
* The `main.c` file with tests contains all the tests
* The `main.c` file is commited under the `test` folder
* To make it work:
	* Make a symbolic link to the `test/main.c` file to the root of the project: `ln -s test/main.c .`
	* Compile project with `-Wno-format` extra flag: `gcc -Wall -Werror -Wextra -pedantic -Wno-format *.c`
	* Do not push any `.c` file containting a main function in the root directory of the project
