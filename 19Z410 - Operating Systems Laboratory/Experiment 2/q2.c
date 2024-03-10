#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <time.h>

// Define the maximum value for p
#define MAX_P 100000

// Declare shared variables
int *p_shared;

int main() {

    // Shared memory setup
    int shmid = shmget(IPC_PRIVATE, sizeof(int), IPC_CREAT | 0666);
    if (shmid == -1) {
        perror("shmget");
        exit(1);
    }
    p_shared = (int *)shmat(shmid, NULL, 0);
    if (*p_shared == -1) {
        perror("shmat");
        exit(1);
    }

    // Initialize random number generator
    srand(time(NULL));

    // Initialize p
    *p_shared = 1;

    // Fork a child process
    pid_t pid = fork();

    if (pid < 0) {
        perror("fork");
        exit(1);
    } else if (pid == 0) {
        // Child process (Michael)
        while (*p_shared < MAX_P) {
            int multiplier = rand() % 8 + 2; // Random number between 2 and 9
            *p_shared *= multiplier;
            printf("Michael: %d\n", *p_shared);
            usleep(500000); // Sleep for 0.5 seconds
        }
        exit(0);
    } else {
        // Parent process (John)
        while (*p_shared < MAX_P) {
            int multiplier = rand() % 8 + 2; // Random number between 2 and 9
            *p_shared *= multiplier;
            printf("John: %d\n", *p_shared);
            usleep(500000); // Sleep for 0.5 seconds
        }
        // Wait for child process to finish
        wait(NULL);
    }

    // Detach and remove shared memory
    shmdt(p_shared);
    shmctl(shmid, IPC_RMID, NULL);

    return 0;
}