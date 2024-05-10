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

Pointers are not the same as variables, ***changing the type of the pointer will not change the size of the pointer***, it will only change the type of the data it points to, The size of the pointer depends on the architecture of the system, for example in a 32-bit system the size of the pointer is 4 bytes, and in a 64-bit system the size of the pointer is 8 bytes, below is an example of how to store the address of a variable in a pointer:

```cpp
int x = 10;
int *ptr = &x; // ptr now contains the address of x
double y = 10.5;
double *ptr2 = &y; // ptr2 now contains the address of y and have the same size as ptr
cout << ptr << " " << sizeof(ptr); // Output: 0x16f1a2ff8 8
cout << ptr2 << " " << sizeof(ptr2); // Output: 0x16f1a2ff0 8
float *ptr3 = &x; // Error: Incompatible types
```

Pointers are also variables so the same rules apply to them, you can change the value of the pointer, but you can't change the type of variable it points to.

## Dereferencing Pointers

To access the data that the pointer points to, we use the **`*`** operator, this operator is called the dereference operator, and it's used to access the value of the variable that the pointer points to.

```cpp
int x = 10;
int *ptr = &x;
cout << *ptr; // Output: 10
```

You can also change the value of the variable that the pointer points to using the dereference operator as follows:

```cpp
int x = 10;
int *ptr = &x;
cout << *ptr; // Output: 10
*ptr = 20;
cout << x; // Output: 20
```

You can also change the address that the pointer points to by assigning a new address to the pointer  to point to another variable as shown below:

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
.
.
.
.
delete[] ptr; // Deallocate the memory
```

### Relationship between Pointers & Arrays

Arrays are a collection of similar data types, and they are stored in contiguous memory locations, and the name of the array is also a pointer to the first element of the array, and we can access the elements of the array using the pointer

If we pointed a pointer to the first element of the array or set it's value to the name of the array, we can access the elements of the array using the pointer, and we can also use the dereference operator to access the value of the element as shown below:

```cpp
int arr[] = {1, 2, 3, 4, 5};
cout << arr << endl; // Output: 0x16f1a2ff8
int *ptr = arr; // ptr now points to the first element of the array
cout << ptr << endl; // Output: 0x16f1a2ff8
cout << *ptr << endl; // Output: 1
```

Adding and subtracting from the pointers does not work as it does with normal variables. For example, adding 1 to an integer variable will increase the value by 1, but adding 1 to a pointer will increase the address by the size of the data type it points to, and subtracting 1 from a pointer will decrease the address by the size of the data type it points to.

```cpp
int arr[] = {1, 2, 3, 4, 5};
int *ptr = arr;
cout << ptr << endl; // Output: 0x16f1a2ff4
ptr++; // ptr now points to the second element of the array
cout << ptr << endl; // Output: 0x16f1a2ff8
```

Using this addition we will be able to access the whole array using pointers and C++ provides us to access the elements of the array using the pointer name using the **`[]`** operator, and this is the same as using the name of the array itself.

```cpp
int arr[] = {1, 2, 3, 4, 5};
int *ptr = arr;
cout << ptr[0] << endl; // Output: 1
cout << ptr[1] << endl; // Output: 2
cout << *(ptr) << endl; // Output: 1
cout << *(ptr + 1) << endl; // Output: 2
```

## Pointers Arithmetic

Pointers can be used in multiple operations which are: Assignnment, Arithmetic, Comparison Operations.

Adding and Subtracting from pointers moves the pointers to the next memmory location by adding/subtracting the size of the data type it points to and multiply it by the number of elements you want to move.

```cpp
int arr[] = {1, 2, 3, 4, 5};
int *ptr = arr;
cout << ptr << endl; // Output: 0x16f1a2ff0
ptr+=2; // ptr now points to the third element of the array
cout << ptr << endl; // Output: 0x16F1A2FF8 (assuming the size of int is 4 bytes)
```

Comparing pointers is also possible, and it's used to compare the addresses of the pointers, and it's used to check if the pointers point to the same memory location or not.

```cpp
int arr[] = {1, 2, 3, 4, 5};
int *ptr = arr;
int *ptr2 = arr;
cout << boolalpha;
cout << (ptr == ptr2) << endl; // Output: true
ptr2++;
cout << (ptr == ptr2) << endl; // Output: false
```

## Constants & Pointers

**`const`** can be used with pointers to specify the following:

1. **Constant Pointers**: The pointer itself is constant and can't be changed, but the value it points to can be changed.
2. **Pointer to Constants**: The value the pointer points to is constant and can't be changed, but the pointer itself can be changed.
3. **Constant Pointer to Constants**: Both the pointer and the value it points to are constant and can't be changed.

```cpp
int x = 10;
const int y = 20;
int *const ptr = &x; // Constant Pointer
*ptr = 20; // Valid
ptr = &y; // Error
```

```cpp
int x = 10;
const int y = 20;
const int *ptr = &x; // Pointer to Constant
*ptr = 20; // Error
ptr = &y; // Valid
```

```cpp
int x = 10;
const int y = 20;
const int *const ptr = &x; // Constant Pointer to Constant
*ptr = 20; // Error
ptr = &y; // Error
```
