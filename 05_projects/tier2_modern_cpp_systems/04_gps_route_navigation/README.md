# 📁 Project 04: GPS Route Navigation Engine (Mini Google Maps)

## 📌 Project Overview
Build a GPS route navigation engine that models real-world road networks, finds the shortest and fastest travel paths between intersections, and compares the efficiency of **Dijkstra's Algorithm** vs **$A^*$ Search**.

---

## 🧠 Key Concepts & Algorithms
- **Graph Modeling**: Intersections as nodes, streets/highways as directed, weighted edges.
- **Euclidean & Manhattan Distance Heuristics**: Guiding the $A^*$ search towards the target destination.
- **Priority Queue (`std::priority_queue`)**: Efficiently expanding the most promising path candidates.
- **Performance Profiling**: Comparing the number of visited nodes in Dijkstra vs $A^*$.

---

## 🏗️ Architecture

```text
[Intersections / Road Network Graph]
               │
               ▼
   [User Input: Source & Destination]
               │
     ┌─────────┴─────────┐
     ▼                   ▼
 [Dijkstra]           [A* Search (with Heuristic)]
(Visits all layers)  (Directed toward target)
     │                   │
     └─────────┬─────────┘
               ▼
[Formatted Turn-by-Turn Route & Benchmark Comparison]
```

---

## 🎯 Step-by-Step Milestones
- [ ] **Milestone 1**: Define `LocationNode` (ID, Name, coordinates X and Y) and `Edge` (destination, distance, speed limit).
- [ ] **Milestone 2**: Implement graph loading from a text/CSV file of nodes and road connections.
- [ ] **Milestone 3**: Implement Dijkstra's algorithm to calculate the shortest path.
- [ ] **Milestone 4**: Implement the $A^*$ algorithm using Euclidean distance as the heuristic function.
- [ ] **Milestone 5**: Output turn-by-turn navigation instructions and benchmark: Compare execution time and nodes visited between Dijkstra and $A^*$.

