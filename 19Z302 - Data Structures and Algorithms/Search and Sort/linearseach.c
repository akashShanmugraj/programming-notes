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
    
    int testcasesizevar, scanplaceholder;

    fscanf(fp, "%d", &testcasesizevar);
    
    int* testcasepointer = (int*)malloc(testcasesizevar * sizeof(int));

    for (int iterable = 0; iterable < testcasesizevar; iterable++){
        fscanf(fp, "%d", &scanplaceholder);
        *(testcasepointer + iterable) = scanplaceholder;
    }

    fclose(fp);

    linearsearch(testcasepointer, testcasesizevar, searchelement);
    
}

int run(char filename[], int searchelement){
    printf("Scanning in `%s` for %d \n", filename, searchelement);
    clock_t start = clock();

    readFile(filename, searchelement);

    clock_t end = clock();
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