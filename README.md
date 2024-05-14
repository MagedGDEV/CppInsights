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
