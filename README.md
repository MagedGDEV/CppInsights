# Polymorphism

Polymorphism is the ability of a single entity to take on multiple forms. In C++, polymorphism enables objects or functions to behave differently based on the context in which they are used.

There are two types of polymorphism in C++:

- **Static Binding (Compile-Time Polymorphism):** This is achieved through techniques like function overloading and operator overloading. Here, the association between the function call and the code to execute is determined at compile time. Static binding is more efficient because decisions are made before the program runs.

- **Dynamic Binding (Run-Time Polymorphism):** This involves function overriding, where the behavior of a base class function is redefined in a derived class. The decision about which function to call is made at runtime, providing greater flexibility. Dynamic binding allows programmers to define what to do with an object at runtime, enabling more abstract and flexible code design.

By default, C++ uses static binding because it is faster and less resource-intensive. However, dynamic binding gives us the power to design more adaptable and extensible systems, allowing us to focus on higher-level abstractions and interactions rather than low-level details.

## Example of why Polymorphism is needed

Imagine you're building a program to manage different types of employees in a company, such as **Manager, Engineer, and Intern**. Each employee has a **`calculateSalary()`** function, but the calculation differs depending on the employee's role. Polymorphism enables you to handle these objects through a shared interface without writing repetitive code.

```cpp
int main() {
    // Array of pointers to base class
    Employee* employees[] = {
        new Manager("Alice", 5),    
        new Engineer("Bob", 3),    
        new Intern("Charlie", 6)   
    };

    
    for (int i = 0; i < 3; ++i) {
        employees[i]->displayDetails();
        std::cout << "Salary: $" << employees[i]->calculateSalary() << "\n\n";
        delete employees[i];
    }

    return 0;
}
```

### Without polymorphism (Static Binding)

Without polymorphism, the base class implementation of **`calculateSalary()`** would be called for all employees, even if the derived classes provide their own specialized versions. This happens because **static binding** (the default behavior) binds function calls at compile-time, ignoring the actual object type.

### With polymorphism (dynamic binding)

- You can override the **`calculateSalary()`** function in each derived class to provide role-specific behavior.
- A base class pointer or reference can invoke the correct function dynamically at runtime based on the actual object type.

To enable polymorphism in C++, a few key components are required:

1. Inheritance
2. Base Class Pointer or Reference
3. Virtual Functions

## Base Class Pointer or Reference

A **base class pointer** or **reference** can point to or refer to objects of derived classes. This allows us to treat all derived objects uniformly through the base class interface, enabling more flexible and reusable code.

When a base class pointer or reference points to a derived class object:

- It **only knows about the base class part** of the object.
- By default, it uses **static binding** and calls base class functions unless a function is marked as **`virtual`**.
- If a function is **`virtual`**, **dynamic binding** occurs, and the function of the actual object type (derived class) is called.

### Example of Base Class Pointer or Reference

```cpp
// Function that accepts a base class reference
void displayEmployeeDetails(const Employee& emp) {
    emp.displayDetails(); // Calls the appropriate derived class function
}

int main() {
    // Single Base Class Pointer
    Employee* employee = new Manager("Alice", 5);
    std::cout << "Using Base Class Pointer:\n";
    employee->displayDetails(); // Calls Manager's displayDetails
    delete employee;

    // Vector of Base Class Pointers
    std::vector<Employee*> employeesVector;
    employeesVector.push_back(new Manager("Bob", 3));
    employeesVector.push_back(new Intern("Charlie", 6));

    std::cout << "\nUsing Vector of Base Class Pointers:\n";
    for (Employee* emp : employeesVector) {
        emp->displayDetails(); // Calls the appropriate derived class function
        delete emp;
    }

    // Base Class Reference in a Function
    Manager manager("Daisy", 7);
    Intern intern("Eve", 4);

    std::cout << "\nUsing Base Class Reference in a Function:\n";
    displayEmployeeDetails(manager); // Calls Manager's displayDetails
    displayEmployeeDetails(intern);  // Calls Intern's displayDetails

    return 0;
}
```

#### Output of Base Class Pointer or Reference

```txt
Using Base Class Pointer:
Manager: Employee: Alice
Team Size: 5

Using Vector of Base Class Pointers:
Manager: Employee: Bob
Team Size: 3
Intern: Employee: Charlie
Internship Duration: 6 months

Using Base Class Reference in a Function:
Manager: Employee: Daisy
Team Size: 7
Intern: Employee: Eve
Internship Duration: 4 months
```

#### Explanation of Base Class Pointer or Reference

1. **Using a Single Base Class Pointer:**
    - The base class pointer **`employee`** is assigned to a **`Manager`** object.
    - Polymorphism ensures that **`Manager::displayDetails()`** is called, demonstrating the ability of the base class pointer to interact with derived class objects.
2. **Using a Vector of Base Class Pointers:**
    - The **`std::vector`** stores pointers to both **`Manager`** and **`Intern`** objects, but the type of the pointers is **`Employee*`**.
    - The correct **`displayDetails()`** function is called for each object in the vector because of polymorphism. This setup is practical for managing a collection of objects of various derived types through a common interface.
3. **Using Base Class Reference in a Function:**
    - The function **`displayEmployeeDetails()`** accepts a base class reference (**`Employee&`**), allowing derived objects to be passed.
    - The overridden **`displayDetails()`** function of each derived class is called, showcasing polymorphism in action when passing derived objects as references.

## Virtual Functions

In C++, virtual functions enable dynamic (or runtime) polymorphism. They allow a derived class to override a function in the base class such that the function that gets called is determined at runtime, not at compile-time. Without virtual functions, the compiler uses static binding (compile-time decision) for function calls, which means the base class version will always be called, even if the object is of the derived class type.

Virtual functions achieve this through a mechanism called the vtable (virtual table). When a class contains virtual functions, a vtable is created for it. The vtable is essentially a table of function pointers, pointing to the appropriate function implementation based on the actual object type.

### Syntax of Virtual Functions

```cpp
class Base {
public:
    virtual void func() { // Virtual function in base class
        // Implementation
    }
};
```

1. The **`virtual`** keyword is used in the base class to declare a function as virtual.
2. The **`virtual`** keyword is **not required** in the **derived class**, but using it improves code readability.
3. Function parameters and return types in the derived class must match the base class to override it. otherwise, it will be treated as function overloading, leading to static binding.

### Example of Virtual Functions

```cpp
class Shape {
public:
    // Virtual function
    virtual void draw() const {
        cout << "Drawing a generic shape" << endl;
    }

    // Non-virtual function
    void info() const {
        cout << "This is a Shape" << endl;
    }
};

class Circle : public Shape {
public:
    virtual void draw() const { 
        cout << "Drawing a Circle" << endl;
    }
};

class Rectangle : public Shape {
public:
    virtual void draw() const { 
        cout << "Drawing a Rectangle" << endl;
    }
};


int main() {
    Shape* shapePtr;

    Circle circle;
    Rectangle rectangle;

    // Pointer to a Circle
    shapePtr = &circle;
    cout << "Circle object:" << endl;
    shapePtr->draw();  // Calls Circle's draw function (dynamic binding)
    shapePtr->info();  // Calls Shape's info function (static binding)

    // Pointer to a Rectangle
    shapePtr = &rectangle;
    cout << "\nRectangle object:" << endl;
    shapePtr->draw();  // Calls Rectangle's draw function (dynamic binding)
    shapePtr->info();  // Calls Shape's info function (static binding)

    return 0;
}
```

#### Output of Virtual Functions

```txt
Circle object:
Drawing a Circle
This is a Shape

Rectangle object:
Drawing a Rectangle
This is a Shape
```

#### Explanation of Virtual Functions

1. **Virtual Function (`draw`):**
    - Declared as **`virtual`** in the **`Shape`** base class.
    - Overridden in the **`Circle`** and **`Rectangle`** classes.
    - At runtime, the actual type of the object (**`Circle`** or **`Rectangle`**) determines which version of the **`draw`** function is executed.
2. **Non-Virtual Function (`info`):**
    - Not declared as **`virtual`**.
    - Always calls the **`Shape`** class's **`info`** function, regardless of the object type, due to static binding.
3. **Polymorphism:**
    - The **`Shape`** pointer **`shapePtr`** can point to objects of derived classes (**`Circle`** or **`Rectangle`**).
    - The overridden **`draw`** function is called based on the actual type of the object being pointed to.

## Virtual Destructor

A **virtual destructor** is essential in achieving fully functional polymorphism in C++. When using polymorphism, if an object of a derived class is deleted through a base class pointer, the base class destructor is called. Without a virtual destructor, the destructor of the derived class will **not** be invoked, potentially leading to resource leaks or undefined behavior.

### Why do we need a Virtual Destructor?

If a base class destructor is not marked as virtual, the **destructor of the derived class will not be called** when a derived class object is deleted through a base class pointer. This happens because the destructor is **statically bound** (resolved at compile time) by default.

However, with a virtual destructor, the destructor becomes **dynamically bound** (resolved at runtime), ensuring both the derived and base class destructors are called in the correct order.

> [!CAUTION]
> If a class has even a **singlevirtual function**, the destructor should always be **virtual**.

### Example of Virtual Destructor

```cpp
class Base {
public:
    Base() {
        cout << "Base constructor called" << endl;
    }
    virtual ~Base() {  
        cout << "Base destructor called" << endl;
    }
};

class Derived : public Base {
public:
    Derived() {
        cout << "Derived constructor called" << endl;
    }
    ~Derived() {
        cout << "Derived destructor called" << endl;
    }
};

int main() {
    Base* ptr = new Derived();  // Base class pointer to derived class object
    delete ptr;  // Both Base and Derived destructors will be called
    return 0;
}
```

#### Output of Virtual Destructor

```txt
Base constructor called
Derived constructor called
Derived destructor called
Base destructor called
```

#### Explanation of Virtual Destructor

- The destructors are dynamically bound at runtime, ensuring both the derived and base destructors are called in the correct order.
- The derived class destructor executes first, followed by the base class destructor.

## Override keyword

The **`override`** keyword in C++11 is used to explicitly declare that a function in a derived class is intended to override a virtual function in the base class. This keyword helps prevent errors due to mismatched function signatures or unintended function hiding.

### Why use the `override` keyword?

1. **Prevents Errors:**
    - If the function in the derived class does not match the signature of the base class function, the compiler will generate an error.
    - This helps catch mistakes where the function in the derived class is not actually overriding the base class function.
2. **Improves Code Readability:**
    - The **`override`** keyword makes it clear that a function is intended to override a virtual function from the base class.

### Example of the override keyword

```cpp

class Base {

public:
    virtual void display() const {
        cout << "Base Display" << endl;
    }
};

class Derived : public Base {

public:
    void display() const override {
        cout << "Derived Display" << endl;
    }
};

int main() {
    Base* ptr = new Derived();
    ptr->display();  // Calls Derived's display function
    delete ptr;
    return 0;
}
```

#### Output of the override keyword

```txt
Derived Display
```

#### Explanation of the override keyword

- The **`override`** keyword in the **`Derived`** class explicitly indicates that the **`display`** function is overriding the **`display`** function in the **`Base`** class.
- If the function in the **`Derived`** class does not match the signature of the **`Base`** class function, the compiler will generate an error.

## Final keyword

The **`final`** keyword in C++11 is used to prevent further overriding of a virtual function in derived classes or to prevent inheritance of a class. When a function is marked as **`final`**, it cannot be overridden in any derived class. Similarly, when a class is marked as **`final`**, it cannot be inherited by other classes.

### Why use the final keyword?

1. **Prevents Further Overriding:**
    - The **`final`** keyword ensures that a virtual function cannot be overridden in any further derived classes.
    - This can be useful when you want to enforce a specific implementation of a function.
2. **Prevents Inheritance:**
    - When a class is marked as **`final`**, it cannot be used as a base class for other classes.
    - This can be useful when you want to prevent further specialization of a class.

### Final keyword Enable Compiler Optimization

1. **No Need for Virtual Table Lookups:**
    - If a virtual function is marked as **`final`**, the compiler knows that this function cannot be overridden in any derived class.
    - This eliminates the need for the compiler to use the virtual table (vtable) to resolve the function call dynamically at runtime. Instead, the compiler can resolve the call at compile-time (static binding), which is faster.
2. **Inline Expansion:**
    - With the knowledge that a **`final`** function or class cannot change further, the compiler can safely inline the function for better performance, avoiding the overhead of a function call.
3. **Simplified Memory Layout:**
    - When a class is marked as **final**, the compiler knows that it cannot be extended. This allows the compiler to optimize the memory layout of the class and its derived objects, reducing unnecessary overhead.
