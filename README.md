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

## Accessing Pointers & Storing addresses

To access the address of a variable, we use the **`&`** unary operator. This address can be different each time you run the program, and it's stored in hexadecimal format. Below is an example of how to access the address of a variable:

```cpp
int x = 10;
cout << &x; // Output: 0x16f1a2ff8
```

Pointers are not the same as variables, changing the type of the pointer will not change the size of the pointer, it will only change the type of the data it points to, The size of the pointer depends on the architecture of the system, for example in a 32-bit system the size of the pointer is 4 bytes, and in a 64-bit system the size of the pointer is 8 bytes, below is an example of how to store the address of a variable in a pointer:

```cpp
int x = 10;
int *ptr = &x; // ptr now contains the address of x
double y = 10.5;
double *ptr2 = &y; // ptr2 now contains the address of y and have the same size as ptr
cout << ptr << " " << sizeof(ptr); // Output: 0x16f1a2ff8 8
cout << ptr2 << " " << sizeof(ptr2); // Output: 0x16f1a2ff0 8
float *ptr3 = &x; // Error: Incompatible types
```

Pointers are also variables so the same rules apply to them, you can change the value of the pointer, and you can also change the address it points to.

## Dereferencing Pointers

To access the data that the pointer points to, we use the **`*`** operator, this operator is called the dereference operator, and it's used to access the value of the variable that the pointer points to.

```cpp
int x = 10;
int *ptr = &x;
cout << *ptr; // Output: 10
```

You can also change the value of the variable that the pointer points to using the dereference operator, and this will change the value of the variable itself.

```cpp
int x = 10;
int *ptr = &x;
cout << *ptr; // Output: 10
*ptr = 20;
cout << x; // Output: 20
```

```cpp
double high_salary {30000};
double low_salary {10000};
double *ptr = &high_salary;
cout << *ptr; // Output: 30000
ptr = &low_salary;
cout << *ptr; // Output: 10000
```

## Dynamic Memory Allocation

Dynamic memory allocation is the process of allocating memory from the heap at run time which allows us to do the following:

1. Allocate memory at run time.
2. Create arrays of user-defined size.

To allocate memory at run time, we use the **`new`** operator, and to deallocate the memory we use the **`delete`** operator where it frees the allocated location from memory. Below is an example of how to allocate memory at run time:

```cpp
int *ptr = new int; // Allocate memory for an integer
*ptr = 10; // Assign 10 to the memory location
.
.
.
.
delete ptr; // Deallocate the memory
```

>[!NOTE]
> After allocating memory using the `new` operator, Don't forget to intialize the memory location to avoid any garbage value.

To allocate memory for an array, we use the **`new`** operator followed by the data type and the size of the array, and to deallocate the memory we use the **`delete[]`** operator. Below is an example of how to allocate memory for an array at run time:

```cpp
int size; 
cin >> size;
int *ptr = new int[size]; // Allocate memory for an array of integers and the size is determined at run time

for (int i = 0; i < size; i++) {
    ptr[i] = i; // Assign i to the memory location
}

delete[] ptr; // Deallocate the memory
```
