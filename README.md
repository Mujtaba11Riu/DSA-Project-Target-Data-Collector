name: Target Data Collector

description: >
  Target Data Collector is a C++ console-based Data Management System 
  using a Binary Search Tree (BST) to efficiently store, search, 
  and manage personal information of individuals. Designed for tracking, 
  referencing, and analyzing user data in an organized manner.

features:
  - Insert Records: Add new individuals with Name, Age, and Address
  - Search Records: Quickly search for a person by name
  - Display Records: Show all records in sorted order using inorder traversal
  - Remove Records: Safely remove a person handling leaf, one-child, and two-children nodes
  - Duplicate Prevention: Ensures no two entries share the same name

technology:
  - C++
  - Binary Search Tree (BST)
  - Console-based interface

project_structure: |
  Target-Data-Collector/
    ├── Person.h         # Struct for storing personal info
    ├── TreeNode.h       # Node class for BST
    ├── Tree.h           # BST class with all operations
    ├── Tree.cpp         # Implementation of BST operations
    └── main.cpp         # Demo usage & testing

usage:
  steps:
    - Clone the repository: git clone <repo-url>
    - Compile the code: g++ main.cpp Tree.cpp -o TargetDataCollector
    - Run the program: ./TargetDataCollector
    - Insert, search, display, or delete user records through console menu

sample_output: |
  Inorder Traversal:
  Name: Ali
  Age: 22
  Address: Islamabad

  Name: Ahmed
  Age: 25
  Address: Lahore

  Name: Zain
  Age: 21
  Address: Karachi

  Searching Ahmed:
  Found

  Searching Faizan:
  Not Found

notes:
  - Data is stored in memory and not in external files
  - Designed for learning and simulation purposes
  - Prevents duplicate names to maintain data integrity

cyber_security_relevance: >
  Demonstrates organized data storage, search, and access control. 
  Efficiently managing personal information while ensuring proper handling 
  and retrieval simulates real-world secure data management practices.
