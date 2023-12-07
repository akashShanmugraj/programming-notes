from graphviz import Digraph

class Node:
    def __init__(self, value):
        self.value = value
        self.left = None
        self.right = None

def add_node_edges(node, dot):
    if node.left:
        dot.edge(str(node.value), str(node.left.value))
        add_node_edges(node.left, dot)
    if node.right:
        dot.edge(str(node.value), str(node.right.value))
        add_node_edges(node.right, dot)

def create_graph(node):
    dot = Digraph()
    dot.node(str(node.value))
    add_node_edges(node, dot)
    return dot

# Example usage
root = Node(1)
root.left = Node(2)
root.right = Node(3)
root.left.left = Node(4)
root.left.right = Node(5)
root.right.left = Node(6)
root.right.right = Node(7)

graph = create_graph(root)
graph.view()
