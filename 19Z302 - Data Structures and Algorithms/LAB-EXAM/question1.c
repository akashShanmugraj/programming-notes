#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
    int key;
};

struct node *returnkeynode(struct node *queueobject, int key)
{
    struct node *traversalnode = queueobject;
    while (traversalnode != NULL)
    {
        if (traversalnode->key == key)
        {
            return traversalnode;
        }
        else
        {
            traversalnode = traversalnode->next;
        }
    }
    return NULL;
}

void printqueue(struct node *rootnode)
{
    struct node *traversalnode = rootnode;

    while (traversalnode != NULL)
    {
        printf(" %d @ (%d)  ", traversalnode->data, traversalnode->key);
        traversalnode = traversalnode->next;
    }
    printf("\n");
}

struct node *getnode(int data)
{
    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data = data;
    newnode->next = NULL;
    newnode->key = 0;
    return newnode;
}

struct node *createqueue(int length)
{
    struct node *rootnode = getnode(0);
    struct node *traversalnode = rootnode;

    for (int iterable = 0; iterable < length - 1; iterable++)
    {
        traversalnode->next = getnode(0);
        traversalnode = traversalnode->next;
        traversalnode->key = iterable + 1;
    }

    return rootnode;
}

struct node *insertat(struct node *queueobject, int data, int key)
{
    struct node *targetnode = returnkeynode(queueobject, key);
    if (targetnode != NULL)
    {
        targetnode->data = data;
    }
    return queueobject;
}

struct node *deleteat(struct node *queueobject, int key, int *returninteger)
{
    struct node *targetnode = returnkeynode(queueobject, key);
    if (targetnode != NULL)
    {
        // printf("DELTRGTVAL %d\n", targetnode->data);
        *(returninteger) = targetnode->data;
        targetnode->data = 0;
    }
    return queueobject;
}

void enqueue(struct node *queueobject, int queuelength, int *backpointer, int data, int *frontpointer)
{   
    if (*(backpointer) == queuelength - 1)
    {
        printf("Overflow\n");
    }
    else
    {
        if (*(backpointer) == -1 && *(frontpointer) == -1)
        {
            *(frontpointer) = 0;
        }
        *(backpointer) = *(backpointer) + 1;
        insertat(queueobject, data, *(backpointer));
    }
}

int dequeue(struct node *queueobject, int *frontpointer, int *(rearpointer))
{
    int deleteinteger = 0;
    if (*(frontpointer) == -1 && *(rearpointer) == -1)
    {
        printf("Underflow\n");
    }
    else
    {
        deleteat(queueobject, *(frontpointer), &deleteinteger);
        *(frontpointer) = *(frontpointer) + 1;
    }
    printf("DEL %d\n", deleteinteger);
    return deleteinteger;
}

int getfront(struct node *queueobject, int *frontpointer)
{
    return returnkeynode(queueobject, *(frontpointer))->data;
}

int isEmpty(int *frontpointer, int *rearpointer)
{   if (*(frontpointer) == *(rearpointer)){
        printf("EMTY Q\n");
    }
    return *(frontpointer) == *(rearpointer);
}

int main()
{
    // test case 1
    printf("TC1\n");
    struct node *rootnode = createqueue(10);
    int sizeofqueue = 10;

    int front = -1;
    int back = -1;

    enqueue(rootnode, sizeofqueue, &back, 5, &front);
    enqueue(rootnode, sizeofqueue, &back, 10, &front);
    printf("FRONT-%d\n", getfront(rootnode, &front));
    printqueue(rootnode);
printf("\n\n");
    // test case 2
    printf("TC2\n");
    rootnode = createqueue(10);
    sizeofqueue = 10;

    front = -1;
    back = -1;

    enqueue(rootnode, sizeofqueue, &back, 3, &front);
    enqueue(rootnode, sizeofqueue, &back, 7, &front);
    enqueue(rootnode, sizeofqueue, &back, 1, &front);
    dequeue(rootnode, &front, &back);
    printf("FRONT VAL %d\n",getfront(rootnode, &front));

    printqueue(rootnode);
printf("\n\n");

    // test case 3
    printf("TC3\n");
    rootnode = createqueue(10);
    sizeofqueue = 10;

    front = -1;
    back = -1;

    isEmpty(&front, &back);

    printqueue(rootnode);
printf("\n\n");

    // test case 4
    printf("TC4\n");
    rootnode = createqueue(10);
    sizeofqueue = 10;

    front = -1;
    back = -1;

    dequeue(rootnode, &front, &back);

    printqueue(rootnode);
printf("\n\n");

    // test case 5
    printf("TC5\n");
    rootnode = createqueue(10);
    sizeofqueue = 10;

    front = -1;
    back = -1;

    enqueue(rootnode, sizeofqueue, &back, 2, &front);
    enqueue(rootnode, sizeofqueue, &back, 4, &front);
    dequeue(rootnode, &front, &back);
    enqueue(rootnode, sizeofqueue, &back, 6, &front);
    printf("FRONT VAL %d\n",getfront(rootnode, &front));

    printqueue(rootnode);
printf("\n\n");

    // test case 6
    printf("TC6\n");
    rootnode = createqueue(10);
    sizeofqueue = 10;

    front = -1;
    back = -1;

    enqueue(rootnode, sizeofqueue, &back, 8, &front);
    dequeue(rootnode, &front, &back);
    printf("%d %d\n", front, back);
    isEmpty(&front, &back);   
}