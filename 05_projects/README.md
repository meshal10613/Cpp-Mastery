# 🚀 C++ Portfolio Projects Roadmap

This directory contains real-world, industry-standard project blueprints designed to consolidate your C++ knowledge, apply core Data Structures & Algorithms, and build a resume-worthy portfolio.

---

## 📂 Project Categories

```text
05_projects/
│
├── tier1_dsa_systems/                    # 🛠️ Tier 1: DSA-Centric Systems Projects
│   ├── 01_huffman_file_compressor/       # Binary Trees, Min-Heap, Bit Manipulation, File I/O
│   └── 02_lru_cache_engine/              # Doubly Linked List, Hash Table, O(1) Eviction Policy
│
└── tier2_modern_cpp_systems/             # ⚡ Tier 2: Real-World Modern C++ Systems
    ├── 03_key_value_database/            # In-Memory KV Store with TTL, Persistence & C++23
    ├── 04_gps_route_navigation/          # Graph Pathfinding, Dijkstra/A*, Geo-Routing
    └── 05_text_editor_piece_table/       # Piece Table Data Structure (VS Code text buffer engine)
```

---

## 🏆 Project Summaries

### Tier 1: DSA-Centric Systems Projects
1. **[Huffman File Compressor](file:///e:/C++/C++%20with%20Bro%20Code/05_projects/tier1_dsa_systems/01_huffman_file_compressor/)**
   - **Data Structures**: Min-Heap (`std::priority_queue`), Binary Tree, Hash Map.
   - **What you learn**: How file compression works at the byte and bit level, reading/writing raw binary streams, tree serialization, and prefix-free encoding.
2. **[LRU Cache Engine](file:///e:/C++/C++%20with%20Bro%20Code/05_projects/tier1_dsa_systems/02_lru_cache_engine/)**
   - **Data Structures**: Hash Map (`std::unordered_map`) + Doubly Linked List (`std::list`).
   - **What you learn**: Designing $O(1)$ lookup, insert, and eviction policies used in web browsers, Redis, and operating system page tables.

---

### Tier 2: Real-World Modern C++ Systems
3. **[In-Memory Key-Value Database](file:///e:/C++/C++%20with%20Bro%20Code/05_projects/tier2_modern_cpp_systems/03_key_value_database/)**
   - **Data Structures & Features**: Hash table storage, TTL (Time-To-Live) expiration, Write-Ahead Logging (WAL) for file persistence, interactive CLI.
   - **What you learn**: Command parsing, RAII file persistence, smart pointers, and modern C++23 error handling (`std::expected`).
4. **[GPS Route Navigation Engine](file:///e:/C++/C++%20with%20Bro%20Code/05_projects/tier2_modern_cpp_systems/04_gps_route_navigation/)**
   - **Data Structures**: Weighted Graphs, Priority Queues, Dijkstra & $A^*$ Search with Euclidean distance heuristics.
   - **What you learn**: Modeling real-world road networks, calculating shortest travel paths, and benchmark comparisons between Dijkstra and $A^*$.
5. **[Text Editor Buffer Engine (Piece Table)](file:///e:/C++/C++%20with%20Bro%20Code/05_projects/tier2_modern_cpp_systems/05_text_editor_piece_table/)**
   - **Data Structures**: Piece Table buffer (Original immutable buffer, Add buffer, sequence of pieces), Undo/Redo stacks.
   - **What you learn**: How professional text editors (like VS Code) handle gigabyte-sized files without lagging or allocating giant contiguous strings.

---

## 💡 How to Approach These Projects

1. Read the dedicated `README.md` inside each project folder for full specifications, architecture diagrams, and milestones.
2. Open `main.cpp` in each folder to review the provided starter skeleton, function contracts, and `// TODO:` implementation steps.
3. Implement one milestone at a time, test with edge cases, and push your commits to GitHub to build your developer portfolio!

