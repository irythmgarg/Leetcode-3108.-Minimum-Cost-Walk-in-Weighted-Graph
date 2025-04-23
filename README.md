# Leetcode-3108.-Minimum-Cost-Walk-in-Weighted-Graph
# Minimum Cost Between Nodes Using Union-Find

This repository contains a C++ implementation of a Union-Find (Disjoint Set Union) based solution for computing the **minimum bitwise AND cost between connected nodes** in a graph.

## 🧠 Problem Statement
Given an undirected graph with `n` nodes (0-indexed) and weighted edges, determine for each query if two nodes are in the same connected component and return the **minimum possible bitwise AND** of edge weights in their component.

If the nodes are not connected, return -1.

## 🔍 Example
### Input:
```cpp
n = 5
edges = {{0, 1, 7}, {1, 2, 6}, {3, 4, 3}}
queries = {{0, 2}, {0, 3}, {3, 4}}
```
### Output:
```
[6, -1, 3]
```

## ⚙️ Approach
We use **Disjoint Set Union (DSU)** with path compression to group connected components and maintain the bitwise AND of costs within each component.

### Key Steps:
1. **Initialization**: Each node starts as its own parent with cost set to `-1` (all bits 1s).
2. **Union Operation**: Merge components and update the cost using `AND` logic.
3. **Find Operation**: Path compression for efficient lookups.
4. **Query**: If two nodes share a root, return the cost of the component, else return `-1`.

## 🧱 File Structure
```
├── Solution.cpp         # Main logic
├── README.md            # Explanation and documentation
```

## 🚀 How to Run
Use any C++ compiler. Example with g++:
```bash
g++ Solution.cpp -o solution
./solution
```
Use custom input setup or integrate into competitive coding platforms.

## ⏱️ Time & Space Complexity
- **Time Complexity**:
  - `find()` and `unite()` operations run in nearly **O(1)** due to path compression.
  - **Overall:** O(E + Q * α(N)), where E = edges, Q = queries, and α = inverse Ackermann function.

- **Space Complexity**: O(N) for parent and cost arrays.

## 📚 Concepts Used
- Union-Find (Disjoint Set Union)
- Path Compression
- Bitwise Operations

---
Made with ❤️ for efficient graph queries!

