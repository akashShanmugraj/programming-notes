#include <stdio.h>

void printelements(int **arraypointer, int size1, int size2) {
    printf("%d")
    for (int i = 0; i < size1; i++) {
        for (int j = 0; j < size2; j++) {
            printf("from numberarray = %d\n", );
        }
    }
}

int main() {
    int numberarray[4][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}, {10, 11, 12}};
    int *numberarraypointer = numberarray;
    int **numberarraypointer2 = &numberarraypointer;
    printelements(numberarraypointer2, 4, 3);
    return 0;
}