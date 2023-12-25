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
