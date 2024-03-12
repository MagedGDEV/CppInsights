# Pointers & References

A pointer is just like any variable in C++, but instead of containing data it stores the address of another variable or function. Pointers have data types just like variables and it points to a variables of that type only, and you can access these variables using the pointer.

You might think that why do we need to use pointers and not use the variables directly, that is beacuse of the following reasons:

1. **Dynamic Memory Allocation**: We can allocate memory at run time on the heap using pointers, which is not possible using variables.
2. Pointers are used to operate on strings & arrays very efficiently.
3. Allow accessing specific memory locations.
    - Useful in embedded systems.
    - Useful in system programming.
4. Pointers allows you to access variables that are defined outside the current function.
