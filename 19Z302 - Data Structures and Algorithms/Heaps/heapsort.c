#include <stdio.h>
#include <stdlib.h>

void printTree(int *tree, int index, int level, int size)
{
    if (index >= size || tree[index] == -1)
    {
        return;
    }

    printTree(tree, 2 * index + 2, level + 1, size); // Right child

    for (int i = 0; i < level; i++)
    {
        printf("    ");
    }
    printf("%d\n", tree[index]); // Current node

    printTree(tree, 2 * index + 1, level + 1, size); // Left child
}

void reheapify(int *heapobject, int heapsize, int pointer)
{
    int leftchild = 2 * pointer + 1;
    int rightchild = 2 * pointer + 2;

    if (leftchild >= heapsize)
    {
        return;
    }
    else if (rightchild >= heapsize)
    {
        if (*(heapobject + leftchild) > *(heapobject + pointer))
        {
            int temp = *(heapobject + leftchild);
            *(heapobject + leftchild) = *(heapobject + pointer);
            *(heapobject + pointer) = temp;
        }
    }
    else
    {
        if (*(heapobject + leftchild) >= *(heapobject + rightchild) && *(heapobject + leftchild) > *(heapobject + pointer))
        {
            int temp = *(heapobject + leftchild);
            *(heapobject + leftchild) = *(heapobject + pointer);
            *(heapobject + pointer) = temp;

            reheapify(heapobject, heapsize, leftchild);
        }
        else if (*(heapobject + leftchild) <= *(heapobject + rightchild) && *(heapobject + rightchild) > *(heapobject + pointer))
        {
            int temp = *(heapobject + rightchild);
            *(heapobject + rightchild) = *(heapobject + pointer);
            *(heapobject + pointer) = temp;

            reheapify(heapobject, heapsize, rightchild);
        }
    }
}

void sortheap(int *heapobject, int heapsize)
{
    int limit = 0;

    for (int iterable = 0; iterable < heapsize; iterable++)
    {
        printf("SWAP %d %d\n\n", *(heapobject), *(heapobject + heapsize - 1 - iterable));

        int temp = *(heapobject);
        *(heapobject) = *(heapobject + heapsize - 1 - iterable);
        *(heapobject + heapsize - 1 - iterable) = temp;

        printf("AFTER SWAP\n");
        printTree(heapobject, 0, 0, heapsize);
        printf("\n");

        reheapify(heapobject, heapsize - 1 - iterable, 0);

        printf("AFTER SWAP, RH5\n");
        printTree(heapobject, 0, 0, heapsize);
        printf("\n");
        printf("\n");
    }
}

int main()
{
    int maxheaparray[] = {94, 84, 78, 42, 40, 42, 31, 22, 2, 31};
    int *maxheappointer = maxheaparray;
    int maxheapsize = sizeof(maxheaparray) / sizeof(int);

    printf("INIT\n");
    
    printTree(maxheappointer, 0, 0, maxheapsize);
    printf("\n");
    for (int i = 0; i < maxheapsize; i++)
    {
        printf("%d-", maxheaparray[i]);
    }

    printf("\n");

    sortheap(maxheappointer, maxheapsize);
    
    printf("\n");
    
    printf("AFTER SORT\n");
    
    printTree(maxheappointer, 0, 0, maxheapsize);
    printf("\n");
    for (int i = 0; i < maxheapsize; i++)
    {
        printf("%d-", maxheaparray[i]);
    }

    printf("\n");
    return 0;
}