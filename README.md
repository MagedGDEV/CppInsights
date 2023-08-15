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
