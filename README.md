# Statements & Operators

***Statement*** is a complete line of code that performs some action, Usually ends with a semicolon `;` and it can contain expressions.

For example:

```cpp
int x = 5; // intialization statement

x = 10; // assignment statement
```

***Expression*** is a combination of one or more operands and operators that can be evaluated to a single value.

For example:

```cpp
int x = 5 + 10; // 5 + 10 is an expression
```

C++ has a rich set of operators that can be classified into the following categories:

- Assignment
- Arithmetic
- Increment and decrement
- Relational
- Logical
- Member access
- ...

The operator can be either **unary, binary or ternary**.

**Assignment** opertor (`=`) is used to assign a value to a variable.

```cpp
LHS = RHS;
```

- right-hand side (RHS) is an expression that is evaluated and assigned to the left-hand side (LHS).
- Value of the RHS must be compatible with the type of the LHS.

For example:

```cpp
int x; 
x = 10; // LHS (x) = RHS (10)
```

You can also assign multiple variables in one statement by chaining the assignment operator.

```cpp
int x, y, z;
x = y = z = 10; // x = (y = (z = 10))
```

What happens above is that the value of `10` is assigned to `z`, then the value of `z` is assigned to `y`, and finally the value of `y` is assigned to `x`.

**Arithmetic** operators are used to perform arithmetic operations on operands (variables and literals):

- Addition (**`+`**)

  - ```cpp
    int x = 5 + 10; // x = 15
    ```

- Subtraction (`-`)

  - ```cpp
    int x = 5 - 10; // x = -5
    ```

- Multiplication (`*`)

  - ```cpp
    int x = 5 * 10; // x = 50
    ```

- Division (`/`)

  - ```cpp
    int x = 5 / 10; // x = 0
    ```

  - The result of the above expression is `0` because both operands are integers, so the result is an integer, to get a floating-point result, at least one of the operands must be a floating-point number.

  - ```cpp
    double x = 5.0 / 10; // x = 0.5
    ```

- Modulus (`%`)

  - ```cpp
    int x = 5 % 10; // x = 5
    ```

  - This operator returns the remainder of the division of the first operand by the second operand.

- Increment & Decrement

  - Increment (`++`)

    - ```cpp
      int x = 5;
      x++; // x = 6
      ```

    - This operator increments the value of the operand by `1`.

  - Decrement (`--`)

    - ```cpp
      int x = 5;
      x--; // x = 4
      ```

    - This operator decrements the value of the operand by `1`.

  - Prefix & Postfix

    - ```cpp
      int x = 5;
      int y = ++x; // x = 6, y = 6
      ```

    - ```cpp
      int x = 5;
      int y = x++; // x = 6, y = 5
      ```

    - The difference between prefix and postfix is that the prefix operator increments the value of the operand and then returns the incremented value, while the postfix operator returns the value of the operand and then increments it.
