# 📁 Project 02: High-Performance LRU Cache Engine

## 📌 Project Overview
Build a generic, high-performance in-memory **LRU (Least Recently Used) Cache** engine in C++ with guaranteed **$O(1)$ constant time** for both `get()` and `put()` operations.

---

## 🧠 Key Data Structures & Concepts
- **Doubly Linked List (`std::list` or custom `Node` list)**: Maintains the recency order of items (most recently used at the front, least recently used at the back).
- **Hash Map (`std::unordered_map<Key, list::iterator>`)**: Maps keys directly to nodes/iterators in the linked list for $O(1)$ instant lookup.
- **Templates (`template <typename K, typename V>`)**: To support any data type as key and value.
- **Thread Safety (`std::mutex`, `std::unique_lock`)**: Protect concurrent access in multi-threaded environments.
- **Eviction Policy**: When capacity is exceeded, automatically evict the item at the tail in $O(1)$ time.

---

## 🏗️ Architecture & Operations

```text
               Most Recent <-----------------------> Least Recent
                    [Head] <-> [Node A] <-> [Node B] <-> [Tail] (Evicted first)
                      ▲           ▲            ▲
                      │           │            │
Hash Map:          {"keyA"}    {"keyB"}     {"keyC"}
```

- **`get(key)`**:
  1. Check if key exists in hash map. If not, return `-1` / `nullopt`.
  2. Move the accessed node to the **front** (head) of the list.
  3. Return the value.
- **`put(key, value)`**:
  1. If key already exists: update value and move node to the **front**.
  2. If key is new:
     - If capacity is full: remove node at the **back** (tail) from both the list and the hash map.
     - Insert new node at the **front** and store its iterator in the hash map.

---

## 🎯 Step-by-Step Milestones
- [ ] **Milestone 1**: Implement the base `LRUCache` class with capacity and core `get` / `put` methods.
- [ ] **Milestone 2**: Verify $O(1)$ performance with a benchmark test of 100,000 insertions/lookups.
- [ ] **Milestone 3**: Add TTL (Time-To-Live) support so keys expire after a specified duration.
- [ ] **Milestone 4**: Make the cache thread-safe using `std::shared_mutex` (allowing multiple readers or one writer).

