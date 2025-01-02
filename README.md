# Smart Pointers

Smart pointers are a modern C++ concept introduced to address the problems commonly associated with raw pointers. They are part of the C++ Standard Library and provide a safer and more convenient way to manage dynamically allocated memory.

## Why Were Smart Pointers Introduced?

Raw pointers have inherent issues that can lead to serious programming errors:

1. **Wild Pointers:** Pointers that point to arbitrary or invalid memory locations.
2. **Memory Leaks:** Forgetting to release dynamically allocated memory, causing resource wastage.
3. **Dangling Pointers:** Pointers that reference memory that has already been deallocated.
4. **Not Exception-Safe:** In case of an exception, raw pointers may not release their memory correctly.

In raw pointers, the programmer must explicitly allocate and deallocate memory, which can lead to lifetime management errors.

## What Are Smart Pointers?

Smart pointers are C++ template classes that act as wrappers around raw pointers. They are objects themselves and provide automatic memory management. When a smart pointer goes out of scope or is no longer needed, it ensures the associated memory is released automatically by calling **`delete`**.

- **Ownership and Lifetime Management:** Smart pointers clearly define who **owns** a pointer and determine when the pointer should be deleted.
- **RAII (Resource Acquisition Is Initialization):** Smart pointers adhere to RAII principles, which ensure that resources are acquired and released automatically based on the container's lifetime.

### Key Features of Smart Pointers

1. **Automatic Memory Management:**

    Smart pointers automatically release memory when they are no longer needed, preventing memory leaks.

2. **Ease of Use:**

    Smart pointers simplify code by removing the need for explicit **`delete`** calls, reducing programmer errors.

3. **Support for Pointer-Like Syntax:**

    Smart pointers can be dereferenced **\*** or used with member access operators **->**, making them behave similarly to raw pointers.

4. **Custom Deleters:**

    Smart pointers allow custom deleters, enabling explicit control over how the memory is released.

5. **No Pointer Arithmetic:**

    Unlike raw pointers, smart pointers do not support pointer arithmetic **`++`**, **`--`** to maintain safety.

6. **Prevent Resource Leaks:**

    Smart pointers help manage dynamic resources effectively, making code easier to maintain and less error-prone.

### Types of Smart Pointers

1. Unique Pointer (**`std::unique_ptr`**)
2. Shared Pointer (**`std::shared_ptr`**)
3. Weak Pointer (**`std::weak_ptr`**)

>[!NOTE]
> To use smart pointers, you need to include the **`<memory>`** header. This header provides the necessary functionality for various types of smart pointers, including **`std::unique_ptr`**, **`std::shared_ptr`**, and **`std::weak_ptr`**. By including this header, you gain access to these tools, which help manage dynamic memory automatically and safely in C++.

## RAII (Resource Acquisition Is Initialization)

**RAII (Resource Acquisition Is Initialization)** is a fundamental idiom in C++ that tightly couples resource management to object lifetime. It ensures that resources such as memory, file handles, sockets, or locks are properly acquired and released, making resource management robust and predictable.

### How RAII Works

1. **Resource Acquisition in the Constructor:**
    - A resource (e.g., memory, file handle) is acquired and initialized when an object is created.
    - The constructor ensures that the resource is properly initialized and ready to use.
2. **Resource Release in the Destructor:**

    - When the object goes out of scope or is destroyed, the destructor automatically releases the resource.
    - This ensures that resources are always cleaned up, even if an exception is thrown or control flow exits prematurely.

### Key Principles of RAII

1. **Scope-Bound Resource Management:**

    Resources are tied to the scope of an object. When the object goes out of scope, its resources are automatically released.

2. **Automatic Cleanup:**

    The cleanup is deterministic and guaranteed, as it occurs in the destructor. This eliminates the risk of forgetting to release resources.

3. **Encapsulation:**

    The logic for acquiring and releasing the resource is encapsulated within the object. The user of the object doesn't need to worry about these details.

### RAII and Smart Pointers

Smart pointers like **`std::unique_ptr`**, **`std::shared_ptr`**, and **`std::weak_ptr`** are prime examples of RAII in action:

- **Acquisition:** When a smart pointer is created, it takes ownership of a raw pointer (or dynamically allocated memory).
- **Release:** When the smart pointer goes out of scope, its destructor automatically deletes the raw pointer, ensuring no memory leaks.

#### Benefits of RAII

1. **Exception Safety:**

    RAII ensures that resources are released even if an exception is thrown. This eliminates resource leaks in error-prone code paths.

2. **Predictability:**

    Resource release happens deterministically in the destructor, ensuring that resources are always cleaned up in a timely manner.

3. **Simplified Resource Management:**

    Developers no longer need to remember to manually release resources, reducing the likelihood of errors.

4. **Encapsulation and Modularity:**

    Resource management logic is encapsulated in the object's constructor and destructor, making the code cleaner and easier to maintain.

## Unique Pointer `std::unique_ptr`

A **`std::unique_ptr`** is a smart pointer that manages the lifetime of a dynamically allocated object. The key feature of **`std::unique_ptr`** is that it follows the **single ownership** principle, meaning it ensures that only one **unique_ptr** can own a particular resource at any given time. This helps prevent memory leaks caused by multiple ownerships and manual memory management errors.

### Key Features of `std::unique_ptr`

1. **Simple Pointer:**
    - **`std::unique_ptr`** is a modern C++ smart pointer that wraps a raw pointer but adds safety and convenience in memory management.
2. **Single Ownership:**
    - It is designed so that a resource (e.g., a dynamically allocated object) is owned by only one **unique_ptr** at a time.
    - This prevents multiple smart pointers from deleting the same resource, avoiding **double delete** errors.
3. **Cannot Be Copied:**
    - A **`std::unique_ptr`** cannot be copied. This ensures that no two **unique_ptr** objects can point to the same resource, thus ensuring single ownership.
    - **Copying** would break ownership semantics, so any attempt to copy a **`std::unique_ptr`** results in a compile-time error.
4. **Can Be Moved:**
    - **`std::unique_ptr`** supports **move semantics**, which means it can be transferred from one **unique_ptr** to another using **`std::move`**.
    - After the move, the source **unique_ptr** becomes **null** and no longer owns the resource.

### Common Operations with `std::unique_ptr`

1. **Creating a `std::unique_ptr`:**

    A **unique_ptr** can be created by explicitly using the **`new`** keyword.

    ```cpp
    std::unique_ptr<int> ptr1(new int{100});  // Raw pointer with new
    ```

2. **Getting the Raw Pointer:**

    To access the raw pointer that **unique_ptr** is managing, you can use the **`get()`** method:

    ```cpp
    int* raw_ptr = ptr1.get();
    ```

    This returns the raw pointer, but you **should not delete** the object manually. The **unique_ptr** will handle that when it goes out of scope.

3. **Resetting the Pointer:**

    You can reset a **`std::unique_ptr`** to release ownership and set it to **`nullptr`**, freeing the managed resource:

    ```cpp
    ptr1.reset();  // Resets the unique_ptr, deletes the object, and sets to nullptr
    ```

4. **Moving Ownership:**

    When transferring ownership of a resource, you use **`std::move`**:

    ```cpp
    std::unique_ptr<int> ptr3 = std::move(ptr2);
    ```

    After this move, **`ptr2`** no longer owns the object and becomes null, while **`ptr3`** now owns the object.

### `std::make_unique`

**`std::make_unique`** is a safer and simpler way to create a **`std::unique_ptr`**. It was introduced in C++14 and eliminates the need to use **`new`** directly.

#### Key Points of `std::make_unique`

- **No new keyword:** You don’t have to manually use **`new`** to allocate memory. It’s done automatically.

    ```cpp
    auto ptr = std::make_unique<int>(100);
    ```

- **Exception Safety:** If an exception occurs during the object creation, **`std::make_unique`** ensures that memory is released properly, preventing memory leaks.

- **Cleaner Syntax:** It reduces boilerplate code compared to manually using new:

    ```cpp
    // Without make_unique
    std::unique_ptr<MyClass> ptr(new MyClass(arg1));

    // With make_unique
    auto ptr = std::make_unique<MyClass>(arg1);
    ```

### Example of Unique Pointers

```cpp
#include <iostream>
#include <memory>

class MyClass {
private:
    int x;
public:
    MyClass(int x) : x{x} {}
    void show() { std::cout << "x: " << x << std::endl; }

};

int main() {
    auto ptr = std::make_unique<MyClass>(10);
    ptr->show();  // Output: x: 10
}
```
