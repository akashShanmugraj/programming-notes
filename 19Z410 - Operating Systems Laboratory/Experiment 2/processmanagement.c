#include <stdio.h>
#include <sys/wait.h> // Required for wait()
#include <unistd.h>   // Required for fork()

int main() {
  // pid_t processid1, processid2;

  // printf("Hello, I am the parent process (P0) with process ID: %d\n",
  // getpid());

  // processid1 = fork();

  // if (processid1 == 0) { // sucessfully created process1
  //   // Child process P1
  //   printf("Hello, I am the child process (P1) with process ID: %d. My "
  //          "parent's process ID is: %d\n",
  //          getpid(), getppid());

  //   processid2 = fork();

  //   if (processid2 == 0) { // sucessfully created process2
  //     printf("Hello, I am the child process (P2) with process ID: %d. My "
  //            "parent's process ID is: %d\n",
  //            getpid(), getppid());
  //   }
  // } else {      // Parent process P0
  //   wait(NULL); // Wait for child process P1 to finish
  //   printf("Parent process (P) with process ID: %d. My child process (P1) has
  //   "
  //          "finished.\n",
  //          getpid());
  // }

  pid_t newprocess;

  printf("Parent (P) is having ID %d\n", getpid());
  newprocess = fork();

  if (newprocess > 0) {
    printf("Child is having ID %d\n", getpid());
    printf("ID of P's Child is %d\n", getpid());
  } else {
    printf("Parent is having ID %d\n", getppid());
  }
}
