#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


int isValidElement(int *tree, int index, int size){
    if (index > size-1){
        return 0;
    }

    if (*(tree+index) != -1){
        printf("Tree has valid child at %d which is %d\n", index,*(tree+index));
        return 1;
    } else {
        return 0;
    }
}

int findMinimum(int *tree, int subtreeindex, int size){
    if (isValidElement(tree, 2*subtreeindex+1, size)){
        return findMinimum(tree, 2*subtreeindex + 1, size);
    }

    return *(tree + subtreeindex);
}

void fastdelete(int *tree, int index, int size){
    if (isValidElement(tree, 2*index+1, size) && isValidElement(tree, 2*index+2, size)){
        printf("Two Children\n");
    } else if (isValidElement(tree, 2*index+1, size) && !isValidElement(tree, 2*index+2, size)){
        printf("Left Child Only\n");
    } else if (!isValidElement(tree, 2*index+1, size) && isValidElement(tree, 2*index+2, size)){
        printf("Right Child Only\n");
    }else if (!isValidElement(tree, 2*index+1, size) && !isValidElement(tree, 2*index+2, size)){
        printf("No Child\n");
    }
}

void insertion(int *tree, int counter, int size, int data)
{
    if (counter >= size)
    {
        printf("Tree is full. Cannot insert %d\n", data);
        return;
    }

    if (*(tree + counter) == -1)
    {
        *(tree + counter) = data;
    }
    else if (*(tree + counter) < data)
    {
        insertion(tree, 2 * counter + 2, size, data);
    }
    else if (*(tree + counter) > data)
    {
        insertion(tree, 2 * counter + 1, size, data);
    }
    else
    {
        printf("Duplicate value %d. Not inserted.\n", data);
    }
}

void inordertraversal(int *tree, int counter, int size)
{
    if (counter >= size || tree[counter] == -1)
    {
        return;
    }

    inordertraversal(tree, 2 * counter + 1, size); // Left child
    printf("%d ", tree[counter]);                  // Current node
    inordertraversal(tree, 2 * counter + 2, size); // Right child
}

void preordertraversal(int *tree, int counter, int size)
{
    if (counter >= size || tree[counter] == -1)
    {
        return;
    }

    printf("%d ", tree[counter]);                   // Current node
    preordertraversal(tree, 2 * counter + 1, size); // Left child
    preordertraversal(tree, 2 * counter + 2, size); // Right child
}

void postordertraversal(int *tree, int counter, int size)
{
    if (counter >= size || tree[counter] == -1)
    {
        return;
    }

    postordertraversal(tree, 2 * counter + 1, size); // Left child
    postordertraversal(tree, 2 * counter + 2, size); // Right child
    printf("%d ", tree[counter]);                    // Current node
}

int main()
{
    int treearray[100] = {-1};
    int stree[] = {53, 31, 75, 28, 40, 63, 88, -1, -1, -1, 1, -1, -1, -1, -1};
    int treesize = sizeof(stree)/sizeof(int);
    int *treepointer = stree;

    fastdelete(treepointer,4,treesize);
    inordertraversal(treepointer, 0, 7);
    printf("\n");
    preordertraversal(treepointer, 0, 7);
    printf("\n");
    postordertraversal(treepointer, 0, 7);
    printf("\n");
    return 0;
}