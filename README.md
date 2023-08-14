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
