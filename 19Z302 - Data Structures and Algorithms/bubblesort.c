#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void bubblesort(int* numberarray, int samplelength){
    printf("    SORT START\n");
    int temp;
    int counter = 0;
    for (int i = 0; i < samplelength; i++){
        for (int j = 0; j < samplelength - i - 1; j ++){
            counter++;
            // printf("    SORT-ITR: %d\r", counter);
            if (*(numberarray+j) > *(numberarray+j+1)){
                printf("    SWAP %d %d\r", *(numberarray+j), *(numberarray+j+1));
                temp = *(numberarray+j);
                *(numberarray+j) = *(numberarray+j+1);
                *(numberarray+j+1) = temp;
            }
        }
    }
    printf("\n");
    printf("    SORT DONE\n");
    // for (int iterable = 0; iterable < samplelength; iterable++){
    //     printf("%d ", *(numberarray+iterable));
    // }
    printf("\n");
}

int* readFile(char filename[]){
    FILE *fp;
    fp = fopen(filename, "r");
    
    int sampleLengthVar, sampleElement;

    fscanf(fp, "%d", &sampleLengthVar);
    printf("Scanning a sample of length: %d\n", sampleLengthVar);

    printf("    ALLOC-PTR_START\n");
    int* sampleArrayPtr = (int*)malloc(sampleLengthVar * sizeof(int));
    printf("    ALLOC-PTR_END\n");

    printf("    SCN-START\n");
    for (int iterable = 0; iterable < sampleLengthVar; iterable++){
        printf("    SCN-ITR: %d\r", iterable);
        fscanf(fp, "%d", &sampleElement);
        *(sampleArrayPtr + iterable) = sampleElement;
    }
    printf("\n");
    printf("    SCN-END\n");

    fclose(fp);

    bubblesort(sampleArrayPtr, sampleLengthVar);
}


int run(char filename[]){
    printf("Scanning for and sorting `%s` \n", filename);
    clock_t start = clock(); // start the timer

    readFile(filename);

    clock_t end = clock(); // end the timer
    double time_spent = (double)(end - start) / CLOCKS_PER_SEC;
    printf("Time spent: %f\n", time_spent);
    printf("\n\n");
}

int main() {
    run("./Testcases/1000nearlysorted1.txt");
    run("./Testcases/1000nearlysorted2.txt");
    run("./Testcases/1000nearlysorted3.txt");\
    run("./Testcases/100K.ascending.txt");
    run("./Testcases/100K.descending.txt");
    run("./Testcases/100K.random.txt");
}