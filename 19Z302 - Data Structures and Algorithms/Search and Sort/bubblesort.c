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
    printf("\n");
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
    
    bubblesort(testcasepointer, testcasesizevar);
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
    run("./Testcases/1000nearlysorted3.txt");\
    run("./Testcases/100K.ascending.txt");
    run("./Testcases/100K.descending.txt");
    run("./Testcases/100K.random.txt");
}