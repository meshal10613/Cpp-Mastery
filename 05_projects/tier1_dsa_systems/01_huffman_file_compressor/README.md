# 📁 Project 01: File Compressor (Huffman Coding)

## 📌 Project Overview
Build a command-line lossless file compression and decompression utility in C++ using **Huffman Coding**. The program should be able to take any text or binary file, compress it into a `.huff` archive, and decompress it back to the exact original file.

---

## 🧠 Key Data Structures & Concepts
- **Min-Heap (`std::priority_queue`)**: To repeatedly combine the two lowest-frequency nodes.
- **Binary Tree**: To build the prefix-free Huffman Tree.
- **Hash Map (`std::unordered_map`)**: To count character frequencies and map characters to binary bit strings.
- **Bit Manipulation**: Packing individual bits (0s and 1s) into 8-bit bytes for file output.
- **File I/O (`std::ifstream`, `std::ofstream`)**: Reading and writing raw binary streams with `ios::binary`.

---

## 🏗️ Architecture & Workflow

```text
[Input File] ──> [Frequency Count] ──> [Build Min-Heap] ──> [Build Huffman Tree]
                                                                     │
[Compressed File (.huff)] <── [Bitstream Packing] <── [Generate Prefix Bit Codes]
```

### Compressed File Format (`.huff`)
1. **Header**:
   - Number of unique characters (e.g. `size_t`).
   - Pairs of `(character, frequency)` so the tree can be reconstructed during decompression.
   - Total number of encoded characters (to handle the trailing padding bits in the last byte).
2. **Payload**:
   - The packed bitstream of Huffman codes.

---

## 🎯 Step-by-Step Milestones
- [ ] **Milestone 1**: Read an input file and build a byte frequency table (`unordered_map<unsigned char, int>`).
- [ ] **Milestone 2**: Build the Huffman Tree using a Min-Heap.
- [ ] **Milestone 3**: Traverse the tree to generate prefix codes (e.g., `'a' -> "010"`, `'e' -> "11"`).
- [ ] **Milestone 4**: Implement a `BitWriter` helper class that accumulates bits into a byte buffer and writes to disk.
- [ ] **Milestone 5**: Implement a `BitReader` helper class that reads bits one by one from the compressed file.
- [ ] **Milestone 6**: Decompress the file by traversing down the tree until reaching leaf nodes, restoring the original file.

