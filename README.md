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

## Overloading the Assignment Operator (copy)

In C++, the **copy assignment operator** is called when you assign a value or copy an object from one to another, such as with the statement **`s2 = s1`**. On the other hand, the **copy constructor** is called when an object is initialized with another object, for example, **`MyClass obj2 = obj1;`**. The key difference is that the copy assignment operator is invoked during assignment, while the copy constructor is invoked during initialization.

By default, C++ provides a **shallow copy** for the copy assignment operator, which works fine in many simple cases. However, if your class contains pointers or other dynamically allocated resources, this shallow copy will not be sufficient, leading to issues like double freeing memory or shallow copying of resources. In such cases, you need to provide a custom **deep copy assignment operator**.

### Syntax of the Copy Assignment Operator

The general syntax for defining a copy assignment operator is as follows:

```cpp
TYPE& TYPE::operator=(const TYPE& rhs) {
    // Implementation
}
```

#### Explanation of copy assignment operator syntax

1. **`TYPE&`**:

    - The operator returns a reference to the current object (**`*this`**). This is essential for supporting chained assignments, such as **`a = b = c;`**.
    - If you return **`TYPE`** (a value) instead of **`TYPE&`**, the operator would create **an unnecessary copy** of the object. This can degrade performance and lead to unexpected behavior.

2. **`TYPE::operator=`**:

    - This declares the function as the **`operator=`** for the class **`TYPE`**.

3. **`const TYPE& rhs`**:

    - This is the parameter that represents the right-hand side of the assignment (**`rhs`**).
    - The parameter is passed by **constant reference** to:
        - Avoid unnecessary copying (improves performance).
        - Ensure the source object (**`rhs`**) is not modified during the assignment.

#### Behind the Scenes

When you write:

```cpp
s2 = s1;
```

The compiler translates this into:

```cpp
s2.operator=(s1);
```

This calls the **`operator=`** function on **`s2`**, passing **`s1`** as the argument.

#### Why **`TYPE&`** Is Used Instead of **`TYPE`**

1. **Avoiding Unnecessary Copies:**

    - Returning **`TYPE`** (by value) creates a copy of the object after every  assignment, which is inefficient and unnecessary.
    - Returning **`TYPE&`** avoids the copy, as it directly returns a reference to the current object.

2. Chained Assignments:

    - When you write **`a = b = c;`**, it is interpreted as:

    ```cpp
    a = (b = c);
    ```

    - This requires **`b = c`** to return a reference to **`b`** so that **`a = b`** can be evaluated.
    - If the operator returned **`TYPE`** instead of **`TYPE&`**, the temporary object would not refer to **`b`**, and the code would fail to chain properly, but it will work.
3. **`(a = b) = c` Wouldn't Work:**

    - If the operator returns **`TYPE`** instead of **`TYPE&`**, the result of **`a = b`** would be a temporary object. Assigning **`c`** to this temporary object **`((a = b) = c)`** would fail because you cannot modify a temporary value.

### Copy Assignment Operator Example

Here is an example of implementing a deep copy assignment operator in a class **`MyClass`** with a pointer.

```cpp
class MyClass {
public:
    int* data;


    MyClass(int value) : data(new int(value)) {}
    ~MyClass() { delete data; }

    // Custom Copy Assignment Operator (Deep Copy)
    MyClass& operator=(const MyClass& other) {
        if (this != &other) {  // Prevent self-assignment
            delete data;  // Free the existing memory
            data = new int(*other.data);  // Allocate new memory and copy the value
        }
        return *this;  // Return the current object for chaining
    }

    void print() const {
        std::cout << *data << std::endl;
    }
};

int main() {
    MyClass obj1(10);  
    MyClass obj2(20); 

    obj2 = obj1;  // Assign obj1 to obj2 (calls the copy assignment operator)

    std::cout << "obj1 data: ";
    obj1.print();  // 10

    std::cout << "obj2 data: ";
    obj2.print();  // 10 

    return 0;
}
```

#### Explanation of Copy Assignment Operator

1. **Constructor:** Dynamically allocates memory for the integer and initializes it with a value.
2. **Destructor:** Releases the allocated memory when the object is destroyed.
3. **Copy Assignment Operator:**

    - Prevents self-assignment using if (**`this != &other`**).
    - Releases the currently held resource using **`delete`**.
    - Allocates new memory and performs a deep copy of the data.
    - Returns **`*this`** to support chained assignments.

4. Printing Values: Demonstrates that **`obj2`** is a separate deep copy of **`obj1`**.

#### Output of Copy Assignment Operator

```txt
obj1 data: 10
obj2 data: 10
```

After the assignment **`obj2 = obj1;`**, **`obj2`** contains a separate copy of **`obj1`**'s data, ensuring proper ownership and avoiding issues like double deletion.

## Overloading the Assignment Operator (move)

In C++, the **move assignment operator** is called when you assign an **r-value** (temporary object) to an existing object. For example, this happens in the statement **`s1 = "String";`** where the right-hand side is an r-value. On the other hand, the **move constructor** is called when you create a new object from an r-value, as in **`std::string s1 = "String";`**.

### Syntax of the Move Assignment Operator

```cpp
TYPE& TYPE::operator=(TYPE&& rhs) noexcept {
    // Implementation
}
```

#### Explanation of Move Assignment Operator Syntax

1. **`TYPE&`:**

    - The operator returns a reference to the current object (**`*this`**) to allow **chained assignments**, such as **`a = b = c;`**.

2. **`TYPE&& rhs`:**

    - The parameter **`rhs`** is an r-value reference.
    - The double ampersand **`&&`** indicates that the function accepts **r-values** (temporary objects) as input.
3. **`noexcept`:**

    - Declaring the move assignment operator **`noexcept`** signals that the operation will not throw exceptions, allowing optimizations like **`std::vector`** to move elements instead of copying them.

### Move Assignment Operator Example

Below is an example of a class **`MyClass`** that implements a move assignment operator to manage a dynamically allocated resource

```cpp
class MyClass {
private:
    int* data;

public:
    MyClass(int value) : data(new int(value)) {}

    MyClass& operator=(MyClass&& rhs) noexcept {
        if (this != &rhs) {  // Prevent self-assignment
            delete data;      // Release current resource
            data = rhs.data;  // Steal resource
            rhs.data = nullptr;  // Nullify source
        }
        return *this;  // Return current object
    }

    ~MyClass() {
        delete data;
    }

    void print() const {
        if (data)
            std::cout << "Data: " << *data << std::endl;
        else
            std::cout << "Data is null\n";
    }
};

int main() {
    MyClass obj1(20);  

    obj1.print()      // Data is 20
    obj1 = obj(50)   // Move Assignment Operator
    obj1.print();   // Data is 50

    return 0;
}
```

#### Explanation of Move Assignment Operator

- **`Move Assignment Operator (operator=(MyClass&& rhs) noexcept)`:**
  - **Steps:**
    - Prevent self-assignment
    - Release current resource
    - **Steal resource:** Transfers ownership of the memory from the source object **`rhs`** to the current object **`data = rhs.data;`**.
    - **Nullify the source object:** Ensures the source object is left in a valid state by setting **`rhs.data = nullptr;`**.
    - **Return **`*this`**:** to support chaining assignments.

#### Output of Move Assignment Operator

```txt
Data: 20
Data: 50
```

**`MyClass obj1(20);`** creates **`obj1`** with **`20`**,**`obj1 = MyClass(50);`** moves the resource **`50`** to **`obj1`**, nullifies the temporary object's data.

## Overloading operators as Member Functions

We can define custom behaviors for operators like **`+`**, **`-`**, **`==`**, and more when they are applied to objects of a class. Just as we overloaded the assignment operators (copy and move), we can overload other operators to make them behave in a way that fits the needs of our class.

In this section, we'll explore how to overload the following operators:

- Unary **`-`** to transform a string into lowercase.
- Binary **`+`** to concatenate two strings.
- Binary **`==`** to compare two values of a class.

Each of these examples will help us understand how operator overloading can make our code more intuitive and easier to read, while also demonstrating the difference between unary and binary operators.

### 1. Overloading the Unary `-` Operator (Convert Text to Lowercase)

The **unary** **`-`** operator typically operates on a single operand. In this example, we will overload the **`-`** operator to turn the characters in a string to lowercase.

```cpp
TYPE operator-() {
    // Implementation
}
```

**Example:**

```cpp
class MyString {
private:
    std::string str;

public:
    MyString(const std::string& s) : str(s) {}

    // Overloading the unary - operator to convert string to lowercase
    MyString operator-() {
        for (char& c : str) {
            c = std::tolower(c);  // Convert each character to lowercase
        }
        return *this;
    }

    void print() const {
        std::cout << str << std::endl;
    }
};

int main() {
    MyString text("Hello World");
    -text;  // Using the overloaded - operator to convert to lowercase
    text.print();  // Output: hello world
    return 0;
}
```

**Explanation:**

- **`operator-()`:** This function defines the behavior of the unary **`-`** operator. It iterates over each character in the string and converts it to lowercase using **`std::tolower`**.
- **Usage:** The expression **`-text`** invokes the overloaded **`operator-()`** to modify **`text`** into lowercase.

### 2. Overloading the Binary `+` Operator (Concatenate Two Strings)

The binary **`+`** operator operates on two operands. In this example, we will overload the **`+`** operator to concatenate two strings together.

```cpp
TYPE operator+(const TYPE& rhs) {
    // Implementation
}
```

**Example:**

```cpp
class MyString {
private:
    std::string str;

public:
    MyString(const std::string& s) : str(s) {}

    // Overloading the binary + operator to concatenate two strings
    MyString operator+(const MyString& rhs) {
        return MyString(str + rhs.str);  // Concatenate strings and return new MyString object
    }

    void print() const {
        std::cout << str << std::endl;
    }
};

int main() {
    MyString text1("Hello ");
    MyString text2("World");
    MyString result = text1 + text2;  // Using the overloaded + operator to concatenate
    result.print();  // Output: Hello World
    return 0;
}
```

**Explanation:**

- **`operator+(const MyString& rhs)`:** This function defines the behavior of the binary **`+`** operator. It concatenates the **`str`** of the current object with the **`str`** of the object passed as the argument **`rhs`**.
- **Usage:** The expression **`text1 + text2`** invokes the overloaded **operator+()** and returns a new object containing the concatenated strings.

### 3. Overloading the Binary `==` Operator (Compare Two Values)

The binary **`==`** operator is used to compare two objects of a class. In this example, we will overload the **`==`** operator to compare two values in a class and check for equality.

```cpp
bool operator==(const TYPE& rhs) const {
    // Implementation
}
```

**Example:**

```cpp
class MyClass {
private:
    int value;

public:
    MyClass(int v) : value(v) {}

    // Overloading the binary == operator to compare values
    bool operator==(const MyClass& rhs) const {
        return value == rhs.value;  // Compare the value of current object and rhs
    }
};

int main() {
    MyClass obj1(10);
    MyClass obj2(10);
    MyClass obj3(20);

    std::cout << (obj1 == obj2) << std::endl;  // Output: 1 (true)
    std::cout << (obj1 == obj3) << std::endl;  // Output: 0 (false)
    return 0;
}
```

**Explanation:**

- **`operator==(const MyClass& rhs)`:** This function defines the behavior of the binary **`==`** operator. It compares the **`value`** of the current object with the **`value`** of the object passed as the argument **`rhs`**.
- **Usage:** The expression **`obj1 == obj2`** invokes the overloaded **`operator==()`** and returns **`true`** if the values are equal, otherwise **false**.

### Conclusion

Operator overloading can significantly improve the readability and intuitiveness of your code by allowing you to use operators like **`-`**, **`+`**, and **`==`** with custom behavior specific to your class. Each of these examples demonstrates how to make C++ operators work for complex objects in a way that fits the problem you're solving.

## Overloading operators as Global Functions

In addition to overloading operators as member functions, we can define them as **global functions**. These global operator functions work similarly to member functions but have a broader scope. To access private or protected members of a class, you can either use **getter methods** or declare the operator function as a **friend** of the class.

In some cases, overloading operators as global functions is more suitable than using member functions. This approach provides greater flexibility, allowing operations where the left-hand operand is not of the class type, such as combining custom objects with standard types like **`std::string`**. It also ensures symmetry for commutative operators like + and ==, enabling expressions like **`obj + str`** and **`str + obj`** to work seamlessly.

> [!IMPORTANT]
> You cannot define both a member and a global operator overload for the same operator, as it would result in ambiguity for the compiler.

### Example of Overloading operators as Global Functions

Below, we will overload the **`+`** operator as a global function to concatenate two **`MyString`** objects and allow concatenation of an object with a string directly.

```cpp
class MyString {
    friend MyString operator+(const MyString &lhs, const MyString &rhs);
private:
    char *str;   

public:
    MyString() : str{nullptr} {
        str = new char[1];
        *str = '\0';
    }

    MyString(const char *s) : str {nullptr} {
        if (s == nullptr) {
            str = new char[1];
            *str = '\0';
        } else {
            str = new char[std::strlen(s) + 1];
            std::strcpy(str, s);
        }
    }

    void print() {
        std::cout << str << std::endl;
    }

    ~MyString() {
        delete[] str;
    }
};

MyString operator+(const MyString &lhs, const MyString &rhs) {
    char *buff = new char[std::strlen(lhs.str) + std::strlen(rhs.str) + 1];
    std::strcpy(buff, lhs.str);
    std::strcat(buff, rhs.str);
    MyString temp {buff};
    delete[] buff;
    return temp;
}

int main() {
    MyString obj1("Hello ");
    MyString obj2("World");
    MyString result1 = obj1 + obj2;  // Concatenate two objects
    result1.print();  // Output: Hello World

    MyString result2 = obj1 + "C++";  // Concatenate object and string
    result2.print();  // Output: Hello C++

    MyString result3 = "Operator overloading " + obj2;
    result3.print();  // Output: Operator overloading World

    return 0;
}
```

### Output of Overloading operators as Global Functions

```txt
Hello World
Hello C++
Operator overloading World
```

#### Explanation of Overloading operators as Global Functions

- In this example, we overload the **`+`** operator as a **global function** to allow concatenation between two **`MyString`** objects or between a **`MyString`** object and a **`const char*`** string. This approach gives us the flexibility to use the **`+`** operator both ways: we can concatenate **`"some string" + MyString`** as well as **`MyString + "some string"`**.

- If we had used a **member function** to overload the **`+`** operator, we could only perform concatenation with another **`MyString`** object, not a **`const char*`** string. This is because member functions have access to the left operand (the current object) but not the right operand in a way that would allow us to handle other types (like **`const char*`**) without additional complexity.

- By defining the operator as a **global function**, we can seamlessly handle both directions of concatenation and support different types, making the code more flexible and user-friendly.

## Overloading the Stream Insertion and Extraction Operators

In C++, the stream insertion **`<<`** and extraction **`>>`** operators are used to input and output data, typically to and from streams like **`std::cin`** and **`std::cout`**. Overloading these operators allows you to define how objects of your class are inputted and outputted.

These operators **must be overloaded as global functions** because they need access to both the left-hand operand (the stream object, like **`std::cout`**) and the right-hand operand (the object you want to insert or extract). Since these operators are non-member functions, defining them as global functions allows them to work with objects of your class while adhering to the syntax required by stream operations.

### Syntax of the Stream Insertion Operator (<<)

```cpp
std::ostream& operator<<(std::ostream& os, const TYPE& obj) {
    // Implementation
}
```

#### Explanation of Stream Insertion Operator Syntax

- **`std::ostream&`:**
  - The function returns a reference to the output stream (**`os`**), allowing multiple outputs to be chained together (e.g., **`std::cout << obj1 << obj2;`**).
- **`std::ostream& os`:**
  - The first parameter is a reference to the output stream (**`os`**), usually **`std::cout`**, which is used to output data.
- **`const TYPE& obj`:**
  - The second parameter is a constant reference to the object being output. This ensures the object is not modified and avoids unnecessary copies.

### Syntax of the Stream Extraction Operator (>>)

```cpp
std::istream& operator>>(std::istream& is, TYPE& obj) {
    // Implementation
}
```

#### Explanation of Stream Extraction Operator Syntax

- **`std::istream&`:**
  - The function returns a reference to the input stream (**`is`**), allowing multiple inputs to be chained together (e.g., **`std::cin >> obj1 >> obj2;`**).
- **`std::istream& is`:**
  - The first parameter is a reference to the input stream (**`is`**), usually **`std::cin`**, which is used to receive data from the user.
- **`TYPE& obj`:**
  - The second parameter is a reference to the object being modified. This allows the extracted value to be stored in the object.

### Example of Overloading the Stream Insertion and Extraction Operators

Consider a simple **`MyNumber`** class that holds an integer. We will overload the **`<<`** and **`>>`** operators to allow input and output of **`MyNumber`** objects.

```cpp
class MyNumber {

    friend std::ostream& operator<<(std::ostream& os, const MyNumber& obj);
    friend std::istream& operator>>(std::istream& is, MyNumber& obj);

private:
    int* num;

public:
    MyNumber(int n = 0) : num(new int(n)) {}

    MyNumber(MyNumber&& other) noexcept : num(std::move(other.num)) {
        other.num = nullptr;
    }

    MyNumber& operator=(MyNumber&& other) noexcept {
        if (this != &other) {
            delete num;       
            num = other.num;  
            other.num = nullptr;
        }
        return *this;
    }

    ~MyNumber() {
        delete num;
    }
};

// Stream Insertion Operator (<<) for output
std::ostream& operator<<(std::ostream& os, const MyNumber& obj) {
    os << *(obj.num);  // Dereference the pointer to get the value
    return os;
}

// Stream Extraction Operator (>>) for input
std::istream& operator>>(std::istream& is, MyNumber& obj) {
    is >> *(obj.num);  // Read value into the dynamically allocated memory
    return is;
}

int main() {
    MyNumber number1(10);  
    MyNumber number2(0);   

    std::cout << "Original number1: " << number1 << std::endl;  // Output: 10

    std::cout << "Enter a new value for number2: ";
    std::cin >> number2;  // Input a new value
    std::cout << "Updated number2: " << number2 << std::endl;  // Output: user input

    MyNumber number3 = std::move(number1);  // Move number1 to number3
    std::cout << "Moved number3: " << number3 << std::endl;  // Output: 10 
    return 0;
}
```

### Output of Overloading the Stream Insertion and Extraction Operators

```txt
Original number1: 10
Enter a new value for number2: 25
Updated number2: 25
Moved number3: 10
```

#### Explanation of Overloading the Stream Insertion and Extraction Operators

- **Stream Insertion (`<<`) Operator:**
  - **`The operator<<`** outputs the integer stored in the dynamically allocated memory (**`num`**) of the **`MyNumber`** object.
  - This operator is overloaded as a friend function, allowing it to access the private **`num`** pointer.
- **Stream Extraction (`>>`) Operator:**
  - The **`operator>>`** reads an integer from the user input and stores it in the **`num`** pointer.
  - This operator is also overloaded as a friend function.
