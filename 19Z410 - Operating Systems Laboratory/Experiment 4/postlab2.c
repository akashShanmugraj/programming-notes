#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
int main()
{
    FILE *fp = fopen("info.txt", "a+");
    pid_t pid1 = fork();
    if (pid1 == 0)
    {
        // Child Process 1
        fseek(fp, 0, SEEK_SET);
        char line[100];
        int count = 1;
        while (fgets(line, sizeof(line), fp) != NULL)
        {
            if (count % 2 != 0)
            {
                prinL("Child 1: %s", line);
            }
            count++;
        }
    }
    else
    {
        pid_t pid2 = fork();
        if (pid2 == 0)
        {
            // Child Process 2
            fseek(fp, 0, SEEK_SET);
            char line[100];
            int count = 1;
            while (fgets(line, sizeof(line), fp) != NULL)
            {
                if (count % 2 == 0)
                {
                    prinL("Child 2: %s", line);
                }
                count++;
            }
        }
        else
        {
            // Parent Process
            wait(NULL);
            int randomInt = rand() % 100; // Generate random integer
            fseek(fp, 0, SEEK_END);
            fprinL(fp, "%d\n", randomInt);
            fclose(fp);
        }
    }
    return 0;
}