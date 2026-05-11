Markdown
# 📦 Inventory Management System

> A console-based Inventory Management System written in **C**. Add, view, update, and delete inventory items — all managed through a structured terminal interface using structures and arrays.

---

## 🗂️ Table of Contents

- [About](#about)
- [Features](#features)
- [Getting Started](#getting-started)
- [Usage](#usage)
- [Limitations](#limitations)
- [File Structure](#file-structure)
- [Future Plans](#future-plans)

---

## 📖 About

This project is an **Inventory Management System** built in C. Inventory items are managed through an interactive terminal menu using structures and arrays.

The program demonstrates:
- Structures
- Arrays
- Function pointers
- Menu-driven programming
- Basic input validation

Built and tested on **Android using CxxDroid**.

---

## ✨ Features

| Feature | Description |
|---|---|
| ➕ Add Items | Add inventory items with quantity |
| 📋 View Inventory | Display all stored inventory items |
| 🗑️ Delete Items | Remove items by matching item name |
| ✏️ Update Items | Modify existing inventory items |
| 🧠 Function Pointer Menu | Uses function pointers for menu navigation |
| 🖥️ Terminal UI | Uses cursor positioning and formatted layout |

---

## 🚀 Getting Started

### Prerequisites

- A C compiler such as **GCC**
- Linux/macOS terminal, **MinGW** on Windows, or **CxxDroid** on Android

### Compilation

```bash
gcc INVENTORY.c -o inventory
```

Run
```Bash
./inventory
```

🖥️ Usage
On launch, the main menu appears:

----------------------INVENTORY MENU----------------------

1. ADD ITEM
2. VIEW INVENTORY
3. UPDATE ITEM
4. DELETE ITEM
5. EXIT

Enter an option:

Item Data Format
Each inventory item stores:
Item Name-Quantity
```
Example:

Keyboard - Quantity: 5
Mouse - Quantity: 2
```
⚠️ Limitations

1. No Permanent Storage:

Inventory data is stored only during runtime. All data is lost after program termination.

2. Fixed Inventory Size:

Maximum inventory capacity is limited using:

```
#define MAX_ITEMS 100
```
3. Exact Name Matching

Deletion requires exact item name matching using strcmp().
Example:

```
Laptop ≠ laptop
```
4.Update Feature Incomplete:

updateItem() is still under development and currently acts as a placeholder.

📁 File Structure
```
.
├── INVENTORY.c    # Main source file
└── README.md      # Documentation
```
🔮 Future Plans:

[1] Add file handling for permanent storage

[2] Improve update item functionality

[3] Add search feature

[4] Add case-insensitive matching

[5] Improve UI formatting

[6] Modularize into multiple files

👤 Author
```
Adrish Datta
```
Made with ❤️ in C by Adrish Datta | Built on Android 📱
