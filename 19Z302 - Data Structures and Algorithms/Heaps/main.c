// percolate down for maxheap and minheap

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int percolatedownmaxheap(int * maxheappointer, int heapsize, int parent){
    
    int leftchild = 2*(parent) + 1;
    int rightchild = 2*(parent) + 2;


    if (!*(maxheappointer+leftchild) && !*(maxheappointer+rightchild)){
        return 0;
    }

    if (leftchild >= heapsize || rightchild >= heapsize){
        return 0;
    }

    if (*(maxheappointer + leftchild) > *(maxheappointer + rightchild)){
        *(maxheappointer + parent) = *(maxheappointer + leftchild);
        *(maxheappointer + leftchild) = -1;
        return percolatedownmaxheap(maxheappointer, heapsize, leftchild);
    }

    else if (*(maxheappointer + leftchild) < *(maxheappointer + rightchild)){
        *(maxheappointer + parent) = *(maxheappointer + rightchild);
        *(maxheappointer + rightchild) = -1;
        return percolatedownmaxheap(maxheappointer, heapsize, rightchild);
    }
    
}

int percolatedownminheap(int * maxheappointer, int heapsize, int parent){
    
    int leftchild = 2*(parent) + 1;
    int rightchild = 2*(parent) + 2;


    if (!*(maxheappointer+leftchild) && !*(maxheappointer+rightchild)){
        return 0;
    }

    if (leftchild >= heapsize || rightchild >= heapsize){
        return 0;
    }

    if (*(maxheappointer + leftchild) < *(maxheappointer + rightchild)){
        *(maxheappointer + parent) = *(maxheappointer + leftchild);
        *(maxheappointer + leftchild) = -1;
        return percolatedownminheap(maxheappointer, heapsize, leftchild);
    }

    else if (*(maxheappointer + leftchild) > *(maxheappointer + rightchild)){
        *(maxheappointer + parent) = *(maxheappointer + rightchild);
        *(maxheappointer + rightchild) = -1;
        return percolatedownminheap(maxheappointer, heapsize, rightchild);
    }
    
}

void printTree(int *tree, int index, int level, int size) {
    if (index >= size || tree[index] == -1) {
        return;
    }

    printTree(tree, 2*index + 2, level + 1, size);  // Right child

    for (int i = 0; i < level; i++) {
        printf("    ");
    }
    printf("%d\n", tree[index]);  // Current node

    printTree(tree, 2*index + 1, level + 1, size);  // Left child
}

int main() {
    
    int maxheaparray[7] = {101,57,65,29,35,6,8};
    int * maxheappointer = maxheaparray;
    int maxheapsize = sizeof(maxheaparray)/sizeof(int);

    printf("Firstly,\n");
    printTree(maxheappointer, 0, 0, maxheapsize);

    printf("\n");

    percolatedownmaxheap(maxheappointer, maxheapsize, 0);

    printf("\n");
    
    printf("Finally, \n");
    printTree(maxheappointer, 0, 0, maxheapsize);
    
    printf("\n");
    printf("\n");

    int minheaparray[7] = {10,20,30,40,50,60,70};
    int * minheappointer = minheaparray;
    int minheapsize = sizeof(minheaparray)/sizeof(int);

    printf("Firstly,\n");
    printTree(minheappointer, 0, 0, minheapsize);

    printf("\n");

    percolatedownminheap(minheappointer, minheapsize, 0);

    printf("\n");
    
    printf("Finally, \n");
    printTree(minheappointer, 0, 0, minheapsize);
    
    printf("\n");
    printf("\n");


    return 0;

}