// testcase 20,10,5,30,40,25,7,35,47,59,68,23,21,2

#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *left;
    struct node *right;
};

struct node *newNode(int data)
{
    struct node *node = (struct node *)malloc(sizeof(struct node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return (node);
}

void printTree(struct node *root, int level)
{
    if (root == NULL)
    {
        return;
    }
    printTree(root->right, level + 1);
    for (int i = 0; i < level; i++)
    {
        printf("|\t");
    }
    printf("|------>%d\n", root->data);
    printTree(root->left, level + 1);
}

int getMaxHeight(struct node *rootnode)
{
    if (rootnode == NULL)
    {
        return 0;
    }
    else
    {
        int leftHeight = getMaxHeight(rootnode->left);
        int rightHeight = getMaxHeight(rootnode->right);

        if (leftHeight > rightHeight)
        {
            return (leftHeight + 1);
        }
        else
        {
            return (rightHeight + 1);
        }
    }
}

void getBalanceFactor(struct node *rootnode)
{
    int balancefactor = getMaxHeight(rootnode->left) - getMaxHeight(rootnode->right);

    printf("CUR %d \t BF %d \t", rootnode->data, balancefactor);

    if (balancefactor < -1 || balancefactor > 1)
    {
        printf("IMBALANCE!\n");
    }
    else
    {
        printf("\n");
    }

    if (rootnode->left != NULL)
    {
        getBalanceFactor(rootnode->left);
    }

    if (rootnode->right != NULL)
    {
        getBalanceFactor(rootnode->right);
    }
}

struct node *rotateRight(struct node *parentnode)
{
    struct node *pivotnode = parentnode->left;
    if (pivotnode == NULL || parentnode == NULL)
    {
        return NULL;
    }

    parentnode->left = pivotnode->right;
    pivotnode->right = parentnode;

    return pivotnode;
}

struct node *rotateLeft(struct node *parentnode)
{
    struct node *pivotnode = parentnode->right;
    if (pivotnode == NULL || parentnode == NULL)
    {
        return NULL;
    }

    parentnode->right = pivotnode->left;
    pivotnode->left = parentnode;

    return pivotnode;
}

int main()
{
    printf("ROTATE RIGHT:\n");
    struct node *leftskewtree = newNode(20);
    leftskewtree->left = newNode(10);
    leftskewtree->left->left = newNode(5);

    printTree(leftskewtree, 0);

    printf("MAX HEIGHT %d\n", getMaxHeight(leftskewtree));

    getBalanceFactor(leftskewtree);

    printf("\n");

    leftskewtree = rotateRight(leftskewtree);
    printTree(leftskewtree, 0);

    printf("\n\n\n");

    printf("ROTATE LEFT: \n");
    struct node *rightskewtree = newNode(20);
    rightskewtree->right = newNode(10);
    rightskewtree->right->right = newNode(5);

    printTree(rightskewtree, 0);

    printf("MAX HEIGHT %d\n", getMaxHeight(rightskewtree));

    getBalanceFactor(rightskewtree);

    printf("\n");

    rightskewtree = rotateLeft(rightskewtree);
    printTree(rightskewtree, 0);

    return 0;
}