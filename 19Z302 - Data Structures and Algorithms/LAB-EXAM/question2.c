// construct tree from inorder and preorder
#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *left;
    struct node *right;
};

int searchfunction(int arr[], int start, int end, int value)
{
    int i;
    for (i = start; i <= end; i++)
    {
        if (arr[i] == value)
            return i;
    }
    return -1;
}

struct node *buildTree(int inorder[], int preorder[], int start, int end)
{
    static int preIndex = 0;

    if (start > end)
        return NULL;

    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    newNode->data = preorder[preIndex++];
    newNode->left = NULL;
    newNode->right = NULL;

    if (start == end)
        return newNode;

    int inIndex = searchfunction(inorder, start, end, newNode->data);

    newNode->left = buildTree(inorder, preorder, start, inIndex - 1);
    newNode->right = buildTree(inorder, preorder, inIndex + 1, end);

    return newNode;
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
    printf("\n\n");

    // test case 1
    printf("TC1\n");
    int preorder1[5] = {3, 9, 20, 15, 7};
    int inorder1[5] = {9, 3, 15, 20, 7};

    int n = sizeof(inorder1) / sizeof(inorder1[0]);

    struct node *root = buildTree(inorder1, preorder1, 0, n - 1);

    printf("TREE \n");
    inorderTraversal(root);

    printf("\n\n");

    // test case 2
    printf("TC2\n");
    int preorder2[0] = {};
    int inorder2[0] = {};
    n = sizeof(inorder2) / sizeof(inorder2[0]);

    root = buildTree(inorder2, preorder2, 0, n - 1);

    printf("TREE \n");
    inorderTraversal(root);

    printf("\n\n");

    // test case 3
    printf("TC3\n");
    int preorder3[1] = {1};
    int inorder3[1] = {1};
    n = sizeof(inorder3) / sizeof(inorder3[0]);

    root = buildTree(inorder3, preorder3, 0, n - 1);

    printf("TREE \n");
    inorderTraversal(root);

    printf("\n\n");

    // test case 4
    printf("TC4\n");
    int preorder4[3] = {3, 2, 1};
    int inorder4[3] = {1, 2, 3};
    n = sizeof(inorder4) / sizeof(inorder4[0]);

    root = buildTree(inorder4, preorder4, 0, n - 1);

    printf("TREE \n");
    inorderTraversal(root);

    printf("\n\n");

    // test case 5
    printf("TC5\n");
    int preorder5[3] = {1, 2, 3};
    int inorder5[3] = {1, 2, 3};
    n = sizeof(inorder5) / sizeof(inorder5[0]);

    root = buildTree(inorder5, preorder5, 0, n - 1);

    printf("TREE \n");
    inorderTraversal(root);

    printf("\n\n");

    // test case 6
    printf("TC6\n");
    int preorder6[8] = {7, 10, 4, 3, 1, 2, 8, 11};
    int inorder6[8] = {4, 10, 3, 1, 7, 11, 8, 2};
    n = sizeof(inorder6) / sizeof(inorder6[0]);

    root = buildTree(inorder6, preorder6, 0, n - 1);

    printf("TREE \n");
    inorderTraversal(root);

    return 0;
}
