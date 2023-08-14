# Structure of C++ Program

C++ has alot of ***keywords***, these keywords are parts of the language that have a special meaning. These keywords are reserved and cannot be used as by programmers as names for variables, functions, classes, or any other identifier.

***Preprocessor*** is a program that process your source code even before compiler sees it, it takes the cpp file do the following:

1. Removes all comments and replace it with a single space
2. Looks for preprocessor directives and process them

Preprocessor directives are lines in source code that start with a # symbol, these directives are instructions for preprocessor to do something. For example: **`#include`** is a preprocessor directive that tells preprocessor to include a header file in the source code.

```cpp
#include <iostream> // This is a preprocessor directive
```

***Comments*** are lines in source code, that are programmer's readable explanation of the code, these lines are ignored by the compiler. Even though comments are important for explaining the code, they should be used wisely and not overused, Don't comment the obvious, your code should be self-explanatory as much as possible.

There are two types of comments in C++:

1. Single line comment: starts with `//` and ends with the end of the line.
2. Multi-line comment: starts with `/*` and ends with `*/`.

```cpp
// This is a single line comment

/*
This 
is 
a 
multi-line 
comment
*/
```

Every C++ program has a ***main( ) function***, this function is the entry point of the program, the program starts executing from the first line of the main function and ends when it reaches the last line of the main function.

The main( ) function has a return type of **`int`**, if the return value is **0** then the program ended successfully, if the return value is **non-zero** then the program ended with an error.

There are two types of main functions:

1. **`int main()`**: This is the most common type of main function, it doesn't take any arguments from the operating system.

    ```cpp

    int main() {
        // Your code goes here
        return 0;
    }
    ```

    To run the program from the terminal, you need to compile the program first, then run the executable file.

    ```bash
    g++ main.cpp -o main
    ./main
    ```

2. **`int main(int argc, char* argv[])`**: This type of main function takes two arguments from the operating system, the first argument is the number of arguments passed to the program, the second argument is an array of strings, each string is one of the arguments passed to the program.

    ```cpp
    int main(int argc, char* argv[]) {
        // Your code goes here
        return 0;
    }
    ```

    To run the program from the terminal, you need to compile the program first, then run the executable file.

    ```bash
    g++ main.cpp -o main
    ./main arg1 arg2 arg3
    ```
