# Object Oriented Programming (OOP)

At the previous branches we learned what we call ***Procedural Programming***, where we have a sequence of instructions & functions, we focus on process & actions that the program will take. Data & functions are separate entities.

Even though it's easier to learn and understand for beginners programmers, but it has it's own limitations as the program grows:

- Difficult to manage.
- Difficult to understand.
- Difficult to extend.
- Difficult to debug.
- Difficult to reuse code.
- Fragile and easy to break.
- Functions need to know the structure of the data they are working with, if the data structure changes, many functions may need to be updated.

## What is Object Oriented Programming?

***Object Oriented Programming*** came to solve the mentioned problems, it focuses on creating classes and objects that model real world entities which allows the developers to think at a higher level of abstraction.

In ***OOP***, we have objects that contain both data and functions that operate on that data. Objects are instances of classes, which act as blueprints for each object. This is called ***Encapsulation***. This concept allows us  to control the access to the data and functions of the objects so that we can protect the data from being modified in an unexpected way. and to allow for more ***Abstraction*** since the users don't need to know allow the logic behind the implementation of the class.

Adding to that, ***OOP*** make it easier for us to manage the code, extend it, debug it, and reuse it in other projects which leads to faster development and more maintainable code. and it allows us to create new classes in terms of existing classes, which is called ***Inheritance***.

Even though ***OOP*** could solve lots of ***Procedural Programming*** problems, it has it's own limitations:

- Steeper learning curve.
- More complex to Design.
- Can be slower to run.

## What are Classes and Objects?

***Class***: is a blueprint for creating objects. It defines the properties and behaviors that objects can have:

- User defined data type.
- Can have variables and functions.
- Can hide data and methods from outside access.

For example, we can have a class called `Car` that has variables like `color`, `make`, `model`, `year`, and functions like `start()`, `stop()`, `accelerate()`, `brake()`.

***Object***: is an instance of a class. It represents a specific instance of a class which has the following properties:

- You can create multiple objects from the same class.
- Each object has its own data and functions.

For example, we can have an object called `myCar` that has the color `red`, make `Toyota`, model `Corolla`, year `2020`, and functions like `start()`, `stop()`, `accelerate()`, `brake()`.

```cpp
int main() {
    // Create an object of the class
    Car myCar;
    return 0;
}
```

In the above example, we created an object called `myCar` from the class `Car` which is the implementation of the object `Car`(how to create implementation will be shown later in this branch).

> [!NOTE]
> Objects are like variables, but they can store multiple variables and functions.

## Declaring a Class and Creating Objects

To declare a class, we use the `class` keyword followed by the class name, and the class body enclosed in curly braces `{}`. The class body can contain class members like variables and functions, at the end of the class declaration, don't forget to add a semicolon `;`.

```cpp
class ClassName {
    // Class variables and functions
};
```

In the following example, we are creating a basic class called **`Player`** that can be used in multiple video games:

```cpp
class Player {
    // Variables
    int health;
    int damage;
    int speed;
    int level;
    int xp;

    // Declare functions
    void move();
    void attack();
    void levelUp();
    void gainXP();
    void die();

    // Function definitions
    void move() {
        // Code to move the player
    }
    void attack() {
        // Code to attack
    }
    /* 
    .
    .   Other functions 
    .
    */
};
```

Once we have declared the class, we can create objects from it. we can deal with the object as we deal with variables, we can create an array of objects, pass objects to functions, and return objects from functions, create objects on the heap using pointers, and so on.

To create an object from a class, we use the class name followed by the object name.

```cpp

class Player {
    // Same as the previous example
};

int main() {
    // Create an object of the class
    Player player1;
    Player player2;

    // Create an array of objects
    Player enemies[10];

    // declare an pointer to an object
    Player* pPlayer = new Player();

    delete pPlayer;
    return 0;
}
```

In the above example, each object of class `Player` created it contains its own copy of the variables and functions of the class. and the variables will contain garbage values because we didn't initialize them. (how to initialize the variables will be shown later in this branch).

## Accessing Class Members

To access the class members (variables and functions) from outside the class, we use the `.` operator for objects and the `->` operator for pointers to objects,  but these members should be declared as `public` in the class definition, otherwise, they will be private by default. (explained in details later in this branch).

```cpp
class Player {
    // Set the access specifier to public 
    public:
        int health;
        int speed;
        int level;
        int xp;

        // Declare functions
        void move();
        void attack();
        void loseHealth(int amount);


        // Function definitions
        // ...
        void loseHealth(int amount) {
            health -= amount;
            cout << "Player lost " << amount << " health points." << endl;
            cout << "Player health is now " << health << endl;
        }
};
```

In the previous example, we set the class members to public to be able to access it from outside the class, at the main function.

```cpp
int main() {
    // Create an object of the class
    Player player1;

    // Access the class members
    player1.health = 100;
    player1.speed = 10;
    player1.level = 1;
    player1.xp = 0;


    // Call the functions
    player1.move();
    player1.lostHealth(10);
    // Player lost 10 health points.
    // Player health is now 90 

    Player* pPlayer = new Player();
    pPlayer->health = 100;

    delete pPlayer;

    return 0;
}
```

>[!IMPORTANT]
> Notice that we did not need to pass the player\`s health to the function, because the function can access the player\`s health directly since it is a member of the class.

## public & private Access Specifiers

OOP gives us the power to control the access to the class members by using access specifiers, which are keywords that define the access level of the class members. There are three access specifiers in C++:

- `public`: members are accessible from outside the class.
- `private`: members are only accessible from within the class or from friends of the class (friends will be explained later in this branch).
- `protected`: members are accessible from outside the class but only in a class derived from it. (explained later in another branch).

This power allows us to hide the implementation details of the class from the users of the class, and to protect the data from being modified in an unexpected way, and to allow for more abstraction since the users don't need to know the logic behind the implementation of the class, easier to debug and maintain.

***By default, the members of a class are always private, unless we specify otherwise.*** In the following example, we have a class called **`BankAccount`** that has a private member called **`balance`** and public members called **`deposit()`**, **`withdraw()`**.

For now let's assume that the balance is initialized to **100** in the below example.

```cpp
class BankAccount {
    // private members
    private: // You don't need to write private, 
             // it's the default access specifier
        double balance;
    public:
        // public members 
        // You need to specify it as public
        void deposit(double amount) {
            balance += amount;
            cout << "balance is now " << balance << endl;
        }
        void withdraw(double amount) {
            balance -= amount;
            cout << "balance is now " << balance << endl;
        }  
};

int main() {
    BankAccount account;
    account.deposit(100); // balance is now 200
    account.withdraw(50); // balance is now 150
    account.balance = 1000; // Error: balance is private (Compile error)
    return 0;
}
```

In the above example, the balance is a private member, so we can't access it from outside the class, but we can access it from the public functions `deposit()` and `withdraw()`. This gives us more control over the data and functions of the class, For example the user of this class can not set the balance to another value directly by mistake.

## Implementing Class Functions

When implementing the class functions, we have several ways to do that:

1. **Inside the class definition**
2. **Outside the class definition**
3. **Separate specification and implementation**

In all cases, the class variables are accessible from the class functions directly without the need to pass them as arguments.

### Inside the class definition

In this case, we define the functions inside the class definition, this is useful for small functions that are simple and don't need to be defined outside the class.

```cpp
class Player {
    public:
        // Player's variables

        // Define functions
        void move() {
            cout << "Player is moving" << endl;
        }

};
```

### Outside the class definition

In this case, we define the functions outside the class definition, this is useful for large functions that are complex and need to be defined outside the class.

we need to use the scope resolution operator `::` to define the function outside the class, to tell the compiler that this function belongs to the class otherwise it will be treated as a normal function.

```cpp
class Player {
    public:
        // Player's variables

        // Declare functions
        void move();
};

// Define the function outside the class
void Player::move() {
    cout << "Player is moving" << endl;
}
```

### Separate specification and implementation

In this case, we separate the class declaration from the class implementation, this is useful when we have a large class with many functions and we want to separate the interface from the implementation.

```cpp
// Player.h file (declaration file)
class Player {
    public:
        // Player's variables

        // Declare functions
        void move();
};
```

```cpp
// Player.cpp file (implementation file)
#include "Player.h" 
// This is the header file that contains the class declaration 
// it should be included in the implementation file

// Define the function outside the class
void Player::move() {
    cout << "Player is moving" << endl;
}
```

In the above example, we have two files, the first file is the header file that contains the class declaration, and the second file is the implementation file that contains the class implementation. The header file should be included in the implementation file to tell the compiler that this implementation belongs to this class.

>[!NOTE]
> When using **`#include "filename"`**  the compiler will look for the file in the current directory first, then in the standard directories. When using **`#include <filename>`** the compiler will look for the file in the standard directories only.

Using the separate specification and implementation method is the most common way to implement classes in C++. It makes the code more organized and easier to maintain. but it can cause some problems like the **`multiple definition`** error if you include the implementation file in multiple source files.

To avoid this problem, C++ provided us with include guards, which are preprocessor directives that prevent the header file from being included more than once in the same source file.

```cpp
// Player.h file (declaration file)
#ifndef _PLAYER_H_
#define _PLAYER_H_

class Player {
    // Player's class declaration
};

#endif
```

In the above example, we used the `#ifndef`, `#define`, and `#endif` preprocessor directives to create an include guard. The first time the header file is included, the `_PLAYER_H_` macro is defined, and the class declaration is included. The next time the header file is included, the `_PLAYER_H_` macro is already defined, so the class declaration will not be included again.

You can use any name for the macro, but it's a common practice to use the name of the header file in uppercase with an underscore at the beginning and the end.

There is also another way include guards, which is using `#pragma once` directive, but it's not standard and not supported by all compilers.

```cpp
// Player.h file (declaration file)
#pragma once

class Player {
    // Player's class declaration
};
```

The implementation file(.cpp) remains the same, and in the main file, you only need to include the header file.

```cpp
#include "Player.h"
int main (){
    Player player;
    player.move(); // Player is moving
    return 0;
}
```

## Constructors & Destructors

When creating an object from a class, the object is created in memory, and the class constructor is called to initialize the object, and when the object is destroyed, the class destructor is called to clean up the object such as releasing memory from the heap or closing files.

### Constructors

We can call our constructors as intialization function for our objects, it's a special member function that is called when an object is created, it has the same name as the class, and it doesn't have a return type, and it can have parameters. and you can have multiple constructors for the same class this is called **constructor overloading**.

Constructors are always public, because they are created specifically to be used when creating objects outside the class.

If you don't define a constructor for your class, the compiler will provide a default constructor for you, which does nothing. but if you define a constructor, the compiler will not provide a default constructor for you.

In the following example, multiple constructors will be defined for the class `Player`:

```cpp
class Player {
public:
    // Player's variables
    int health;
    int speed;
    int level;
    int xp;
    // Constructors
    Player() {
        health = 100;
        speed = 10;
        level = 1;
        xp = 0;
    }
    Player(int h, int s, int l, int x) {
        health = h;
        speed = s;
        level = l;
        xp = x;
    }
};

int main() {
    // Create an object of the class
    Player player1; // health = 100, speed = 10, level = 1, xp = 0
    Player player2(200, 20, 2, 100); // health = 200, speed = 20, level = 2, xp = 100
    return 0;
}
```

In the above example, we defined two constructors for the class `Player`, the first constructor is the constructor that initializes the player's variables to default values, and the second constructor is a parameterized constructor that initializes the player's variables to the values passed to it.

>[!CAUTION]
> Since you can have multiple constructors for the same class, you can't have two constructors with the same signature, because the compiler will not be able to differentiate between them. meaning that you can't have two constructors with the same number of parameters and the same types.

if you define a constructor with parameters, the compiler will not provide a default constructor for you, **so you have to define it yourself if you need it otherwise you will get a compile error**.

```cpp
class Player {
public:
    // Player's variables
    int health;
    int speed;
    int level;
    int xp;
    // Constructor
    Player(int h, int s, int l, int x) {
        health = h;
        speed = s;
        level = l;
        xp = x;
    }
};

int main() {
    // Create an object of the class
    Player player1; // Error: no default constructor available
    Player player2(200, 20, 2, 100); // health = 200, speed = 20, level = 2, xp = 100
    return 0;
}
```

**C++11** allowed us to give default values to the class members without the need to define a specific constructor for that, this is called **default member initialization**.

```cpp
class Player {
public:
    // Player's variables
    int health = 100;
    int speed = 10;
    int level = 1;
    int xp = 0;
};
```

In the above example, we gave default values to the player's variables directly in the class definition, so when creating an object from the class, the variables will be initialized to these values without the need to define a constructor.

### Destructors

Destructors are special member functions that are called when an object is destroyed, they have the same name as the class preceded by a tilde **`~`**, and they don't have parameters or return type.

Just like constructors, if you don't define a destructor for your class, the compiler will provide a default destructor for you, which does nothing. but if you define a destructor, the compiler will not provide a default destructor for you. and the destructor is always public.

You can use the destructor to clean up the object, such as releasing memory from the heap, closing files, or releasing other resources, for each class, there is only one destructor.

The destructor is called automatically when the object goes out of scope, or when the `delete` operator is used to delete the object from the heap.

In the following example, a destructor will be defined for the class `Player` to release memory from the heap:

```cpp
class Player {
public:
    // Player's variables
    int* data;
    // Constructor
    Player() {
        data = new int[100];
    }
    // Destructor
    ~Player() {
        delete[] data;
        cout << "Destructor called" << endl;
    }
};

int main() {
    // Create an object of the class
    Player player;
    return 0;
} // Destructor called (destructor is called automatically 
  //when the object goes out of scope)
```

## Constructor Initialization Lists

When creating an object from a class, the constructor is called to initialize the object, and the constructor can initialize the object's variables using the constructor body, but there is another way to initialize the object's variables using the constructor initialization list.

This is useful and more efficient when initializing the object's variables as it initializes the variables before entering the constructor body instead of intializing a variable once when it's declared and then intializing it again in the constructor body.

When you give values to the class members in the constructor body, you are actually assigning values to the variables not initializing them, which can cause larger overhead in complex classes.

To use the constructor initialization list, you need to add a colon `:` after the constructor's parameters, followed by the list of variables to be initialized and their values. The following example demonstrates how to use the constructor initialization list:

```cpp
class Player {
public:
    // Player's variables
    string name;
    // constructor
    Player(){
        name = "Player";
    }
};

class Account {
public:
    // Account's variables
    string name;
    double balance;
    // constructor
    Account () : name("Account"), balance(0.0) {
        // constructor body
    }
    Account(string n, double b) : name(n), balance(b) {
        // constructor body
    }
};

int main(){

    Player player; 
    // At player's class name is intialized to empty string first
    // then it's intialized to "Player" in the constructor body
    Account account;
    // At account's class name is intialized to Account and balance to 0.0
    // directly in the constructor initialization list

    // This saves overhead in complex classes and large programs
    return 0;
}
```

## Delegating Constructors in C++

When working with classes, it’s common to use overloaded constructors to provide multiple ways of initializing an object. However, repeating shared initialization code across multiple constructors can lead to code duplication, making maintenance harder and less efficient.

C++11 introduced **delegating constructors**, a feature that allows one constructor to call another constructor in the same class. This approach reduces redundancy by centralizing shared initialization logic.

### Key Points about Delegating Constructors

- Constructors can delegate to other constructors within the same class.
- Delegation uses the **constructor initialization list** syntax.
- It improves code readability and reduces redundancy.

### Example: Using Delegating Constructors

Consider the following example, where the `Player` class has three constructors:

1. The **primary constructor** initializes all member variables (`health`, `speed`, and `xp`).
2. A **secondary constructor** accepts two arguments and delegates the rest to the primary constructor.
3. A **default constructor** initializes the object with default values by delegating to the primary constructor.

```cpp
class Player {

    int health;
    int speed;
    int xp;

public:
    // Primary constructor (Delegating constructor)
    Player(int health_val, int speed_val, int xp_val)
        : health{health_val}, speed{speed_val}, xp{xp_val} {
        cout << "Three-argument constructor" << endl;
    }
    // Secondary constructor
    Player(int health_val, int speed_val)
        : Player{health_val, speed_val, 0} { // Delegates to the primary constructor
        cout << "Two-argument constructor" << endl;
    }
    // Default constructor
    Player()
        : Player{100, 10, 0} { // Delegates to the primary constructor
        cout << "Default constructor" << endl;
    }
};

int main() {
    Player p1{100, 20, 300}; // Calls the primary constructor
    Player p2{150, 25};      // Calls the secondary constructor, which delegates
    Player p3;               // Calls the default constructor, which delegates

    return 0;
}
```

### Explanation of Output

When you run the code, the output is:

```bash
Three-argument constructor
Three-argument constructor
Two-argument constructor
Three-argument constructor
Default constructor
```

#### Breakdown of the Output

1. `p1`: The primary constructor is called directly, initializing all three variables.
2. `p2`: The secondary constructor delegates to the primary constructor before printing its message.
3. `p3`: The default constructor delegates to the primary constructor before printing its message.

## Constructor Parameters & Default Values

Recall from the [Functions](https://github.com/MagedGDEV/CppInsights/tree/functions#default-arguments) branch, we could add default values to parameters, and likewise, we can apply the same concept to constructors. This allows us to create constructors with varying numbers of arguments, reducing the need for overloading.

Default parameter values save more code compared to delegating constructors, as they eliminate the need for redundant constructors entirely while still maintaining flexibility.

> [!NOTE]  
> Default values in a constructor **always override** default member initializers for the same member.

---

### Example: Constructor with Default Values

```cpp
class Player {

    int health;
    int speed;
    int xp;

public:
    // Constructor with default values
    Player(int health_val = 100, int speed_val = 1, int xp_val = 0)
        : health{health_val}, speed{speed_val}, xp{xp_val} {
        cout << "Player created with health: " << health
             << ", speed: " << speed << ", xp: " << xp << endl;
    }
};

int main() {
    Player p1;                     // Uses all defaults: health=100, speed=1, xp=0
    Player p2{80};                 // Overrides health: health=80, speed=1, xp=0
    Player p3{70, 5};              // Overrides health and speed: health=70, speed=5, xp=0
    Player p4{95, 10, 100};        // Overrides all values: health=95, speed=10, xp=100

    return 0;
}
```

### Output

```bash
Player created with health: 100, speed: 1, xp: 0
Player created with health: 80, speed: 1, xp: 0
Player created with health: 70, speed: 5, xp: 0
Player created with health: 95, speed: 10, xp: 100
```

#### Explanation of the Code Above

- p1: Calls the constructor with no arguments, so all default values are used.
- p2: Passes 80 for health, and the other parameters (speed and xp) use their defaults.
- p3: Passes 70 for health and 5 for speed, while xp defaults to 0.
- p4: Passes values for all parameters, overriding all defaults.

> [!CAUTION]
> While default values in constructors are powerful, they can lead to ambiguity when combined with overloaded constructors. Let’s explore an example of such ambiguity

### Ambiguity Example

```cpp
class Player {

    int health;
    int speed;

public:
    // Constructor with default values
    Player(int health_val = 100, int speed_val = 1)
        : health{health_val}, speed{speed_val} {
        cout << "Two arguments constructor" << endl;
    }
    // Constructor with one parameter
    Player(int health_val)
        : health{health_val}, speed{0} {  // Default speed = 0
        cout << "One argument constructor" << endl;
    }
};

int main() {
    Player p1{50};  // Ambiguity: Which constructor should be called?

    return 0;
}
```

#### Why Ambiguity Occurs?

- Player(int health_val = 100, int speed_val = 1) can accept one or two arguments because of the default for speed_val.
- Player(int health_val) also accepts one argument.
- When the compiler sees Player p1{50}, it cannot determine whether to:
  - Use the two-argument constructor, treating speed_val as defaulted, or
  - Use the one-argument constructor directly.

## Copy Constructor

In C++, copying data from one variable to another is common. Similarly, we can copy data from one object to another using a **copy constructor**. This constructor tells the compiler how to copy the data from one object to another.

### When Do You Need a Copy Constructor?

- When **passing an object by value** as a function parameter.
- When **returning an object by value** from a function.
- When **constructing one object from another** of the same class.

If you don't provide a custom copy constructor, C++ will provide a **default compiler-defined copy constructor**. This default constructor:

- Copies the values of each member to the new object.
- Works well in many cases but may cause problems in some scenarios (e.g., with dynamic memory).

### Syntax of a Copy Constructor

```cpp
ClassName(const ClassName& other);
```

- Adding a reference **`&`** in the copy constructor is **crucial** because it prevents unnecessary copies of the source object and **avoids creating an infinite loop by repeatedly calling the constructor**.

- Adding **`const`** ensures that the source object cannot be modified during the copying process.

### Example: Copy Constructor

```cpp
class Player {
    
    int health;

public:
    // Constructor
    Player(int h) : health(h) {}
    // Copy Constructor
    Player(const Player& other) : health(other.health) {
        std::cout << "Copy Constructor Called" << std::endl;
    }
    void showHealth() {
        std::cout << "Health: " << health << std::endl;
    }
};

int main() {
    Player p1(100);   // Constructor is called
    Player p2 = p1;    // Copy Constructor is called

    p1.showHealth();   // Displays: Health: 100
    p2.showHealth();   // Displays: Health: 100

    return 0;
}
```

In the above example, the copy constructor ensures that the value of health from **`p1`** is copied to **`p2`**. Since both objects have their own health value, the constructor copies the data without issues.

> [!TIP]
> Delegating constructors can also be used with copy constructors to simplify and avoid code duplication.

### Shallow copying vs Deep copying

As mentioned before, there are situations where using the default copy constructor might not be sufficient, especially when working with dynamically allocated memory (like pointers). A shallow copy can cause serious problems, such as **`double deletion`** or **`data corruption`** when the object is destroyed. In these cases, you need to define a deep copy constructor to ensure each object manages its own memory.

#### Example: Shallow Copy with Pointer (Crashing with Errors)

Here’s an example of shallow copying using a pointer. This approach leads to a crash because both objects end up pointing to the same memory, and when one object is destroyed, it frees the memory that the other object is still using.

```cpp
class Player {
public:
    int *score;
    // Constructor
    Player(int val) {
        score = new int(val);
        cout << "Player created with score: " << *score << endl;
    }
    // Shallow copy constructor (just copies the pointer)
    Player(const Player& other) {
        score = other.score; // Shallow copy of the pointer
        cout << "Shallow copy created with score: " << *score << endl;
    }
    // Destructor
    ~Player() {
        cout << "Destroying Player with score: " << *score << endl;
        delete score; // Deleting memory
    }
};

int main() {
    Player p1(100);     // Player with score 100
    Player p2 = p1;     // Shallow copy of p1

    return 0;           // Destructor is called for both objects here
}
```

#### Output with (crash)

```bash
Player created with score: 100
Shallow copy created with score: 100
Destroying Player with score: 100
Destroying Player with score: 0  // Undefined behavior, could show 0 or other values
```

##### Explanation of shallow copying

- When **`p1`** is destroyed, it deletes the memory pointed to by score.
- **`p2`** shares the same pointer (score) due to the shallow copy. When **`p2`**'s destructor is called, it tries to access the already deleted memory, leading to undefined behavior. The value shown may be the result of accessing a memory location that has already been freed, but it's not guaranteed and depends on the environment and compiler.

> [!WARNING]
> Another key issue with shallow copying is that if the pointer value in **`p2`** is modified, it will also change the value of the data in **`p1`**, since both objects share the same memory. This can lead to unexpected behavior and bugs.

#### Deep Copy Constructor Example (Fixing the Issue)

To avoid this issue, we can implement a **deep copy constructor**. In a deep copy, we allocate new memory for each object, so they don’t share the same memory. Here’s an updated version of the class with a deep copy constructor:

```cpp
class Player {
public:
    int *score;
    // Constructor
    Player(int val) {
        score = new int(val);
        cout << "Player created with score: " << *score << endl;
    }
    // Deep copy constructor (allocates new memory)
    Player(const Player& other) {
        score = new int(*other.score); // Deep copy (new memoryallocation)
        cout << "Deep copy created with score: " << *score << endl;
    }
    // Destructor
    ~Player() {
        cout << "Destroying Player with score: " << *score << endl;
        delete score; // Deleting memory
    }
};

int main() {
    Player p1(100);     // Player with score 100
    Player p2 = p1;     // Deep copy of p1

    return 0;           // Destructor is called for both objects here
}
```

#### Output (with no errors)

```bash
Player created with score: 100
Deep copy created with score: 100
Destroying Player with score: 100
Destroying Player with score: 100
```

##### Explanation of deep copying

- In this example, when p2 is created as a deep copy of p1, a new memory block is allocated for score, and the value of p1's score is copied into p2's score.
- The destructors are called for both p1 and p2, but now each object has its own memory, so the memory is deleted correctly without causing any errors.

## Move Constructor

In modern C++, efficiency is key, especially when dealing with objects that involve resource management, such as dynamic memory or file handles. This is where the move constructor comes into play—it allows for the efficient transfer of resources rather than duplicating them. But before diving into how the move constructor works, we first need to understand two fundamental concepts: L-Value references and R-Value references.

### L-Value references

An **L-value reference** is a reference to a variable (an object or memory location) that has a name and persists in memory. Simply put, it acts like an **alias** for the variable, allowing you to refer to the same memory location using a different name.

L-value references are typically used to pass objects to functions without making a copy, enabling efficient operations while preserving the original value.

#### Key Points for L-Value references

- L-value references can only bind to L-values (objects that have a persistent location in memory).
- They are commonly used in function parameters to avoid copying data.

#### Example of L-Value references

```cpp
void modify(int& ref) { // L-value reference as a parameter
    ref = 10; // Modify the original variable
}

int main() {
    int x = 5;
    cout << "Before: " << x << endl; 
    modify(x); // Pass x by reference
    cout << "After: " << x << endl; // x is modified
    return 0;
}
```

##### Output of L-Value references

```bash
Before: 5
After: 10
```

- **`ref`** is an L-value reference that aliases **`x`**.
- Modifying **`ref`** directly changes the value of **`x`**.

### R-Value references

An **R-value reference** is a reference to a temporary object (an object without a persistent memory location). It allows you to bind to values that would otherwise be inaccessible, such as temporary results of expressions.

R-value references are primarily used for **move semantics** and **perfect forwarding**, enabling efficient handling of resources by transferring ownership instead of copying.

#### Key Points for R-Value References

- R-value references can only bind to R-values (temporary objects or literals).
- They are denoted using **`&&`** in the syntax.
- They allow modification of temporary objects.

#### Example of R-Value References

```cpp
void printAndModify(int&& ref) { // R-value reference as a parameter
    cout << "Original: " << ref << endl;
    ref = 20; // Modify the temporary value
    cout << "Modified: " << ref << endl;
}

int main() {
    printAndModify(10); // Pass a temporary (R-value)
    int x = 10;
    // printAndModify(x); will cause an error because passing an L-value
    return 0;
}
```

##### Output of R-Value references

```bash
Original: 10  
Modified: 20
```

- **`ref`** is an R-value reference that binds to the temporary **`10`**.
- It allows modification of a value that would otherwise be discarded.

Now that we've covered **L-value** and **R-value references**, let's delve into the **move constructor**, a critical feature in modern C++ that optimizes resource handling.

When we pass or return objects, the **copy constructor** duplicates resources, which can be inefficient for large objects or objects managing dynamically allocated memory. Instead, the **move constructor** transfers ownership of resources from one object to another, avoiding expensive deep copies.

The **move constructor** is invoked when an object is initialized from a temporary (R-value), ensuring efficient resource management by **moving** instead of **copying**.

### Syntax Move Constructor

```cpp
ClassName(ClassName&& other) noexcept;
```

- **`&&`** indicates R-Value reference.
- **`noexcept`** keyword guarantees that this function (move constructor in our case) will not throw exceptions.
  - While optional, it is **highly recommended** for STL containers like **`std::vector`** or **`std::map`**, as it allows them to perform move operations efficiently during resizing or reallocation.
  - If noexcept is omitted, STL containers may fall back to the copy constructor, negating the performance benefits of the move constructor.

### Example of move constructor

```cpp
class Player {

    std::string name;

public:
    Player(std::string name_val) : name{name_val} {
        std::cout << "Constructor called for " << name << std::endl;
    }
    // Move Constructor
    Player(Player&& other) noexcept : name{std::move(other.name)} {
        std::cout << "Move constructor called for " << name <<std::endl;
    }
    ~Player() {
        std::cout << "Destructor called for " << name << std::endl;
}
};

int main() {
    std::vector<Player> players;
    players.push_back(Player("Player1")); // Move constructor is called
    players.push_back(Player("Player2")); // Move constructor is called

    return 0;
}
```

- **`std::move`** function is part of C++ Standard Library and is used to indicate that an object can be "moved" rather than copied. Specifically, it casts its argument to an R-value reference, allowing the move constructor or move assignment operator to be invoked.
  - it tells the compiler: "I don't need the contents of **`other.name`** in the original object anymore; you can safely transfer its resources to **`name`**."
  - Without **`std::move`** the move constructor will act as a copy constructor.

### Output of move constructor

```txt
Constructor called for Player1
Move constructor called for Player1
Destructor called for 
Constructor called for Player2
Move constructor called for Player2
Destructor called for 
Destructor called for Player1
Destructor called for Player2
```

#### Explanation of move constructor

1. First Object Creation **`(Player("Player1"))`**:
    1. A temporary Player object is created with the name **`Player1`**.
    2. The constructor is called for this temporary object.
    3. This temporary object is then moved into the players vector and move constructor is invoked to transfer ownership into vector.
    4. Once the temporary object is moved, it is destroyed, as its lifetime ends after the move and notice **`name`** is not available when calling the destructor **because it is moved**.
2. Same Steps happens for Second Object Creation.
3. At the end the vector is destroyed, destroying it's players.

### Why Move Constructor Is Essential Despite the Presence of a Copy Constructor?

When working with large containers like vectors, using a **move constructor** is much more efficient than using a **copy constructor**. Here's why:

- Copy Constructor: Duplicates every element in the container, which can be slow and memory-intensive, especially with large amounts of data.
- Move Constructor: Instead of copying data, it **transfers ownership** of the data from one object to another, which is much faster and uses less memory.

When a container like a vector needs to resize, the **move constructor** just moves the data, while the **copy constructor** makes a full copy, which is slower. The move constructor is faster and more efficient, especially when dealing with large data.

## The 'this' pointer

The **`this`** pointer is a special, implicit pointer that refers to the current instance of a class. It holds the address of the object for which a non-static member function is called. Although we don't typically need to use the **`this`** pointer explicitly because the compiler automatically uses it to access members, there are cases where we need to reference it, such as when there is a name conflict between member variables and function parameters.

### When to Use the `this` Pointer

A common scenario where the **`this`** pointer is useful is when a member variable and a parameter share the same name. In such cases, using the **`this`** pointer helps differentiate between the two.

### Example of `this` Pointer

```cpp
class Player {
public:
    int health;
    // Constructor
    Player(int health_val) : health{health_val} {}
    // Member function using 'this' to avoid name conflict
    void setHealth(int health) {
        this->health = health;  // 'this' differentiates membervariable and parameter
    }
    void showHealth() {
        cout << "Health: " << health << endl;  // 'this' is optionalhere
}
};

int main() {
    Player p1(100);
    p1.showHealth();  // Output: Health: 100
    p1.setHealth(80);
    p1.showHealth();  // Output: Health: 80

    return 0;
}
```

In the above example, **`this->health`** is used inside the **`setHealth`** function to clearly reference the member variable, as it shares the same name as the parameter health. Without the this pointer, the compiler would treat the parameter as the variable to assign **(ambiguity)**.

## Using `const` with classes

In the [Variables & Constants](https://github.com/MagedGDEV/CppInsights/tree/variables) branch, we discussed how variables can be initialized with values and how **`const`** disables changes to those variables. Similarly, **`const`** objects prevent any modification of their members.

When dealing with **`const`** objects, any member functions that modify the object's state must be avoided. The compiler enforces this rule by requiring those functions to be marked as **`const`** if they don't modify the object.

### Example of using `const` with classes

```cpp
class Player {

    int health;

public:
    // Constructor to initialize health
    Player(int health_val) : health{health_val} {}
    // Function that tries to modify the object (will give error)
    void setHealth(int health_val) {
        health = health_val; // Error: cannot modify member of aconst  object
    }
    // Function that doesn't modify the object (works fine withconst   objects)
    void showHealth() const {
        cout << "Health: " << health << endl; // No modification, soit's   fine
    }
};

int main() {
    const Player p1(100); // const object

    // p1.setHealth(50); // Error: can't call non-const function on a const object
    p1.showHealth(); // Works fine: const function, doesn't modify object

    return 0;
}
```

#### Explanation of using `const` with classes

- **`setHealth`**: This function tries to modify the member health, which is not allowed when working with a **`const`** object. This will result in a **compilation error**.
- **`showHealth`**: This function is marked as **`const`**, meaning it guarantees not to modify any members of the object. Thus, it works fine with **`const`** objects.

>[!IMPORTANT]
> All members must be initialized in the constructor when creating a const object. Once constructed, you cannot modify the members later.

## Static Class Members & Functions

In C++, **`static`** members are variables or functions that are shared across all instances of a class, meaning they do not belong to individual objects but rather to the class itself. This means that **static variables** are common to all instances of the class, and their value is shared between all objects. **Static functions** can also be called on the class itself, not requiring an object instance and they can only access static members of the class.

### Initialization of Static Members Outside the Class

Static class members are declared inside the class, but they must be initialized outside the class. This is because the static member is part of the class definition, but it needs a specific memory location shared by all instances, and this memory needs to be allocated separately. The reason C++ requires the initialization to be outside the class is to ensure that the static member gets allocated a memory location that persists across all instances.

### Example of Static Class Members & Functions

```cpp
class Player {

    std::string name;
    static int playerCount; // Static member to track the number ofPlayer  objects

public:
    Player(std::string name_val) : name{name_val} {
        ++playerCount; // Increment count when a new player is created
        std::cout << "Constructor called for " << name << std::endl;
    }
    ~Player() {
        --playerCount; // Decrement count when a player is destroyed
        std::cout << "Destructor called for " << name << std::endl;
    }
    // Static function to display the number of players
    static void displayPlayerCount() {
        std::cout << "Number of players: " << playerCount << std::endl;
    }
};

// Definition of the static member outside the class
int Player::playerCount = 0;

int main() {
    Player p1("Player1");
    Player p2("Player2");

    Player::displayPlayerCount();

    {
        Player p3("Player3");
        Player::displayPlayerCount(); 
    }

    Player::displayPlayerCount(); 

    return 0;
}
```

### Output of Static Class Members & Functions

```txt
Constructor called for Player1
Constructor called for Player2
Number of players: 2
Constructor called for Player3
Number of players: 3
Destructor called for Player3
Number of players: 2
Destructor called for Player2
Destructor called for Player1
```

#### Explanation of Static Class Members & Functions

- Notice **Static member functions** can be called directly on the class, such as **`Player::displayPlayerCount()`**, without needing an object instance.

1. **Creating `p1` and `p2`**: When **`p1`** and **`p2`** are created, the constructors increment playerCount to 2, **`displayPlayerCount()`** shows 2 players.
2. **Creating `p3`**: The creation of **`p3`** inside a block scope increases **`playerCount`** to 3, and the updated count is displayed.
3. **Destructor for `p3`**: Once **`p3`** goes out of scope, its destructor is called, and **`playerCount`** is decremented to 2. The updated count is displayed.
4. **Destructor for `p1` and `p2`**: As the program finishes, the destructors for **`p1`** and **`p2`** decrement **`playerCount`** further. After all destructors are called,**`playerCount`** is 0, indicating all players are destroyed.

## Struct vs Classes

**`struct`** is inherited from C and is essentially the same as a **`class`** in C++. The key difference is that, by default:

- struct members are public.
- class members are private by default.

```cpp
struct Player {
    std::string name;  // public by default
    int health;        // public by default
};

class Enemy {
    std::string name;  // private by default
    int health;        // private by default
};
```

## Friend of a Class

The **`friend`** keyword grants access to private and protected members of a class to specific functions or other classes. It can be applied to:

- A non-member function.
- A member function of another class.
- Another class.

### Syntax for Friend

1. Friend Function (non-member):

    ```cpp
    class ClassName {
    private:
        int privateValue;
    public:
        friend void someFunction(ClassName& obj);
    };
    ```

2. Friend member function of another class

    ```cpp
    class AnotherClass;

    class ClassName {
    private:
        int privateValue;
    public:
        friend void AnotherClass::someFunction(ClassName& obj);
    };
    ```

3. Friend Class:

    ```cpp
    class ClassName {
    private:
        int privateValue;
    public:
        friend class AnotherClass;
    };
    ```

### Example of Friend of a Class

```cpp
#include <iostream>
using namespace std;

class Player {

    int health;
public:
    // Declare a friend function
    friend void displayHealth(const Player& p);
    
    Player(int h) : health(h) {}
};

// Friend function definition
void displayHealth(const Player& p) {
    cout << "Player health: " << p.health << endl;
}


int main() {
    Player p1(100);
    displayHealth(p1);  // Can access private member `health` directly

    return 0;
}
```

- **`displayHealth`** is a **friend function** of the **`Player`** class, which allows it to access the private member **`health`** directly.
