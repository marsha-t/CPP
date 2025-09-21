# 42 C++ Modules (CPP00 – CPP09)

This repository contains my solutions for the 42 C++ Modules: these are 10 projects designed to introduce and deepen understanding of C++ programming concepts.  
Each module builds upon the previous, covering object-oriented programming, memory management, inheritance, polymorphism, templates, and the Standard Template Library (STL).

---

## Modules Overview

### CPP00 – Basics
- Introduction to C++ syntax and conventions
- Namespaces, classes, member functions
- Basic I/O 

### CPP01 – Memory, References, Pointers
- Stack vs heap allocation
- References and pointers
- New/delete

### CPP02 – Orthodox Canonical Form & Operator Overloading
- Orthodox canonical form (constructor, destructor, copy constructor, copy assignment operator)
- Operator overloading
- Fixed-point numbers implementation

### CPP03 – Inheritance
- Inheritance basics
- Constructors/destructors in inheritance chains
- Diamond problem introduction

### CPP04 – Polymorphism
- Abstract classes, interfaces
- Virtual functions and destructors
- Polymorphic behavior
- Deep vs shallow copies

### CPP05 – Bureaucracy
- Exceptions
- Nested classes

### CPP06 – Casting
- Static, dynamic, reinterpret, and const cast
- Serialization & deserialization
- RTTI

### CPP07 – Templates
- Function templates
- Class templates
- Generic programming

### CPP08 – Standard Template Library
- Standard Template Library: `std::vector`, `std::stack`, `std::map`, iterators
- Algorithms (e.g., `find`, `sort`)

### CPP09 – Advanced STL
- Parsing input
- Using STL containers and algorithms together
- Performance considerations

---

## How to Build & Run

Each exercise produces its own executable. Names are defined in the corresponding Makefile.

From inside an exercise folder:

```bash
make        # compile the program
./program   # run executable (name defined in Makefile)
make clean  # remove object files
make fclean # remove executables
make re     # rebuild

