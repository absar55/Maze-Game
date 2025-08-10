# 🎯🚀 Maze Game Pathfinding: Advanced BFS (A*) vs Dijkstra in Python & C++ 🚀🎯

<p align="center">
  <img src="https://img.shields.io/badge/Language-Python-blue?style=for-the-badge" />
  <img src="https://img.shields.io/badge/Language-C++-green?style=for-the-badge" />
  <img src="https://img.shields.io/badge/Algorithm-BFS-orange?style=for-the-badge" />
  <img src="https://img.shields.io/badge/Algorithm-Dijkstra-purple?style=for-the-badge" />
  <img src="https://img.shields.io/badge/Category-Pathfinding-yellow?style=for-the-badge" />
</p>

---

## 🧩 Project Overview

Welcome to the **Maze Game Pathfinding Algorithm Benchmark Project**, where we compare the efficiency and accuracy of two legendary algorithms — **Advanced Breadth-First Search (BFS)** and **Dijkstra's Algorithm** — in solving **mazes** in both **Python** and **C++**.

The **goal** is to identify which combination of algorithm + programming language gives the **best performance** for different maze configurations, considering **execution time, memory usage, and scalability**.

---

## 📝 Problem Statement

We are tasked with finding the shortest path in a maze from a given **start point** to an **exit point**. The maze is represented as a **graph**, where:

- **Each cell** → A **node**
- **Possible moves** → **Edges** between nodes

The challenge:  
➡ Implement **Advanced BFS** and **Dijkstra’s Algorithm** in both **Python** and **C++**, then **compare** them based on speed, memory efficiency, and scalability.

---

## 🔍 Algorithms at a Glance

### 1️⃣ Breadth-First Search (BFS)
- **Nature:** Explores neighbors layer-by-layer.
- **Optimality:** Guarantees shortest path in unweighted mazes.
- **Termination:** Stops as soon as the exit is found.
- **Data Structures Used:** Queue, visited set, parent mapping.
2️⃣ Advanced BFS (Optimized BFS)
Enhancements over standard BFS:

Early exit conditions when destination is reached.

Heuristics (A*-like prioritization) to guide search.

Efficient hashing for visited states.

Priority queues for exploration order.

Parallelization for large mazes.

Adaptive cost handling for varied cell types.

Benefits:
✅ Reduced search space
✅ Faster execution for complex mazes
✅ Memory optimization

3️⃣ Dijkstra's Algorithm
Nature: Single-source shortest path.

Optimality: Always finds shortest path for weighted/unweighted graphs.

Approach: Uses a priority queue to expand the least-cost node.

Best For: Weighted mazes, when all paths must be explored.

| Factor                  | Python 🐍                 | C++ ⚡                                  |
| ----------------------- | ------------------------- | -------------------------------------- |
| **Execution Speed**     | Slower for large mazes    | Extremely fast                         |
| **Memory Usage**        | Higher                    | Lower                                  |
| **Ease of Development** | Very easy                 | More complex                           |
| **Scalability**         | Limited                   | Excellent                              |
| **Best Use Case**       | Prototyping & small mazes | Large-scale, performance-critical apps |

📊 Performance Insights
1️⃣ Advanced BFS vs Dijkstra
Advanced BFS is faster for sparse mazes with fewer obstacles.

Dijkstra is better for weighted mazes or when exploring all paths is required.

2️⃣ Python vs C++
C++ consistently outperforms Python in speed & memory usage.

Python is easier to code & debug, great for quick experiments.


| Algorithm        | Time Complexity                 | Space Complexity |
| ---------------- | ------------------------------- | ---------------- |
| **BFS**          | O(V + E)                        | O(V)             |
| **Advanced BFS** | O(V + E) with heuristic speedup | O(V)             |
| **Dijkstra**     | O(E log V)                      | O(V + E)         |



MazePathfinding/
│── python/
│   ├── bfs.py
│   ├── advanced_bfs.py
│   ├── dijkstra.py
│── cpp/
│   ├── bfs.cpp
│   ├── advanced_bfs.cpp
│   ├── dijkstra.cpp
│── mazes/
│   ├── maze1.txt
│   ├── maze2.txt
│── benchmarks/
│   ├── results.csv
│── README.md


**Pseudocode:**
```plaintext
1. Initialize a queue with the start node
2. Mark start node as visited
3. While queue not empty:
    a. Dequeue current node
    b. If current == exit: break
    c. For each neighbor:
        - If not visited, mark visited, enqueue
4. Reconstruct path from start to exit
