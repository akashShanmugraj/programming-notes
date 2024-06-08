from math import inf
from typing import *


class Node:
    def __init__(self, data, frequency, datatype, leftchild, rightchild):
        self.left = None
        self.right = None
        self.data = data
        self.frequency = frequency
        self.datatype = datatype

    def PrintTree(self):
        print(self.data)
        print(self.frequency)


def popminimumnode(frequencyobject: List[Node]) -> Node:
    minimumnode = frequencyobject[0]
    for node in frequencyobject:
        if node.frequency < minimumnode.frequency:
            minimumnode = node

    frequencyobject.remove(minimumnode)
    return minimumnode


frequencystructure = [
    Node("A", 10, "CHAR", None, None),
    Node("B", 20, "CHAR", None, None),
    Node("C", 15, "CHAR", None, None),
    Node("D", 25, "CHAR", None, None),
    Node("E", 5, "CHAR", None, None),
    Node("F", 25, "CHAR", None, None),
]

globalminima = -inf

while len(frequencystructure) != 1:
    mincharacter1 = popminimumnode(frequencystructure)
    mincharacter2 = popminimumnode(frequencystructure)
    localparent = Node(
        None,
        mincharacter1.frequency + mincharacter2.frequency,
        "INT",
        mincharacter1,
        mincharacter2,
    )
    frequencystructure.append(localparent)

(frequencystructure[0].PrintTree)
