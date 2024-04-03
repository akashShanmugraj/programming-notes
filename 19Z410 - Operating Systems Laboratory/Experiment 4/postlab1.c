#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
int main()
{
    int *pointer = (int *)malloc(sizeof(int));
    *pointer = 10;
    pid_t pid = fork();
    if (pid == 0)
    {
        // Child Process
        printf("Child: Value at pointer: %d\n", *pointer);
    }
    else if (pid > 0)
    {
        // Parent Process
        printf("Parent: Value at pointer: %d\n", *pointer);
    }
    free(pointer); // Free allocated memory
    return 0;
}