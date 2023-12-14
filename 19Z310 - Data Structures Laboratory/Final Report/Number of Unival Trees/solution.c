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
    struct node *newnode = malloc(sizeof(struct node));
    newnode->data = data;
    newnode->left = NULL;
    newnode->right = NULL;

    return newnode;
}

void printTree(struct node *rootnode, int level, int ccode, int ctarget)
{
    if (rootnode == NULL)
    {
        return;
    }
    printTree(rootnode->right, level + 1, ccode, ctarget);
    for (int i = 0; i < level; i++)
    {
        printf("    ");
    }
    if (ccode == 1){
        if (rootnode->data == ctarget){
            printf("\033[1;31m");
        }
    }
    else if (ccode == 2){
        if (rootnode->data == ctarget){
            printf("\033[1;31m");
        }
    }
    printf("%d\n", rootnode->data);
    printTree(rootnode->left, level + 1, ccode, ctarget);
}

int countunival(struct node *root, int *counterpointer)
{
    if (root == NULL) {
        return 1;
    }

    int left = countunival(root->left, counterpointer);
    int right = countunival(root->right, counterpointer);

    if (left && right) {
        if (root->left && root->data != root->left->data) {
            return 0;
        }
        if (root->right && root->data != root->right->data) {
            return 0;
        }

        (*counterpointer)++;
        return 1;
    }

    return 0;
}

int main()
{
    struct node *rootnode = getnode(10);
    rootnode->left = getnode(10);
    rootnode->right = getnode(20);

    rootnode->left->left = getnode(9);
    rootnode->left->right = getnode(10);

    rootnode->right->right = getnode(20);
    rootnode->right->left = getnode(20);

    printTree(rootnode, 0, 1, 10);

    int univalcounter = 0;
    int *univalcounterpointer = &univalcounter;

    countunival(rootnode, univalcounterpointer);

    printf("%d\n", *(univalcounterpointer));
    return 0;
}