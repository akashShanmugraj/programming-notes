# Dijkstra's Algorithm

Dijkstra's Algorithm is a popular algorithm for finding the shortest path between nodes in a graph. It was conceived by computer scientist Edsger W. Dijkstra in 1956.

Here's a high-level overview of how it works:

1. The algorithm starts at the source node (a node of your choosing), where the "distance" is zero. The distances to all other nodes are set to infinity initially.

2. The algorithm then repeatedly visits the unvisited node with the smallest current known distance from the source.

3. For the current node, consider all of its unvisited neighbors and calculate their tentative distances. Compare the newly calculated tentative distance to the current assigned value and assign the smaller one.

4. After we've visited all the neighbors of the current node, mark the current node as visited. A visited node will not be checked again.

5. The process continues until all the nodes in the graph have been visited.

The algorithm uses a priority queue to select the unvisited node with the smallest distance, and it uses a process of relaxation, where the tentative distance to a node is gradually replaced by more accurate values until the shortest path is eventually found.

# Python Implementation

## using MinHeaps

Reference Image:
<img width="808" alt="Dijkstra Reference Image" src="https://github.com/akashShanmugraj/programming-notes/assets/65720968/07f8ae9d-7508-4ea1-9893-5716ffdcaf92">

```python
from heapq import heapify, heappush, heappop

adjacencymatrix = [
    [0, 10, 3, -1, -1],
    [-1, 0, -1, 2, -1],
    [-1, 4, 0, 8, 2],
    [-1, -1, -1, 0, 5],
    [-1, -1, -1, -1, 0],
]

rowcount = len(adjacencymatrix)
columncount = len(adjacencymatrix[0])

startnode = 0
visited = [
    0,
]
edgelist = []
currentnode = startnode
path = []

while len(visited) != rowcount:
    for ein in range(columncount):
        if adjacencymatrix[currentnode][ein] != -1 and ein not in visited:
            heappush(
                edgelist,
                (
                    adjacencymatrix[currentnode][ein],
                    [currentnode, ein],
                ),
            )

    currentnode = edgelist[0][1][1]
    visited.append(edgelist[0][1][1])
    path.append(edgelist.pop(0))

print(path)
```