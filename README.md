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

***Assignment*** opertor (`=`) is used to assign a value to a variable.

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

***Arithmetic*** operators are used to perform arithmetic operations on operands (variables and literals):

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

It is important to know that the precedence of arithmetic operators is from left to right,  and going from highest to lowest precedence:

- `()` prantheses
- `++` and `--`
- `*`, `/` and `%`
- `+` and `-`

In some cases you may need to change type of variable for specific operation only, this is known as ***type-casting***, and there are two ways to do it:

- C-style casting
In the below example we needed to cast the value of `x` to `double` to get a floating-point result.

  - ```cpp
    int x = 5;
    double y = (double) x / 10; // y = 0.5
    ```

- Modern C++ casting
This is the preferred way of casting in C++, as it is more safe than C-style casting, and checks if the casting is possible at compile time.

  - ```cpp
    int x = 5;
    double y = static_cast<double>(x) / 10; // y = 0.5
    ```

> **Note:** `cout << boolalpha;` is used to print boolean values as `true` or `false` instead of `1` or `0` and you can revert back to the default behavior by using `cout << noboolalpha;`

***Relational*** operators are used to compare two operands and return a boolean value (`true` or `false`):

- Equal to (`==`)

  - ```cpp
    bool x = 5 == 10; // x = false
    ```

- Not equal to (`!=`)

  - ```cpp
    bool x = 5 != 10; // x = true
    ```

- Greater than (`>`)
  
  - ```cpp
    bool x = 10 > 10; // x = false
    ```

- Less than (`<`)

  - ```cpp
    bool x = 10 < 10; // x = false
    ```

- Greater than or equal to (`>=`)

  - ```cpp
    bool x = 10 >= 10; // x = true
    ```

- Less than or equal to (`<=`)

  - ```cpp
    bool x = 10 <= 10; // x = true
    ```

***Logical*** operators are used to combine two or more relational expressions and return a boolean value (`true` or `false`):

- Logical NOT (`!`)

  - ```cpp
    bool x = !false; // x = true
    ```

- Logical AND (`&&`)

  - ```cpp
    bool x = (5 == 10) && (10 > 5); // x = false
    ```

- Logical OR (`||`)

  - ```cpp
    bool x = (5 == 10) || (10 > 5); // x = true
    ```

The precedence of logical operators is from left to right, and going from highest to lowest precedence:

- `!`
- `&&`
- `||`

Be smart about using logical operators, since it uses short-circuit evaluation, which means that if the first operand of `&&` is `false`, then the second operand will not be evaluated, and if the first operand of `||` is `true`, then the second operand will not be evaluated.

```cpp

bool x = (5 == 10) && (0 == 10); 
/* (0 == 10) will not be evaluated because (5 == 10) is false
 and this is enough to make the whole expression false */

bool y = (5 == 5) || (10 == 10);
/* (10 == 10) will not be evaluated because (5 == 5) is true 
and this is enough to make the whole expression true*/
```

***Compound assignment*** operators are used to combine an arithmetic or relational operator with the assignment operator.

| Operator | Example | Equivalent to |
| :---: | :---: | :---: |
| `+=` | `x += 5;` | `x = x + 5;` |
| `-=` | `x -= 5;` | `x = x - 5;` |
| `*=` | `x *= 5;` | `x = x * 5;` |
| `/=` | `x /= 5;` | `x = x / 5;` |
| `%=` | `x %= 5;` | `x = x % 5;` |
| `&=` | `x &= 5;` | `x = x & 5;` |
| `|=` | `x |= 5;` | `x = x | 5;` |

