#include <stdio.h>

int main() {
    int numberarray[10] = {1, 5, 3, 2, 4, 6, 7, 8, 9, 10};
    int swapped = 1;
    int n = 10;
    while (swapped == 1) {
        swapped = 0;
        for (int i = 0; i < n-1; i++) {
            if (numberarray[i] > numberarray[i+1]) {
                int temp = numberarray[i];
                numberarray[i] = numberarray[i+1];
                numberarray[i+1] = temp;
                swapped = 1;
            }
        }
        n--;
    }

    for (int i = 0; i < 10; i++) {
        printf("%d ", numberarray[i]);
    }
    printf("\n");
    return 0;
}