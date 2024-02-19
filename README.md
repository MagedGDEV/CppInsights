# Characters and Strings

Characters and strings are represented by the `char` and `string` types, respectively. A `char` is a single character, while a `string` is a sequence of characters. The `string` type is a compound type, meaning that it is made up of smaller parts. In this case, the smaller parts are `char`s.

## Characters

A `char` is a single character. It is written as a single character surrounded by single quotes, like this:

```cpp
char a = 'a';
```

In C++, there are useful functions that can be useful for working with **`char`**

| Testing functions | Description |
| --- | --- |
| **`isalpha()`** | Returns `true` if the character is an alphabetic character (A-Z, a-z) |
| **`isdigit()`** | Returns `true` if the character is a digit (0-9) |
| **`isalnum()`** | Returns `true` if the character is an alphabetic character or a digit |
| **`isspace()`** | Returns `true` if the character is a whitespace character (tab, newline, vertical tab, form feed, carriage return, space) |
| **`isupper()`** | Returns `true` if the character is an uppercase alphabetic character (A-Z) |
| **`islower()`** | Returns `true` if the character is a lowercase alphabetic character (a-z) |
| **`isprint()`** | Returns `true` if the character is printable (not control character) |
| **`ispunct()`** | Returns `true` if the character is a punctuation character (neither alphanumeric nor whitespace) |

| Conversion functions | Description |
| --- | --- |
| **`tolower()`** | Returns the lowercase version of the character, if possible |
| **`toupper()`** | Returns the uppercase version of the character, if possible |

and many more...

## Strings

A `string` is a sequence of characters. It is written as a sequence of characters surrounded by double quotes, like this:

```cpp
string myName = "Alex";
```

There are two types of strings in C++:

- C-style strings
- C++ strings

### C-style strings

A C-style string is simply an array of characters (**`char`**) that uses a null terminator. A null terminator is a special character (**`\0`**) used to indicate the end of the string. For example:

```cpp
char myName[] = "Alex"; // C-style string
```

|A|l|e|x|\0|
|---|---|---|---|---|

The string `"Alex"` is actually 5 characters long, because there is a null terminator at the end of the string. The null terminator is automatically added to the end of C-style strings.

if you decide to change character 5 to another character, the null terminator will be removed and the string will still be longer than 5 characters.

```cpp
myName[5] = 'a'; // Change the null terminator to 'a'
```

The above code will not give you an error, but it could cause problems later on when you try to use the string. This is because the null terminator is no longer at the end of the string, so the program will continue reading characters until it finds a null terminator. This is called a **buffer overflow**.

You need to be careful when intializing C-style strings away from their declaration. For example:

```cpp
char myName[5];
myName = "Alex"; // Error!
```

The above code will give you an error, because you cannot assign a string to a C-style string after it has been declared. instead, you need to use the `strcpy()` function from the `<cstring>` header:

```cpp
// #include <cstring>

char myName[5];
strcpy(myName, "Alex");
```

There are many functions provided by the `<cstring>` header that can be useful when working with C-style strings, such as:

| Function | Description |
| --- | --- |
| **`strlen()`** | Returns the length of the string |
| **`strcpy()`** | Copies a string to another string |
| **`strcat()`** | Concatenates two strings |
| **`strcmp()`** | Compares two strings |

You can convert a C-style String to an integer, float, long, .... using functions provided by the `<cstdlib>` header, such as:

| Function | Description |
| --- | --- |
| **`atoi()`** | Converts a C-style string to an integer |
| **`atof()`** | Converts a C-style string to a float |
| **`atol()`** | Converts a C-style string to a long |

```cpp
#include <iostream>
#include <cstring>
#include <cstdlib>

using namespace std;

int main() {
    char myName[] = "Alex";
    cout << strlen(myName) << endl; // 4

    char myName2[] = "123";
    cout << atoi(myName2) << endl; // 123

    return 0;
}
```

> [!CAUTION]
> All the functions provided by the `<cstring>` and `<cstdlib>` headers may depend on the null terminator to work properly. If the null terminator is not present, the functions will continue reading characters until they find a null terminator, so it is important to make sure that the null terminator is present when working with C-style strings and their functions.

In some cases you may need to ignore the spaces the user enters, and get everything the user enters in that line as a string to do that you can use the `cin.getline()` function.

```cpp
#include <iostream>
using namespace std;

int main() {
    char myName[100];
    cin.getline(myName, 100); // 100 is the maximum number of characters that can be stored in myName
    cout << myName << endl;

    return 0;
}
```

user input:

```bash
Maged Elesseily # "Maged Elesseily" will be stored in myName
```

> [!TIP]
> When working with functions that returns the size of an array, string, .... it would be better to store the result in a variable of type `size_t` which is a type that is guaranteed to be big enough to hold the size of any object, and this type's size is dependent on the machine and the compiler you are using.

### C++ strings

 A C++ string (**`string`**) is a class that is provided by the `<string>` header. It is a compound type. This means that it is made up of `char`s. it is a lot easier to work with than C-style strings and provides lots of advantages:

- Ability to increase and decrease the size of the string dynamically at runtime.
- Does not require a null terminator.
- Works with operators and functions that are not available for C-style strings (e.g. `+`, `==`, `!=`, `+=`, `[]`, ...).
- Can be converted to C-style strings when needed.
- .....

There are several ways that gives us several functionalities when intializing a C++ string:

- You can use the ways of intializing any variable with the C++ string type:

```cpp
#include <iostream>
#include <string>

using std::string;

int main() {
    string myName = "Maged"; // using the C-like initialization
    string myName("Maged"); // using the Constructor initialization
    string myName{"Maged"}; // using the List initialization

    return 0;
}
```

- You can get a specific number of characters from a string at initialization:

```cpp
string myName {"Maged", 3}; // "Mag" will be stored in myName
```

- You can get a specific number of characters from a string at initialization starting from a specific index:

```cpp
string myName {"Maged", 2, 3}; // "ged" will be stored in myName
```

- You can initialize a string with a specific number of a specific character:

```cpp
string myName(5, 'a'); // "aaaaa" will be stored in myName
```

> [!NOTE]
> Unlike C-style strings, when you declare a C++ string, it will be automatically intialized to an empty string if you don't intialize it yourself no need to worry about the null terminator, and you can intialize it after declaration using the assignment operator `=`, which is not allowed for C-style strings you have to use `strcpy()`.

You can access any index in C++ strings just like you do with vectors:

```cpp
string myName = "Maged";
cout << myName[0] << endl; // M
cout << myName.at(1) << endl; // a
```

C++ operators provides a lot of functionalities when working with C++ strings:

- You can concatenate using the `+` operator, you can concatenate **a string with a C-style string, character, another string**. for example:

```cpp
string myName = "Maged";
string fullName = myName + " Elesseily"; // "Maged Elesseily" will be stored in fullName
string fullName2 = "Maged" + " Elesseily"; // Illegal!, because you can't concatenate two C-style strings using the + operator
```

- You can compare **a string with another string or C-style string** using the `==`, `!=`, `>`, `<`, `>=`, `<=` operators, for example:

```cpp
string myName = "Maged";
if (myName == "Maged") {
    cout << "Equal" << endl;
} else {
    cout << "Not Equal" << endl;
}
// Output: Equal
```

>[!NOTE]
>\>, <, >=, <= operators are used to compare the strings lexicographically (i.e. dictionary order).

We are provided with a lot of functions that can be useful when working with C++ strings, such as:

| Function | Description |
| --- | --- |
| **`length() / size()`** | Returns the length of the string |
| **`substr(begin, length)`** | Returns a substring of the string starting from the index `begin` and has a length of `length` |
| **`find(substring)`** | Returns the index of the first occurrence of `substring` in the string, if not found it returns `string::npos` (not found)|
| **`find(substring, begin)`** | Returns the index of the first occurrence of `substring` in the string starting from the index `begin`, if not found it returns `string::npos`|
| **`erase(begin, length)`** | Erases a substring of the string starting from the index `begin` and has a length of `length` |
| **`clear()`** | Erases the whole string |

Just like C-style strings, we can ignore the spaces the user enters, and get everything the user enters in that line as a string using the `getline()` function.

```cpp
#include <iostream>
#include <string>
using namespace std;

int main() {
    string myName;
    getline(cin, myName);
    cout << myName << endl;

    return 0;
}
```

user input:

```bash
Maged Elesseily # "Maged Elesseily" will be stored in myName
```

You can also specify a delimiter to stop reading the input when it is found, for example:

```cpp
#include <iostream>
#include <string>
using namespace std;

int main() {
    string myName;
    getline(cin, myName, 'x'); // Stop reading when 'x' is found
    cout << myName << endl;

    return 0;
}
```

user input:

```bash
Magedx Elesseily # "Maged" will be stored in myName
```
