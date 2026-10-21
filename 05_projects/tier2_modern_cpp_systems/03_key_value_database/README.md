# 📁 Project 03: In-Memory Key-Value Database (Mini-Redis)

## 📌 Project Overview
Build a lightweight, high-performance in-memory Key-Value database server/engine inspired by Redis. It features an interactive REPL command prompt, key expiration (TTL), disk persistence via Write-Ahead Logging (WAL), and modern C++23 error handling.

---

## 🧠 Key Concepts & Modern C++ Features
- **Modern C++23 Error Handling**: Using `std::expected<Success, Error>` instead of throwing exceptions.
- **In-Memory Storage**: `std::unordered_map<string, Entry>` where `Entry` stores the value, data type, and expiration timestamp.
- **Persistence (Write-Ahead Log / AOF)**: Appending operations to an append-only log file on disk using `<fstream>` so database state survives server restarts.
- **Interactive REPL Shell**: Command parsing, string tokenization, and formatted responses.

---

## 💻 Supported Commands

| Command | Arguments | Description | Example |
|---|---|---|---|
| `SET` | `key value [EX seconds]` | Stores a string value with optional TTL expiration | `SET user:1 Alice EX 60` |
| `GET` | `key` | Retrieves the stored value | `GET user:1` |
| `DEL` | `key` | Removes a key from the database | `DEL user:1` |
| `EXISTS`| `key` | Returns 1 if key exists, 0 otherwise | `EXISTS user:1` |
| `TTL` | `key` | Returns remaining time-to-live in seconds | `TTL user:1` |
| `SAVE` | None | Manually forces database snapshot to disk | `SAVE` |
| `EXIT` | None | Flushes state and shuts down | `EXIT` |

---

## 🎯 Step-by-Step Milestones
- [ ] **Milestone 1**: Implement core `SET`, `GET`, and `DEL` operations using `std::unordered_map`.
- [ ] **Milestone 2**: Implement TTL expiration logic (active cleanup and passive cleanup upon `GET`).
- [ ] **Milestone 3**: Add Write-Ahead Log (WAL) to persist commands to disk on every write.
- [ ] **Milestone 4**: Replay the WAL log on startup to restore in-memory state.
- [ ] **Milestone 5**: Build the interactive REPL CLI with clean status messages using `std::println`.

