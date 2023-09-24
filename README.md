# Controlling Program Flow

There are **three** types of controlling program flow in C++:

1. Sequence

    - Order of execution of statements in a program ***(squentially)***

2. Selection

    - Making decisions based on conditions using:
        1. **`if`** statement
        2. **`if-else`** statement
        3. **`if-else-if`** statement
        4. Nested **`if`** statement
        5. **`switch`** statement
        6. Conditional operator **`?:`**

3. Iteration

    - Repeating a block of code until a certain condition is met using:
        1. **`for`** loop
        2. **`while`** loop
        3. **`do-while`** loop
        4. **`continue`** & **`break`** statements
        5. Nested loops

Before we start learning about these types, we need to know about **blocks** and **scope**.

**Blocks** statements are the statements that are enclosed in curly braces **`{}`**, and they can be nested inside each other, each block defines a new scope.

**Scope** is the region of the program where a variable can be accessed, there are three types of scope:

1. **Local scope**

    - Variables declared inside a block are local to that block, and can only be accessed inside that block.

2. **Global scope**

    - Variables declared outside any block are global, and can be accessed anywhere in the program.

3. **Function scope**

    - Variables declared inside a function are local to that function, and can only be accessed inside that function, **we will learn more about functions later.**

In the below example we will see how blocks and scope work:

```cpp
#include <iostream>

using std::cout;
using std::endl;

int main()
{ // start of a new scope
    int x = 1; 
    { // start of a new scope
        int y = 2; 
        { // start of a new scope
            int x = 3; // shadowing
            cout << "x = " << x << endl; // x = 3
            cout << "y = " << y << endl; // y = 2
        } // x = 3 is destroyed here
        cout << "x = " << x << endl; // x = 1
        cout << "y = " << y << endl; // y = 2
    } // y is destroyed here
    cout << "x = " << x << endl; // x = 1
    cerr << "y = " << y << endl; // this will give an error because y is not defined in this scope
    return 0;
}
```

>[!IMPORTANT]
> Even though we already have a variable named **`x`** in the first scope, we can still declare another variable with the same name inside another block and now the first variable **`x`** is hidden inside that block, and we can only access the local variable inside that block, this is known as **shadowing**.

## Selection

In this section we will learn about the different ways to make decisions in C++, to allow our programs to behave differently based on different conditions.

1. **`if`** statement

    - The **`if`** statement is used to execute a block of code if a condition is true.

    - The syntax of the **`if`** statement is:

        ```cpp
        if (condition)
            statement;
        ```

    - The condition can be any expression that evaluates to a boolean value, and it can be a compound condition using logical operators.

    - The statement can be any statement, the if condition is followed by a single statement, if we want to execute multiple statements we need to enclose them in a block.

    - The syntax of the **`if`** statement with a block is:

        ```cpp
        if (condition)
        {
            statement1;
            statement2;
            ...
        }
        ```

    - Example:

        ```cpp
        #include <iostream>

        using std::cout;
        using std::cin;
        using std::endl;

        int main()
        {
            int x;
            cout << "Enter a number: ";
            cin >> x;
            if (x > 0)
                cout << "The number is positive" << endl;
            return 0;
        }
        ```

2. **`if-else`** statement

    - The **`if-else`** statement is used to execute a block of code if a condition is true, and another block of code if the condition is false.

    - The syntax of the **`if-else`** statement is:

        ```cpp
        if (condition)
            statement1;
        else
            statement2;
        ```

    - Like the **`if`** statement, the condition can be any expression that evaluates to a boolean value, and it can be a compound condition using logical operators, and the statement can be any statement, the if condition is followed by a single statement, if we want to execute multiple statements we need to enclose them in a block.

    - Example:

        ```cpp
        #include <iostream>

        using std::cout;
        using std::cin;
        using std::endl;

        int main()
        {
            int x;
            cout << "Enter a number: ";
            cin >> x;
            if (x > 0) {
                cout << "The number is positive" << endl;
            }
            else {
                cout << "The number is negative" << endl;
            }
            return 0;
        }
        ```

3. **`if-else-if`** statement

    - The **`if-else-if`** statement is used to execute a block of code if a condition is true, and another block of code if the condition is false, and another block of code if another condition is true, and so on.

    - The syntax of the **`if-else-if`** statement is:

        ```cpp
        if (condition1)
            statement1;
        else if (condition2)
            statement2;
        else if (condition3)
            statement3;
        ...
        else
            statementN;
        ```

    - Like the **`if`** statement, the condition can be any expression that evaluates to a boolean value, and it can be a compound condition using logical operators, and the statement can be any statement, the if condition is followed by a single statement, if we want to execute multiple statements we need to enclose them in a block.

    - Example:

        ```cpp
        #include <iostream>

        using std::cout;
        using std::cin;
        using std::endl;

        int main()
        {
            int x;
            cout << "Enter a number: ";
            cin >> x;
            if (x > 0) {
                cout << "The number is positive" << endl;
            }
            else if (x < 0) {
                cout << "The number is negative" << endl;
            }
            else {
                cout << "The number is zero" << endl;
            }
            return 0;
        }
        ```

        > [!NOTE]
        > Once a condition is true, the rest of the conditions are not checked. and the statements in the block of the first true condition are executed.
