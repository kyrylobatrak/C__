# C++ Learning and Coursework Repository

Welcome to my C++ repository! This project contains a comprehensive collection of C++ code, ranging from fundamental programming concepts to advanced Object-Oriented Programming (OOP) and Data Structures. The code is organized into different modules representing laboratory works, homework assignments, personal practice, competitive programming tasks, and tutorial follow-alongs.

## 📂 Repository Structure

The repository is divided into several main directories:

* **`Labparabola/` (Laboratory Works):** The core academic laboratory assignments divided by topics (Labs 1 through 21).
* **`HW/` (Homework Assignments):** Practical homework tasks (HW 1 through 20) complementing the lab sessions.
* **`myself/`:** Self-study exercises and practice codes divided by chapters/topics.
* **`youtube/`:** Code snippets and exercises written while following C++ video tutorials and courses.
* **`eolimp/`:** Solutions to algorithmic problems from the E-Olymp competitive programming platform.
* **`Lecture/`:** Code examples provided during theoretical lectures.

---

## 🔬 Detailed Breakdown of Laboratory Works (`Labparabola/`)

The `Labparabola` directory contains 21 laboratory assignments, gradually increasing in complexity. Here is an overview of the topics covered in each lab:

### Labs 1 - 9: Fundamentals of C++
These initial labs cover the building blocks of procedural programming in C++.
* **Basic Syntax & I/O:** Standard input/output, variables, and data types.
* **Control Structures:** `if/else` statements, `switch` cases, and loops (`for`, `while`, `do-while`).
* **Functions:** Declaration, definition, passing by value and by reference, recursion.
* **Arrays & Pointers:** 1D and 2D arrays, basic pointer arithmetic, and array manipulation.

### Lab 10: Structures and Introduction to Classes
* Introduction to custom data types.
* Creating structures (`struct`) and basic classes.
* Key examples: `chess10.2.cpp`, `date10.3.cpp`, `mountain10.5.cpp`, `rational10.4.cpp`.

### Lab 11: Classes, Methods, and File Processing
* Deep dive into Object-Oriented Programming basics.
* Constructors, destructors, and access modifiers (`public`, `private`).
* File filtering and data management.
* Key examples: `arrayutils`, `file_filter`, `polynomial`, `rectangle_manager`.

### Labs 12 - 14: Advanced Pointers and Memory Management
* Dynamic memory allocation (`new` and `delete`).
* Working with complex string manipulations and dynamically sized arrays.

### Lab 15: Operator Overloading
* Redefining the way C++ operators work with custom classes to write cleaner code.
* Key implementations:
    * `Point15.2` (Overloading coordinates)
    * `Polynomial15.3` (Math operations on polynomials)
    * `Rational15.1` (Fractions and rational number math)

### Lab 16: Aggregation, Composition, and Basic Inheritance
* Building complex objects using simpler ones.
* Key implementations: `Acquaintance`, `Person`, `PhoneDirectory`.

### Lab 17: Inheritance and Polymorphism (Class Hierarchies)
* Creating robust class hierarchies using base and derived classes.
* Virtual functions, overriding, and runtime polymorphism.
* Key implementation: A University hierarchy system involving `UniversityMember`, `Person`, `Student`, `Teacher`, and `Aspirant`.

### Labs 18 - 21: STL, Templates, and Advanced Concepts
* **Templates:** Writing generic functions and classes.
* **Standard Template Library (STL):** Utilizing standard containers like `std::vector` (e.g., `vector19.2.cpp`), iterators, and algorithms.
* Advanced data manipulation and code optimization.

---

## 📝 Homework Assignments (`HW/`)

The `HW` directory directly mirrors the progression of the labs with practical, real-world implementations. Notable projects include:
* **File Processors:** `file_processor11.9.cpp`, `luggage_processor11.11.cpp` (Handling I/O streams and file data).
* **Geometry Hierarchies:** `HW/16` contains a complete geometry implementation with base class `Figure` / `Polygon` and derived classes like `Triangle`, `Rectangle`, and `Pentagon`.
* **Time & Employee Management:** `employee10.13.cpp`, `time10.6.cpp` (Practicing encapsulation and class design).

---

## 🚀 How to Build and Run

This project uses **CMake** for build configuration. To compile the code:

1. Ensure you have a C++ compiler (GCC/Clang/MSVC) and `cmake` installed.
2. Open a terminal in the root directory of the repository.
3. Generate the build files:
   ```bash
   cmake -B build
