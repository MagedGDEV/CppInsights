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

> [!IMPORTANT]
> All the functions provided by the `<cstring>` and `<cstdlib>` headers depend on the null terminator to work properly. If the null terminator is not present, the functions will continue reading characters until they find a null terminator, so it is important to make sure that the null terminator is present when working with C-style strings and their functions.
