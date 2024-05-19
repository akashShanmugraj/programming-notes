def multistagegraph(edgeweight, totaledges):
    cost = [float('inf')] * totaledges
    nextnode = [0] * totaledges
    cost[totaledges - 1] = 0
    
    for node in range(totaledges - 2, -1, -1):
        mincost = float('inf')
        minedge = 0
        for outgoingedge in range(totaledges):
            tempcost = edgeweight[node][outgoingedge] + cost[outgoingedge]
            if tempcost < mincost:
                mincost = tempcost
                minedge = outgoingedge
        
        cost[node] = mincost
        nextnode[node] = minedge
            
    return cost, nextnode


edgeweight = [
    [0, 1, 2, 5, float('inf'), float('inf'), float('inf'), float('inf')],
    [float('inf'), 0, float('inf'), float('inf'), 4, 11, float('inf'), float('inf')],
    [float('inf'), float('inf'), 0, float('inf'), 9, 5, 16, float('inf')],
    [float('inf'), float('inf'), float('inf'), 0, float('inf'), float('inf'), 2, float('inf')],
    [float('inf'), float('inf'), float('inf'), float('inf'), 0, float('inf'), float('inf'), 18],
    [float('inf'), float('inf'), float('inf'), float('inf'), float('inf'), 0, float('inf'), 13],
    [float('inf'), float('inf'), float('inf'), float('inf'), float('inf'), float('inf'), 0, 2],
    [float('inf'), float('inf'), float('inf'), float('inf'), float('inf'), float('inf'), float('inf'), 0]
]

print(multistagegraph(edgeweight, len(edgeweight)))