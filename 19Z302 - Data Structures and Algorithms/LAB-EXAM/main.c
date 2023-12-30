#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *left;
    struct node *right;
};

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

int main()
{
    // test case 1
    printf("TC1\n");
    int preorder1[5] = {3, 9, 20, 15, 7};
    int inorder1[5] = {9, 3, 15, 20, 7};

    int n = sizeof(inorder1) / sizeof(inorder1[0]);

    struct node *root = constructtree(inorder1, preorder1, 0, n - 1);

    printf("Inorder traversal of the constructed tree: ");
    inorderTraversal(root);

    // test case 2
    printf("TC2\n");
    int preorder2[0] = {};
    int inorder2[0] = {};
    n = sizeof(inorder2) / sizeof(inorder2[0]);

    root = constructtree(inorder2, preorder2, 0, n - 1);

    printf("Inorder traversal of the constructed tree: ");
    inorderTraversal(root);

    // test case 3
    printf("TC3\n");
    int preorder3[1] = {1};
    int inorder3[1] = {1};
    n = sizeof(inorder3) / sizeof(inorder3[0]);

    root = constructtree(inorder3, preorder3, 0, n - 1);

    printf("Inorder traversal of the constructed tree: ");
    inorderTraversal(root);

    // test case 4
    printf("TC4\n");
    int preorder4[3] = {3, 2, 1};
    int inorder4[3] = {1, 2, 3};
    n = sizeof(inorder4) / sizeof(inorder4[0]);

    root = constructtree(inorder4, preorder4, 0, n - 1);

    printf("Inorder traversal of the constructed tree: ");
    inorderTraversal(root);

    // test case 5
    printf("TC5\n");
    int preorder5[3] = {1, 2, 3};
    int inorder5[3] = {1, 2, 3};
    n = sizeof(inorder5) / sizeof(inorder5[0]);

    root = constructtree(inorder5, preorder5, 0, n - 1);

    printf("Inorder traversal of the constructed tree: ");
    inorderTraversal(root);

    // test case 6
    printf("TC6\n");
    int preorder6[8] = {7, 10, 4, 3, 1, 2, 8, 11};
    int inorder6[8] = {4, 10, 3, 1, 7, 11, 8, 2};
    n = sizeof(inorder6) / sizeof(inorder6[0]);

    root = constructtree(inorder6, preorder6, 0, n - 1);

    printf("Inorder traversal of the constructed tree: ");
    inorderTraversal(root);

    return 0;
}
