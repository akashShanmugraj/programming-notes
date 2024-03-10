def printavailableedges(edgeobject):
    for entry in edgeobject:
        print(f"FROM NODE {entry[2]} TO NODE {entry[1]} WITH EDGE WEIGHT {entry[0]}")


graphobject = [
    [-1, 2, 3, 3, -1, -1, -1],
    [-1, -1, 4, -1, 3, -1, -1],
    [-1, -1, -1, 5, 1, -1, -1],
    [-1, -1, -1, -1, -1, 7, -1],
    [-1, -1, -1, -1, -1, 8, -1],
    [-1, -1, -1, -1, -1, -1, 9],
    [-1, -1, -1, -1, -1, -1, -1],
]

startingnode = 0
totalnodes = 7

visited = [
    startingnode,
]
spanningtree = []
availableedges = []

while len(visited) != totalnodes:
    for node in visited:
        for column in range(0, 7):
            if column in visited or graphobject[node][column] == -1:
                continue

            availableedges.append([graphobject[node][column], column, node])

    minimumedge = min(availableedges)
    spanningtree.append([minimumedge[1], minimumedge[2]])
    visited.append(minimumedge[1])
    printavailableedges(
        [
            minimumedge,
        ]
    )
    print(visited)
    availableedges.clear()

    print("\n\n")
