## Program 1
```c
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/shm.h>
#include <sys/time.h>
#define SHM_SIZE sizeof(struct timeval)
int main(int argc, char *argv[])
{
    struct timeval *starttimestruct;
    int sharedmemoryid = shmget(IPC_PRIVATE, SHM_SIZE, IPC_CREAT | 0666);
    
    starttimestruct = (struct timeval *)shmat(sharedmemoryid, NULL, 0);
    
    pid_t processid = fork();
    if (processid == 0)
    {
        gettimeofday(starttimestruct, NULL);
        execvp(argv[1], &argv[1]);
        perror("execvp");
        exit(EXIT_FAILURE);
    }
    else
    {
        int status;
        waitpid(processid, &status, 0);
        if (WIFEXITED(status))
        {
            struct timeval end_time;
            gettimeofday(&end_time, NULL);
            printf("TIME: %ld.%06ld\n",
                   end_time.tv_sec - starttimestruct->tv_sec,
                   (long)(end_time.tv_usec - starttimestruct->tv_usec));
        }
        shmdt(starttimestruct);
        shmctl(sharedmemoryid, IPC_RMID, NULL);
    }
    return 0;
}
```


## Program 2
```c
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#define MIN_PID 300
#define MAX_PID 5000
#define MAX_PID_COUNT (MAX_PID - MIN_PID + 1)
int pid_map[MAX_PID_COUNT];

int allocate_map(void)
{
    for (int iterable1 = 0; iterable1 < MAX_PID_COUNT; iterable1++)
        pid_map[iterable1] = 0;
    return 1;
}
int allocate_pid(void)
{
    for (int iterable1 = 0; iterable1 < MAX_PID_COUNT; iterable1++)
    {
        if (pid_map[iterable1] == 0)
        {
            pid_map[iterable1] = 1;
            return iterable1 + MIN_PID;
        }
    }
    return -1;
}
void release_pid(int pid)
{
    if (pid >= MIN_PID && pid <= MAX_PID)
        pid_map[pid - MIN_PID] = 0;
}
int main()
{
    allocate_map();
    int pid1 = allocate_pid();
    printf("Allocated PID: %d\n", pid1);
    int pid2 = allocate_pid();
    printf("Allocated PID: %d\n", pid2);
    release_pid(pid1);
    printf("Released PID: %d\n", pid1);
    int pid3 = allocate_pid();
    printf("Allocated PID: %d\n", pid3);
    return 0;
}
```

## Program 3
```c
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

int numberslist[] = {90, 81, 78, 95, 79, 72, 85};
int numberscount = 7;
double averagevalue;
int maximumvalue;
int minimumvalue;

void *computeaverage(void *arg)
{
    int sum = 0;
    for (int iterable1 = 0; iterable1 < numberscount; iterable1++)
        sum += numberslist[iterable1];
    averagevalue = (double)sum / numberscount;
    pthread_exit(NULL);
}
void *computemaximum(void *arg)
{
    maximumvalue = numberslist[0];
    for (int iterable1 = 1; iterable1 < numberscount; iterable1++)
    {
        if (numberslist[iterable1] > maximumvalue)
            maximumvalue = numberslist[iterable1];
    }
    pthread_exit(NULL);
}
void *computeminimum(void *arg)
{
    minimumvalue = numberslist[0];
    for (int iterable1 = 1; iterable1 < numberscount; iterable1++)
    {
        if (numberslist[iterable1] < minimumvalue)
            minimumvalue = numberslist[iterable1];
    }
    pthread_exit(NULL);
}
int main()
{
    pthread_t tid1, tid2, tid3;
    pthread_create(&tid1, NULL, computeaverage, NULL);
    pthread_create(&tid2, NULL, computemaximum, NULL);
    pthread_create(&tid3, NULL, computeminimum, NULL);
    pthread_join(tid1, NULL);
    pthread_join(tid2, NULL);
    pthread_join(tid3, NULL);
    printf("The averagevalue value is %.2lf\n", averagevalue);
    printf("The minimumvalue value is %d\n", minimumvalue);
    printf("The maximumvalue value is %d\n", maximumvalue);
    return 0;
}
```

## Program 4
```c
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
void *print_primes(void *arg)
{
    int targetnumber = *((int *)arg);
    for (int iterable1 = 2; iterable1 <= targetnumber; iterable1++)
    {
        int isprimeboolean = 1;
        for (int iterable2 = 2; iterable2 * iterable2 <= iterable1; iterable2++)
        {
            if (iterable1 % iterable2 == 0)
            {
                isprimeboolean = 0;
                break;
            }
        }
        if (isprimeboolean)
            printf("%d ", iterable1);
    }
    printf("\targetnumber");
    pthread_exit(NULL);
}
int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        fprintf(stderr, "Usage: %s <number>\targetnumber", argv[0]);
        exit(EXIT_FAILURE);
    }
    int targetnumber = atoi(argv[1]);
    pthread_t tid;
    pthread_create(&tid, NULL, print_primes, &targetnumber);
    pthread_join(tid, NULL);
    return 0;
}
```