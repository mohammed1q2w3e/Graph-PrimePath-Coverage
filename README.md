# Graph Prime Path Coverage (Educational Project)

This project was developed for **educational and training purposes** as part of the **Software Testing course**.  
The goal is to implement **Prime Path Coverage** using Depth-First Search (DFS) in graphs, which is a key concept in software testing to ensure comprehensive path coverage.

---

## 🎯 Project Objectives
- Practice applying **graph theory** concepts in C++.  
- Implement **DFS traversal** to extract all possible paths in a directed graph.  
- Identify **Prime Paths** (paths that are not subpaths of longer ones).  
- Construct **Test Paths** to achieve prime path coverage.  
- Gain hands-on experience with **Git/GitHub** for code management and sharing.  

---

## ⚙️ Project Components
- **Graph Class**:
  - `addEdge(u, v)` → Add edges between nodes.  
  - `getAllPaths()` → Extract all paths using DFS.  
  - `getPrime()` → Identify prime paths.  
  - `buildTests()` → Build test paths based on prime paths.  
  - `simpleDFS()` → Simple DFS to connect start and end nodes.  

- **Utilities**:
  - `isSub()` → Check if a path is a subpath of another.  
  - `printPaths()` → Print paths with titles.  

- **Main Program**:
  - Reads number of nodes and edges from user input.  
  - Generates all paths, prime paths, and test paths.  
  - Prints results clearly for analysis.  

---

## 🚀 How to Run
1. Compile the code:

Enter number of nodes: 4
Enter edges (u v), end with -1:
0 1
1 2
2 3
-1




Notes
This project is educational only and not intended for production use.

It was created as part of the Software Testing course to demonstrate path coverage techniques.

Future improvements could include:

Visualization of graphs.

Integration with testing frameworks.

🧑‍💻 Developer
Mohammed

Student in Software Testing, practicing C++ and graph theory concepts.
