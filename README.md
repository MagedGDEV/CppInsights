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

***Vectors*** are similar to arrays, where they are a collection of variables of the same type, it is provided by the C++ Standard Library. Vectors are more flexible than arrays which provides the following characteristics:

- Size of the vector is **dynamic**
- Variables are of same type
- Stored in contiguous memory locations
- Each element can be accessed by using an index (position)
- Position of first element is **`0`** not **`1`**
- Provides methods to add and remove, sort, and ...

To use vectors, we have to include the `<vector>` header file, and to declare a vector, we use the following syntax:

```cpp
#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<int> numbers; // Empty vector of integers
    vector<double> values (10); // Vector of 10 doubles initialized to 0.0
}
```

Unlike arrays, when we declare a vector the values of the vector are intialized to **`0`** incase of integers and **`0.0`** incase of doubles, ...

We can also initialize a vector with values, we use the following syntax:

```cpp
vector<int> numbers { 1, 2, 3, 4, 5 }; // Vector of 5 integers
```

You can intialize a vector with a specific size, and specify a value for all elements, we use the following syntax:

```cpp
vector<int> numbers (5, 100); // Vector of 5 integers initialized to 100
```

To access an element in a vector, we can do it in two ways:

- Using the `[]` operator

```cpp
vector<int> numbers { 1, 2, 3, 4, 5 };
cout << numbers[0] << endl; // 1
```

- Using the `at()` method

```cpp
cout << numbers.at(0) << endl; // 1
```

The **`at()`** method is safer than the **`[]`** operator, because it does ***bounds checking***, and if you try to access an element outside the bounds of the vector, it will throw an exception during runtime instead of undefined behavior.

