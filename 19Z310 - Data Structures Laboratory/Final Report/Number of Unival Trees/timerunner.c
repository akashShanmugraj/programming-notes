#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Definition for a binary tree node.
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

int countunival(struct TreeNode *root, int *counterpointer)
{
    if (root == NULL) {
        return 1;
    }

    int left = countunival(root->left, counterpointer);
    int right = countunival(root->right, counterpointer);

    if (left && right) {
        if (root->left && root->val != root->left->val) {
            return 0;
        }
        if (root->right && root->val != root->right->val) {
            return 0;
        }

        (*counterpointer)++;
        return 1;
    }

    return 0;
}

struct TreeNode* newNode(int val) {
    struct TreeNode* node = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    node->val = val;
    node->left = NULL;
    node->right = NULL;
    return node;
}

struct TreeNode* insert(struct TreeNode* root, int val) {
    if (root == NULL) return newNode(val);

    if (val < root->val)
        root->left = insert(root->left, val);
    else if (val > root->val)
        root->right = insert(root->right, val);

    return root;
}

struct TreeNode* generateBST(int arr[], int n) {
    struct TreeNode* root = NULL;
    for (int i = 0; i < n; i++) {
        root = insert(root, arr[i]);
    }
    return root;
}

double measureTime(struct TreeNode* root, int *univalCount) {
    struct timespec start, end;
    double cpu_time_used;
    int counter = 0;

    clock_gettime(CLOCK_MONOTONIC, &start);
    countunival(root, &counter);
    clock_gettime(CLOCK_MONOTONIC, &end);

    *univalCount = counter;
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
    fprintf(fp, "Test Case,Array Size,Unival Count,Runtime\n");

    for (int i = 0; i < 100000; i++) {
        int size = rand() % 100000 + 1; // Generate array size between 1 to 100000
        int testData[size];

        // Generate random integers for test val
        for (int j = 0; j < size; j++) {
            testData[j] = rand() % 1000; // Random integers between 0 to 999
        }

        struct TreeNode* root = generateBST(testData, size);

        int univalCount;
        double runtime = measureTime(root, &univalCount);
        fprintf(fp, "%d,%d,%d,%f\n", i + 1, size, univalCount, runtime);
    }

    fclose(fp); // Close the file

    return 0;
}