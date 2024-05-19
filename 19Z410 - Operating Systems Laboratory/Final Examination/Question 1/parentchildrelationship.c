// A) Parent (P) is having ID <PID>
// C) Child is having ID <PID>
// D) My Parent ID is <PID_of_Parent>
// B) ID of P’s Child is <PID_of_Child>

#include<stdio.h>
#include<sys/types.h>
#include<sys/wait.h>
#include<unistd.h>


int main(){
    pid_t childprocess = fork();
    // parent process print statements
    if (childprocess == 0){
        printf("Child is having the id %d\n", getpid());
        printf("My parent ID is %d\n", getppid());
    } else {
        printf("Parent (P) is having the id %d\n", getpid());
        wait(NULL);
        printf("ID of P's Child is %d\n", childprocess);

    }
}