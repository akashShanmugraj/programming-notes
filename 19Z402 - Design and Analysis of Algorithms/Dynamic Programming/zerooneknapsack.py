def knapSack(maxWeight, weights, values, numItems):
    print(numItems, max)
    knapSackTable = []
    for item in range(numItems + 1):
        row = []
        for weight in range(maxWeight + 1):
            row.append(0)
        knapSackTable.append(row)
             
    # Build table knapSackTable[][] in bottom up manner
    for item in range(numItems + 1):
        for weight in range(maxWeight + 1):
            if item == 0 or weight == 0:
                knapSackTable[item][weight] = 0
            elif weights[item - 1] <= weight:
                knapSackTable[item][weight] = max(values[item - 1]
                  + knapSackTable[item - 1][weight - weights[item - 1]],
                               knapSackTable[item - 1][weight])
            else:
                knapSackTable[item][weight] = knapSackTable[item - 1][weight]
 
    return knapSackTable[numItems][maxWeight]
 
# Test the function
values = [60, 100, 120]
weights = [10, 20, 30]
maxWeight = 50
numItems = len(values)
 
print(knapSack(maxWeight, weights, values, numItems))


