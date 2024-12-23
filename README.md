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

In this example, **`Car`** publicly inherits from **`Vehicle`**. The **`Car`** class can access public members of the **`Vehicle`** class, such as **``**.

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
