import csv
import random
import time
from collections import deque

class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None

class Codec:
    def serialize(self, root):
        if not root:
            return "[]"
        
        queue = deque([root])
        result = []
        
        while queue:
            node = queue.popleft()
            if node:
                result.append(str(node.val))
                queue.append(node.left)
                queue.append(node.right)
            else:
                result.append('null')
        
        return '[' + ','.join(result) + ']'

    def deserialize(self, data):
        if data == "[]":
            return None
        
        nodes, i = data[1:-1].split(','), 1
        root = TreeNode(int(nodes[0]))
        queue = deque([root])
        
        while queue:
            node = queue.popleft()
            if nodes[i] != 'null':
                node.left = TreeNode(int(nodes[i]))
                queue.append(node.left)
            i += 1
            if nodes[i] != 'null':
                node.right = TreeNode(int(nodes[i]))
                queue.append(node.right)
            i += 1
        
        return root

def generate_random_tree(depth):
    if depth > 0 and random.random() < 0.9:  # 90% chance to continue to generate a subtree
        node = TreeNode(random.randint(0, 100))
        node.left = generate_random_tree(depth - 1)
        node.right = generate_random_tree(depth - 1)
        return node
    return None  # 10% chance to return a leaf node (None)

def main():
    codec = Codec()
    with open('benchmarks.csv', 'w', newline='') as file:
        writer = csv.writer(file)
        writer.writerow(["S.NO", "Testcase Size", "Runtime"])
        for i in range(1, 10001):  # Generate 10000 test cases
            tree = generate_random_tree(5)  # Generate a random tree with depth up to 5
            start_time = time.time()
            serialized = codec.serialize(tree)
            deserialized = codec.deserialize(serialized)
            end_time = time.time()
            writer.writerow([i, len(serialized), end_time - start_time])

if __name__ == "__main__":
    main()