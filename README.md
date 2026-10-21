# C++ Programming: From Basics to Modern C++23 🚀

A comprehensive repository containing complete notes, runnable practice exercises, games, and advanced modules spanning the **Bro Code C++ Full Course** (Completed ✅) and the **Advanced & Modern C++23 Roadmap** (In Progress 🎯).

[![Course](https://img.shields.io/badge/Course-Bro%20Code%20C%2B%2B%20(Completed)-brightgreen?logo=youtube)](https://youtu.be/-TkoO8Z07hI)
[![Language](https://img.shields.io/badge/Language-C%2B%2B23%20%2F%20C%2B%2B20-blue?logo=c%2B%2B)](https://en.cppreference.com/)
[![Compiler](https://img.shields.io/badge/Compiler-GCC%2016%20%2F%20MSYS2%20UCRT64-orange)](https://www.msys2.org/)
[![Status](https://img.shields.io/badge/Phase%201-100%25%20Completed-success)]()
[![Status](https://img.shields.io/badge/Phase%202-Active%20Roadmap-blue)]()

---

## 📺 Course & Learning Resources

- **Phase 1 (Completed)**: [Bro Code - C++ Full Course for free (YouTube)](https://youtu.be/-TkoO8Z07hI)
- **Phase 2 (Advanced Topics)**: Modern C++ Standards ([cppreference.com](https://en.cppreference.com/w/cpp/23)), STL Deep-Dive, Smart Pointers, and C++23 features.

---

## 🛠️ Environment & Tools

- **Language Standard**: C++23 (`-std=c++23`)
- **Compiler**: GCC / G++ 16.1+ (MSYS2 MinGW-w64 UCRT64)
- **Editor**: [Visual Studio Code](https://code.visualstudio.com/)
- **Recommended Extensions**:
  - [C/C++ (Microsoft)](https://marketplace.visualstudio.com/items?itemName=ms-vscode.cpptools)
  - [Code Runner](https://marketplace.visualstudio.com/items?itemName=formulahendry.code-runner)
  - [Better Comments](https://marketplace.visualstudio.com/items?itemName=aaron-bond.better-comments) (Highlights `//?` questions and `//*` key concepts)

---

## ⚡ How to Run

### Method 1: One-Click Run (Code Runner) — *Recommended*
This repository is pre-configured with C++23 (`-std=c++23 -lstdc++exp`):
1. Open any `.cpp` file (e.g., `vectors/01_vector_basics/main.cpp` or `modern_cpp23/01_std_print/main.cpp`).
2. Click the **▶ (Play button)** in the top-right corner of the editor, or press:
   ```text
   Ctrl + Alt + N
   ```
> [!NOTE]
> VS Code automatically navigates into the active file's folder, compiles with GCC using C++23, and runs interactively in your terminal so `std::cin` works seamlessly without freezing.

### Method 2: Integrated Terminal
Open an integrated terminal (`Ctrl + ~`) in any lesson directory and run:

```bash
# Compile with C++23 support
g++ -std=c++23 main.cpp -lstdc++exp -o main

# Run (PowerShell / Command Prompt)
.\main.exe

# Run (Git Bash / MSYS2)
./main.exe
```

### Method 3: VS Code Build Task
Press `Ctrl + Shift + B` on any active file to trigger the pre-configured default build task defined in `.vscode/tasks.json`.

---

## 📂 Repository Structure

The repository is organized into two primary phases: **Phase 1 (Foundations & OOP)** and **Phase 2 (Advanced & Modern C++23)**:

```text
C++ with Bro Code/
│
├── .vscode/                                  # Configured IDE settings & build tasks
│   ├── c_cpp_properties.json                 # IntelliSense & C++23 standard config
│   ├── settings.json                         # Code Runner C++23 executor mapping
│   └── tasks.json                            # Default GCC C++23 build task
│
├── ══════════════════════════════════════════
│   PHASE 2: ADVANCED & MODERN C++23
│   (New Topics & Modular Learning)
│   ══════════════════════════════════════════
│
├── vectors/                                  # 🚀 Vectors (Dynamic Arrays)
│   ├── 01_vector_basics/main.cpp             # Access, size vs capacity, reserve & shrink
│   ├── 02_vector_operations/main.cpp         # push/emplace_back, insert, erase, iterators, sort
│   └── 03_2d_vectors/main.cpp                # 2D matrices, jagged arrays, airplane seating demo
│
├── polymorphism/                             # 🎭 Polymorphism (Static & Dynamic)
│   ├── 01_compile_time_polymorphism/main.cpp # Function & operator overloading (+, ==, <<)
│   ├── 02_virtual_functions_override/main.cpp# Dynamic binding, virtual, override, vtable
│   ├── 03_abstract_classes_interfaces/main.cpp# Pure virtual functions (=0), payment interfaces
│   └── 04_virtual_destructors/main.cpp       # Virtual destructors & memory leak prevention
│
├── stl/                                      # 📦 Standard Template Library (STL)
│   ├── 01_sequence_containers/main.cpp       # std::vector, std::deque, std::list, std::array
│   ├── 02_associative_containers/main.cpp    # std::set, multiset, std::map, multimap (Red-Black trees)
│   ├── 03_unordered_containers/main.cpp      # std::unordered_map & unordered_set (Hash tables)
│   ├── 04_container_adapters/main.cpp        # std::stack (LIFO), queue (FIFO), priority_queue
│   ├── 05_stl_algorithms/main.cpp            # <algorithm> (sort, binary_search, find, transform)
│   └── 06_iterators_and_lambdas/main.cpp     # Advance/next/prev iterators & modern lambdas
│
├── smart_pointers/                           # 🧠 Modern Smart Pointers & Memory Management
│   ├── 01_unique_ptr/main.cpp                # std::make_unique, exclusive ownership, move semantics
│   ├── 02_shared_ptr/main.cpp                # std::make_shared, ref-counting, shared ownership
│   ├── 03_weak_ptr/main.cpp                  # std::weak_ptr, circular reference prevention, .lock()
│   └── 04_raii_and_custom_deleters/main.cpp  # RAII scoped patterns & custom deleters (FILE*, lambdas)
│
├── modern_cpp23/                             # ⚡ Modern C++20 / C++23 Features
│   ├── 01_std_print/main.cpp                 # C++23 <print> (std::print, std::println, formatting)
│   ├── 02_ranges_and_views/main.cpp          # <ranges> pipe composition, filter, transform, chunk, slide
│   ├── 03_expected_and_optional/main.cpp     # C++23 std::expected<T, E> & monadic std::optional
│   ├── 04_concepts_and_constraints/main.cpp  # C++20/23 <concepts>, requires clauses, type constraints
│   └── 05_deducing_this/main.cpp             # C++23 explicit object parameter, recursive lambdas
│
├── ══════════════════════════════════════════
│   PHASE 1: BRO CODE C++ FULL COURSE
│   (Foundations & Core OOP — Completed ✅)
│   ══════════════════════════════════════════
│
├── variable/ ... abstraction/                # 01-60. Core course topics
├── console_calculator/                       # 🎯 Mini-project: Calculator
├── hypotenuse_calculator/                    # 🎯 Mini-project: Hypotenuse Calculator
├── temperature_conversion/                   # 🎯 Mini-project: Temperature Conversion
├── number_guessing_game/                     # 🎯 Mini-project: Number Guessing Game
├── banking_system/                           # 🎯 Mini-project: Banking System
├── rock_paper_scissors_game/                 # 🎯 Mini-project: Rock, Paper, Scissors
├── quiz_game/                                # 🎯 Mini-project: Quiz Game
├── credit_card_validator/                    # 🎯 Mini-project: Credit Card Validator
├── tic_tac_toe_game/                         # 🎯 Mini-project: Tic-Tac-Toe Game
│
├── .gitignore                                # Excludes compiled binaries (*.exe, *.o, etc.)
└── README.md                                 # Course documentation & progress roadmap
```

---

## 📚 Learning Roadmap & Checklists

### 🎓 Phase 1: Bro Code C++ Full Course (Completed ✅)

- [x] **01.** Hello World & Comments (`main.cpp`)
- [x] **02.** Variables & Basic Data Types (`variable/`)
- [x] **03.** The `const` Keyword (`const/`)
- [x] **04.** Namespaces (`namespace/`)
- [x] **05.** `typedef` & Type Aliases (`typedef/`)
- [x] **06.** Arithmetic Operators (`operators/`)
- [x] **07.** Type Conversion (`type_conversion/`)
- [x] **08.** User Input (`user_input/`)
- [x] **09.** Useful Math Functions (`math/`)
- [x] **10.** 🎯 *Program: Hypotenuse Calculator* (`hypotenuse_calculator/`)
- [x] **11.** If / Else Statements (`if_statements/`)
- [x] **12.** Switch Statements (`switch/`)
- [x] **13.** 🎯 *Program: Console Calculator* (`console_calculator/`)
- [x] **14.** Ternary Operator (`ternery_operator/`)
- [x] **15.** Logical Operators (`logical_operators/`)
- [x] **16.** 🎯 *Program: Temperature Conversion* (`temperature_conversion/`)
- [x] **17.** Useful String Methods (`string_methods/`)
- [x] **18.** While Loops (`while_loops/`)
- [x] **19.** Do-While Loops (`do_while_loops/`)
- [x] **20.** For Loops (`for_loops/`)
- [x] **21.** Break & Continue (`for_loops/`)
- [x] **22.** Nested Loops (`nested_loops/`)
- [x] **23.** Random Number Generator (`random_number_generator/`)
- [x] **24.** Random Event Generator (`random_event_generator/`)
- [x] **25.** 🎯 *Program: Number Guessing Game* (`number_guessing_game/`)
- [x] **26.** User-Defined Functions (`function/`)
- [x] **27.** Return Keyword (`function/`)
- [x] **28.** Function Overloading (`overloaded_functions/`)
- [x] **29.** Variable Scope (Local vs. Global) (`function/`)
- [x] **30.** 🎯 *Program: Banking System* (`banking_system/`)
- [x] **31.** 🎯 *Program: Rock, Paper, Scissors* (`rock_paper_scissors_game/`)
- [x] **32.** Arrays (`arrays/`)
- [x] **33.** `sizeof` Operator (`sizeof_operator/`)
- [x] **34.** Iterating Over an Array (`iterate_an_array/`)
- [x] **35.** Foreach Loop (`for_each_loop/`)
- [x] **36.** Pass Array to a Function (`pass_array_in_function/`)
- [x] **37.** Search an Array for an Element (`search_in_array/`)
- [x] **38.** Sort an Array (Bubble Sort) (`bubble_sort/`)
- [x] **39.** `std::fill()` Function (`fill_function/`)
- [x] **40.** Fill an Array with User Input (`fill_array_with_input/`)
- [x] **41.** Multidimensional Arrays (2D Arrays) (`multidimensional_array/`)
- [x] **42.** 🎯 *Program: Quiz Game* (`quiz_game/`)
- [x] **43.** Memory Addresses (`memory_addresses/`)
- [x] **44.** Pass by Value vs. Pass by Reference (`pass_by_value_vs_pass_by_reference/`)
- [x] **45.** `const` Parameters (`pass_by_value_vs_pass_by_reference/`)
- [x] **46.** 🎯 *Program: Credit Card Validator* (`credit_card_validator/`)
- [x] **47.** Pointers (`pointers/`)
- [x] **48.** Null Pointers (`null_pointers/`)
- [x] **49.** 🎯 *Program: Tic-Tac-Toe Game* (`tic_tac_toe_game/`)
- [x] **50.** Dynamic Memory (`dynamic_memory/`)
- [x] **51.** Recursion (`recursion/`)
- [x] **52.** Function Templates (`function_templates/`)
- [x] **53.** Structs (`structs/`)
- [x] **54.** Pass Structs as Arguments (`pass_structs_as_arguments/`)
- [x] **55.** Enums (`enums/`)
- [x] **56.** Object-Oriented Programming (`oop/`)
- [x] **57.** Constructors (`constructors/`)
- [x] **58.** Constructor Overloading (`overloaded_constructors/`)
- [x] **59.** Abstraction & Encapsulation (`abstraction/`)
- [x] **60.** Inheritance (`inheritance/`)

---

### 🚀 Phase 2: Advanced Topics & Modern C++23 Roadmap

#### 1. Vectors (Dynamic Arrays)
- [ ] **V1.** Vector Basics, Memory Layout & Sizing (`vectors/01_vector_basics/`)
- [ ] **V2.** Modifiers, Algorithms & Iterator Traversal (`vectors/02_vector_operations/`)
- [ ] **V3.** 2D Matrices & Dynamic Jagged Vectors (`vectors/03_2d_vectors/`)

#### 2. Polymorphism & OOP Mastery
- [ ] **P1.** Compile-Time Polymorphism: Operator & Function Overloading (`polymorphism/01_compile_time_polymorphism/`)
- [ ] **P2.** Run-Time Polymorphism: `virtual`, `override`, and VTables (`polymorphism/02_virtual_functions_override/`)
- [ ] **P3.** Abstract Base Classes & Pure Interfaces (`polymorphism/03_abstract_classes_interfaces/`)
- [ ] **P4.** Virtual Destructors & Polymorphic Memory Safety (`polymorphism/04_virtual_destructors/`)

#### 3. Standard Template Library (STL)
- [ ] **S1.** Sequence Containers: `vector`, `deque`, `list`, `array` (`stl/01_sequence_containers/`)
- [ ] **S2.** Associative Containers: `set`, `multiset`, `map`, `multimap` (`stl/02_associative_containers/`)
- [ ] **S3.** Unordered Containers: `unordered_map` & `unordered_set` (Hash Tables) (`stl/03_unordered_containers/`)
- [ ] **S4.** Container Adapters: `stack`, `queue`, `priority_queue` (`stl/04_container_adapters/`)
- [ ] **S5.** STL Algorithms: `<algorithm>` & `<numeric>` (`stl/05_stl_algorithms/`)
- [ ] **S6.** Modern Iterators & Lambda Expressions (`stl/06_iterators_and_lambdas/`)

#### 4. Smart Pointers & Memory Management
- [ ] **SP1.** `std::unique_ptr` & Exclusive Ownership (`smart_pointers/01_unique_ptr/`)
- [ ] **SP2.** `std::shared_ptr` & Reference Counting (`smart_pointers/02_shared_ptr/`)
- [ ] **SP3.** `std::weak_ptr` & Breaking Circular Dependencies (`smart_pointers/03_weak_ptr/`)
- [ ] **SP4.** RAII Idiom & Custom Deleters (`smart_pointers/04_raii_and_custom_deleters/`)

#### 5. Modern C++20 & C++23 Features
- [ ] **M1.** `std::print` & `std::println` from `<print>` (`modern_cpp23/01_std_print/`)
- [ ] **M2.** Ranges & Views Pipeline Composition (`modern_cpp23/02_ranges_and_views/`)
- [ ] **M3.** Functional Error Handling with `std::expected` & Monadic `std::optional` (`modern_cpp23/03_expected_and_optional/`)
- [ ] **M4.** Concepts & Constraints with `<concepts>` & `requires` (`modern_cpp23/04_concepts_and_constraints/`)
- [ ] **M5.** C++23 Explicit Object Parameter ("Deducing this") & Recursive Lambdas (`modern_cpp23/05_deducing_this/`)

---

## 💡 Tips for Learning

1. **Active Coding**: Each lesson contains runnable demonstration code followed by a **📝 Practice Challenge** at the bottom of `main.cpp`. Try implementing the challenge before moving to the next topic!
2. **Experimentation**: Change inputs, test boundary conditions, and observe how compiler warnings or exceptions behave.
3. **Check Off Your Progress**: Keep updating the checkboxes (`[ ]` ➔ `[x]`) in this README as you complete each topic!
