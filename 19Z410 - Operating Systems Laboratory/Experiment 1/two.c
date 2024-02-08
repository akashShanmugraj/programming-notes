#include <stdio.h>

int main() {
    int num, digit, sum = 0;

    num = 172345;

    while (num != 0) {
        digit = num % 10;
        sum += digit;
        num /= 10;
    }

    printf("Sum of digits: %d\n", sum);

    return 0;
}
