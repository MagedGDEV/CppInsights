# Variables & Constants

***Variables*** are abstractions for a memory location that allows programmers to use meaningful names and not deal directly with memory addresses.

Variables have two main characteristics:

- **Type**: The type of data that can be stored in the variable. For example, `int`, `float`, `char`, `bool`, etc.
- **Value**: The value stored in the variable. For example, `5`, `3.14`, `'a'`, `true`, etc.

Variables must be declared before they can be used, and their value can be changed during the execution of the program.

To ***declare*** a variable, we must specify its type and name, and you must follow the following rules for naming variables:

- Can only contain letters, digits, and underscores (`_`).
- Must begin with a letter or an underscore (`_`).
- Case-sensitive (`myVar` and `myvar` are different variables).
- Cannot contain spaces.
- Cannot use C++ reserved keywords.
- Cannot redeclare a variable in the same scope.

```cpp
// Valid variable names
int myVar;
int _age; 
int my_age20; 
```

```cpp
// Invalid variable names
int 20age; // Cannot begin with a digit
int my age; // Cannot contain spaces
int my-age; // Cannot contain hyphens
```

After declaring a variable, it can have any value which is not predictable, So before using a variable, we must ***initialize*** it with a value first, otherwise, it will have a garbage value.

C++ has multiple ways to intialize a variable:

1. **C-like initialization**

    ```cpp
    int myVar = 5;
    ```

2. **Constructor initialization**

    ```cpp
    int myVar(5);
    ```

3. **List initialization**

    ```cpp
    int myVar{5};
    ```

Variables have different **types** that determine the size of the memory location and the range of values that can be stored in it, it is important to be aware that the size of a variable depends on the compiler and the operating system.

The variables types are:
| Type | Size  | Purpose |
| ------------- | ------ | --- |
|**`char`**|at least 8 bits | Used to store characters: `'a'`, `'b'`, `'c'`, etc.|
|**`char16_t`**|at least 16 bits| Used to store Unicode characters: `u'a'`, `u'b'`, `u'c'`, etc.|
|**`short`**|at least 16 bits| Used to store integers: `1`, `2`, `3`, etc.|
|**`int`**|at least 16 bits| Used to store integers|
|**`long`**|at least 32 bits| Used to store large integers values|
|**`long long`**|at least 64 bits| Used to store large integers values|
|**`float`**|at least (32 bits / 7 decimal digits)| Used to store floating-point numbers: `3.14`, `2.718`, etc.|
|**`double`**|at least (64 bits / 15 decimal digits)| Used to store floating-point numbers|
|**`bool`**|at least 8 bits| Used to store boolean values: `true` or `false`|

> To intialize a character variable, we must use single quotes (`'`), for example: `char myChar {'a'};`
> The variable that stores integer values can be either `signed` or `unsigned`, the `signed` is the default type, and it can store both positive and negative values, while the `unsigned` type can only store positive values, to declare an `unsigned` variable, we must use the `unsigned` keyword before the type, for example: `unsigned int myVar {5};`

The benefit of using list initialization is that it prevents narrowing conversions, for example, if we try to initialize a `int` variable with a `double` value, the compiler will throw an error, but other types of initialization will not throw an error, and the value will be truncated.

```cpp
int myVar1 = 5.5; // No error
int myVar4 {5.5}; // Error: narrowing conversion
```

To get the size of a variable,  or size of a type, we can use the `sizeof` operator, for example:

```cpp
#include <iostream>
using std::cout;
using std::endl;

int main() {
    int myVar {5};
    cout << sizeof(myVar) << endl; // 4 bytes
    cout << sizeof(int) << endl; // 4 bytes
    return 0;
}
```

**Constants** are variables whose value cannot be changed during the execution of the program, and they are declared using the `const` keyword, for example:

```cpp

const int myVar {5};
myVar = 10; // Error: cannot assign to variable 'myVar' with const-qualified type 'const int'
```
