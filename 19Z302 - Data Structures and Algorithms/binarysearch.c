#include<stdio.h>   
#include<time.h>
#include<stdlib.h>

int binarysearch(int* sortedarraypointer, int arraysize,  int searchelement){
    int searchstartindex = 0;
    int searchendindex = arraysize - 1;
    int mid = (searchstartindex + searchendindex)/2;
    while(searchstartindex <= searchendindex){
        if(sortedarraypointer[mid] == searchelement){
            return mid;
            break;
        }
        else if(sortedarraypointer[mid] < searchelement){
            searchstartindex = mid + 1;
        }
        else{
            searchendindex = mid - 1;
        }
        mid = (searchstartindex + searchendindex)/2;
    }
    if(searchstartindex > searchendindex){
        return -1;
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

    binarysearch(testcasepointer, testcasesizevar, searchelement);
    
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

    run("./Testcases/100K.ascending.txt", 1);
    run("./Testcases/100K.ascending.txt", 100000);
    run("./Testcases/100K.ascending.txt", 50000);
    run("./Testcases/100K.ascending.txt", 42354);

    printf("\n\n");


}

