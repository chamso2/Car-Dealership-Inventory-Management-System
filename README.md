# Car-Dealership-Inventory-Management-System

## Overview
This project is a **Car Dealership Inventory Management System** developed in **C** as part of a term project supervised by **Dr. Falah Bouchaib** at **Al Akhawayn University**.

The goal of this project is to apply core concepts of **Dynamic Memory Allocation** and **Doubly Linked Lists** by building a console-based system that enables a car dealership to efficiently manage vehicle inventory records.

---
## Authors
Chaimae Aboulrhit (122215)
Housna Mounib (121932)

## Supervisor
Dr. Falah Bouchaib


## Learning Objectives
- Master **dynamic memory allocation** in C
- Implement and manipulate a **Doubly Linked List**
- Apply **file I/O operations**
- Design a **menu-driven console application**
- Handle **searching, insertion, deletion, and updates** in structured data

---

## Features
- **Load data from file** (`carList.txt`)
- **Display all cars** sorted alphabetically by make
- **Insert a new car** with unique Vehicle-ID validation
- **Update car details**, including cost and mileage
- **Delete a car** using its Vehicle-ID
- **Search functionality**:
  - By Vehicle-ID
  - By Make
  - By Year
  - By Cost
- **Persistent storage**, with all updates saved back to the file upon exit

---
## Program Flow
1. The user provides the file path (`carList.txt`)
2. Vehicle data is loaded into a doubly linked list
3. A menu-driven interface allows user interaction
4. All operations are applied in memory
5. Upon exit, the updated data is saved back to the file in sorted order

---

## Technologies Used
- **Programming Language:** C
- **Core Concepts:** Doubly Linked Lists, Dynamic Memory Allocation
- **File Handling:** Standard C I/O (`stdio.h`)
- **Platform:** Console-based application

---

## Data Structure
The system is implemented using a **Doubly Linked List**, where each node represents a vehicle:

```c
typedef struct Vehicle {
    int vehicle_ID;
    char make[50];
    char model[30];
    int year;
    int mileage;
    int cost;
    struct Vehicle *next;
    struct Vehicle *prev;
} Vehicle;

##Academic Note
This project was developed strictly for academic purposes and was demonstrated live in front of the instructor as required.

## Project Structure

├── src/
│   ├── main.c
│   ├── vehicle.c
│   ├── vehicle.h
│   ├── file_io.c
│   └── menu.c
├── data/
│   └── carList.txt
├── README.md





