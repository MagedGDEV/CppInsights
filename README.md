# Structure of C++ Program

C++ has alot of ***keywords***, these keywords are parts of the language that have a special meaning. These keywords are reserved and cannot be used as by programmers as names for variables, functions, classes, or any other identifier.

***Preprocessor*** is a program that process your source code even before compiler sees it, it takes the cpp file do the following:

1. Removes all comments and replace it with a single space
2. Looks for preprocessor directives and process them

Preprocessor directives are lines in source code that start with a # symbol, these directives are instructions for preprocessor to do something. For example: **`#include`** is a preprocessor directive that tells preprocessor to include a header file in the source code.

```cpp
#include <iostream> // This is a preprocessor directive
```

***Comments*** are lines in source code, that are programmer's readable explanation of the code, these lines are ignored by the compiler. Even though comments are important for explaining the code, they should be used wisely and not overused, Don't comment the obvious, your code should be self-explanatory as much as possible.

There are two types of comments in C++:

1. Single line comment: starts with `//` and ends with the end of the line.
2. Multi-line comment: starts with `/*` and ends with `*/`.

```cpp
// This is a single line comment

/*
This 
is 
a 
multi-line 
comment
*/
```

Every C++ program has a ***main( ) function***, this function is the entry point of the program, the program starts executing from the first line of the main function and ends when it reaches the last line of the main function.

The main( ) function has a return type of **`int`**, if the return value is **0** then the program ended successfully, if the return value is **non-zero** then the program ended with an error.

There are two types of main functions:

1. **`int main()`**: This is the most common type of main function, it doesn't take any arguments from the operating system.

    ```cpp

    int main() {
        // Your code goes here
        return 0;
    }
    ```

    To run the program from the terminal, you need to compile the program first, then run the executable file.

    ```bash
    g++ main.cpp -o main
    ./main
    ```

2. **`int main(int argc, char* argv[])`**: This type of main function takes two arguments from the operating system, the first argument is the number of arguments passed to the program, the second argument is an array of strings, each string is one of the arguments passed to the program.

    ```cpp
    int main(int argc, char* argv[]) {
        // Your code goes here
        return 0;
    }
    ```

    To run the program from the terminal, you need to compile the program first, then run the executable file.

    ```bash
    g++ main.cpp -o main
    ./main arg1 arg2 arg3
    ```

**Namespaces** are used to organize code into logical groups and to prevent name collisions that can occur especially when your code base includes multiple libraries that uses the same names for different things.

C++ provide us with 3 different ways to use namespaces:

1. Explicitly use a specific name from a namespace.

    ```cpp
    #include <iostream>

    int main() {
        std::cout << "Hello World!" << std::endl;
        return 0;
    }
    ```

    This is done by adding the namespace name followed by the scope resolution operator **`::`** before the name you want to use, in our example above we used the name **`cout`** from the namespace **`std`**.

2. The using namespace directive.

    ```cpp
    #include <iostream>
    using namespace std;

    int main() {
        cout << "Hello World!" << endl;
        return 0;
    }
    ```

    This is done by adding the keyword **`using`** followed by the namespace name, in our example above we used the namespace **`std`**, it saves us from writing **`std::`** before every name we want to use from the namespace **`std`**.

    > But it's not recommended to use this method for large projects because it can cause name collisions.

3. The using directive.

    ```cpp
    #include <iostream>
    using std::cout;
    using std::endl;

    int main() {
        cout << "Hello World!" << endl;
        return 0;
    }
    ```

    This is done by adding the keyword **`using`** followed by the keyword **`std`** followed by the scope resolution operator **`::`** followed by the name you want to use, in our example above we used the name **`cout`** from the namespace **`std`**.

    > This is best practice since it saves us from writing **`std::`** before every name we want to use, and it doesn't cause name collisions.

## Basic Input/Output

C++ provides us with the **`iostream`** library, this library contains the definitions of **`cin`**, **`cout`**, **`cerr`**, and **`clog`**, these are objects that are used to communicate with the user.

- **`cin`** is an object of type **`istream`**, it is used to read input from the user.
- **`cout`** is an object of type **`ostream`**, it is used to write output to the user.
- **`cerr`** is an object of type **`ostream`**, it is used to write errors to the user.
- **`clog`** is an object of type **`ostream`**, it is used to write logs to the user.

We use the **`<<`** operator to write to the user, and the **`>>`** operator to read from the user.

```cpp

#include <iostream>
using namespace std;

int main() {
    int x;
    cout << "Enter a number: ";
    cin >> x;
    cout << "You entered: " << x << endl;
    return 0;
}
```

To break a line in the output, you can use the **`endl`** keyword or the **`\n`** character, both of them will do the same thing
> But **endl** will flush the output buffer, which means it will write the output to the user immediately, while **\n** will not flush the output buffer, which means it will write the output to the user when the buffer is full.

```cpp
#include <iostream>
using namespace std;

int main() {
    cout << "Hello World!" << endl;
    cout << "Hello World!\n";
    return 0;
}
```
