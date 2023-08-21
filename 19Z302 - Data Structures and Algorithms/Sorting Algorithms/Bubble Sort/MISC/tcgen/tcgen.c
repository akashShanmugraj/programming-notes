#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define N 10000

int main() {
    srand(time(NULL));

    FILE *file1 = fopen("tc1C.txt", "w");
    FILE *file2 = fopen("tc2C.txt", "w");
    FILE *file3 = fopen("tc3C.txt", "w");

    for (int i = 0; i < N; i++) {
        printf("%d\n", i);

        int numberlist1[i+1];
        for (int j = 0; j <= i; j++) {
            numberlist1[j] = j;
        }
        char numberstring1[10000];
        sprintf(numberstring1, "%d", numberlist1[0]);
        for (int j = 1; j <= i; j++) {
            char temp[100];
            sprintf(temp, " %d", numberlist1[j]);
            strcat(numberstring1, temp);
        }
        fprintf(file1, "%d %s\n", i, numberstring1);

        int numberlist2[i+1];
        for (int j = 0; j <= i; j++) {
            numberlist2[j] = i - j;
        }
        char numberstring2[10000];
        sprintf(numberstring2, "%d", numberlist2[0]);
        for (int j = 1; j <= i; j++) {
            char temp[100];
            sprintf(temp, " %d", numberlist2[j]);
            strcat(numberstring2, temp);
        }
        fprintf(file2, "%d %s\n", i, numberstring2);

        int numberlist3[i+1];
        for (int j = 0; j <= i; j++) {
            numberlist3[j] = j;
        }
        for (int j = i; j > 0; j--) {
            int k = rand() % (j+1);
            int temp = numberlist3[j];
            numberlist3[j] = numberlist3[k];
            numberlist3[k] = temp;
        }
        char numberstring3[10000];
        sprintf(numberstring3, "%d", numberlist3[0]);
        for (int j = 1; j <= i; j++) {
            char temp[100];
            sprintf(temp, " %d", numberlist3[j]);
            strcat(numberstring3, temp);
        }
        fprintf(file3, "%d %s\n", i, numberstring3);
    }

    fclose(file1);
    fclose(file2);
    fclose(file3);

    return 0;
}