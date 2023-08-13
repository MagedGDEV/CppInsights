# Introduction

Computer does exactly what you tell it to do. It doesn't know how to do anything on its own, when you write a program, you are giving the computer a series of commands that it will execute in order to perform some task.

Progams are written in multiple programming languages such as C, C++, Java, Python, etc. Each programming language has its own syntax and rules that must be followed to write a valid program in that language, we will be using C++ for this repository.

The programming language we write our is called high-level language which is understandable by humans. But computers doesn't know how to execute tasks from high-level lanaguage, So we need to convert our high-level language to low-level language which is in form of 0's and 1's, This process is done by a program called **compiler**, and each programming language has its own compiler.

Programs are made up of one or more files, the code in each file is linked together to form a single executable program, this process is done by a program called **linker**.

It's normal to encounter **Errors** when writing programs, it is the nature of programming, So it's important to learn about different types of errors:

- *Compiler Errors*

  - Syntax Errors
  - Semantic Errors

- *Linker Errors*
- *Runtime Errors*
- *Logic Errors*

## Compiler Errors

These types of errors are detected by the compiler, and the prevent the compiler from compiling the program, and stop it from creating an object file.

There are two types of errors that cause the compiler to generate compiler errors:

### Syntax Errors

Syntax is the grammar of a programming language, and it's rules that must be followed to write a valid program in that language. when you break the rules of the language, the compiler will generate a syntax error.

These erros are like:

- Missing semicolon at the end of the statement.
- Missing closing parenthesis.
- Misspelling a keyword.
- Using a variable without declaring it.
- ...

For example:

```cpp
#include <iostream>

int main() 
// Missing opening parenthesis
    std::cout << "Hello World!" << std::endl // Missing semicolon
    return 0;
} 
```

### Semantic Errors

Semantic errors deals with the meaning of the code written by programmer, and does it make sense or not, if the compiler can't understand the meaning of the code, it will generate a semantic error.

These errors are like:

- Using a variable with the wrong type.
- Using a variable outside of its scope.
- ...

For example:

```cpp
int main() {
    // Using a variable with the wrong type
    int greet = "Hello World!";
    return 0;
}
```

## Linker Errors

These types of errors are detected by the linker, where the linker is unable to link all the object files together to form a single executable program.

These errors are detected after the compiler has completed its job, and they are like:

- Missing libraries include
- Multiple definitions of the same function
- ...

For example:

```cpp

int main() {
    // Missing to include the std library
    std::cout << "Hello World!" << endl;
    return 0;
}
```
