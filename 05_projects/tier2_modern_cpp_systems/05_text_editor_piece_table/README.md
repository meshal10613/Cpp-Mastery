# 📁 Project 05: Text Editor Buffer Engine (Piece Table)

## 📌 Project Overview
Build a high-performance **Piece Table text buffer engine**, the exact core data structure used in production text editors like **Visual Studio Code** and **Sublime Text** to open and edit massive files in real time with instantaneous Undo/Redo.

---

## 🧠 Why Not a Simple `std::string`?
If you store a 100 MB file inside a simple `std::string`, typing a single character at the start of the file forces the computer to **shift 100 million characters in memory** ($O(N)$ copy). The editor will freeze!

The **Piece Table** solves this:
- **Original Buffer**: The initial file loaded into memory (Read-Only, never modified).
- **Add Buffer**: All newly typed characters are appended to the end of an append-only string.
- **Pieces Sequence**: A linked list or vector of lightweight spans/pieces:
  `{BufferSource (ORIGINAL or ADD), offset, length}`.

Inserting or deleting text simply splits or removes pieces—**zero characters are shifted or reallocated**!

---

## 🏗️ Architecture

```text
Original Buffer (Immutable):  "The quick brown fox jumps over the lazy dog"
Add Buffer (Append-only):     "really "

Piece Table Sequence:
[Piece 1: Original, offset: 0, length: 16]  --> "The quick brown "
[Piece 2: Add,      offset: 0, length: 7]   --> "really "
[Piece 3: Original, offset: 16, length: 27] --> "fox jumps over the lazy dog"

Resulting Document: "The quick brown really fox jumps over the lazy dog"
```

---

## 🎯 Step-by-Step Milestones
- [ ] **Milestone 1**: Define `enum BufferType { ORIGINAL, ADD }` and `struct Piece`.
- [ ] **Milestone 2**: Implement `insert(position, text)`: Splits the target piece into two, inserts a new piece pointing to the appended text in the Add buffer.
- [ ] **Milestone 3**: Implement `deleteText(position, length)`: Adjusts piece boundaries or removes pieces entirely without altering raw buffers.
- [ ] **Milestone 4**: Implement `getText()` to reconstruct the full document text by iterating through pieces.
- [ ] **Milestone 5**: Implement instant `undo()` and `redo()` by maintaining a history stack of piece lists!

