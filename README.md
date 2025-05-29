# 42 C++ Modules  C++️⃣

This repository contains my solutions for the C++ modules of the 42 School curriculum. These modules are designed to introduce and deepen understanding of C++ programming, from basic syntax to advanced concepts like templates, the Standard Template Library (STL), and Object-Oriented Programming (OOP).

## 📋 Table of Contents

- [About This Repository](#about-this-repository)
- [Core C++ Concepts Covered](#core-c-concepts-covered)
- [General Project Goals](#general-project-goals)
- [Installation & Compilation](#installation--compilation)
- [Project Structure](#project-structure)
- [Modules Overview](#modules-overview)
  - [Module 00: Namespaces, Classes, Member Functions, stdio Stream, Initialization Lists, Static, Const, and Lots of Basic Stuff](#module-00)
  - [Module 01: Memory Allocation, Pointers to Members, References, Switch](#module-01)
  - [Module 02: Ad-hoc Polymorphism, Operator Overloading and Orthodox Canonical Class Form](#module-02)
  - [Module 03: Inheritance](#module-03)
  - [Module 04: Subtype Polymorphism, Abstract Classes, Interfaces](#module-04)
  - [Module 05: Repetition and Exceptions](#module-05)
  - [Module 06: C++ Casts](#module-06)
  - [Module 07: C++ Templates](#module-07)
  - [Module 08: Templated Containers, Iterators, Algorithms](#module-08)
  - [Module 09: C++ Standard Template Library (Containers)](#module-09)
- [Testing](#testing)
- [Author](#author)
- [Notes](#notes)

## 🎯 About This Repository

This repository serves as a personal archive of my work through the 42 C++ Piscine. Each module (`ex00`, `ex01`, etc.) typically explores different facets of the C++ language, building upon previous knowledge. The primary focus is on understanding C++'s power, its differences from C, and best practices in modern C++ development.

## 🧠 Core C++ Concepts Covered

Throughout these modules, a wide range of C++ topics are explored, including but not limited to:

- **Basic Syntax and Namespaces**
- **Classes and Objects (OOP Fundamentals)**
    - Constructors (including copy constructors), Destructors
    - Member functions, `this` pointer
    - Encapsulation, Inheritance, Polymorphism
    - Access specifiers (public, private, protected)
- **Operator Overloading**
- **Orthodox Canonical Form (OCF)**
- **Memory Management** (`new`, `delete`)
- **Pointers, References, and Pointers to Members**
- **Static Members and Functions**
- **Constant Correctness (`const`)**
- **Inheritance (Single, Multiple, Virtual)**
- **Abstract Classes and Interfaces**
- **Exceptions and Error Handling**
- **Type Casting (static_cast, dynamic_cast, reinterpret_cast, const_cast)**
- **Templates (Function and Class Templates)**
- **The Standard Template Library (STL)**
    - Containers (e.g., `vector`, `list`, `map`, `stack`, `queue`, `set`)
    - Iterators
    - Algorithms

## ✨ General Project Goals

- Gain a solid understanding of Object-Oriented Programming principles.
- Master C++ syntax, memory management, and class design.
- Learn to use and appreciate the C++ Standard Library.
- Develop good coding habits, including const-correctness and exception safety.
- Understand the compilation process and use of Makefiles in C++ projects.

## 🚀 Installation & Compilation

Each module or exercise typically has its own `Makefile`.

1.  **Clone the repository:**
    ```bash
    git clone https://github.com/Marouane0107/cpp.git
    cd cpp
    ```

2.  **Navigate to a specific module/exercise directory:**
    ```bash
    cd module00/ex00 # Example
    ```

3.  **Compile the project using Makefile:**
    ```bash
    make
    ```
    This will usually create an executable (e.g., `program`, `app`, or named after the exercise).

    Common Makefile targets:
    ```bash
    # Clean object files
    make clean

    # Full clean (object files and executable)
    make fclean

    # Recompile
    make re
    ```

## 📁 Project Structure

The repository is generally structured by modules, and each module contains several exercises:

```
cpp/
├── module00/
│   ├── ex00/
│   │   ├── main.cpp
│   │   ├── SomeClass.cpp
│   │   ├── SomeClass.hpp
│   │   └── Makefile
│   ├── ex01/
│   │   └── ...
│   └── ...
├── module01/
│   └── ...
├── module02/
│   └── ...
...
├── module09/
│   └── ...
└── .gitignore
└── README.md
```

## 📚 Modules Overview

This section provides a brief overview of each C++ module.
*(You can fill in more details or specific challenges for each module as you progress or reflect on them.)*

### <a name="module-00"></a>Module 00: Namespaces, Classes, Member Functions, stdio Stream, Initialization Lists, Static, Const, and Lots of Basic Stuff
- **Focus:** Introduction to C++ syntax, classes, basic OOP concepts, and differences from C.
- **Key Topics:** `iostream` vs `stdio`, namespaces, class declaration and definition, member functions, `this` pointer, initialization lists, `static` members/functions, `const` correctness.
- **Example Exercises:** Simple class implementations, I/O handling.

### <a name="module-01"></a>Module 01: Memory Allocation, Pointers to Members, References, Switch
- **Focus:** Deeper dive into memory management in C++, references, and pointers to class members.
- **Key Topics:** `new` and `delete`, references, pointers to members, file streams.
- **Example Exercises:** Dynamic memory allocation, reference usage, simple data management.

### <a name="module-02"></a>Module 02: Ad-hoc Polymorphism, Operator Overloading and Orthodox Canonical Class Form
- **Focus:** Operator overloading and implementing classes in Orthodox Canonical Form (OCF).
- **Key Topics:** Ad-hoc polymorphism, overloading arithmetic and comparison operators, assignment operator, copy constructor, destructor. Fixed-point numbers.
- **Example Exercises:** Creating classes that behave like built-in types, ensuring OCF.

### <a name="module-03"></a>Module 03: Inheritance
- **Focus:** Understanding and implementing inheritance.
- **Key Topics:** Single inheritance, access specifiers in inheritance (`public`, `protected`, `private`), virtual inheritance (diamond problem).
- **Example Exercises:** Creating class hierarchies.

### <a name="module-04"></a>Module 04: Subtype Polymorphism, Abstract Classes, Interfaces
- **Focus:** Runtime polymorphism, abstract classes, and interfaces.
- **Key Topics:** `virtual` functions, pure `virtual` functions, abstract base classes (ABCs), interfaces.
- **Example Exercises:** Implementing polymorphic behavior, designing interfaces.

### <a name="module-05"></a>Module 05: Repetition and Exceptions
- **Focus:** Exception handling and advanced class design.
- **Key Topics:** `try`, `catch`, `throw`, standard exceptions, creating custom exceptions, Bureaucrat/Form exercises.
- **Example Exercises:** Implementing robust error handling, complex class interactions.

### <a name="module-06"></a>Module 06: C++ Casts
- **Focus:** Understanding and correctly using different C++ type casting operators.
- **Key Topics:** `static_cast`, `dynamic_cast`, `reinterpret_cast`, `const_cast`. Serialization.
- **Example Exercises:** Safely converting between types, data serialization.

### <a name="module-07"></a>Module 07: C++ Templates
- **Focus:** Generic programming using function and class templates.
- **Key Topics:** Function templates, class templates, template specialization.
- **Example Exercises:** Creating generic functions (e.g., `swap`, `min`, `max`) and data structures.

### <a name="module-08"></a>Module 08: Templated Containers, Iterators, Algorithms
- **Focus:** Deeper dive into templates with an emphasis on creating STL-like containers and understanding iterators and algorithms.
- **Key Topics:** Custom templated containers, iterators, basic algorithms (e.g., `easyfind`), `std::span` (or similar concepts).
- **Example Exercises:** Implementing a simple templated container, span, mutant stack.

### <a name="module-09"></a>Module 09: C++ Standard Template Library (Containers)
- **Focus:** Exploring and using various containers provided by the C++ Standard Template Library and advanced algorithms.
- **Key Topics:** `std::vector`, `std::map`, `std::stack`, `std::list`, `std::deque`, `std::set`. Reverse Polish Notation (RPN) calculator, Bitcoin exchange.
- **Example Exercises:** Solving problems using appropriate STL containers and algorithms.

## 🧪 Testing

Each exercise within a module typically comes with its own `main.cpp` or a set of instructions for testing.
- Compile the specific exercise using its `Makefile`.
- Run the resulting executable, often providing command-line arguments if required by the exercise.
- Compare output against expected results or subject requirements.
- Test edge cases and error conditions as specified or imagined.

## 👨‍💻 Author

**Marouane Aouzal** (Marouane0107)
- GitHub: [@Marouane0107](https://github.com/Marouane0107)
- UM6P-1337 Coding School Student

## 📝 Notes

- This repository reflects my learning journey through the 42 C++ modules.
- Adherence to the 42 School coding standards (Norminette, though often less strict for C++ than for C projects) and project-specific requirements is aimed for.
- The primary goal is to understand the concepts, not just to complete the exercises.
- All solutions are my own, developed as part of the 42 curriculum.

---

*Repository for 42 School C++ Modules.*

*Last Updated: 2024*
