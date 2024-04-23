#include <stdio.h> 
#include <stdbool.h>

#define MAX_RESOURCES 10 
#define MAX_PROCESSES 10

int allocation[MAX_PROCESSES][MAX_RESOURCES];
int max[MAX_PROCESSES][MAX_RESOURCES];
int available[MAX_RESOURCES];
bool finished[MAX_PROCESSES];
int safe_sequence[MAX_PROCESSES];
int num_processes, num_resources;
bool isSafe()
{
    int work[MAX_RESOURCES];
    for (int i = 0; i < num_resources; ++i)
    {
        work[i] = available[i];
    }
    bool finish;
    int count = 0;
    while (count < num_processes)
    {
        finish = false;
        for (int i = 0; i < num_processes; ++i)
        {
            if (!finished[i])
            {
                int j;
                for (j = 0; j < num_resources; ++j)
                {
                    if (max[i][j] - allocation[i][j] > work[j])
                    {
                        break;
                    }
                }
                if (j == num_resources)
                {
                    for (int k = 0; k < num_resources; ++k)
                    {
                        work[k] += allocation[i][k];
                    }
                    safe_sequence[count++] = i;
                    finished[i] = true;
                    finish = true;
                }
            }
        }
        if (!finish)
        {
            break;
        }
    }
    return (count == num_processes);
}
int main()
{
    printf("Enter number of processes: ");
    scanf("%d", &num_processes);
    printf("Enter number of resources: ");
    scanf("%d", &num_resources);
    printf("Enter allocated resources matrix:\n");
    for (int i = 0; i < num_processes; ++i)
    {
        for (int j = 0; j < num_resources; ++j)
        {
            scanf("%d", &allocation[i][j]);
        }
    }
    printf("Enter maximum resources matrix:\n");
    for (int i = 0; i < num_processes; ++i)
    {
        for (int j = 0; j < num_resources; ++j)
        {
            scanf("%d", &max[i][j]);
        }
    }
    printf("Enter available resources vector:\n");
    for (int i = 0; i < num_resources; ++i)
    {
        scanf("%d", &available[i]);
    }
    for (int i = 0; i < num_processes; ++i)
    {
        finished[i] = false;
    }
    if (isSafe())
    {
        printf("Safe sequence: ");
        for (int i = 0; i < num_processes; ++i)
        {
            printf("%d ", safe_sequence[i]);
        }
        printf("\n");
    }
    else
    {
        printf("Unsafe state\n");
    }
    return 0;
}