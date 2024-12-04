# Operator Overloading

Operator overloading allows us to define the behavior of operators for user-defined types. This enables us to make our custom classes work with operators in a way that is intuitive, readable, and natural, just like with built-in types (e.g., **`int`**, **`char`**, **`double`**).

## Why Operator Overloading?

Without operator overloading, we would have to use functions or member functions to perform operations, making the code less readable. Operator overloading allows us to write more concise and expressive code. For example, instead of using a function like **`addNumbers(a, b)`**, we could simply write **`a + b`**.

### Example without Operator Overloading

Let's consider the scenario where we have a Number class that contains an integer member value, and we need to perform a series of operations with four Number objects. We'll first show how this could be done without operator overloading, and then we'll show the same scenario with operator overloading.

```cpp
class Number {
public:
    int value;

    Number(int val) : value(val) {}

    /* 
     *  Member Functions implementation
    */
};

int main() {
    
    Number num1(10), num2(5), num3(20), num4(30);
    Number result = num4.add(num3.subtract(num1.multiply(num2)));

    std::cout << "Final result: " << result.value << std::endl; // Output: 0

    return 0;
}
```

As shown in the example, performing simple mathematical operations without operator overloading can be cumbersome and confusing. It requires multiple function calls, which can make the code harder to read and maintain.

### Example with Operator Overloading

Assuming the operators are overloaded, we can enhance code readability by writing mathematical operations in a concise, familiar syntax that closely mirrors standard mathematical notation.

```cpp
class Number {
public:
    int value;

    Number(int val) : value(val) {}

    /* 
     *  Overloading operators implementation
    */
};

int main() {
    
    Number num1(10), num2(5), num3(20), num4(30);
    Number result = num4 + (num3 - (num1 * num2));
;

    std::cout << "Final result: " << result.value << std::endl; // Output: 0

    return 0;
}
```

Now, the operation is more intuitive, and we can use the operators directly. The operator overloading makes the code more natural and readable, similar to how the operators works with primitive types.

>[!WARNING]
> C++ automatically generates a default assignment operator for you, but it may not always do what you expect, especially when your class contains complex members like pointers.

### Important Rules for Operator Overloading

1. **Precedence & Associativity:** You cannot change the precedence or associativity of operators. They will remain the same as predefined in C++.

2. **Arity:** You cannot change the number of operands an operator works with. For example, the binary **`+`** operator must take two operands, and you cannot make it a unary operator.

3. **Primitive Types:** You cannot overload operators for primitive types (e.g., **`int`**, **`char`**, **`float`**). Operator overloading only applies to user-defined types.

4. **Cannot Create New Operators:** You cannot create new operators. You can only overload existing ones.

5. **Special Operator Rules:**

    - **Member functions only:** **`[]`**, **`()`**, **`->`**, and **`=`** must be declared as member functions of the class.
    - **Member or Global functions:** Any other operator can be declared either as a member function or a global function.

### Five Operators That Can't Be Overloaded

1. **`::`** (Scope resolution operator)
2. **`:`** (Member access operator)
3. **`?`** (Ternary conditional operator)
4. **`.*`** (Pointer-to-member operator)
5. **`sizeof`** (Size operator)
These operators are reserved by the language and cannot be overloaded.

> [!IMPORTANT]
> Operator overloading should be used to make code more intuitive and readable. If overloading an operator would make the code more complex or less clear, it's better to use a member function or an external function instead.
