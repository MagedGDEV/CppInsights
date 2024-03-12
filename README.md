# Pointers & References

A pointer is just like any variable in C++, but instead of containing data it stores the address of another variable or function. Pointers have data types just like variables and it points to a variables of that type only, and you can access these variables using the pointer.

You might think that why do we need to use pointers and not use the variables directly, that is beacuse of the following reasons:

1. **Dynamic Memory Allocation**: We can allocate memory at run time on the heap using pointers, which is not possible using variables.
2. Pointers are used to operate on strings & arrays very efficiently.
3. Allow accessing specific memory locations.
    - Useful in embedded systems.
    - Useful in system programming.
4. Pointers allows you to access variables that are defined outside the current function.

## Declaration & Initialization

To declare a pointer, we must use the `*` operator, and follow the same rules as we did for declaring variables **(Check [Variables branch](https://github.com/MagedGDEV/CppInsights/tree/variables))** as shown below:

```cpp
int *ptr; // Pointer to an integer
char *ptr; // Pointer to a character
double *ptr; // Pointer to a double
float *ptr; // Pointer to a float
```

It's important to intialize the pointer to `nullptr` or `0` to avoid any garbage value, and to avoid any undefined behavior unless you are going to intialize the pointer to a specific variable address.

```cpp
int *ptr = nullptr;
double *ptr = 0;
```