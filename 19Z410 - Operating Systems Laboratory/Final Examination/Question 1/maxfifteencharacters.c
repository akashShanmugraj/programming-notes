#include<stdio.h>
#include<string.h>

int main() {
    char input[16];
    printf("Enter a string: ");
    scanf("%s", input);

    if (strlen(input) > 15) {
        printf("Input string is has more than 15 characters.\n");
    } else {
        printf("Input String: %s\n", input);
    }
}