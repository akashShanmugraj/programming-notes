#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *leftchild;
    struct node *rightchild;
    int height;
};

int getMaximum(int a, int b)
{
    return (a > b) ? a : b;
}

int height(struct node *node)
{
    if (node == NULL)
    {
        return 0;
    }
    return node->height;
}

int getBalanceFactor(struct node *node)
{
    if (node == NULL)
    {
        return 0;
    }
    return height(node->leftchild) - height(node->rightchild);
}

struct node *rightRotate(struct node *parent)
{
    struct node *pivot = parent->leftchild;
    parent->leftchild = pivot->rightchild;
    pivot->rightchild = parent;
    parent->height = getMaximum(height(parent->leftchild), height(parent->rightchild)) + 1;
    pivot->height = getMaximum(height(pivot->leftchild), height(pivot->rightchild)) + 1;
    return pivot;
}

struct node *leftRotate(struct node *parent)
{
    struct node *pivot = parent->rightchild;
    parent->rightchild = pivot->leftchild;
    pivot->leftchild = parent;
    parent->height = getMaximum(height(parent->leftchild), height(parent->rightchild)) + 1;
    pivot->height = getMaximum(height(pivot->leftchild), height(pivot->rightchild)) + 1;
    return pivot;
}

struct node *insert(struct node *node, int data)
{
    if (node == NULL)
    {
        struct node *temp = (struct node *)malloc(sizeof(struct node));
        temp->data = data;
        temp->leftchild = NULL;
        temp->rightchild = NULL;
        temp->height = 0;
        return temp;
    }
    if (data < node->data)
    {
        node->leftchild = insert(node->leftchild, data);
    }
    else if (data > node->data)
    {
        node->rightchild = insert(node->rightchild, data);
    }
    else
    {
        return node;
    }
    node->height = getMaximum(height(node->leftchild), height(node->rightchild));
    int balanceFactor = getBalanceFactor(node);
    if (balanceFactor > 1)
    {
        if (data < node->leftchild->data)
        {
            return rightRotate(node);
        }
        else
        {
            node->leftchild = leftRotate(node->leftchild);
            return rightRotate(node);
        }
    }
    else if (balanceFactor < -1)
    {
        if (data > node->rightchild->data)
        {
            return leftRotate(node);
        }
        else
        {
            node->rightchild = rightRotate(node->rightchild);
            return leftRotate(node);
        }
    }
    return node;
}

void printInorder(struct node *node)
{
    if (node == NULL)
    {
        return;
    }
    printInorder(node->leftchild);
    printf("%d ", node->data);
    printInorder(node->rightchild);
}

void printTree(struct node *root, int level)
{
    if (root == NULL)
    {
        return;
    }
    printTree(root->rightchild, level + 1);
    for (int i = 0; i < level; i++)
    {
        printf("|\t");
    }
    printf("|------>%d\n", root->data);
    printTree(root->leftchild, level + 1);
}

struct node *deleteNode(struct node *root, int key)
{
    if (root == NULL)
    {
        return root;
    }
    if (key < root->data)
    {
        root->leftchild = deleteNode(root->leftchild, key);
    }
    else if (key > root->data)
    {
        root->rightchild = deleteNode(root->rightchild, key);
    }
    else
    {
        if (root->leftchild == NULL || root->rightchild == NULL)
        {
            struct node *temp = root->leftchild ? root->leftchild : root->rightchild;
            if (temp == NULL)
            {
                temp = root;
                root = NULL;
            }
            else
            {
                *root = *temp;
            }
            free(temp);
        }
        else
        {
            struct node *temp = minValueNode(root->rightchild);
            root->data = temp->data;
            root->rightchild = deleteNode(root->rightchild, temp->data);
        }
    }
    if (root == NULL)
    {
        return root;
    }
    root->height = getMaximum(height(root->leftchild), height(root->rightchild)) + 1;
    int balanceFactor = getBalanceFactor(root);
    if (balanceFactor > 1 && getBalanceFactor(root->leftchild) >= 0)
    {
        return rightRotate(root);
    }
    if (balanceFactor > 1 && getBalanceFactor(root->leftchild) < 0)
    {
        root->leftchild = leftRotate(root->leftchild);
        return rightRotate(root);
    }
    if (balanceFactor < -1 && getBalanceFactor(root->rightchild) <= 0)
    {
        return leftRotate(root);
    }
    if (balanceFactor < -1 && getBalanceFactor(root->rightchild) > 0)
    {
        root->rightchild = rightRotate(root->rightchild);
        return leftRotate(root);
    }
    return root;
}


int main()
{
    struct node *root = NULL;
    // 20,10,5,30,40,25,7,35,47,59,68,23,21,2
    root = insert(root, 20);
    root = insert(root, 10);
    root = insert(root, 5);
    root = insert(root, 30);
    root = insert(root, 40);
    root = insert(root, 25);
    root = insert(root, 7);
    root = insert(root, 35);
    root = insert(root, 47);
    root = insert(root, 59);
    root = insert(root, 68);
    root = insert(root, 23);
    root = insert(root, 21);
    root = insert(root, 2);

    printf("Inorder traversal of the constructed AVL tree is \n");
    printInorder(root);

    printf("\n");

    printTree(root, 0);

    return 0;
}