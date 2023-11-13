# Binary Search Trees

## Linked List Implementation

### Inorder Traversal

```c
void inordertraversal(struct node *rootnode)
{
    struct node *traversalnode = rootnode;

    if (traversalnode->left != NULL)
    {
        inordertraversal(traversalnode->left);
    }

    printf("%d ", traversalnode->data);

    if (traversalnode->right != NULL)
    {
        inordertraversal(traversalnode->right);
    }
}
```

### Preorder Traversal
```c
void preordertraversal(struct node *rootnode)
{
    struct node *traversalnode = rootnode;

    if (rootnode == NULL)
    {
        return;
    }
    printf("%d ", traversalnode->data);

    if (traversalnode->left != NULL)
    {
        preordertraversal(traversalnode->left);
    }

    if (traversalnode->right != NULL)
    {
        preordertraversal(traversalnode->right);
    }
}
```

### Postorder Traversal
```c
void postordertraversal(struct node *rootnode)
{
    struct node *traversalnode = rootnode;

    if (traversalnode->left != NULL)
    {
        postordertraversal(traversalnode->left);
    }

    if (traversalnode->right != NULL)
    {
        postordertraversal(traversalnode->right);
    }

    printf("%d ", traversalnode->data);
}
```

### Insertion - Iteration
```c
struct node *insertion(struct node *rootnode, int data)
{
    struct node *traversalpointer = rootnode;

    struct node *newnode = getNode(data);

    if (!rootnode) {
        return newnode;
    }
    while (traversalpointer) {
        if (traversalpointer->data < data && traversalpointer->right != NULL){
            traversalpointer = traversalpointer->right;
        } else if (traversalpointer->data >= data && traversalpointer->left != NULL){
            traversalpointer = traversalpointer->left;
        } else {
            break;
        }
    }

    if (traversalpointer->data < data){
        traversalpointer->right = newnode;
    } else if (traversalpointer->data >= data){
        traversalpointer->left = newnode;
    }

    return rootnode;
}
```

### Insertion - Recursion
```c
struct node *insertNode(struct node *rootnode, int data)
{
    if (rootnode == NULL){
        return getNode(data);
    } else if (data > rootnode->data){
        rootnode -> right = insertNode(rootnode->right, data);
    } else if (data < rootnode->data){
        rootnode -> left = insertNode(rootnode->left, data); 
    } else {
        return rootnode;
    }
    
}

```