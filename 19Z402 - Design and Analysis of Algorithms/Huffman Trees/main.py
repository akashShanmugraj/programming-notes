from math import inf
from typing import *

# def dictionarysortkeys(inputdictionary: dict) -> dict:
#     sortedkeys = sorted(inputdictionary.keys())
#     finaldictionary = dict()
#     for key in sortedkeys:
#         finaldictionary[key] = inputdictionary[key]

#     return finaldictionary


# def dictionarysortvalues(inputdictionary: dict) -> dict:
#     sortedvalues = sorted(inputdictionary.values())
#     finaldictionary = dict()
#     inverseinputdictionary = dict(zip(inputdictionary.values(), inputdictionary.keys()))
#     for value in sortedvalues:
#         finaldictionary[value] = inverseinputdictionary[value]
#     return finaldictionary


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
    Node("C", 30, "CHAR", None, None),
    Node("D", 40, "CHAR", None, None),
]

globalminima = -inf

while len(frequencystructure) != 1:
    mincharacter1 = popminimumnode(frequencystructure)
    mincharacter2 = popminimumnode(frequencystructure)
    localparent = Node(None, None, "INT", mincharacter1, mincharacter2)
    frequencystructure.append(localparent)

print(frequencystructure)
