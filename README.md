# Arrays & Vectors

***Arrays*** are a collection of variables of the **same type** placed in contiguous memory locations that can be individually referenced by using an index to a **unique identifier**.

Arrays have several characteristics:

- Size of the array is fixed
- Variables are of same type
- Stored in contiguous memory locations
- Each element can be accessed by using an index (position)
- Position of first element is **`0`** not **`1`**

To declare an array, we use the following syntax:

```cpp
type arrayName [ arraySize ];
```

For example:

```cpp
int numbers[5]; // array of 5 integers
double values[10]; // array of 10 doubles
```

To intialize an array there multiple ways:

- Initialize each element individually

```cpp
int numbers[5] = { 1, 2, 3, 4, 5 }; // array of 5 integers
```

- Intialize first few elements and rest will be set to **`0`**

```cpp
int numbers[5] = { 1, 2, 3 }; // array of 5 integers -> { 1, 2, 3, 0, 0 }
```

- Intialize all elements to **`0`**

```cpp
int numbers[5] = { }; // array of 5 integers -> { 0, 0, 0, 0, 0 }
int numbers[5] = { 0 }; // array of 5 integers -> { 0, 0, 0, 0, 0 }
```

- Size automatically calculated by compiler

```cpp
int numbers[] = { 1, 2, 3, 4, 5 }; // array of 5 integers
```

To access an element in an array, we use the following syntax:

```cpp
arrayName[index];
```

For example:

```cpp
int numbers[5] = { 1, 2, 3, 4, 5 };
cout << numbers[0] << endl; // 1
cout << numbers[1] << endl; // 2

numbers[3] = 10; // assign 10 to 4th element
```

The ***name of the array*** represents the address of the first element in the array in memory. This is why we can use the array name as a pointer to the first element in the array. The ***index*** of the array represents the offset from the first element in the array.

> You have to do the bounds checking yourself. If you try to access an element outside the bounds of the array, you will get undefined behavior.

***Multidimensional arrays*** are arrays of arrays, where each element is itself an array. You have to be *`aware that some compilers limit the number of dimensions`* you can have in an array.

To declare a multidimensional array, we use the following syntax:

```cpp
type arrayName [ arraySize1 ][ arraySize2 ];
```

For example:

```cpp
int numbers[5][5]; // array of 5 arrays of 5 integers
```

To initialize a multidimensional array, we use the following syntax:

```cpp

int array2D[2][3] = { 
    { 1, 2, 3 }, 
    { 4, 5, 6 } 
}; // array of 2 arrays of 3 integers
```

To access an element in a multidimensional array, we use the following syntax:

```cpp
array2D [0][1] = 2;
```
