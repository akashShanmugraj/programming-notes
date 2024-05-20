#include<stdio.h>
#include<stdbool.h>

#define numberofprocesses 3
#define numberofresources 4

int available[numberofresources];
int maximum[numberofprocesses][numberofresources];
int allocation[numberofprocesses][numberofresources];
int need[numberofprocesses][numberofresources];
bool finished[numberofprocesses];

bool issafestate() {
    int work[numberofresources];
    bool finish[numberofprocesses];

    for (int iterable = 0; iterable < numberofresources; iterable++){
        work[iterable] = available[iterable];
    }
    for (int iterable = 0; iterable < numberofprocesses; iterable++){
        finish[iterable] = false;
    }

    for (int processindex = 0; processindex < numberofprocesses; processindex++){
        if (!finished[processindex]) {
            bool canexecute = true;
            for (int resourceindex = 0; resourceindex < numberofresources; resourceindex++){
                if (need[processindex][resourceindex] > work[resourceindex]){
                    canexecute = false;
                    break;
                }
            }

            if (canexecute) {
                for (int resourceindex = 0; resourceindex < numberofresources; resourceindex ++) {
                    work[resourceindex] += allocation[processindex][resourceindex];
                }

                finish[processindex] = true;
                finished[processindex] = true;
                processindex = -1;
            }
        }
    }

    for (int processindex = 0; processindex < numberofprocesses; processindex ++) {
        if (!finish[processindex]){
            return false;
        }

    }
    return true;
}

int main() {
    available[0] = 10;
    available[1] = 5;
    available[2] = 7;
    available[3] = 8;

    maximum[0][0] = 7;
    maximum[0][1] = 5;
    maximum[0][2] = 3;
    maximum[0][3] = 2;

    maximum[1][0] = 3;
    maximum[1][1] = 2;
    maximum[1][2] = 2;
    maximum[1][3] = 2;

    maximum[2][0] = 9;
    maximum[2][1] = 0;
    maximum[2][2] = 2;
    maximum[2][3] = 2;

    allocation[0][0] = 0;
    allocation[0][1] = 1;
    allocation[0][2] = 0;
    allocation[0][3] = 0;

    allocation[1][0] = 2;
    allocation[1][1] = 0;
    allocation[1][2] = 0;
    allocation[1][3] = 1;

    allocation[2][0] = 3;
    allocation[2][1] = 0;
    allocation[2][2] = 2;
    allocation[2][3] = 1;

    for (int i = 0; i < numberofprocesses; i++) {
        for (int j = 0; j < numberofresources; j++) {
            need[i][j] = maximum[i][j] - allocation[i][j];
        }
    }

    if (issafestate()) {
        printf("The system is in a safe state.\n");
    } else {
        printf("The system is not in a safe state.\n");
    }

    return 0;
}