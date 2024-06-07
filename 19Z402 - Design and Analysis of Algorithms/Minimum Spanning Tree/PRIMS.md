Prim's algorithm is a greedy algorithm that finds a minimum spanning tree (MST) for a connected, undirected graph with weighted edges. Here's a detailed explanation of the algorithm and a trace with an example:

### Prim's Algorithm Explanation

**Input**:
- A connected undirected graph \( G = (V, E) \) with edge weights \( w \).

**Output**:
- An array \( prev \) that defines the MST.

**Steps**:

1. **Initialization**:
   - For each vertex \( u \) in \( V \), set \( cost(u) \) to infinity and \( prev(u) \) to nil.
   - Pick an initial node \( u_0 \) and set \( cost(u_0) \) to 0.
   - Create a priority queue \( H \) that includes all vertices, using \( cost \) values as keys.

2. **Main Loop**:
   - While \( H \) is not empty:
     - Remove the vertex \( v \) with the smallest \( cost \) from \( H \).
     - For each neighbor \( z \) of \( v \):
       - If \( cost(z) \) is greater than \( w(v, z) \):
         - Update \( cost(z) \) to \( w(v, z) \).
         - Set \( prev(z) \) to \( v \).
         - Update the priority queue with the new \( cost(z) \).

**Detailed Steps**:

- **Initialization**:
  ```plaintext
  for all u ∈ V:
      cost(u) = ∞
      prev(u) = nil
  Pick any initial node u0
  cost(u0) = 0
  H = makequeue(V)
  ```

- **Main Loop**:
  ```plaintext
  while H is not empty:
      v = deletemin(H)
      for each {v, z} ∈ E:
          if cost(z) > w(v, z):
              cost(z) = w(v, z)
              prev(z) = v
              decreasekey(H, z)
  ```

### Example Trace

Consider the following graph \( G \):

```
   A --1-- B
   |     / |
   4   3   2
   | /     |
   C --5-- D
```

**Vertices**: \( V = \{A, B, C, D\} \)

**Edges with Weights**: \( E = \{ (A, B, 1), (A, C, 4), (B, C, 3), (B, D, 2), (C, D, 5) \} \)

**Initial Setup**:
- \( cost(A) = 0 \)
- \( cost(B) = ∞ \)
- \( cost(C) = ∞ \)
- \( cost(D) = ∞ \)
- Priority Queue \( H = \{A, B, C, D\} \)

### Trace Steps

1. **Select Initial Node**:
   - \( v = A \)
   - \( H = \{B, C, D\} \)
   - Update neighbors of \( A \):
     - \( B \): \( cost(B) = 1 \), \( prev(B) = A \)
     - \( C \): \( cost(C) = 4 \), \( prev(C) = A \)
   - Priority Queue \( H = \{B(1), C(4), D(\infty)\} \)

2. **Select Node with Minimum Cost**:
   - \( v = B \)
   - \( H = \{C, D\} \)
   - Update neighbors of \( B \):
     - \( C \): \( cost(C) = 3 \), \( prev(C) = B \)
     - \( D \): \( cost(D) = 2 \), \( prev(D) = B \)
   - Priority Queue \( H = \{C(3), D(2)\} \)

3. **Select Node with Minimum Cost**:
   - \( v = D \)
   - \( H = \{C\} \)
   - Update neighbors of \( D \):
     - No update required as \( C \) already has a lower cost.
   - Priority Queue \( H = \{C(3)\} \)

4. **Select Node with Minimum Cost**:
   - \( v = C \)
   - \( H = \{\} \)
   - All vertices have been processed.

**Final Arrays**:
- \( prev(A) = nil \)
- \( prev(B) = A \)
- \( prev(C) = B \)
- \( prev(D) = B \)

### Minimum Spanning Tree (MST)
The MST formed is:
- \( A --1-- B \)
- \( B --3-- C \)
- \( B --2-- D \)

### Explanation of MST

The algorithm constructs the MST by always adding the smallest possible edge that connects a new vertex to the growing tree. Starting from \( A \), the algorithm picks the smallest edge connected to \( A \), which is \( A-B \). Then, it picks the smallest edge connected to either \( A \) or \( B \), and so on, ensuring that no cycles are formed and the total weight of the tree is minimized.
