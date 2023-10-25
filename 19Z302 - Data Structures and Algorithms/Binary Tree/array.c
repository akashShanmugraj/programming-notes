#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// print binary tree
void display(int *binarytree, int size)
{
    for (int i = 0; i < pow(2, size) - 1; i++)
    {
        printf("BT%d: %d\n", i, binarytree[i]);
    }
}

int main()
{
    int size = 0;
    printf("Enter total number of elements in the Binary Tree: ");
    scanf("%d", &size);

    int *binarytree = (int *)calloc(pow(2, size) - 1, sizeof(int));
    printf("NOTE: Empty nodes are represented by 0\n");

    printf("Enter value of root node: ");
    scanf("%d", &binarytree[0]);

    for (int nodeiterable = 0; nodeiterable < size; nodeiterable++)
    {
        int currentnodeval = binarytree[nodeiterable];
        if (currentnodeval == 0)
        {
            continue;
        }

        int lnodepointer = 2 * nodeiterable + 1;
        printf("Enter value of left node of %d: ", currentnodeval);
        scanf("%d", &binarytree[lnodepointer]);

        if (binarytree[lnodepointer] != 0)
        {
            int rnodepointer = 2 * nodeiterable + 2;
            printf("Enter value of right node of %d: ", currentnodeval);
            scanf("%d", &binarytree[rnodepointer]);
        }
    }

    display(binarytree, size);
    free(binarytree);
    return 0;
}