#include <stdio.h>
#include <stdlib.h>

void insertion(int *tree, int counter, int size, int data) {
    if (counter >= size) {
        printf("Tree is full. Cannot insert %d\n", data);
        return;
    }

    if (*(tree + counter) == -1) {
        *(tree + counter) = data;
    } else if (*(tree + counter) < data) {
        insertion(tree, 2*counter + 2, size, data);
    } else if (*(tree + counter) > data) {
        insertion(tree, 2*counter + 1, size, data);
    } else {
        printf("Duplicate value %d. Not inserted.\n", data);
    }
}

void inordertraversal(int *tree, int counter, int size) {
    if (counter >= size || tree[counter] == -1) {
        return;
    }

    inordertraversal(tree, 2*counter + 1, size);    // Left child
    printf("%d ", tree[counter]);                  // Current node
    inordertraversal(tree, 2*counter + 2, size);  // Right child
}

void preordertraversal(int *tree, int counter, int size) {
    if (counter >= size || tree[counter] == -1) {
        return;
    }

    printf("%d ", tree[counter]);                    // Current node
    preordertraversal(tree, 2*counter + 1, size);   // Left child
    preordertraversal(tree, 2*counter + 2, size);  // Right child
}

void postordertraversal(int *tree, int counter, int size) {
    if (counter >= size || tree[counter] == -1) {
        return;
    }

    postordertraversal(tree, 2*counter + 1, size);    // Left child
    postordertraversal(tree, 2*counter + 2, size);   // Right child
    printf("%d ", tree[counter]);                   // Current node
}

int main() {
    int treearray[100] = {-1};
    int stree[] = {53,31,75,28,40,63,88,-1,-1,-1,-1,-1,-1,-1,-1};
    int * treepointer = stree;
    inordertraversal(treepointer,0,7);
    printf("\n");
    preordertraversal(treepointer,0,7);
    printf("\n");
    postordertraversal(treepointer,0,7);
    printf("\n");
    return 0;
}