#include <stdio.h>
#define MIN -9999;
struct proc {
  int processnumber, arrivaltime, bursttime, rt, ct, waitingtime, turnaroundtime, priority, temp;
};
struct proc read(int i) {
  struct proc processlist;
  printf("\nProcess processnumber: %d\n", i);
  processlist.processnumber = i;
  printf("Enter Arrival Time: ");
  scanf("%d", &processlist.arrivaltime);
  printf("Enter Burst Time: ");
  scanf("%d", &processlist.bursttime);
  processlist.rt = processlist.bursttime;
  printf("Enter Priority: ");
  scanf("%d", &processlist.priority);
  processlist.temp = processlist.priority;
  return processlist;
}
void main() {
  int i, n, c, remaining, max_val, max_index;
  struct proc processlist[10], temp;
  float averageturnaroundtime = 0, averagewaitingtime = 0;
  
  // Getting Inputs
  printf("Enter Number of Processes: ");
  scanf("%d", &n);
  for (int i = 0; i < n; i++)
    processlist[i] = read(i + 1);
  remaining = n;

  // Sorting based on Arrival Time
  for (int i = 0; i < n - 1; i++)
    for (int j = 0; j < n - i - 1; j++)
      if (processlist[j].arrivaltime > processlist[j + 1].arrivaltime) {
        temp = processlist[j];
        processlist[j] = processlist[j + 1];
        processlist[j + 1] = temp;
      }
  max_val = processlist[0].temp, max_index = 0;

  
  for (int j = 0; j < n && processlist[j].arrivaltime <= processlist[0].arrivaltime; j++)
    if (processlist[j].temp > max_val)
      max_val = processlist[j].temp, max_index = j;
  i = max_index;
  c = processlist[i].ct = processlist[i].arrivaltime + 1;
  processlist[i].rt--;
  if (processlist[i].rt == 0) {
    processlist[i].temp = MIN;
    remaining--;
  }
  while (remaining > 0) {
    max_val = processlist[0].temp, max_index = 0;
    for (int j = 0; j < n && processlist[j].arrivaltime <= c; j++)
      if (processlist[j].temp > max_val)
        max_val = processlist[j].temp, max_index = j;
    i = max_index;
    processlist[i].ct = c = c + 1;
    processlist[i].rt--;
    if (processlist[i].rt == 0) {
      processlist[i].temp = MIN;
      remaining--;
    }
  }
  printf("\nProcessNo\turnaroundtime\tBT\tPri\tCT\tTAT\tWT\n");
  for (int i = 0; i < n; i++) {
    processlist[i].turnaroundtime = processlist[i].ct - processlist[i].arrivaltime;
    averageturnaroundtime += processlist[i].turnaroundtime;
    processlist[i].waitingtime = processlist[i].turnaroundtime - processlist[i].bursttime;
    averagewaitingtime += processlist[i].waitingtime;
    printf("processlist%d\t\t%d\t%d\t%d\t%d\t%d\t%d\n", processlist[i].processnumber, processlist[i].arrivaltime, processlist[i].bursttime,
           processlist[i].priority, processlist[i].ct, processlist[i].turnaroundtime, processlist[i].waitingtime);
  }
  averageturnaroundtime /= n, averagewaitingtime /= n;
  printf("\nAverage TurnAroundTime=%f\nAverage WaitingTime=%f", averageturnaroundtime, averagewaitingtime);
}
