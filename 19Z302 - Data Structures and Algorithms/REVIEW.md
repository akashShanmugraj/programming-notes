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