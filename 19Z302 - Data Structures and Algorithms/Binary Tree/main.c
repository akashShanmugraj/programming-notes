// Linked List Implementation of Binary Search, only traversal and insertion

#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node * left;
    struct node * right;
};

struct node * getNode(int data) {
    struct node * newNode = (struct node *)malloc(sizeof(struct node));
    newNode -> data = data;
    newNode -> left = NULL;
    newNode -> right = NULL;
    return newNode;
}

struct node * insertNode(struct node * rootnode, int data) {
    if (rootnode == NULL) {
        return getNode(data);
    }
    if (data < rootnode->data) {
        rootnode->left = insertNode(rootnode->left, data);
    } else if (data > rootnode->data) {
        rootnode->right = insertNode(rootnode->right, data);
    }
    return rootnode;
}

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

int main() {
    struct node * rootnode = NULL;

    // Inserting nodes
    rootnode = insertNode(rootnode, 53);
    rootnode = insertNode(rootnode, 31);
    rootnode = insertNode(rootnode, 75);
    rootnode = insertNode(rootnode, 28);
    rootnode = insertNode(rootnode, 40);
    rootnode = insertNode(rootnode, 62);
    rootnode = insertNode(rootnode, 88);

    // Printing the tree
    printTree(rootnode, 0);

    return 0;
}