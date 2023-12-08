#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *left;
    struct node *right;
};

struct node *constructtree(int inorder[], int preorder[], int start, int end);
void inorderTraversal(struct node *root);
int searchfunction(int treeobject[], int start, int end, int value);

struct node *constructtree(int inorder[], int preorder[], int start, int end)
{
    if (start > end)
        return NULL;

    static int index = 0;
    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data = preorder[index++];
    newnode->left = NULL;
    newnode->right = NULL;

    if (start == end)
        return newnode;

    int index1 = searchfunction(inorder, start, end, newnode->data);

    newnode->left = constructtree(inorder, preorder, start, index1 - 1);
    newnode->right = constructtree(inorder, preorder, index1 + 1, end);

    return newnode;
}

void inorderTraversal(struct node *root)
{
    if (root == NULL)
        return;

    inorderTraversal(root->left);
    printf("%d ", root->data);
    inorderTraversal(root->right);
}

int searchfunction(int treeobject[], int start, int end, int value)
{
    for (int iterable = start; iterable <= end; iterable++)
    {
        if (treeobject[iterable] == value)
            return iterable;
    }
    return -1;
}

int searchfunction(int treeobject[], int start, int end, int value)
{
    int iterable;
    for (iterable = start; iterable <= end; iterable++)
    {
        if (treeobject[iterable] == value)
            return iterable;
    }
    return 0;
}

struct node *constructtree(int inorder[], int preorder[], int start, int end)
{
    int index = 0;

    if (start > end)
        return NULL;

    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data = preorder[index++];
    newnode->left = NULL;
    newnode->right = NULL;

    if (start == end)
        return newnode;

    int index1 = searchfunction(inorder, start, end, newnode->data);

    newnode->left = constructtree(inorder, preorder, start, index1 - 1);
    newnode->right = constructtree(inorder, preorder, index1 + 1, end);

    return newnode;
}

void inorderTraversal(struct node *root)
{
    if (root == NULL)
        return;

    inorderTraversal(root->left);
    printf("%d ", root->data);
    inorderTraversal(root->right);
}