## Unival Counting Function

### Faulty Code
```c
void countunival(struct node *root, int *counterpointer)
{
    printf("C:%d L:%d R:%d\n", root->data, root->left->data, root->right->data);
    if (root->left && root->right)
    {
        if (root->left->data == root->data && root->right->data == root->data)
        {
            printf("MATCH1\n");
            *(counterpointer) = *(counterpointer) + 1;
            printf("NOW %d\n", *(counterpointer));
        }
        countunival(root->left, counterpointer);
        countunival(root->right, counterpointer);
    }
    else if (root->left && !root->right)
    {
        if (root->left->data == root->data)
        {
            printf("MATCH2\n");
            *(counterpointer) = *(counterpointer) + 1;
        }
        countunival(root->left, counterpointer);
    }
    else if (root->right && !root->left)
    {
        if (root->right->data == root->data)
        {
            printf("MATCH3\n");
            *(counterpointer) = *(counterpointer) + 1;
        }
        countunival(root->right, counterpointer);
    }
    else if (!root->left && !root->right)
    {
        return;
    }
}
```
### Corrected Code:
```c
void countunival(struct node *root, int *counterpointer)
{
    if (root == NULL) {
        return;
    }

    if (root->left != NULL && root->right != NULL) {
        printf("C:%d L:%d R:%d\n", root->data, root->left->data, root->right->data);
        if (root->left->data == root->data && root->right->data == root->data)
        {
            printf("MATCH1\n");
            *(counterpointer) = *(counterpointer) + 1;
            printf("NOW %d\n", *(counterpointer));
        }
        countunival(root->left, counterpointer);
        countunival(root->right, counterpointer);
    }
    else if (root->left != NULL) {
        printf("C:%d L:%d\n", root->data, root->left->data);
        if (root->left->data == root->data)
        {
            printf("MATCH2\n");
            *(counterpointer) = *(counterpointer) + 1;
        }
        countunival(root->left, counterpointer);
    }
    else if (root->right != NULL) {
        printf("C:%d R:%d\n", root->data, root->right->data);
        if (root->right->data == root->data)
        {
            printf("MATCH3\n");
            *(counterpointer) = *(counterpointer) + 1;
        }
        countunival(root->right, counterpointer);
    }
    else {
        printf("C:%d\n", root->data);
    }
}
```

### Copilot's Explaination
The segmentation fault is likely occurring because you're trying to access root->left->data and root->right->data without first checking if root->left and root->right are not NULL.

In this corrected code, we first check if root is NULL at the beginning of the function. If it is, we return immediately. This prevents a segmentation fault that could occur if root is NULL.

Then, before accessing root->left->data and root->right->data, we check if root->left and root->right are not NULL, respectively. This ensures that we only try to access these members if they exist, preventing a segmentation fault.

## Function to Insert into a complete Binary Tree

```c
void completebinarytreeinsertion(int *arrayobject, int parent, int size, int data, int *insertflag)
{
    int leftchild = 2 * parent + 1;
    int rightchild = 2 * parent + 2;

    if (*(arrayobject + parent) == -1)
    {
        *(arrayobject + parent) = data;
    }

    if (!*(insertflag) && leftchild < size && rightchild < size)
    {
        if (*(arrayobject + leftchild) == -1)
        {
            *(arrayobject + leftchild) = data;
            *(insertflag) = 1;
            return;
        }
        else
        {
            completebinarytreeinsertion(arrayobject, leftchild, size, data, insertflag);
        }

        if (*(arrayobject + rightchild) == -1)
        {
            *(arrayobject + rightchild) = data;
            *(insertflag) = 1;
            return;
        }
        else
        {
            completebinarytreeinsertion(arrayobject, rightchild, size, data, insertflag);
        }
    }
}
```

## Function to get maximum height of a Binary Tree
```c
int getMaxHeight(struct node * rootnode, int * leftcountervariable, int * rightcountervariable){
    
    // printf("ST L%d R%d\n", leftcountervariable, rightcountervariable);

    // printf("CUR %d\n\n", rootnode->data);
    
    if (rootnode->left != NULL){
        *(leftcountervariable) = *(leftcountervariable) + 1; 
        getMaxHeight(rootnode->left, leftcountervariable, rightcountervariable);
    }

    if (rootnode->right != NULL){
        *(rightcountervariable) = *(rightcountervariable) + 1;
        getMaxHeight(rootnode->right, leftcountervariable, rightcountervariable);
    }

    // printf("END L%d R%d\n", leftcountervariable, rightcountervariable);

}
```

## Function to rotate a binary tree towards right

### Faulty Code:
```c
struct node * rotateRight(struct node * pivotnode, struct node * parentnode){
    if (pivotnode->right == NULL){
        pivotnode->right = parentnode;
    } else {
        struct node * pivotrightnode = pivotnode->right;
        pivotnode->right = parentnode;
        parentnode->left = pivotrightnode;
    }

    return pivotnode;
}
```

### Copilot's Explanation
The implementation of the `rotateRight` function you provided is partially correct, but it's missing a crucial step. When you perform a right rotation, the left child of the pivot node becomes the new parent, and the old parent becomes the right child of the new parent. However, the old parent's left child should be set to the right child of the pivot node.

### Corrected Code
```c
struct node * rotateRight(struct node * pivotnode, struct node * parentnode){
    if (pivotnode == NULL || parentnode == NULL) {
        return NULL;
    }

    parentnode->left = pivotnode->right;
    pivotnode->right = parentnode;

    return pivotnode;
}
```

This function first checks if either `pivotnode` or `parentnode` is NULL. If so, it returns NULL. Then it sets the left child of `parentnode` to be the right child of `pivotnode`. After that, it sets the right child of `pivotnode` to be `parentnode`. Finally, it returns `pivotnode`, which is now the new root of the rotated subtree.
