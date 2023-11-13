#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *left;
    struct node *right;
};

struct node *getNode(int data)
{
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

int findminimum(struct node *rootnode){
    if (rootnode->left != NULL){
        return findminimum(rootnode->left);
    }
    return rootnode->data;
}

struct node *deletion(struct node *rootnode, int data){
    struct node * traversalpointer = rootnode;
    struct node * parentpointer = NULL;

    while (traversalpointer->data != data){
        printf("%d - ", traversalpointer->data);
        if (data < traversalpointer->data){
            parentpointer = traversalpointer;
            traversalpointer = traversalpointer -> left;
        } else if (data > traversalpointer->data){
            parentpointer = traversalpointer;
            traversalpointer = traversalpointer->right;
        }

    }

    printf("\nDEL DATA: %d\n", traversalpointer->data);

    if ((traversalpointer->left && !traversalpointer->right) || (!traversalpointer->left && traversalpointer->right)){
        if (traversalpointer->left){
            printf("Left Child Only\n");
            parentpointer->left = traversalpointer->left;
        } else if (traversalpointer->right){
            printf("Right Child Only\n");
            parentpointer->right = traversalpointer->right;
        }
        free(traversalpointer);
    } else if (!traversalpointer->right && !traversalpointer->left){
        printf("No Child\n");
        if (parentpointer->data < data){
            parentpointer->right = NULL;
            free(traversalpointer);
        } else if (parentpointer->data > data){
            parentpointer->left = NULL;
            free(traversalpointer);
        }
    } else {
        printf("Two Children\n");
        printf("INORDER SUCCESSOR IS %d\n", findminimum(traversalpointer->right));
    }

    return rootnode;
}

struct node *insertion(struct node *rootnode, int data)
{
    struct node *traversalpointer = rootnode;

    struct node *newnode = getNode(data);

    if (!rootnode) {
        return newnode;
    }
    while (traversalpointer) {
        if (traversalpointer->data < data && traversalpointer->right != NULL){
            traversalpointer = traversalpointer->right;
        } else if (traversalpointer->data >= data && traversalpointer->left != NULL){
            traversalpointer = traversalpointer->left;
        } else {
            break;
        }
    }

    if (traversalpointer->data < data){
        traversalpointer->right = newnode;
    } else if (traversalpointer->data >= data){
        traversalpointer->left = newnode;
    }

    return rootnode;
}

void printTree(struct node *rootnode, int level)
{
    if (rootnode == NULL)
    {
        return;
    }
    printTree(rootnode->right, level + 1);
    for (int i = 0; i < level; i++)
    {
        printf("    ");
    }
    printf("%d\n", rootnode->data);
    printTree(rootnode->left, level + 1);
}

void inordertraversal(struct node *rootnode)
{
    struct node *traversalnode = rootnode;

    if (traversalnode->left != NULL)
    {
        inordertraversal(traversalnode->left);
    }

    printf("%d ", traversalnode->data);

    if (traversalnode->right != NULL)
    {
        inordertraversal(traversalnode->right);
    }
}

void preordertraversal(struct node *rootnode)
{
    struct node *traversalnode = rootnode;

    if (rootnode == NULL)
    {
        return;
    }
    printf("%d ", traversalnode->data);

    if (traversalnode->left != NULL)
    {
        preordertraversal(traversalnode->left);
    }

    if (traversalnode->right != NULL)
    {
        preordertraversal(traversalnode->right);
    }
}

void postordertraversal(struct node *rootnode)
{
    struct node *traversalnode = rootnode;

    if (traversalnode->left != NULL)
    {
        postordertraversal(traversalnode->left);
    }

    if (traversalnode->right != NULL)
    {
        postordertraversal(traversalnode->right);
    }

    printf("%d ", traversalnode->data);
}

int main()
{
    struct node *rootnode = NULL;

    // Inserting nodes
    rootnode = insertion(rootnode, 12);
    rootnode = insertion(rootnode, 5);
    rootnode = insertion(rootnode, 15);
    rootnode = insertion(rootnode, 3);
    rootnode = insertion(rootnode, 7);
    rootnode = insertion(rootnode, 13);
    rootnode = insertion(rootnode, 17);
    rootnode = insertion(rootnode, 16);
    rootnode = insertion(rootnode, 1);
    rootnode = insertion(rootnode, 9);
    rootnode = insertion(rootnode, 14);
    rootnode = insertion(rootnode, 20);
    rootnode = insertion(rootnode, 8);
    rootnode = insertion(rootnode, 11);
    rootnode = insertion(rootnode, 18);

    printf("Before Deletion\n");
    // Printing the tree
    printTree(rootnode, 0);

    deletion(rootnode, 3);
    deletion(rootnode, 7);
    deletion(rootnode, 18);

    printf("\n");
    printf("\n");
    printf("After Deletion\n");
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