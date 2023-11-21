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
