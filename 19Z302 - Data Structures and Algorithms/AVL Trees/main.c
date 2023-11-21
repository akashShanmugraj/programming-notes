#include <stdio.h>
#include <stdlib.h>

// Step 1: Define a struct for the tree node
struct node {
    int data;
    struct node* left;
    struct node* right;
};

// Step 2: Create a function to create a new node
struct node* newNode(int data) {
    struct node* node = (struct node*)malloc(sizeof(struct node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return(node);
}

// Step 3: Create a function to print the tree
void printTree(struct node * rootnode, int level) {
    if (rootnode == NULL) {
        return;
    }
    printTree(rootnode -> right, level + 1);
    for (int i = 0; i < level; i++) {
        printf("    ");
    }
    printf("%d", rootnode -> data);
    printTree(rootnode -> left, level + 1);
}

int getMaxHeight(struct node * rootnode){
    if (rootnode == NULL){
        return 0;
    }
    else {
        int leftHeight = getMaxHeight(rootnode->left);
        int rightHeight = getMaxHeight(rootnode->right);
        
        if (leftHeight > rightHeight) {
            return(leftHeight + 1);
        }
        else {
            return(rightHeight + 1);
        }
    }
}

void getBalanceFactor(struct node * rootnode){
    int balancefactor = getMaxHeight(rootnode->left)-getMaxHeight(rootnode->right);

    printf("CUR %d \t BF %d \t", rootnode->data, balancefactor);

    if (balancefactor < -1 || balancefactor > 1){
        printf("IMBALANCE!\n");
    } else {
        printf("\n");
    }

    if (rootnode->left != NULL){
        getBalanceFactor(rootnode->left);
    }
    
    if (rootnode->right != NULL){
        getBalanceFactor(rootnode->right);
    }
}

struct node * rotateRight(struct node * pivotnode, struct node * parentnode){
    if (pivotnode->right == NULL){
        pivotnode->right = parentnode;
    } else {
        struct node * pivotrightnode = pivotnode->right;
        pivotnode->right = parentnode;
        parentnode->left = pivotrightnode;
    }

    return pivotnode;
}
int main() {
    // Step 4: Create 3 nodes and link them to form a left-skewed tree
    struct node *root = newNode(20);
    root->left = newNode(10);
    root->left->left = newNode(5);


    // Step 5: Call the printTree function to print the tree
    printTree(root, 0);

    int * leftcounterpointer = 0;
    int * rightcounterpointer = 0;

    // printf("MAX HEIGHT %d\n", getMaxHeight(root));

    // getBalanceFactor(root);

    printf("\n");

    root = rotateRight(root->left, root);
    printTree(root, 0);

    printf("RT-VAL %d\n", root->data);
    printf("RT-LVAL %d\n", root->left->data);
    printf("RT-RVAL %d\n", root->right->data);

    return 0;
}