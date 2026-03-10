# C++ Calculator Project

## Overview

A simple calculator application written in **C++** using **CMake**.
Designed as a **console application** with clean, modular code using separate header (`.h`) and implementation (`.cpp`) files.

This project demonstrates:

* Modular C++ code structure (`include/` and `src/`)
* Building projects with **CMake**
* Using shell scripts to automate build and run processes
* Version control and project organization for GitHub

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

---


