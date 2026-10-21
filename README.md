# C++ Mastery: Basics ➔ Modern C++23 ➔ DSA ➔ Systems Projects 🚀

A structured, production-grade learning repository tracking the complete journey from **C++ Fundamentals (Bro Code)** to **Modern C++23**, **Data Structures & Algorithms (DSA)**, and **Industry-Standard Software Projects**.

[![Course](https://img.shields.io/badge/Foundations-Bro%20Code%20C%2B%2B%20(Completed)-brightgreen?logo=youtube)](https://youtu.be/-TkoO8Z07hI)
[![Language](https://img.shields.io/badge/Standard-C%2B%2B23%20%2F%20C%2B%2B20-blue?logo=c%2B%2B)](https://en.cppreference.com/)
[![Compiler](https://img.shields.io/badge/Compiler-GCC%2016%20%2F%20MinGW--w64-orange)](https://www.msys2.org/)
[![DSA](https://img.shields.io/badge/DSA-Core%20Patterns%20Implemented-success)]()
[![Projects](https://img.shields.io/badge/Projects-5%20System%20Blueprints-purple)]()

---

## 📂 Master Repository Architecture

The repository is organized into five structured progression phases:

```text
C++ with Bro Code/
│
├── 📁 01_bro_code_basics/           # Phase 1: Complete Bro Code Beginner Foundations (Completed ✅)
│   ├── hello_world/ ... abstraction/ # 56 Topics & 9 Mini-Projects (Calculator, Games, etc.)
│
├── 📁 02_intermediate_modern_cpp/   # Phase 2: Advanced OOP, STL, Smart Pointers & Modern C++23
│   ├── vectors/                      # 01_basics, 02_operations, 03_2d_vectors
│   ├── polymorphism/                 # 01_overloading, 02_virtual_override, 03_interfaces, 04_virtual_destructors
│   ├── stl/                          # 01_sequence, 02_associative, 03_unordered, 04_adapters, 05_algorithms, 06_lambdas
│   ├── smart_pointers/               # 01_unique_ptr, 02_shared_ptr, 03_weak_ptr, 04_raii_custom_deleters
│   └── modern_cpp23/                 # 01_std_print, 02_ranges_views, 03_expected_optional, 04_concepts, 05_deducing_this
│
├── 📁 03_dsa_bridge/                # Step 1: Theoretical & Practical Foundations Before DSA
│   ├── 01_big_o_and_complexity/      # Big-O benchmarks (O(1), O(log N), O(N), O(N^2)) & CPU limits
│   ├── 02_stl_complexity_cheatsheet/ # Vector vs List cache locality & Map vs Unordered_Map
│   ├── 03_recursion_and_call_stack/  # Visualizing stack frames, base cases, and stack unwinding
│   └── 04_memory_and_pass_by_reference/ # Benchmarking pass-by-value vs pass-by-const-ref (TLE prevention)
│
├── 📁 04_dsa_core/                  # Step 2: Essential Data Structures & Algorithmic Patterns
│   ├── 01_arrays_and_strings/        # Prefix Sum, Two Pointers, Sliding Window, Kadane's Algorithm
│   ├── 02_linked_lists/              # In-Place Reversal, Floyd's Cycle Detection (Tortoise & Hare)
│   ├── 03_stacks_and_queues/         # Monotonic Stack (Next Greater Element), O(1) MinStack
│   ├── 04_binary_search_and_sorting/ # Binary Search, Lower Bound, Merge Sort (Divide & Conquer)
│   ├── 05_trees_and_bst/             # Binary Tree BFS (Level-Order), DFS, BST, Lowest Common Ancestor
│   ├── 06_heaps_and_priority_queues/ # Min/Max Heaps, Top-K Elements, Custom Task Scheduler
│   ├── 07_graphs/                    # Adjacency List, BFS, DFS, Dijkstra's Shortest Path
│   └── 08_dynamic_programming/       # 1D DP (Climbing Stairs, Coin Change), 2D DP (0/1 Knapsack)
│
└── 📁 05_projects/                  # Real-World Portfolio Systems Projects (Uncompleted Skeletons)
    ├── tier1_dsa_systems/            # DSA-Centric Systems
    │   ├── 01_huffman_file_compressor/ # Lossless File Compression (Min-Heap, Prefix Tree, Bit I/O)
    │   └── 02_lru_cache_engine/      # O(1) LRU Cache (Hash Map + Doubly Linked List + TTL)
    └── tier2_modern_cpp_systems/     # Modern C++ Systems
        ├── 03_key_value_database/    # Mini-Redis with TTL, Persistence & C++23 std::expected
        ├── 04_gps_route_navigation/  # GPS Engine (Dijkstra vs A* Search on Road Networks)
        └── 05_text_editor_piece_table/ # VS Code Piece Table Buffer Engine (Fast Insert/Undo)
```

---

## ⚡ How to Run Any Lesson

### 1. One-Click Execution (Code Runner)
This workspace is pre-configured with **C++23** (`-std=c++23 -lstdc++exp`):
1. Open any `.cpp` file in VS Code.
2. Click the **▶ (Play Button)** in the top-right corner, or press:
   ```text
   Ctrl + Alt + N
   ```
> [!NOTE]
> VS Code automatically changes directory (`cd`) to the active file's folder, compiles using GCC 16, and launches the binary interactively in your integrated terminal.

### 2. Manual Command Line
```bash
# Compile any file with C++23 standard
g++ -std=c++23 main.cpp -lstdc++exp -o main

# Run executable (Windows PowerShell)
.\main.exe
```

---

## 🗺️ Progression Roadmaps & Checklists

### 🎓 01. Bro Code C++ Full Course (Completed ✅)
All 56 beginner-to-intermediate topics and mini-projects are archived inside [`01_bro_code_basics/`](file:///e:/C++/C++%20with%20Bro%20Code/01_bro_code_basics/):
- [x] Basic syntax, variables, `const`, namespaces, `typedef`, and operators.
- [x] Control flow (If/Else, Switch, Ternary, While, For, Nested loops).
- [x] Functions, scope, recursion, and function templates.
- [x] Arrays (1D, 2D, searching, bubble sort, passing to functions).
- [x] Pointers, memory addresses, dynamic memory (`new`/`delete`), and structs/enums.
- [x] Core OOP (Classes, constructors, overloading, encapsulation, inheritance).
- [x] 9 Mini-Projects (Banking System, Tic-Tac-Toe, Credit Card Validator, Quiz Game, etc.).

---

### 🚀 02. Intermediate & Modern C++23 Roadmap
Located in [`02_intermediate_modern_cpp/`](file:///e:/C++/C++%20with%20Bro%20Code/02_intermediate_modern_cpp/):

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
- [ ] **S3.** Unordered Containers: `unordered_map` & `unordered_set` (`stl/03_unordered_containers/`)
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

### 🌉 03. The Bridge Before DSA (Step 1)
Located in [`03_dsa_bridge/`](file:///e:/C++/C++%20with%20Bro%20Code/03_dsa_bridge/):
- [ ] **B1. Big-O Complexity & Limits** (`01_big_o_and_complexity/`): Benchmarks for $O(1)$ through $O(N^2)$ and CP time-limit constraints ($10^8$ operations/sec).
- [ ] **B2. STL Complexity & Cache Locality** (`02_stl_complexity_cheatsheet/`): Why `std::vector` contiguous memory outperforms node-based `std::list`.
- [ ] **B3. Recursive Call Stack** (`03_recursion_and_call_stack/`): Tracing push/pop stack frames, base cases, and stack overflow limits.
- [ ] **B4. Memory & Pass-by-Reference** (`04_memory_and_pass_by_reference/`): Eliminating silent $O(N)$ copy overhead with `const &`.

---

### 🧠 04. Core Data Structures & Algorithms (Step 2)
Located in [`04_dsa_core/`](file:///e:/C++/C++%20with%20Bro%20Code/04_dsa_core/):
- [ ] **D1. Arrays & Strings** (`01_arrays_and_strings/`): Prefix Sum, Two Pointers, Sliding Window, Kadane's Maximum Subarray.
- [ ] **D2. Linked Lists** (`02_linked_lists/`): In-place node reversal and Floyd's Cycle Detection (Tortoise and Hare).
- [ ] **D3. Stacks & Queues** (`03_stacks_and_queues/`): Monotonic Stack (Next Greater Element) and $O(1)$ MinStack.
- [ ] **D4. Binary Search & Sorting** (`04_binary_search_and_sorting/`): Overflow-safe Binary Search, Lower Bound, Merge Sort.
- [ ] **D5. Trees & BST** (`05_trees_and_bst/`): Level-order BFS queue traversal, BST insertion/search, Lowest Common Ancestor (LCA).
- [ ] **D6. Heaps & Priority Queues** (`06_heaps_and_priority_queues/`): Kth Largest Element in $O(N \log K)$ and custom task schedulers.
- [ ] **D7. Graphs** (`07_graphs/`): Adjacency list representation, BFS layer traversal, Dijkstra's Shortest Path algorithm.
- [ ] **D8. Dynamic Programming** (`08_dynamic_programming/`): 1D DP (Climbing Stairs, Coin Change) and 2D DP (0/1 Knapsack).

---

### 🏆 05. Portfolio Systems Projects Roadmap
Located in [`05_projects/`](file:///e:/C++/C++%20with%20Bro%20Code/05_projects/):

#### Tier 1: DSA-Centric Systems
- [ ] **Project 1: Huffman File Compressor** ([`tier1_dsa_systems/01_huffman_file_compressor/`](file:///e:/C++/C++%20with%20Bro%20Code/05_projects/tier1_dsa_systems/01_huffman_file_compressor/))
  - Uses Min-Heap, Prefix Tree, and bitstream packing for lossless compression.
- [ ] **Project 2: High-Performance LRU Cache Engine** ([`tier1_dsa_systems/02_lru_cache_engine/`](file:///e:/C++/C++%20with%20Bro%20Code/05_projects/tier1_dsa_systems/02_lru_cache_engine/))
  - Combines Hash Map and Doubly Linked List for guaranteed $O(1)$ cache operations and eviction.

#### Tier 2: Real-World Modern C++ Systems
- [ ] **Project 3: In-Memory Key-Value Database (Mini-Redis)** ([`tier2_modern_cpp_systems/03_key_value_database/`](file:///e:/C++/C++%20with%20Bro%20Code/05_projects/tier2_modern_cpp_systems/03_key_value_database/))
  - Implements REPL CLI, TTL key expiration, Write-Ahead Logging (WAL) persistence, and C++23 `std::expected`.
- [ ] **Project 4: GPS Route Navigation Engine** ([`tier2_modern_cpp_systems/04_gps_route_navigation/`](file:///e:/C++/C++%20with%20Bro%20Code/05_projects/tier2_modern_cpp_systems/04_gps_route_navigation/))
  - Road network graph pathfinding with Dijkstra vs $A^*$ Search using Euclidean distance heuristics.
- [ ] **Project 5: Text Editor Buffer Engine (Piece Table)** ([`tier2_modern_cpp_systems/05_text_editor_piece_table/`](file:///e:/C++/C++%20with%20Bro%20Code/05_projects/tier2_modern_cpp_systems/05_text_editor_piece_table/))
  - Production text buffer data structure (VS Code engine) for instantaneous editing and Undo/Redo.
