#include<stdio.h>
#include<sys/types.h>
#include<unistd.h>
#include<sys/wait.h>

int main(){
    pid_t process1 = fork();
    if (process1 == 0){
        printf("Process 1 with process id %d\n", getpid());

        pid_t process2 = fork();
        if (process2 == 0){
            printf("Process 2 with process id %d\n", getpid());
        } else if (process2 > 0){
            wait(NULL);
        }
    } else if (process1 > 0){
        printf("Process 0 with process id %d\n", getpid());
        wait(NULL);
    }
}