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

void display_tree(struct node *root, int level)
{
    if (root == NULL)
    {
        return;
    }
    display_tree(root->right, level + 1);
    for (int i = 0; i < level; i++)
    {
        printf("|\t");
    }
    printf("|------>%d\n", root->data);
    display_tree(root->left, level + 1);
}

struct node* invertTree(struct node* root) {

    // if (root->left && root->right){
    //     temppointer = root->left;
    //     root->left = root->right;
    //     root->right = root->left;
    //     root->left = (root->left, temppointer);
    //     root->right = (root->right, temppointer);
    // } else if (root->left && !root->right){
    //     root->right = root->left;
    //     root->left = NULL;
    //     invertTree(root->right, temppointer);
    // } else if (!root->left && root->right){
    //     root->left = root->right;
    //     root->right = NULL;
    //     invertTree(root->left, temppointer);
    // }

    if (root == NULL) {
        return NULL;
    }

    struct node* temp = root->left;
    root->left = invertTree(root->right);
    root->right = invertTree(temp);

    return root;
}

int maxDepth(struct node* root){
    if (root == NULL){
        return 0;
    }

    int LHeight = maxDepth(root->left);
    int RHeight = maxDepth(root->right);

    if (LHeight > RHeight){
        return LHeight+1;
    } else {
        return RHeight+1;
    }

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
    rootnode = insertion(rootnode, 1);

    printf("BEFORE INVERT\n");

    display_tree(rootnode, 0);

    struct node * traversalpointer = malloc(sizeof(struct node));

    // invertTree(rootnode);

    // printf("AFTER INVERT\n");

    // display_tree(rootnode, 0);
    
    return 0;
}