from collections import deque

class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

def level_order_traversal(root):
    if not root:
        return []

    result = []
    queue = deque([root])

    print("Queue:", dir(queue))

    while queue:
        current_node = queue.popleft()
        result.append(current_node.val)

        if current_node.left:
            queue.append(current_node.left)
        if current_node.right:
            queue.append(current_node.right)

    return result

# Insert from an array of values
def insert_level_order(arr, root, i, n):
    if i < n:
        temp = TreeNode(arr[i])
        root = temp

        root.left = insert_level_order(arr, root.left, 2 * i + 1, n)
        root.right = insert_level_order(arr, root.right, 2 * i + 2, n)

    return root

def print_tree(root, level=0):
    if root is None:
        return

    print_tree(root.right, level + 1)
    print('    ' * level + '->', root.val)
    print_tree(root.left, level + 1)

# Example usage:
if __name__ == "__main__":
    # Creating a binary tree
    root = TreeNode(10)
    root.left = TreeNode(7)
    root.right = TreeNode(15)
    root.left.left = TreeNode(5)
    root.left.right = TreeNode(8)
    root.right.left = TreeNode(12)
    root.right.right = TreeNode(20)

    # Perform level order traversal
    result = level_order_traversal(root)
    print("Level Order Traversal:", result)

    # Insert from an array of values
    arr = result
    root = None
    root = insert_level_order(arr, root, 0, len(arr))
    print_tree(root)
