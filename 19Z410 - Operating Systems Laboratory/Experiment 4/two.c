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