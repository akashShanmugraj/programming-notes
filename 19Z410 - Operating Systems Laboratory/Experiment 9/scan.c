#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#define NUM_QUERIES 10

void swap(int * a, int i)
{
    int tmp;
    tmp = a[i];
    a[i] = a[i + 1];
    a[i + 1] = tmp;
}

void bsort(int * a, int n)
{
    int comparisons = 0, swaps = 0, flag;
    for (int i = 0; i < n - 1; i++)
    {
        flag = 1;
        for (int j = 0; j < n - i - 1; j++)
        {
            //comparisons++;
            if (a[j] > a[j + 1])
            {
                swap(a, j);
                //swaps++;
                flag = 0;
            }
        }
        if (flag) break;
    }
    //printf("\nComparisons: %i\nSwaps: %i\n", comparisons, swaps);
}

void removeIndex(int *a, int *n, int index)
{
    if (index < 0 || index >= *n)
    {
        printf("Invalid index\n");
        return;
    }

    for (int i = index; i < *n - 1; i++)
    {
        a[i] = a[i + 1];
    }

    (*n)--;
}

int main(){
    int queue[NUM_QUERIES];
    int i;
    srand(time(NULL));
    for(i = 0; i < NUM_QUERIES; i++){
        queue[i] = rand() % 501;
        printf("%d ",queue[i]);
    }
    bsort(queue,NUM_QUERIES);
    printf("Sorted queries: \n");
    for(i = 0; i < NUM_QUERIES; i++){
        printf("%d ",queue[i]);
    }
    int headPos = rand() % 501;
    int ogHeadPos = headPos;
    int lb = 0;
    int ub = 500;

    int* ptr = queue;
    i = 0;
    printf("Head starts at %d\n",headPos);
    do{
        i++;
    }while(headPos > queue[i]);
    printf("\nHead first goes to %d at index %d\n",queue[i],i);

    while(i < NUM_QUERIES){
        headPos = queue[i];
        printf("Head at position %d\n",headPos);
        i++;
    }
    headPos = ub;
    printf("Head moves to %d",headPos);
    do{
        i--;
    }while(ogHeadPos < queue[i]);
    headPos = ogHeadPos;
    while(i < 0){
        headPos = queue[i];
        printf("Head at position %d\n",headPos);
        i++;
    }
}

