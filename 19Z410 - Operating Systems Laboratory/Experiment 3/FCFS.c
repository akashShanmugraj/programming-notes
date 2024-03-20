/*
 NOTE:
 1. Ignored sorting the processes by arrival time
 (not expected) (sorting not implemented in Lab Manual)
 2. Therefore FCFS here is the regular Process Scheduling here
 3. Processes have been inserted into the doubly linked list manually in the
 sorted based on arrival time
*/

#include <stdio.h>
#include <stdlib.h>

struct process {
  int processID;
  int bursttime;
  int turnaroundtime;
  int starttime;
  int endtime;
  int waitingtime;
  int arrivaltime;
  struct process *nextprocess;
  struct process *previousprocess;
};

struct processmetrics {
  struct process *processhead;
  float averageWaitingTime;
  float averageTurnAroundTime;
};

void printProcessList(struct process *processhead) {
  struct process *traversalnode = processhead;

  do {
    printf("PID: %d BRST: %d \nSTRT: %d END: %d \nWAITING TIME: %d "
           "TURNAROUND TIME: %d\n\n",
           traversalnode->processID, traversalnode->bursttime,
           traversalnode->starttime, traversalnode->endtime,
           traversalnode->waitingtime, traversalnode->turnaroundtime);
    traversalnode = traversalnode->nextprocess;
  } while (traversalnode != processhead);
}

void printProcessMetrics(struct processmetrics *metricsresult) {
  printProcessList(metricsresult->processhead);
  printf("Average Waiting Time: %f \nAverage Turnaround Time: %f\n",
         metricsresult->averageWaitingTime,
         metricsresult->averageTurnAroundTime);
}

struct processmetrics *computeOtherMetrics(struct process *processhead) {
  struct process *traversalnode = processhead;
  float waittimecalculator = 0;
  float turnaroundtimecalculator = 0;
  int processcounter = 0;

  do {
    traversalnode->waitingtime = (traversalnode->endtime) -
                                 (traversalnode->starttime) -
                                 (traversalnode->bursttime);
    traversalnode->turnaroundtime =
        (traversalnode->endtime) - (traversalnode->arrivaltime);

    waittimecalculator += traversalnode->waitingtime;
    turnaroundtimecalculator += traversalnode->turnaroundtime;

    processcounter += 1;

    traversalnode = traversalnode->nextprocess;

  } while (traversalnode != processhead);

  struct processmetrics *computedmetrics =
      malloc(sizeof(struct processmetrics));
  computedmetrics->processhead = processhead;
  computedmetrics->averageWaitingTime = waittimecalculator / processcounter;
  computedmetrics->averageTurnAroundTime =
      turnaroundtimecalculator / processcounter;
  return computedmetrics;
}

int FirstComeFirstServe(struct process *processhead) {
  int clockcyclecounter = 0;
  struct process *traversalpointer = processhead;

  do {
    if (traversalpointer->arrivaltime > clockcyclecounter) {
      clockcyclecounter = traversalpointer->arrivaltime;
    }
    traversalpointer->starttime = clockcyclecounter;
    clockcyclecounter += traversalpointer->bursttime;
    traversalpointer->endtime = clockcyclecounter;

    traversalpointer = traversalpointer->nextprocess;
  } while (traversalpointer != processhead);
  return 0;
}
int main() {
  struct process *process0 = malloc(sizeof(struct process));
  struct process *process1 = malloc(sizeof(struct process));
  struct process *process2 = malloc(sizeof(struct process));
  struct process *process3 = malloc(sizeof(struct process));

  process0->processID = 0;
  process1->processID = 1;
  process2->processID = 2;
  process3->processID = 3;

  process0->previousprocess = process3;
  process0->nextprocess = process1;

  process1->previousprocess = process0;
  process1->nextprocess = process2;

  process2->previousprocess = process1;
  process2->nextprocess = process3;

  process3->previousprocess = process2;
  process3->nextprocess = process0;

  process0->bursttime = 10;
  process1->bursttime = 20;
  process2->bursttime = 15;
  process3->bursttime = 25;

  process0->starttime = -1;
  process1->starttime = -1;
  process2->starttime = -1;
  process3->starttime = -1;

  process0->endtime = -1;
  process1->endtime = -1;
  process2->endtime = -1;
  process3->endtime = -1;

  process0->arrivaltime = 0;
  process1->arrivaltime = 15;
  process2->arrivaltime = 20;
  process3->arrivaltime = 30;

  FirstComeFirstServe(process0);
  printProcessMetrics(computeOtherMetrics(process0));
}
