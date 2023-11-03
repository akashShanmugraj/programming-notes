#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node* left;
    struct node* right;
};

struct node* getNode(int data) {
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

struct node* insertNode(struct node* rootnode, int data) {
    if (rootnode == NULL) {
        return getNode(data);
    }
    if (data < rootnode->data) {
        rootnode->left = insertNode(rootnode->left, data);
    }
    else if (data > rootnode->data) {
        rootnode->right = insertNode(rootnode->right, data);
    }
    return rootnode;
}

void printTree(struct node* rootnode, int level) {
    if (rootnode == NULL) {
        return;
    }
    printTree(rootnode->right, level + 1);
    for (int i = 0; i < level; i++) {
        printf("    ");
    }
    printf("%d\n", rootnode->data);
    printTree(rootnode->left, level + 1);
}

void inordertraversal(struct node* rootnode) {
    struct node* traversalnode = rootnode;

    if (traversalnode->left != NULL) {
        inordertraversal(traversalnode->left);
    }

    printf("%d ", traversalnode->data);

    if (traversalnode->right != NULL) {
        inordertraversal(traversalnode->right);
    }

}

void preordertraversal(struct node * rootnode){
    struct node * traversalnode = rootnode;

    if (rootnode == NULL){
        return;
    }
    printf("%d ", traversalnode->data);

    if (traversalnode->left != NULL){
        preordertraversal(traversalnode->left);
    }

    if (traversalnode->right != NULL){
        preordertraversal(traversalnode->right);
    }
}

void postordertraversal(struct node * rootnode){
    struct node * traversalnode = rootnode;

    if (traversalnode->left != NULL){
        postordertraversal(traversalnode->left);
    }

    if (traversalnode->right != NULL){
        postordertraversal(traversalnode->right);
    }

    printf("%d ", traversalnode->data);

}

int main() {
    struct node* rootnode = NULL;

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

    printf("INORDER: ");
    inordertraversal(rootnode);
    printf("\n");


    printf("PREORDER: ");
    preordertraversal(rootnode);
    printf("\n");

    printf("POSTORDER: ");
    postordertraversal(rootnode);
    printf("\n");

    return 0;
}