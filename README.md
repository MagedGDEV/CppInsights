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
