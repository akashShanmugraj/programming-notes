def allpairsshortestpath(edgeweightmatrix, totaledges):    
    for relaxnode in range(totaledges):
        for row in range(totaledges):
            for col in range(totaledges):
                edgeweightmatrix[row][col] = min(edgeweightmatrix[row][col], edgeweightmatrix[row][relaxnode] + edgeweightmatrix[relaxnode][col])
    
    return edgeweightmatrix

edgeweight = [
    [0, 5, float('inf'), 10],
    [float('inf'), 0, 3, float('inf')],
    [float('inf'), float('inf'), 0, 1],
    [float('inf'), float('inf'), float('inf'), 0]
]

shortest_paths = allpairsshortestpath(edgeweight, len(edgeweight))

for row in shortest_paths:
    print(row)