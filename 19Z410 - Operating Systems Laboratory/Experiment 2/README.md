# Programming and Controlling Processes in C

Use the below guide on how to use the popular `fork()` and `wait()` functions to create and control processes in C.

```c
#include <sys/wait.h> // Required for wait()
#include <unistd.h>   // Required for fork()

pid_t newprocess;

  newprocess = fork();

  if (newprocess < 0) {
    // code for handling the error
    // that occured during creation of newprocess
  } else if (newprocess == 0) {
    // code for executing on newprocess
    // every line of code inside this block will be executed as newprocess
    // this code block is the runtime of newprocess
  } else {
    // code for executing on the parent of newprocess
    // i.e., the runtime on which newprocess was actually created
    // this code block is the runtime of the parent of newprocess
    // wait() function used here will stop further 
    // execution in this runtime until all executions are done in the runtime in else if block
  }

```