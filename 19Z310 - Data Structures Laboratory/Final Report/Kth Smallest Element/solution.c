#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node * left;
    struct node * right;
};

void printTree(struct node * rootnode, int level) {
    if (rootnode == NULL) {
        return;
    }
    printTree(rootnode -> right, level + 1);
    for (int i = 0; i < level; i++) {
        printf("    ");
    }
    printf("%d\n", rootnode -> data);
    printTree(rootnode -> left, level + 1);
}

struct node * getnode(int data){
    struct node * newnode = malloc(sizeof(struct node));
    newnode->data = data;
    newnode->left = NULL;
    newnode->right = NULL;

    return newnode;
}

void kthsmallest(struct node *rootnode, int * counterpointer, int k)
{
    if (rootnode == NULL || *counterpointer >= k) {
        return;
    }

    kthsmallest(rootnode->left, counterpointer, k);

    *counterpointer = *counterpointer + 1;

    if (*counterpointer == k) {
        printf("Kth smallest element is %d \n", rootnode->data);
        return;
    }

    kthsmallest(rootnode->right, counterpointer, k);
}

int main() {
    struct node * rootnode = getnode(10);   
    rootnode->left = getnode(5);
    rootnode->right = getnode(20);

    rootnode->left->left = getnode(1);
    rootnode->left->right = getnode(8);

    rootnode->right->right = getnode(40);

    printTree(rootnode, 0);


    int inordercounter = 0;
    int * inordercounterpointer = &inordercounter;

    kthsmallest(rootnode, inordercounterpointer, 3);
    
    return 0;
}