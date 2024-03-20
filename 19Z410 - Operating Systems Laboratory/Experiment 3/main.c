#include <stdio.h>
#include <stdlib.h>

struct process {
  int processID;
  int bursttime;
  int remainingbursttime;
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

int burstSum(struct process *processhead) {
  struct process *traversalnode = processhead;
  int counter = 0;
  do {
    counter += traversalnode->remainingbursttime;
    traversalnode = traversalnode->nextprocess;
  } while (traversalnode != processhead);
  return counter;
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

void roundRobin(struct process *processhead, int timequantum) {
  struct process *traversalnode = processhead;
  int clockcyclecounter = 0;

  while (burstSum(processhead)) {
    if (traversalnode->bursttime == traversalnode->remainingbursttime) {
      traversalnode->starttime = clockcyclecounter;
    }

    int quantum = traversalnode->remainingbursttime >= timequantum
                      ? timequantum
                      : traversalnode->remainingbursttime;

    clockcyclecounter += quantum;
    traversalnode->remainingbursttime -= quantum;

    if (traversalnode->remainingbursttime == 0 &&
        traversalnode->endtime == -1) {
      traversalnode->endtime = clockcyclecounter;
    }

    traversalnode = traversalnode->nextprocess;
  }
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

  process0->remainingbursttime = 10;
  process1->remainingbursttime = 20;
  process2->remainingbursttime = 15;
  process3->remainingbursttime = 25;

  process0->starttime = -1;
  process1->starttime = -1;
  process2->starttime = -1;
  process3->starttime = -1;

  process0->endtime = -1;
  process1->endtime = -1;
  process2->endtime = -1;
  process3->endtime = -1;

  process0->arrivaltime = 0;
  process1->arrivaltime = 0;
  process2->arrivaltime = 0;
  process3->arrivaltime = 0;

  int roundrobinTimeQuantum = 100;
  roundRobin(process0, roundrobinTimeQuantum);

  printProcessMetrics(computeOtherMetrics(process0));
}
