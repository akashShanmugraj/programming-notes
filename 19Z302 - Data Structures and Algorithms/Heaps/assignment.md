# Heaps Assignment 
### 19z302 - Data Structures

taught at **PSG College of Technology** by _Dr Lovelyn Rose S, Associate Professor, PSGCT_

Submitted on **18th November 2023**

### Aim:
Write a program to perform the below operations in a Heap: 
1. Insertion
2. ExtractMin
3. DeleteMin

### 1. Insertion
First, a function to insert the *Complete Binary Tree* way,
```c
int completeBinaryTreeInsertion(int *array, int size, int data)
{
    for (int iterable = 0; iterable < size; iterable++)
    {
        if (*(array + iterable) == -1)
        {
            *(array + iterable) = data;
            return iterable;
        }
    }
    return -1;
}
```

This function performs insertion and returns the index where `data` was inserted / returns -1 if no space to insert

Then,  a function to reheapify after insertion
```c
int percolateupminheap(int *minheappointer, int heapsize, int child)
{
    int parent = (child - 1) / 2;
    int tempvar;

    if (parent < 0)
    {
        return -1;
    }
    else
    {
        if (*(minheappointer + child) < *(minheappointer + parent))
        {
    
            tempvar = *(minheappointer + child);
            *(minheappointer + child) = *(minheappointer + parent);
            *(minheappointer + parent) = tempvar;

            percolateupminheap(minheappointer, heapsize, parent);
        }
    }
}
```

This function takes 
- a pointer to the heap (array implementation)
- Size of the heap
- an integer pointer to the newly inserted child node

Below is an implementation of Insertion:

```c
// inside main function
int anotherminheap[7] = {10, 15, 20, -1, -1, -1, -1};
int *anotherminheappointer = anotherminheap;

printf("Initially, the anotherminheap is\n");
printTree(anotherminheappointer, 0, 0, 7);
printf("\n");

printf("Percolating Up 5:\n");
percolateupminheap(anotherminheappointer, 7, completeBinaryTreeInsertion(anotherminheappointer, 7, 5));
printTree(anotherminheappointer, 0, 0, 7);
printf("\n");
```

Output:
```
Initially, the anotherminheap is
    20
10
    15

Percolating Up 5:
    20
5
    10
        15
```

### `ExtractMin` and `DeleteMin`

First, a percolate-down function that does `reheapify`

```c
int percolatedownminheap(int *minheappointer, int heapsize, int parent)
{

    int leftchild = 2 * (parent) + 1;
    int rightchild = 2 * (parent) + 2;

    if (!*(minheappointer + leftchild) && !*(minheappointer + rightchild))
    {
        return 0;
    }

    if (leftchild >= heapsize || rightchild >= heapsize)
    {
        return 0;
    }

    if (*(minheappointer + leftchild) < *(minheappointer + rightchild))
    {
        *(minheappointer + parent) = *(minheappointer + leftchild);
        *(minheappointer + leftchild) = -1;
        return percolatedownminheap(minheappointer, heapsize, leftchild);
    }

    else if (*(minheappointer + leftchild) > *(minheappointer + rightchild))
    {
        *(minheappointer + parent) = *(minheappointer + rightchild);
        *(minheappointer + rightchild) = -1;
        return percolatedownminheap(minheappointer, heapsize, rightchild);
    }
}
```

Finally, 

```c
// in main function
int minheaparray[7] = {10, 20, 30, 40, 50, 60, 70};
int *minheappointer = minheaparray;
int minheapsize = sizeof(minheaparray) / sizeof(int);

printf("Firstly,\n");
printTree(minheappointer, 0, 0, minheapsize);

printf("\n");
printf("MIN-ELEMENT: %d\n", *(minheappointer));
percolatedownminheap(minheappointer, minheapsize, 0);
```

The `MIN-ELEMENT` print statement accounts for the ExtractMin function
