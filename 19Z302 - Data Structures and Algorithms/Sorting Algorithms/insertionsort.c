#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void insertionsort(int* numberarray, int samplelength){
    int i,k,key;
    printf("    SORT START\n");
    // insertion sort with two for loops
    for (i = 1; i < samplelength; i++){
        key = *(numberarray+i);
        k = i - 1;
        while (k >= 0 && *(numberarray+k) > key){
            *(numberarray+k+1) = *(numberarray+k);
            k = k - 1;
        }
        *(numberarray+k+1) = key;
    }

    printf("    SORT DONE\n");
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

    insertionsort(sampleArrayPtr, sampleLengthVar);
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
    run("./Testcases/1000nearlysorted3.txt");
    run("./Testcases/10K.ascending.txt");
    run("./Testcases/10K.descending.txt");
    run("./Testcases/10K.random.txt");

    
    

}