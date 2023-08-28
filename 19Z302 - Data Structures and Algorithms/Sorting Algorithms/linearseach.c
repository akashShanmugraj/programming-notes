#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int linearsearch(int *numberarray, int arraylength, int searchelement){
    for (int iterable = 0; iterable < arraylength; iterable++){
        if (*(numberarray+iterable) == searchelement){
            return iterable;
        }
    }
}

int* readFile(char filename[], int searchelement){
    FILE *fp;
    fp = fopen(filename, "r");
    
    int sampleLengthVar, sampleElement;

    fscanf(fp, "%d", &sampleLengthVar);
    printf("Scanning a sample of length: %d\n", sampleLengthVar);

    // printf("    ALLOC-PTR_START\n");
    int* sampleArrayPtr = (int*)malloc(sampleLengthVar * sizeof(int));
    // printf("    ALLOC-PTR_END\n");

    // printf("    SCN-START\n");
    for (int iterable = 0; iterable < sampleLengthVar; iterable++){
        // printf("    SCN-ITR: %d\r", iterable);
        fscanf(fp, "%d", &sampleElement);
        *(sampleArrayPtr + iterable) = sampleElement;
    }
    printf("\n");
    printf("    SCN-END\n");

    fclose(fp);

    linearsearch(sampleArrayPtr, sampleLengthVar, searchelement);
    
}


int run(char filename[], int searchelement){
    printf("Scanning in `%s` for %d \n", filename, searchelement);
    clock_t start = clock(); // start the timer

    readFile(filename, searchelement);

    clock_t end = clock(); // end the timer
    double time_spent = (double)(end - start) / CLOCKS_PER_SEC;
    printf("Time spent: %f\n", time_spent);
    printf("\n\n");
}

int main() {
    run("./Testcases/1000nearlysorted1.txt", 1);
    run("./Testcases/1000nearlysorted1.txt", 1000);
    run("./Testcases/1000nearlysorted1.txt", 500);
    run("./Testcases/1000nearlysorted1.txt", 658);

    printf("\n\n");

    run("./Testcases/100K.ascending.txt", 1);
    run("./Testcases/100K.ascending.txt", 100000);
    run("./Testcases/100K.ascending.txt", 50000);
    run("./Testcases/100K.ascending.txt", 42354);

    printf("\n\n");

    run("./Testcases/100K.descending.txt", 1);
    run("./Testcases/100K.descending.txt", 100000);
    run("./Testcases/100K.descending.txt", 50000);
    run("./Testcases/100K.descending.txt", 42354);

    printf("\n\n");

    run("./Testcases/100K.random.txt", 1);
    run("./Testcases/100K.random.txt", 100000);
    run("./Testcases/100K.random.txt", 50000);
    run("./Testcases/100K.random.txt", 42354);

}