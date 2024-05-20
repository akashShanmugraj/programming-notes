#include<stdio.h>
#include<stdlib.h>

void firstcomefirstserve(int seeksequence[], int headpointer, int seeksequencesize) {
    int seekcounter = 0;
    int distancefromheadpointer, currenttrack;

    for (int seek = 0; seek < seeksequencesize; seek++){
        currenttrack = seeksequence[seek];

        distancefromheadpointer = abs(currenttrack - headpointer);

        seekcounter += distancefromheadpointer;

        headpointer = currenttrack;        
    }

    printf("Total Number of Seek Operations = %d\n", seekcounter);

    printf("Seek Sequence is \n");

    for (int i = 0; i<seeksequencesize;i++){
        printf("%d\n", seeksequence[i]);
    }
}

int main() {
    int arr[] = {176, 79, 34, 60, 92, 11, 41, 114};
    int head = 50;

    FCFS(arr, head, sizeof(arr) / sizeof(arr[0]));

    return 0;
}