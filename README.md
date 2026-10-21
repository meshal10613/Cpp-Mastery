# C++ Programming with Bro Code 🚀

A comprehensive repository for notes, practice exercises, and projects based on the **Bro Code C++ Full Course**.

[![Course](https://img.shields.io/badge/Course-Bro%20Code%20C%2B%2B-red?logo=youtube)](https://youtu.be/-TkoO8Z07hI)
[![Language](https://img.shields.io/badge/Language-C%2B%2B17%20%2F%20C%2B%2B20-blue?logo=c%2B%2B)](https://en.cppreference.com/)
[![Compiler](https://img.shields.io/badge/Compiler-GCC%20%2F%20MinGW--w64-green)](https://www.msys2.org/)

---

## 📺 Course Resource

- **Video Tutorial**: [Bro Code - C++ Full Course for free Bro Code (YouTube)](https://youtu.be/-TkoO8Z07hI)

---

## 🛠️ Environment & Tools

- **Language**: C++ (C++17 / C++20 standard)
- **Compiler**: GCC / G++ (MSYS2 MinGW-w64 UCRT64)
- **Editor**: [Visual Studio Code](https://code.visualstudio.com/)
- **Recommended Extensions**:
  - [C/C++ (Microsoft)](https://marketplace.visualstudio.com/items?itemName=ms-vscode.cpptools)
  - [Code Runner](https://marketplace.visualstudio.com/items?itemName=formulahendry.code-runner)

---

## ⚡ How to Run

### Method 1: One-Click Run (Code Runner)
This project is pre-configured for one-click execution:
1. Open any `.cpp` or `.c` file (e.g., `main.cpp`).
2. Click the **▶ (Play button)** in the top-right corner of the editor, or press:
   ```text
   Ctrl + Alt + N
   ```
> [!NOTE]
> The configuration automatically saves your file, clears the terminal, and runs interactively in the terminal so `std::cin` works without freezing.

### Method 2: Integrated Terminal
Open a terminal in the project directory (`Ctrl + ~`) and run:

```bash
# Compile
g++ main.cpp -o main

# Run (Git Bash)
./main

# Run (PowerShell / Command Prompt)
.\main.exe
```

### Method 3: VS Code Build Task
Press `Ctrl + Shift + B` to trigger the pre-configured build task using `tasks.json`.

---

## 📂 Project Structure

Each lesson and practice exercise is structured into its own dedicated folder containing an independent, runnable `main.cpp`:

```text
C++ with Bro Code/
│
├── .vscode/                     # VS Code environment configurations
│   ├── c_cpp_properties.json    # IntelliSense & MSYS2 MinGW-w64 compiler path
│   ├── settings.json            # Code Runner one-click run & auto-save settings
│   └── tasks.json               # Default g++ build task
│
├── namespace/                   # 04. Namespaces
│   └── main.cpp                 # Identifier scope & collision prevention
│
├── operators/                   # 06. Arithmetic & Operators
│   └── main.cpp                 # Basic arithmetic & operator practice
│
├── typedef/                     # 05. typedef & Type Aliases
│   └── main.cpp                 # Type aliases using `typedef` and `using`
│
├── variable/                    # 02-03. Variables & Constants
│   └── main.cpp                 # Basic data types (int, double, char, bool, string) & const
│
├── .gitignore                   # Excludes compiled binaries (*.exe, *.out, *.o, *.obj)
├── README.md                    # Course documentation & progress checklist
└── main.cpp                     # Root playground / 01. Hello World starter
```

> [!TIP]
> **Modular Execution**: Because Code Runner is configured with `cd $dirWithoutTrailingSlash`, you can open `main.cpp` inside **any** subfolder and hit the **▶ Play button** (or `Ctrl + Alt + N`) to compile and run that specific lesson immediately!

---

## 📚 Course Progress & Topics

Track your progress through the course topics:

- [x] **01.** Hello World & Comments
- [x] **02.** Variables & Basic Data Types
- [x] **03.** The `const` Keyword
- [x] **04.** Namespaces
- [x] **05.** `typedef` & Type Aliases
- [x] **06.** Arithmetic Operators
- [x] **07.** Type Conversion
- [x] **08.** User Input (`std::cin` & `std::getline`)
- [x] **09.** Useful Math Functions (`<cmath>`)
- [x] **10.** 🎯 *Program: Hypotenuse Calculator*
- [x] **11.** If / Else Statements
- [x] **12.** Switch Statements
- [x] **13.** 🎯 *Program: Console Calculator*
- [x] **14.** Ternary Operator (`?:`)
- [x] **15.** Logical Operators (`&&`, `||`, `!`)
- [x] **16.** 🎯 *Program: Temperature Conversion*
- [x] **17.** Useful String Methods
- [x] **18.** While Loops
- [x] **19.** Do-While Loops
- [x] **20.** For Loops
- [x] **21.** Break & Continue
- [x] **22.** Nested Loops
- [x] **23.** Random Number Generator
- [x] **24.** Random Event Generator
- [x] **25.** 🎯 *Program: Number Guessing Game*
- [x] **26.** User-Defined Functions
- [x] **27.** Return Keyword
- [x] **28.** Function Overloading
- [x] **29.** Variable Scope (Local vs. Global)
- [x] **30.** 🎯 *Program: Banking System*
- [x] **31.** 🎯 *Program: Rock, Paper, Scissors*
- [x] **32.** Arrays
- [x] **33.** `sizeof` Operator
- [x] **34.** Iterating Over an Array
- [x] **35.** Foreach Loop (Range-based for)
- [x] **36.** Pass Array to a Function
- [x] **37.** Search an Array for an Element
- [x] **38.** Sort an Array (Bubble Sort)
- [x] **39.** `std::fill()` Function
- [x] **40.** Fill an Array with User Input
- [x] **41.** Multidimensional Arrays (2D Arrays)
- [x] **42.** 🎯 *Program: Quiz Game*
- [x] **43.** Memory Addresses
- [x] **44.** Pass by Value vs. Pass by Reference
- [x] **45.** `const` Parameters
- [x] **46.** 🎯 *Program: Credit Card Validator*
- [x] **47.** Pointers
- [x] **48.** Null Pointers (`nullptr`)
- [x] **49.** 🎯 *Program: Tic-Tac-Toe Game*
- [x] **50.** Dynamic Memory (`new` & `delete`)
- [x] **51.** Recursion
- [x] **52.** Function Templates
- [x] **53.** Structs
- [x] **54.** Pass Structs as Arguments
- [x] **55.** Enums
- [x] **56.** Object-Oriented Programming (Classes & Objects)
- [ ] **57.** Constructors
- [ ] **58.** Constructor Overloading
- [ ] **59.** Getters & Setters (Encapsulation)
- [ ] **60.** Inheritance
