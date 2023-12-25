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

>[!CAUTION]
> Even though we already have a variable named **`x`** in the first scope, we can still declare another variable with the same name inside another block and now the first variable **`x`** is hidden inside that block, and we can only access the local variable inside that block, this is known as **shadowing**.

## Selection

In this section we will learn about the different ways to make decisions in C++, to allow our programs to behave differently based on different conditions.

- **`if`** statement

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

- **`if-else`** statement

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

- **`if-else-if`** statement

  - The if-else-if statement is used to execute a block of code if a condition is true. If the condition is false, it checks another condition and, if true, executes a different block of code. This process can continue for multiple conditions, with each else-if block providing an alternative code path when its condition is true.

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

- Nested **`if`** statement

  - We can have an **`if`** statement inside another **`if`** statement.

  - The syntax of the nested **`if`** statement is:

      ```cpp
      if (condition1)
      {
          statement1;
          if (condition2)
              statement2;
          else
              statement3;
      }
      ```

  - You can have as many nested **`if`** statements as you want, but make sure to indent your code properly to make it more readable.

  - Be aware of **dangling else** problem, which happens when we have an **`if-else`** statement inside another **`if`** statement, and we don't know which **`if`** statement the **`else`** belongs to, for example:

      ```cpp
      if (condition1)
          if (condition2)
              statement1;
      else 
          statement3;
      ```

  - Example:

      ```cpp
      #include <iostream>

      using std::cout;
      using std::cin;
      using std::endl;

      int main() {
          int x;
          cout << "Enter a number: ";
          cin >> x;
          if (x > 0) {
              if (x % 2 == 0) {
                  cout << "The number is positive and even" << endl;
              }
              else {
                  cout << "The number is positive and odd" << endl;
              }
          }
          else if (x < 0) {
              if (x % 2 == 0) {
                  cout << "The number is negative and even" << endl;
              }
              else {
                  cout << "The number is negative and odd" << endl;
              }
          }
          else {
              cout << "The number is zero" << endl;
          }
          return 0;
      }
      ```

>[!WARNING]
> The compiler will generate warning to inform you about the dangling else problem, but it will not prevent you from compiling your code, so you need to use curly braces so that the compiler knows which **`if`** statement the **`else`** belongs to.

- **`switch`** statement

  - The **`switch`** statement is used to execute a block of code based on the value of a variable, it is similar to the **`if-else-if`** statement, but it is more readable when we have a lot of conditions.

  - The syntax of the **`switch`** statement is:

      ```cpp
      switch (variable)
      {
          case value1:
              statement1;
              break;
          case value2:
              statement2;
              break;
          ...
          default:
              statementN;
      }
      ```

  - The **`default`** case is optional, and it is executed if none of the cases is true, so it is similar to the **`else`** statement in the **`if-else-if`** statement. Even though it is optional, it is recommended to always include it, to make sure that the program will always execute a statement.

  - if you want to execute the same statement for multiple cases, you can do that by omitting the **`break`** statement, for example:

      ```cpp
      switch (variable)
      {
          case value1:
          case value2:
              statement1;
              break;
          case value3:
              statement2;
              break;
          ...
          default:
              statementN;
      }
      ```

  - In the above example, statement1 will be executed if the value of the variable is either value1 or value2.

  - The variable can be of any integral type, and the cases can be any integral constant expression.

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
      switch (x)
      {
          case 1:
              cout << "The number is one" << endl;
              break;
          case 2:
              cout << "The number is two" << endl;
              break;
          case 3:
              cout << "The number is three" << endl;
              break;
          default:
              cout << "The number is not one, two or three" << endl;
      }
      return 0;
  }
  ```

> [!IMPORTANT]
> The existence of the **`break`** statement is very important, because without it the program will continue executing the statements in the next cases, until it finds a **`break`** statement or the end of the **`switch`** statement.

- Conditional operator **`?:`**

  - The conditional operator **`?:`** is used to execute one of two expressions based on a condition, it is similar to the **`if-else`** statement, but it is more readable when we have a simple condition.

  - The syntax of the conditional operator **`?:`** is:

      ```cpp
      (condition) ? expression1 : expression2;
      ```

  - The condition can be any expression that evaluates to a boolean value, and it can be a compound condition using logical operators, and the expressions can be any expression, and they can be compound expressions using the comma operator.

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
          cout << "The number is " << ((x > 0) ? "positive" : "negative") << endl;
          return 0;
      }
      ```

> [!CAUTION]
> Don't add nested conditional operators, because it will make your code less readable.

## Iteration

In this section we will learn about the different ways to repeat a block of code and how to control the flow of the loop.

- **`for`** loop

  - The **`for`** loop is used to repeat a block of code a certain number of times, it is the most commonly used loop in C++.

  - The syntax of the **`for`** loop is:

      ```cpp
      for (initialization; condition; update)
          statement;
      ```

  - The initialization is used to initialize the loop counter, it is executed only once before the loop starts.

  - The condition is used to check if the loop counter has reached the end of the loop, if the condition is true, the statement is executed, if the condition is false, the loop is terminated.

  - The update is used to update the loop counter, it is executed after each iteration.

  - The statement can be any statement, the for condition is followed by a single statement, if we want to execute multiple statements we need to enclose them in a block.

  - Example:

      ```cpp
      #include <iostream>

      using std::cout;
      using std::endl;

      int main()
      {
          for (int i = 0; i < 10; i++)
              cout << i << endl;
          return 0;
      }
      ```

  - The initialization, condition and update can be any expression, and they can be compound expressions using the **comma operator `,`**.

  - Example:

      ```cpp
      #include <iostream>

      using std::cout;
      using std::endl;

      int main()
      {
          int x = 0;
          for (int i = 0; i < 10; i++, x += 2)
              cout << i << " " << x << endl;
          return 0;
      }
      ```

  - The initialization, condition and update can be omitted, but you need to make sure that the loop will terminate, otherwise it will be an infinite loop.

  - Example:

      ```cpp
      #include <iostream>

      using std::cout;
      using std::endl;

      int main()
      {
          int i = 0;
          for (;;)
          {
              cout << i << endl;
              i++;
              if (i == 10)
                  break;
          }
          return 0;
      }
      ```

- **Range-based `for`** loop

  - This is a new type of **`for`** loop that was introduced in C++11, it is used to iterate over the elements of a range, such as an array or a container.

  - The syntax of the range-based **`for`** loop is:

      ```cpp
      for (declaration : range)
          statement;
      ```

  - The declaration is used to declare a variable that will be used to store the value of each element in the range, it can be a reference to the elements of the range, or it can be a copy of the elements of the range.

  - The range is used to specify the range of elements to iterate over, it can be an array, a container, a vector, or any other range of elements.

  - The statement can be any statement, the for condition is followed by a single statement, if we want to execute multiple statements we need to enclose them in a block.

  - Example:

      ```cpp
      #include <iostream>

      using std::cout;
      using std::endl;

      int main()
      {
          int arr[] = { 1, 2, 3, 4, 5 };
          for (int x : arr)
              cout << x << endl;
          return 0;
      }
      ```

  - The output of the above example is:

      ```dash
      1
      2
      3
      4
      5
      ```
  
  - If the elements you are iterating over won't be useful in the code later, you can add the container to the **`for`** loop directly, without declaring a variable to store the elements.

  - Example:

      ```cpp
      #include <iostream>
      #include <vector>

      using std::cout;
      using std::endl;
      using std::vector;

      int main()
      {
          for (int x : { 1, 2, 3, 4, 5 })
              cout << x << endl;
          return 0;
      }
      ```

  - At some point you won't be able to specify the type of the elements in the range, in this case you can use **`auto`** to let the compiler deduce the type of the elements.

  - Example:

      ```cpp
      #include <iostream>
      #include <vector>
    
      using std::cout;
      using std::endl;
      using std::vector;
    
      int main()
      {
          vector<int> v = { 1, 2, 3, 4, 5 };
          for (auto x : v)
              cout << x << endl;
          return 0;
      }
      ```

> [!TIP]
> You can control the precision of the decimal points of the output using **`std::setprecision`** function from the **`iomanip`** header.

- **`while`** loop

  - The **`while`** loop is used to repeat a block of code while a condition is true.

  - The syntax of the **`while`** loop is:

      ```cpp
      while (condition)
          statement;
      ```

  - The condition can be any expression that evaluates to a boolean value, and it can be a compound condition using logical operators, and the statement can be any statement, the while condition is followed by a single statement, if we want to execute multiple statements we need to enclose them in a block.

  - Example:

      ```cpp
      #include <iostream>

      using std::cout;
      using std::endl;

      int main()
      {
          int i = 0;
          while (i < 10)
          {
              cout << i << endl;
              i++;
          }
          return 0;
      }
      ```

  - The condition can be omitted, but you need to make sure that the loop will terminate, otherwise it will be an infinite loop.

  - Example:

      ```cpp
      #include <iostream>

      using std::cout;
      using std::endl;

      int main()
      {
          int i = 0;
          while (true)
          {
              cout << i << endl;
              i++;
              if (i == 10)
                  break;
          }
          return 0;
      }
      ```

- **`do-while`** loop

  - The **`do-while`** loop is similar to the **`while`** loop, but the condition is checked at the end of the loop, so the loop will always execute at least once.

  - The syntax of the **`do-while`** loop is:

      ```cpp
      do
          statement;
      while (condition);
      ```

  - The condition can be any expression that evaluates to a boolean value, and it can be a compound condition using logical operators, and the statement can be any statement, the do-while condition is followed by a semicolon **`;`**.

  - Example:

      ```cpp
      #include <iostream>

      using std::cout;
      using std::endl;

      int main()
      {
          int i = 0;
          do
          {
              cout << i << endl;
              i++;
          } while (i < 10);
          return 0;
      }
      ```

> [!CAUTION]
> Be careful when dealing with variables in the condition of the **`do-while`** loop, you need to make sure that the variable is initialized before the loop not inside the do block, otherwise it would lead to an error.

- **`continue`** & **`break`** statements

  - The **`continue`** statement is used to skip the rest of the statements in the current iteration of the loop, and start the next iteration.

  - The **`break`** statement is used to terminate the loop immediately.

  - Example:

      ```cpp
      #include <iostream>

      using std::cout;
      using std::endl;

      int main()
      {
          for (int i = 0; i < 10; i++)
          {
              if (i % 2 == 0)
                  continue;
              if (i == 7)
                  break;
              cout << i << endl;
          }
          return 0;
      }
      ```

  - The output of the above example is:

      ```dash
      1
      3
      5
      ```

- Nested loops

  - We can have a loop inside another loop, this is known as nested loops.

  - Example:

      ```cpp
      #include <iostream>

      using std::cout;
      using std::endl;

      int main()
      {
          for (int i = 0; i < 10; i++)
          {
              for (int j = 0; j < 10; j++)
                  cout << i << " " << j << endl;
          }
          return 0;
      }
      ```
  
  - The output of the above example is:

      ```dash
        0 0
        0 1
        0 2
        0 3
        .
        .
        .
        5 9
        6 0
        6 1
        6 2
        6 3
        .
        .
        9 9
      ```
