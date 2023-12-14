#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Definition for a binary tree node.
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

// The provided function kth and kthSmallest

int kthsmallest(struct TreeNode *rootnode, int * counterpointer, int k)
{
    if (rootnode == NULL || *counterpointer >= k) {
        return -1;
    }

    int left = kthsmallest(rootnode->left, counterpointer, k);

    if (*counterpointer == k) {
        return left; // return the kth smallest from the left subtree if found
    }

    *counterpointer = *counterpointer + 1;

    if (*counterpointer == k) {
        return rootnode->val;
    }

    return kthsmallest(rootnode->right, counterpointer, k);
}

struct TreeNode* newNode(int val) {
    struct TreeNode* node = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    node->val = val;
    node->left = NULL;
    node->right = NULL;
    return node;
}

// Function to insert nodes into the tree
struct TreeNode* insert(struct TreeNode* root, int val) {
    if (root == NULL) return newNode(val);

    if (val < root->val)
        root->left = insert(root->left, val);
    else if (val > root->val)
        root->right = insert(root->right, val);

    return root;
}

// Function to generate a BST with given elements
struct TreeNode* generateBST(int arr[], int n) {
    struct TreeNode* root = NULL;
    for (int i = 0; i < n; i++) {
        root = insert(root, arr[i]);
    }
    return root;
}

// Function to measure execution time of kthSmallest function
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

double measureTime(struct TreeNode* root, int k, int *position) {
    struct timespec start, end;
    double cpu_time_used;
    int counter = 0;

    clock_gettime(CLOCK_MONOTONIC, &start);
    *position = kthsmallest(root, &counter, k); // Corrected function name
    clock_gettime(CLOCK_MONOTONIC, &end);

    cpu_time_used = (end.tv_sec - start.tv_sec) + (double)(end.tv_nsec - start.tv_nsec) / 1e9;
    return cpu_time_used;
}

int main() {
    srand(time(NULL)); // Seed for random numbers
    FILE *fp;

    // Open the file in write mode
    fp = fopen("benchmarks.csv", "w");
    if (fp == NULL) {
        printf("Error opening file.\n");
        return 1;
    }

    // Write header to the CSV file
    fprintf(fp, "Test Case,Array Size,Kth Smallest Element Position,Runtime\n");

    for (int i = 0; i < 100000; i++) {
        int size = rand() % 100000 + 1; // Generate array size between 1 to 100000
        int testData[size];

        // Generate random integers for test data
        for (int j = 0; j < size; j++) {
            testData[j] = rand() % 1000; // Random integers between 0 to 999
        }

        struct TreeNode* root = generateBST(testData, size);

        int position;
        double runtime = measureTime(root, rand() % size + 1, &position); // Random k value between 1 to size
        if(position!=0){
            fprintf(fp, "%d,%d,%d,%f\n", i + 1, size, position, runtime);
        }
    }

    fclose(fp); // Close the file

    return 0;
}