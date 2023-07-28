#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE *fp = fopen("s.txt", "r");
    if (fp == NULL) {
        printf("Error opening file\n");
        exit(1);
    }

    // find average of numbers stored in the file
    int n, count = 0;
    double sum = 0.0;
    while (fgetc(fp) != EOF) {
        while(fgetc(fp) != '\n') {
            printf("%c", fgetc(fp));
        }
        printf("\n");
    }


}