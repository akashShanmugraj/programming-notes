Set 2
### Question: Implement a Queue Using Linked Lists

**Task**: Write a program to implement a queue using linked lists. The queue should support the following operations:

1. **Enqueue**: Adds an element to the end of the queue.
2. **Dequeue**: Removes the front element from the queue and returns it.
3. **Front**: Returns the front element of the queue without removing it.
4. **IsEmpty**: Returns `true` if the queue is empty, otherwise `false`.

The linked list should be a singly linked list with nodes that contain an integer value and a reference to the next node.

#### Test Cases

1. **Enqueue and Front**
   - **Input**: Enqueue 5, Enqueue 10, Front
   - **Expected Output**: Front element is 5

2. **Enqueue and Dequeue**
   - **Input**: Enqueue 3, Enqueue 7, Enqueue 1, Dequeue, Front
   - **Expected Output**: Dequeue returns 3, Front element is 7

3. **Empty Queue**
   - **Input**: IsEmpty
   - **Expected Output**: true

4. **Dequeue from Empty Queue**
   - **Input**: Dequeue
   - **Expected Output**: Error or null (depending on how you handle underflow)

5. **Multiple Operations**
   - **Input**: Enqueue 2, Enqueue 4, Dequeue, Enqueue 6, Front
   - **Expected Output**: Dequeue returns 2, Front element is 4

6. **IsEmpty after Enqueue and Dequeue**
   - **Input**: Enqueue 8, Dequeue, IsEmpty
   - **Expected Output**: true

### Question: Construct Binary Tree from Preorder and Inorder Traversal

#### Task
You are provided with two integer arrays: `preorder` and `inorder`. The `preorder` array represents the preorder traversal of a binary tree, while the `inorder` array represents the inorder traversal of the same tree. Your task is to construct and return the binary tree represented by these traversals.

#### Objective
- Given the `preorder` and `inorder` traversal sequences, construct the binary tree.
- Assume that there are no duplicate elements in the tree.

#### Example
- **Input**: 
  - `preorder` = [3, 9, 20, 15, 7]
  - `inorder` = [9, 3, 15, 20, 7]
- **Expected Output**: A binary tree represented by the structure corresponding to these traversals.

#### Test Cases

1. **Basic Case**
   - **Input**: 
     - `preorder` = [3, 9, 20, 15, 7]
     - `inorder` = [9, 3, 15, 20, 7]
   - **Expected Output**: The binary tree structure corresponding to these traversals.

2. **Empty Tree**
   - **Input**: 
     - `preorder` = []
     - `inorder` = []
   - **Expected Output**: `null` or equivalent representation of an empty tree.

3. **Single Node Tree**
   - **Input**: 
     - `preorder` = [1]
     - `inorder` = [1]
   - **Expected Output**: A tree with a single node.

4. **Left-Skewed Tree**
   - **Input**: 
     - `preorder` = [3, 2, 1]
     - `inorder` = [1, 2, 3]
   - **Expected Output**: A left-skewed tree (each node only has a left child).

5. **Right-Skewed Tree**
   - **Input**: 
     - `preorder` = [1, 2, 3]
     - `inorder` = [1, 2, 3]
   - **Expected Output**: A right-skewed tree (each node only has a right child).

6. **Complex Tree**
   - **Input**: 
     - `preorder` = [7, 10, 4, 3, 1, 2, 8, 11]
     - `inorder` = [4, 10, 3, 1, 7, 11, 8, 2]
   - **Expected Output**: The binary tree structure corresponding to these traversals.
