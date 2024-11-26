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

To create an object from a class, we use the class name followed by the object name, and the object name.

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

> [!TIP]  
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
> While default values are powerful, they can lead to ambiguity when combined with overloaded constructors. Let’s explore an example of such ambiguity:

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
