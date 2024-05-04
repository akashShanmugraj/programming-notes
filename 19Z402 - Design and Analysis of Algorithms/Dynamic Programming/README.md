# Dynamic Programming Problems

## Multistage Graph Problem
For a Multistage Graph of N vertices, assume that we have edgeweight matrix of size `N * N`.

A `cost` matrix of size `1 * N` has minimum cost of every node to sink

A `nextnode` matrix of size `1 * N` has node from the next stage that gives the respective minimum cost

```
cost[n] = 0

FOR node = n - 1 TO 1 STEP -1
    mincost = edgeweight[node][0] + cost[0]
    minr = 0
    FOR ewindex = 0 TO LEN(edgeweight[node])
        IF edgeweight[node][ewindex] + cost[ewindex] < mincost:
            mincost = edgeweight[node][ewindex] + cost[ewindex]
            minr = ewindex
        
        cost[ewindex] = mincost
        nextnode[ewindex] = minr

path = [0, ]
pointer = 0

WHILE pointer <= 9:
    pointer = nextnode[pointer]
    path.append(pointer)
```

## All Pair Shortest Path / Floyd Warshall Algorithm

For a graph of N vertices, assume that we have edgeweight matrix of size `N * N`.
A cost matrix, which is a deep copy of the edgeweight matrix

```plaintext
FOR relaxindex = 0 TO n - 2:
    FOR row = 0 TO N - 1:
        FOR col = 0 to N - 1:
            cost[row][col] = MIN( cost[row][col], cost[row][relaxindex] + cost[relaxindex][col] )
```

### (Optional) Explanation
In this pseudocode, `relaxindex` is the intermediate vertex we're considering, and `row` and `col` are the start and end vertices of the path. 
For each pair of vertices `(row, col)`, we try to improve the shortest path between them by including `relaxindex` as an intermediate vertex in the path. 
If the path `row -> relaxindex -> col` is shorter than the current shortest path `row -> col`, we update the shortest path. We do this for all pairs of vertices for each possible intermediate vertex.