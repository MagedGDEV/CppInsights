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

