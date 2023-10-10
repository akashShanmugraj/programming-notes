#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void insertionsort(int* numberarray, int samplelength){
    int variable1,variable2,key;

    for (variable1 = 1; variable1 < samplelength; variable1++){
        key = *(numberarray+variable1);
        variable2 = variable1 - 1;
        while (variable2 >= 0 && *(numberarray+variable2) > key){
            *(numberarray+variable2+1) = *(numberarray+variable2);
            variable2 = variable2 - 1;
        }
        *(numberarray+variable2+1) = key;
    }

}

int* readFile(char filename[]){
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
    
    insertionsort(testcasepointer, testcasesizevar);
}


int run(char filename[]){
    printf("Scanning for and sorting `%s` \n", filename);
    clock_t start = clock();

    readFile(filename);

    clock_t end = clock();
    double time_spent = (double)(end - start) / CLOCKS_PER_SEC;
    printf("Time spent: %f\n", time_spent);
    printf("\n\n");
}

int main() {
    run("./Testcases/1000nearlysorted1.txt");
    run("./Testcases/1000nearlysorted2.txt");
    run("./Testcases/1000nearlysorted3.txt");
    run("./Testcases/100K.ascending.txt");
    run("./Testcases/100K.descending.txt");
    run("./Testcases/100K.random.txt");
}