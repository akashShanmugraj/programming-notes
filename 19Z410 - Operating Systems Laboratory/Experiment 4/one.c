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