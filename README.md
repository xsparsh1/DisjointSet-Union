# DisjointSet-Union-CPP

This repository contains an implementation of the **Disjoint Set Union (DSU)** or **Union-Find** data structure in C++.

### Features
- Union by Size
- Path Compression
- Nearly constant time operations - O(4(α))   α - Aplha
- Simple and clean OOP design

### Concepts Covered
- Graph components
- Union-Find data structure
- Optimized merging and parent tracking

### Example Usage
```cpp
DisjoinSet ds(7);
ds.unionBySize(0, 1);
ds.unionBySize(1, 3);
if (ds.ultimateParent(4) == ds.ultimateParent(3))
    cout << "Same Component";
else
    cout << "Different Components";

```

### Compile & Run
- g++ DisjointSet.cpp -o DisjointSet
- ./DisjointSet


Author
- Sparsh Tyagi
- https://www.linkedin.com/in/sparsh-tyagi-19502b33b/
- https://github.com/xsparsh1