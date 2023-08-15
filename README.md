# Variables & Constants

***Variables*** are abstractions for a memory location that allows programmers to use meaningful names and not deal directly with memory addresses.

Variables have two main characteristics:

- **Type**: The type of data that can be stored in the variable. For example, `int`, `float`, `char`, `bool`, etc.
- **Value**: The value stored in the variable. For example, `5`, `3.14`, `'a'`, `true`, etc.

Variables must be declared before they can be used, and their value can be changed during the execution of the program.

To declare a variable, we must specify its type and name, and you must follow the following rules for naming variables:

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
