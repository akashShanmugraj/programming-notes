#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *left;
    struct node *right;
};

struct node *getnode(int data)
{
    struct node *newnode = malloc(sizeof(struct node *));
    newnode->data = data;
    newnode->left = NULL;
    newnode->right = NULL;

    return newnode;
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

void countunival(struct node *root, int *counterpointer)
{
    if (root == NULL) {
        return;
    }

    if (root->left != NULL && root->right != NULL) {
        printf("C:%d L:%d R:%d\n", root->data, root->left->data, root->right->data);
        if (root->left->data == root->data && root->right->data == root->data)
        {
            printf("MATCH1\n");
            *(counterpointer) = *(counterpointer) + 1;
            printf("NOW %d\n", *(counterpointer));
        }
        countunival(root->left, counterpointer);
        countunival(root->right, counterpointer);
    }
    else if (root->left != NULL) {
        printf("C:%d L:%d\n", root->data, root->left->data);
        if (root->left->data == root->data)
        {
            printf("MATCH2\n");
            *(counterpointer) = *(counterpointer) + 1;
        }
        countunival(root->left, counterpointer);
    }
    else if (root->right != NULL) {
        printf("C:%d R:%d\n", root->data, root->right->data);
        if (root->right->data == root->data)
        {
            printf("MATCH3\n");
            *(counterpointer) = *(counterpointer) + 1;
        }
        countunival(root->right, counterpointer);
    }
    else {
        printf("C:%d\n", root->data);
    }
}int main()
{
    struct node *rootnode = getnode(10);
    rootnode->left = getnode(10);
    rootnode->right = getnode(20);

    rootnode->left->left = getnode(10);
    rootnode->left->right = getnode(10);

    rootnode->right->right = getnode(20);
    rootnode->right->left = getnode(20);

    printTree(rootnode, 0);

    int univalcounter = 0;
    int *univalcounterpointer = &univalcounter;

    countunival(rootnode, univalcounterpointer);

    printf("%d\n", *(univalcounterpointer));
    return 0;
}