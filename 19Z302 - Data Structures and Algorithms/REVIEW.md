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