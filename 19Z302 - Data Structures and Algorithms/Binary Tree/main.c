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

struct node *findminimum(struct node *rootnode)
{
    if (rootnode->left != NULL)
    {
        return findminimum(rootnode->left);
    }
    return rootnode;
}

struct node *search(struct node *root, int target, int *child_side)
{
    if (root->data == target)
    {
        *child_side = 0;
        return root;
    }
    else if (root->left->data == target)
    {
        *child_side = 1;
        return root;
    }
    else if (root->right->data == target)
    {
        *child_side = 2;
        return root;
    }
    else if (target < root->data)
    {
        search(root->left, target, child_side);
    }
    else if (target > root->data)
    {
        search(root->right, target, child_side);
    }
    else
    {
    }
}

struct node *deletion(struct node *rootnode, int data)
{
    struct node *traversalpointer = rootnode;
    struct node *parentpointer = NULL;

    while (traversalpointer->data != data)
    {
        printf("%d - ", traversalpointer->data);
        if (data < traversalpointer->data)
        {
            parentpointer = traversalpointer;
            traversalpointer = traversalpointer->left;
        }
        else if (data > traversalpointer->data)
        {
            parentpointer = traversalpointer;
            traversalpointer = traversalpointer->right;
        }
    }

    printf("\nDEL DATA: %d\n", traversalpointer->data);

    if ((traversalpointer->left && !traversalpointer->right) || (!traversalpointer->left && traversalpointer->right))
    {
        if (traversalpointer->left)
        {
            printf("Left Child Only\n");
            parentpointer->left = traversalpointer->left;
        }
        else if (traversalpointer->right)
        {
            printf("Right Child Only\n");
            parentpointer->right = traversalpointer->right;
        }
        free(traversalpointer);
    }
    else if (!traversalpointer->right && !traversalpointer->left)
    {
        printf("No Child\n");
        if (parentpointer->data < data)
        {
            parentpointer->right = NULL;
            free(traversalpointer);
        }
        else if (parentpointer->data > data)
        {
            parentpointer->left = NULL;
            free(traversalpointer);
        }
    }
    else
    {
        printf("Two Children\n");
        struct node *inordersucessor = findminimum(traversalpointer->right);
        printf("INORDER SUCCESSOR IS %d\n", inordersucessor->data);
        int finder = 0;
        int *finderpointer = &finder;

        struct node *searchresult = search(rootnode, inordersucessor->data, finderpointer);

        if (*(finderpointer) == 1)
        {
            searchresult->left = NULL;
        }
        else if (*(finderpointer) == 2)
        {
            searchresult->right = NULL;
        }
        else if (*(finderpointer) == 0)
        {
            printf("UNKNOWN CASE\n");
        }

        traversalpointer->data = inordersucessor->data;
        free(inordersucessor);
    }

    return rootnode;
}

struct node *insertion(struct node *rootnode, int data)
{
    struct node *traversalpointer = rootnode;

    struct node *newnode = getNode(data);

    if (!rootnode)
    {
        return newnode;
    }
    while (traversalpointer)
    {
        if (traversalpointer->data < data && traversalpointer->right != NULL)
        {
            traversalpointer = traversalpointer->right;
        }
        else if (traversalpointer->data >= data && traversalpointer->left != NULL)
        {
            traversalpointer = traversalpointer->left;
        }
        else
        {
            break;
        }
    }

    if (traversalpointer->data < data)
    {
        traversalpointer->right = newnode;
    }
    else if (traversalpointer->data >= data)
    {
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

void iterinorder(struct node * rootnode){
    struct node * current = rootnode;
    struct node * stack[100];

    int top = -1;

    while (current != NULL || top != -1){
        while (current != NULL){
            stack[top] = current;
            top = top + 1;
            current = current->left;
        }

        current = stack[top];
        top = top - 1;
        printf(" %d ", current->data);
        current = current->right;
    }
}

void iterpreorder(struct node * rootnode){
    if (rootnode == NULL){
        return ;
    }

    struct node * stack[100];
    int top = -1;
    stack[++top] = rootnode;

    while (top != -1){
        struct node * current = stack[top];
        top = top - 1;

        printf(" %d ", current->data);

        if (current->right != NULL){
            stack[++top] = current->right;
        }
        if (current->left != NULL){
            stack[++top] = current->left;
        }
    }
}

void iterpostorder1(struct node * rootnode){
    if (rootnode == NULL){
        return ;
    }

    struct node * stack1[100];
    struct node * stack2[100];
    int top1 = -1, top2 = -1;
    stack1[++top1] = rootnode;

    while (top1 != -1){
        struct node * current = stack1[top1--];
        stack2[++top2] = current;

        if (current->left != NULL){
            stack1[++top1] = current->left;
        }
        if (current->right != NULL){
            stack1[++top1] = current->right;
        }
    }

    while (top2 != -1){
        struct node * current = stack2[top2--];
        printf(" %d ", current->data);
    }
}

void iterpostorder2(struct node * rootnode){
    if (rootnode == NULL){
        return ;
    }

    struct node * stack[100];
    int top = -1;
    struct node * current = rootnode;
    struct node * visited = NULL;

    do {
        while (current != NULL){
            stack[++top] = current;
            current = current->left;
        }
        current = stack[top];
        if (current->right == NULL || current->right == visited){
            printf(" %d ", current->data);
            top--;
            visited = current;
            current = NULL;
        } else {
            current = current->right;
        }
    } while (top != -1);
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
    rootnode = insertion(rootnode, 6);

    printf("Before Deletion\n");
    // Printing the tree
    printTree(rootnode, 0);
    display_tree(rootnode, 0);

    deletion(rootnode, 5);
    // deletion(rootnode, 7);
    // deletion(rootnode, 18);

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
