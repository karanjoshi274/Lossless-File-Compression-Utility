# 📦 Lossless File Compressor

A powerful and efficient **command-line utility** built in **C++** for **lossless file compression and decompression** using the **Huffman Coding** algorithm. This tool is ideal for compressing text files and demonstrates strong foundations in **data structures**, **greedy algorithms**, and **binary file I/O**.

> 🔗 **GitHub Repository:** [https://github.com/karanjoshi274/Lossless-File-Compression-Utility.git](https://github.com/karanjoshi274/Lossless-File-Compression-Utility.git)

---

## 📚 Table of Contents

- [✨ Key Features](#-key-features)  
- [⚙️ How It Works](#-how-it-works)  
- [🧰 Technologies Used](#-technologies-used)  
- [🚀 Setup and Compilation](#-setup-and-compilation)  
- [💡 Usage](#-usage)  
- [📁 Project Structure](#-project-structure)  
- [📬 Contact](#-contact)  

---

## ✨ Key Features

- 🔹 **Efficient Compression:** Significant size reduction for repetitive data (like text files).
- 🔹 **Lossless Decompression:** Perfectly restores the original file.
- 🔹 **Low-Level Binary I/O:** Bit-level file handling for compact output.
- 🔹 **Cross-Platform:** Standard C++ ensures compatibility across OSes.
- 🔹 **Custom Format:** Stores tree/frequency map to enable accurate decompression.

---

## ⚙️ How It Works

1. **Frequency Analysis** – Counts frequency of each character.
2. **Min-Heap (Priority Queue)** – Stores nodes by frequency.
3. **Build Huffman Tree** – Combines nodes to form optimal prefix tree.
4. **Generate Codes** – Traverse tree to assign binary codes to characters.
5. **Compression** – Replace characters with binary codes, write output.
6. **Decompression** – Reconstruct tree, decode bits to retrieve original content.

---

## 🧰 Technologies Used

- **Language:** C++
- **Core Concepts:** Huffman Coding, Greedy Algorithms
- **Data Structures:** Min-Heap, Binary Tree, Hash Map
- **File I/O:** Binary read/write using `fstream`

---

## 🚀 Setup and Compilation

### ✅ Prerequisites

- A C++ compiler (e.g., `g++`)
- C++17 or later

### 🔧 Installation

Clone the Repository:

```bash
git clone https://github.com/karanjoshi274/Lossless-File-Compression-Utility.git
cd Lossless-File-Compression-Utility
```

Compile the Source Code:
```bash

g++ -o huffman_compressor main.cpp huffman.cpp -std=c++17
```
This creates an executable named huffman_compressor.

💡 Usage
Run the tool via command line with the following syntax:

📥 Compress a File
```bash
./huffman_compressor -c <input_file_path> <output_file_path>
```
Example:
```bash

./huffman_compressor -c notes.txt notes_compressed.huff
```
📤 Decompress a File
```bash
./huffman_compressor -d <compressed_file_path> <output_file_path>
```
Example:
```bash

./huffman_compressor -d notes_compressed.huff notes_restored.txt
```
📁 Project Structure
```bash
.
├── huffman_compressor      # Compiled executable
├── main.cpp                # Main function, argument parsing, file operations
├── huffman.h               # Header for Huffman class and node structure
├── huffman.cpp             # Core Huffman algorithm implementation
└── README.md               # Project documentation
```
### 📬 Contact
For feedback or questions, feel free to open an issue on the GitHub repository:
👉 https://github.com/karanjoshi274/Lossless-File-Compression-Utility.git


---

### ✅ Tips to Make It Work Perfectly:
- Make sure you're using a `.md` extension.
- Preview it on GitHub or VS Code's built-in Markdown preview.
- Don't mix tabs and spaces — stick to 2 or 4 spaces for indenting nested items.
- Always leave a blank line before/after code blocks, headings, or lists.

Let me know if you'd like this as a downloadable file or want to test it on GitHub Pages.
