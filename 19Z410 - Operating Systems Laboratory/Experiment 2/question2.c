#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int number;

int main()
{
    printf("Value of N: ");
    scanf("%d", &number);

    int fd1[2], fd2[2];
    if (pipe(fd1) == -1 || pipe(fd2) == -1)
    {
        perror("pipe");
        exit(EXIT_FAILURE);
    }

    pid_t process = fork();

    if (process < 0)
    {
        perror("fork");
        exit(EXIT_FAILURE);
    }
    else if (process == 0)
    {
        close(fd1[0]);
        close(fd2[1]);
        int p = 1;
        while (p < number)
        {
            int factor = (rand() % 8) + 2;
            p *= factor;
            printf("Michael multiplied p by %d, p is now %d\n", factor, p);
            write(fd1[1], &p, sizeof(int));
            if (p >= number)
                break;
            read(fd2[0], &p, sizeof(int));
        }
        close(fd1[1]);
        close(fd2[0]);
    }
    else
    {
        close(fd1[1]);
        close(fd2[0]);
        int p = 1;
        while (p < number)
        {
            read(fd1[0], &p, sizeof(int));
            if (p >= number)
            {
                printf("John reached or exceeded N\n");
                break;
            }
            int factor = (rand() % 8) + 2;
            p *= factor;
            printf("John multiplied p by %d, p is now %d\n", factor, p);
            write(fd2[1], &p, sizeof(int));
        }
        close(fd1[0]);
        close(fd2[1]);
    }

    return 0;
}