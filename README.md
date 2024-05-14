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
