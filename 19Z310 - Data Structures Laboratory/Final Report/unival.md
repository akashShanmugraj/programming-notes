# Source Code

### Importing Standard Libraries

```c
#include <stdio.h>
#include <stdlib.h>
```

We import standard libraries for input/output and dynamic memory allocation.

### Defining the Node Structure

```c
struct node {
    int data;
    struct node * left;
    struct node * right;
};
```

We define a node of our Binary Search Tree using `struct`, having integer (data) field and two pointers to the left and right child nodes.

### `getnode()` function

```c
struct node * getnode(int data){
    struct node * newnode = malloc(sizeof(struct node));
    newnode->data = data;
    newnode->left = NULL;
    newnode->right = NULL;

    return newnode;
}
```

A standard `getnode` function that takes in an integer and returns a pointer to a new tree node with the passed data

### Function to count total number of Unival Subtrees in a Binary Tree

```c
int countunival(struct node *root, int *counterpointer)
{
    if (root == NULL) {
        return 1;
    }

    int left = countunival(root->left, counterpointer);
    int right = countunival(root->right, counterpointer);

    if (left && right) {
        if (root->left && root->data != root->left->data) {
            return 0;
        }
        if (root->right && root->data != root->right->data) {
            return 0;
        }

        (*counterpointer)++;
        return 1;
    }

    return 0;
}
```
This function counts the total number of Unival Subtrees in the passed Binary Tree and returns the count.

It's aim is achieved primarily by recursively traversing the tree in a bottom-up manner, i.e. inorder traversal. Then we check if the left and right subtrees are unival or not. If they are, we check if the current node's data is equal to the data of its left and right child nodes. If it is, we increment the counter and return 1. Else, we return 0.

### Standard Driver Code

```c
int main()
{
    struct node *rootnode = getnode(10);
    rootnode->left = getnode(10);
    rootnode->right = getnode(20);

    rootnode->left->left = getnode(9);
    rootnode->left->right = getnode(10);

    rootnode->right->right = getnode(20);
    rootnode->right->left = getnode(20);

    int univalcounter = 0;
    int *univalcounterpointer = &univalcounter;

    countunival(rootnode, univalcounterpointer);

    printf("Total number of UniVal Trees is %d\n", *(univalcounterpointer));
    return 0;
}
```

We artifically create a Binary Tree with 7 nodes, and then call the `countunival` function on the root node. We pass the address of the `univalcounter` variable to the function, so that the function can increment the counter variable as and when required.