# C++ Calculator Project

## Overview

A simple calculator application written in **C++** using **CMake**.
Supports basic arithmetic operations: addition, subtraction, multiplication, and division.
Designed as a **console application** with clean, modular code using separate header (`.h`) and implementation (`.cpp`) files.

This project demonstrates:

* Modular C++ code structure (`include/` and `src/`)
* Building projects with **CMake**
* Using shell scripts to automate build and run processes
* Version control and project organization for GitHub

---

## Features

* Addition, subtraction, multiplication, division
* Handles division by zero gracefully
* Easily extendable to GUI or more advanced operations
* Clean separation of **interface (header)** and **implementation (cpp)**

---

## Project Structure

```
calc_app/
├── CMakeLists.txt     # CMake build configuration
├── build.sh           # Script to build project
├── run.sh             # Script to run executable
├── include/           # Header files
│   └── calculator.h
└── src/               # Implementation files
    ├── calculator.cpp
    └── main.cpp
.gitignore
README.md
```

---

## Build and Run

1. Make sure you have **CMake** and a **C++ compiler** installed.
2. Build the project:

```bash
./build.sh
```

3. Run the calculator:

```bash
./run.sh
```

4. Input format:

```
<number> <operator> <number>
Example: 5 + 3
```

---

## License

This project is released under the **MIT License**. Feel free to use, modify, and distribute.

---
