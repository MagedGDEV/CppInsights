# Inheritance

Inheritance is a powerful feature of object-oriented programming that allows us to create a new class based on an existing class. With inheritance, we can reuse the code of the base (parent) class, modify it, and add new features without altering the original class. This allows us to build upon existing functionality, creating more specialized versions of a class.

## Key concepts in Inheritance

### 1. "Is-a" Relationship

- Inheritance establishes an "is-a" relationship. For example, a **Student** "is a" **Person**, and a **Teacher** "is a" **Person**. This means that the derived class (like **Student**) can be treated as an instance of the base class (like **Person**).
- This concept is what allows derived classes to be used interchangeably with their base classes in certain situations.

### 2. Generalization

- Generalization is the process of defining a base class that captures common characteristics shared by multiple derived classes. The **Person** class is a generalization of **Student**, **Teacher**, or any other individual because it includes basic properties like name and age that all people share.
- By creating a **Person** class, we avoid repeating code for common attributes in **Student** or **Teacher**.

### 3. Specialization

- Specialization refers to creating specific versions of a class that add more features. For example, the **Teacher** class is a specialized version of the **Person** class because it adds attributes specific to teachers, like the department they belong to.
- Specialization allows us to focus on the unique aspects of a class, such as adding a course list to the **Student** class, while still inheriting general features from the base class.

### Important Terminologies

- **Base class (Parent class):** The class from which properties and behaviors are inherited.
- **Derived class (Child class):** The class that inherits from the base class and may extend or override its functionality.

#### Examples of Inheritance

1. Student, Teacher and Staff inherits from a general class **Person**.
2. Player and Enemy inherits from a general class **Character**.
3. Car, Truck and Motorcycle from a general class **Vehicle**.
4. Circle, Rectangle and Triangle from a general clas **Shape**.

### Why Inheritance is Useful

- **Code Reusability:** Instead of writing the same code in multiple classes, inheritance lets us define shared behavior once in the base class and then inherit it in derived classes.
- **Maintainability:** If we need to change or fix a feature that is shared across many classes, we only need to update the base class, and all derived classes will automatically benefit from the change.
- **Flexibility:** Derived classes can override or extend the functionality of the base class. For example, if a derived class needs to behave differently, it can modify inherited methods, or add entirely new ones, without affecting the base class.

## Inheritance vs Composition

Both **inheritance** and **composition** allow us to reuse existing classes, but they represent different types of relationships between objects. Here's a breakdown of their differences and when to use each:

### When to use Inheritance

- Use inheritance when a **derived** class is a **specialization** of a **base** class.
- If the derived class is a type of the base class, then inheritance is appropriate. The derived class should be able to inherit and extend the functionality of the base class

### Composition

- **"has-a" relationship:** Composition represents a **"has-a"** relationship, where one class contains an instance of another class as a member. The class **has** another class as part of its state or behavior.

#### When to use composition

- Use composition when one class **contains** an instance of another class, but the contained class **does not** need to be a specialized type of the containing class.
- Composition is used to model relationships where objects are composed of other objects.

### Example of Inheritance and Composition

A **Person** has an **Account** this is **composition**. The **Account** belongs to the **Person** but isn't a **specialized** version of it.

Now, an **Employee** and a **Manager** are both types of **Person** this is **inheritance**. They both inherit the **Account** from **Person** but also have their own specific features.

So, **Employee** and **Manager** both ***have*** an **Account** (composition) and ***are*** a **Person** (inheritance).

## Deriving class from existing class

In C++, you can derive a class from an existing class (called the base class) to create a new class (called the derived class). This allows you to reuse the code from the base class while adding new features or modifying existing ones.

Syntax for Deriving a Class:

```cpp
class DerivedClass : accessSpecifier BaseClass {
    // Derived class members and functions
};
```

### Explanation of Access Specifiers in Inheritance

In inheritance, access specifiers play an important role in determining how members of the base class are accessible in the derived class:

1. **Public Inheritance `public`**:
    - In **public inheritance**, the public and protected members of the base class remain accessible in the derived class.
    - This represents an "is-a" relationship. For example, a **Car** "is a" **Vehicle**.
2. **Private Inheritance `private`:**
    - In **private inheritance**, the public and protected members of the base class become private members of the derived class.
    - This is generally used when the derived class wants to use the base class functionality internally but does not want to expose it to the outside world.
    - This represents a **has-a** relationship, similar to composition. For example, a **Smartphone** "has a" **Battery**.
3. **Protected Inherithance `proctected`:** explain later in this branch.

#### Example of Public Inheritance

```cpp
class Vehicle {
public:
    void startEngine() {
        // Start the engine
    }
};

class Car : public Vehicle {
public:
    void drive() {
        // Drive the car
    }
};
```

##### Explanation of Public Inheritance

In this example, **`Car`** publicly inherits from **`Vehicle`**. The **`Car`** class can access public members of the **`Vehicle`** class.

#### Example of Private Inheritance

```cpp
class Engine {
public:
    void start() {
        // Start engine
    }
};

class Car : private Engine {
public:
    void drive() {
        start();  // Accesses Engine's start function
    }
};
```

##### Explanation of Private Inheritance

In this case, **`Car`** privately inherits from **`Engine`**. The **`Car`** class can use the **`start()`** function from **`Engine`**, but it is not accessible outside of **`Car`** because the inheritance is private.

## Protected Members and Class Access

### Protected Member

A protected member in a class is similar to a private member but with an important difference:

- **Accessible from Base Class**
- **Accessible from Derived Class:**
- **Not Accessible by Objects:** Protected members cannot be accessed directly by objects of the class or derived class.

### Protected Inheritance

- When a class is derived using **protected inheritance**, the public and protected members of the base class become **protected** in the derived class.
- This means they are not accessible directly by objects, but they are still accessible in further derived classes.

### Example of Protected Members and Protected Inheritance

```cpp
class Person {
protected:
    string name;  // Protected member
    int age;      // Protected member

public:
    Person(string n, int a) : name(n), age(a) {}

    void displayInfo() const {
        cout << "Name: " << name << ", Age: " << age << endl;
    }
};

class Student : protected Person {  // Protected inheritance
private:
    string studentID;

public:
    Student(string n, int a, string id) : Person(n, a), studentID(id) {}

    void displayStudent() const {
        // Accessing protected members from the base class
        cout << "Student Name: " << name << ", Age: " << age << ", ID: " << studentID << endl;
    }
};

int main() {

    Student s("Alice", 20, "S12345");

    s.displayStudent();  // Accessing derived class member function

    // cout << s.name;  // Error: Protected members are not accessible directly by objects.

    return 0;
}
```

### Output of Protected Members and Protected Inheritance

```txt
Student Name: Alice, Age: 20, ID: S12345
```

#### Explanation

1. **Protected Members in the Base Class:**
    - **`name`** and **`age`** are declared as **protected** in the Person class.
    - This means they are accessible in the **`Person`** class and in classes derived from **`Person`**.
2. **Access in Derived Class:**
    - In the **`Student`** class, which inherits **`Person`** with **protected inheritance**, **`name`** and **`age`** are accessible.
    - However, they are treated as **protected** in **`Student`**, so they are not directly accessible by objects of **`Student`**.
3. **Access by Objects:**
    - **`s.displayStudent()`** works because the function has access to the protected members of the base class.
    - Direct access to **`name`** or **`age`** through the object **`s`** is not allowed.
4. **Protected Inheritance:**
    - Protected inheritance ensures that all public and protected members of the base class are inherited as **protected** in the derived class, restricting their access to further derived classes or member functions of the derived class.

## Access Control Table  

| **Access Level** | **Private Members** | **Protected Members** | **Public Members** |
|-|-|-|-|
| **Accessible in Base Class**   | ✅ Yes | ✅ Yes | ✅ Yes |
| **Accessible in Derived Class** | ❌ No | ✅ Yes | ✅ Yes |
| **Accessible by Objects**      | ❌ No | ❌ No | ✅ Yes |
| **Inheritance with `public`** | Not inherited (remains private in base class, inaccessible in derived class) | Becomes **protected** in derived class | Remains **public** in derived class |
| **Inheritance with `protected`** | Not inherited (remains private in base class, inaccessible in derived class) | Remains **protected** in derived class | Becomes **protected** in derived class |
| **Inheritance with `private`** | Not inherited (remains private in base class, inaccessible in derived class) | Becomes **private** in derived class | Becomes **private** in derived class |
| **Use Case** | - Used to strictly restrict access, ensuring only the base class can use it. | - Used to allow derived classes to access members while still hiding them from objects. | - Used to make members widely accessible to other classes or functions. |

## Constructors & Destructors

In inheritance, the order of construction and destruction is crucial. When a derived class is instantiated, the base class constructor is executed first.

During destruction, the process is reversed: the derived class destructor is executed first, followed by the base class destructor. Each class is responsible for managing its own resources.

>[!NOTE]
> Derived classes do not inherit constructors, destructors, overloaded assignment operators, or friends from the base class.

### Example of Constructors & Destructors

This example illustrates the order of construction and destruction.

```cpp
class Base {
public:
    Base() {
        cout << "Base constructor called" << endl;
    }

    ~Base() {
        cout << "Base destructor called" << endl;
    }

    Base& operator=(const Base& rhs) {
        cout << "Base assignment operator called" << endl;
        return *this;
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
    Derived d1;
    Derived d2;

    return 0;
}
```

### Output of Constructors & Destructors

```txt
Base constructor called
Derived constructor called
Base constructor called
Derived constructor called
Derived destructor called
Base destructor called
Derived destructor called
Base destructor called
```

#### Explanation of Constructors & Destructors

1. **Order of Construction:**
    - The **`Base`** constructor is executed first for each **`Derived`** object.
    - After the base portion is initialized, the **`Derived`** constructor is called.
2. **Order of Destruction:**
    - When the program ends, the **`Derived`** destructor is executed first for each object.
    - The **`Base`** destructor is then executed to clean up resources in the base class.
3. **Assignment Operator:**
    - The derived class does not have an assignment operator explicitly defined.
    - Therefore, the base class's assignment operator is invoked when **`d2 = d1;`** is   executed.
    - If the derived class had additional resources, it would need its own assignment operator to manage them.

## Passing Arguments to Base Class Constructors

When a derived class is instantiated, you can call any constructor from the base class to initialize its members. This allows you to pass specific arguments to the base class constructor as needed.

> [!NOTE]
> If you don't explicitly invoke a specific constructor of the base class in the derived class's initializer list, the base class's default (no-argument) constructor will be called automatically.

### Example of Passing Arguments to Base Class Constructors

```cpp
class Base {
private:
    string name;

public:
    Base() : name("Default Base") {
        cout << "Base no-args constructor called\n";
    }

    Base(const string& name) : name(name) {
        cout << "Base parameterized constructor called\n";
    }

    void showBase() const {
        cout << "Base name: " << name << "\n";
    }
};

class Derived : public Base {
private:
    int value;

public:
    // Explicitly calling the base class parameterized constructor
    Derived(const string& baseName, int val) : Base(baseName), value(val) {
        cout << "Derived constructor called\n";
    }

    void showDerived() const {
        showBase(); // Use Base's member function to display base details
        cout << "Derived value: " << value << "\n";
    }
};

int main() {

    cout << "Creating object with specific base constructor:\n";
    Derived obj1("Custom Base", 42);
    obj1.showDerived();

    return 0;
}
```

### Output of Passing Arguments to Base Class Constructors

```txt
Creating object with specific base constructor:
Base parameterized constructor called
Derived constructor called
Base name: Custom Base
Derived value: 42
```

#### Explanation of Passing Arguments to Base Class Constructors

1. **Base Class Constructor Selection:**
    - **`obj1`** uses the base class's parameterized constructor to set the **`Base`** member to **`"Custom Base"`**.
2. **Construction Order:**
    - The base class constructor is called before the derived class constructor, ensuring the base class's members are fully initialized.
3. **Separate Responsibilities:**
    - The base class handles its own initialization **`name`**, while the derived class focuses on its specific members **`value`**.

> [!TIP]
> You can simplify the process by using delegate constructors in combination with inheritance.

## Copy/Move Constructors & Assignment Operator with Derived Classes

When working with derived classes, it's important to understand how **copy constructors** and **assignment operators** behave. Since the derived class inherits from the base class, the derived class contains the base class portion as well. Therefore, when creating or assigning a derived class object, you must consider both the base and derived portions.

In inheritance, the base class's copy constructor and assignment operator are not automatically invoked unless explicitly called in the derived class. This can lead to incomplete copying or assignment if the derived class adds extra data or resources. Properly managing copy constructors and assignment operators ensures that both the base and derived portions are handled correctly, especially when dynamic memory or external resources are involved.

**Important Notes:**

1. **Object Slicing:**

    When assigning or passing a derived object to a base object, the compiler slices off the derived-specific data, leaving only the base part.

2. **Base Class in Assignment Operator:**

    If you don't explicitly call the base class's assignment operator in the derived class, the base portion of the derived object will not be assigned.

3. **Copy Constructor in Derived:**

    If a copy constructor or assignment operator is created in the derived class, it's critical to ensure the base class's version is also invoked to handle the base portion of the object.

4. **Dynamic Memory or Resources:**

    If neither the base nor the derived class manages dynamic memory or external resources (like files), there's no need to create custom copy/move constructors or assignment operators. The default ones are sufficient.

5. **No Extra Data:**

    If the derived class does not add any new data members, the default copy/move constructors and assignment operators automatically handle the situation, invoking the base class's versions as needed.

### Example of Copy Constructor and Assignment Operator in Derived Classes

```cpp
class Base {
private:
    string base_data;
public:
    Base(const string& data = "Base Data") : base_data{data} {}

    Base(const Base& source) : base_data{source.base_data} {
        cout << "Base Copy Constructor Called" << endl;
    }

    Base& operator=(const Base& rhs) {
        if (this != &rhs) {
            base_data = rhs.base_data;
            cout << "Base Assignment Operator Called" << endl;
        }
        return *this;
    }

    void display() const {
        cout << "Base Data: " << base_data << endl;
    }
};

class Derived : public Base {
private:
    string derived_data;
public:
    Derived(const string& base_data = "Base Data", const string& derived_data = "Derived Data") 
        : Base{base_data}, derived_data{derived_data} {}

    // Only Base part is taken from rhs (slicing operation)
    Derived(const Derived& source) 
        : Base{source}, derived_data{source.derived_data} {
        cout << "Derived Copy Constructor Called" << endl;
    }

    Derived& operator=(const Derived& rhs) {
        if (this != &rhs) {
            // Only Base part is taken from rhs (slicing operation)
            Base::operator=(rhs);  // Call base class assignment part 

            derived_data = rhs.derived_data;
            cout << "Derived Assignment Operator Called" << endl;
        }
        return *this;
    }

    void display() const {
        Base::display();
        cout << "Derived Data: " << derived_data << endl;
    }
};

int main() {
    Derived d1{"Base Info", "Derived Info"};
    d1.display();

    cout << "\nCopying d1 to d2:" << endl;
    Derived d2{d1};  // Calls copy constructor
    d2.display();

    cout << "\nAssigning d1 to d3:" << endl;
    Derived d3;
    d3 = d1;  // Calls assignment operator
    d3.display();

    return 0;
}
```

### Output of Copy Constructor and Assignment Operator in Derived Classes

```txt
Base Data: Base Info
Derived Data: Derived Info

Copying d1 to d2:
Base Copy Constructor Called
Derived Copy Constructor Called
Base Data: Base Info
Derived Data: Derived Info

Assigning d1 to d3:
Base Assignment Operator Called
Derived Assignment Operator Called
Base Data: Base Info
Derived Data: Derived Info
```

#### Explanation of Copy Constructor and Assignment Operator in Derived Classes

1. **Base Copy Constructor & Assignment Operator:**

    When a derived class object is copied or assigned, the base portion of the derived object must also be copied or assigned. This is achieved by explicitly calling the base class's constructor or assignment operator in the derived class's implementations.

2. **Derived Class Copy Constructor & Assignment Operator:**

    The derived class constructor or assignment operator handles its own members after delegating the base class portion.

3. **Object Slicing:**

    If a derived object is passed or assigned to a base object, the derived-specific data would be sliced off, leaving only the base part.

4. **Dynamic Memory Management:**

    If dynamic memory or other resources were involved, these constructors and assignment operators would ensure proper resource handling, avoiding memory leaks or undefined behavior.

> [!NOTE]
> These rules also apply to the move constructor and the move assignment operator.
