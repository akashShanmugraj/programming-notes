from typing import List


def issafe(color: int, node: int, adjacencymatrix: List[List[int]]):
    for edgein in range(len(adjacencymatrix[node])):
        if (
            adjacencymatrix[node][edgein] == -1
            and adjacencymatrix[edgein][edgein] == color
        ):
            return False
    return True


def printcolorednodes(am, refhm):
    for i in range(len(am)):
        print(f"{i} - {refhm.get(am[i][i])}")
    print("\n\n")

def colornode(node: int, adjmatrix: List[List[int]], totalcolors: int):

    if node == len(adjmatrix[0]):
        printcolorednodes(adjmatrix, referencehashmap)
        return

    allcolors = list(range(1, totalcolors + 1))
    colorablecolors = []

    for color in allcolors:
        if issafe(color, node, adjmatrix):
            colorablecolors.append(color)

    for color in colorablecolors:
        adjmatrix[node][node] = color
        colornode(node + 1, adjmatrix, totalcolors)
        adjmatrix[node][node] = 0


adjmatrix = [
    [0, -1, -1, 0, 0],
    [-1, 0, 0, -1, -1],
    [-1, 0, 0, -1, 0],
    [0, -1, -1, 0, -1],
    [0, -1, 0, -1, 0],
]

referencehashmap = {1: "Red", 2: "Green", 3: "Yellow"}

colornode(0, adjmatrix, 3)
