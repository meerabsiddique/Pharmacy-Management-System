# 💊 Pharmacy Management System

A console-based **Pharmacy Management System** developed in **C++** to demonstrate Object-Oriented Programming (OOP) concepts. 
The application manages different types of pharmacy items, calculates prices based on item type, and displays inventory information using runtime polymorphism.

---

## 📌 Project Overview

This project models a simple pharmacy inventory system where different categories of items are represented using inheritance. 
It demonstrates how abstract classes, virtual functions, dynamic memory allocation, and operator overloading can be used to build an extensible object-oriented application.

---

## ✨ Features

### 💊 Perishable Items
- Stores expiry date
- Checks whether an item has expired
- Sets the sale price to Rs. 0 for expired items

### 📦 Permanent Items
- Stores entry date
- Calculates depreciation based on item age
- Updates sale price automatically

### 📋 Bulk Items
- Inherits from Permanent Items
- Supports fixed-price and depreciating-price modes
- Stores additional item description

### 🏥 Pharmacy Inventory
- Add different types of pharmacy items
- Store all items using base class pointers
- Display complete inventory details
- Automatic memory management

---

## 🛠 Technologies Used

- C++
- Object-Oriented Programming
- Inheritance
- Polymorphism
- Abstract Classes
- Virtual Functions
- Dynamic Memory Allocation
- Operator Overloading

---


---

## ▶️ How to Run

1. Clone the repository

```bash
git clone https://github.com/yourusername/Pharmacy-Management-System.git
```

2. Open the project in Visual Studio, Code::Blocks, or any C++ IDE.

3. Compile and run the program.

---

## 📋 Classes Implemented

- Date
- Item (Abstract Base Class)
- Perishable
- Permanent
- Bulk_Item
- Pharmacy

---

## 📚 OOP Concepts Demonstrated

- ✅ Abstraction
- ✅ Inheritance
- ✅ Runtime Polymorphism
- ✅ Virtual Functions
- ✅ Pure Virtual Functions
- ✅ Dynamic Binding
- ✅ Dynamic Memory Allocation
- ✅ Constructors & Destructors
- ✅ Operator Overloading
- ✅ Composition

---

## 📌 Sample Output

The program displays:

- Item Name
- Original Price
- Sale Price
- Entry/Expiry Date
- Quantity
- Item Status
- Inventory Information

---

## 🎯 Learning Outcomes

This project helped strengthen understanding of:

- Designing class hierarchies
- Runtime polymorphism
- Memory management using `new` and `delete`
- Abstract class implementation
- Object-oriented design principles
- Date-based price calculations




## 📄 License

This project was developed for educational purposes as part of an Object-Oriented Programming course.
