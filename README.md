# Vehicle Rental Management System

A desktop application for managing vehicle rentals, built with **C++** and the **Qt Framework**.

## About

The Vehicle Rental Management System is an object-oriented desktop application that simulates the operations of a vehicle rental business. The project is being developed to strengthen my understanding of C++, Object-Oriented Programming (OOP), and GUI application development using Qt.

## Learning Objectives

This project is intended to reinforce the following concepts:

- Object-Oriented Programming (OOP)
- Encapsulation
- Inheritance
- Polymorphism
- Abstraction
- Composition
- GUI development with Qt Widgets
- Event-driven programming
- Modern C++ development
- Software design principles
- Version control with Git

## Planned Features

- Add, update, and remove vehicles
- Register and manage customers
- Rent vehicles to customers
- Process vehicle returns
- View available and rented vehicles
- Search for vehicles
- Save and load application data
- Input validation
- Rental history

## Object-Oriented Design

The project will begin with the following inheritance hierarchy:

```text
                Vehicle
                   ▲
          ┌────────┴────────┐
          │                 │
         Car          Motorcycle
```

### Vehicle (Base Class)

Common attributes shared by all vehicles:

- Make
- Model
- Year
- Registration Number
- Daily Rental Rate
- Availability Status

### Car (Derived Class)

Additional attributes may include:

- Number of Doors
- Fuel Type
- Transmission

### Motorcycle (Derived Class)

Additional attributes may include:

- Engine Capacity
- Has Sidecar

Additional classes such as `Customer`, `Rental`, and `RentalManager` will be introduced as the project grows.

## Technologies

- C++
- Qt Framework (Qt Widgets)
- CMake
- Git
- GitHub

## Project Status

🚧 Under Development

Development will be completed incrementally, with each milestone focusing on applying object-oriented programming principles before integrating the graphical user interface.

## Author

**Ivy**

BSc Mathematics and Computer Science Student

Building projects to strengthen C++, Qt, and software engineering skills.