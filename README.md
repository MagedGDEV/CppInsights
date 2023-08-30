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
