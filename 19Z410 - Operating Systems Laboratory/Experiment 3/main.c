#include <stdio.h>
#include <stdlib.h>

struct process {
  int processID;
  int bursttime;
  int remainingbursttime;
  int turnaroundtime;
  int starttime;
  int endtime;
  struct process *nextprocess;
  struct process *previousprocess;
};

void printProcessList(struct process *processhead) {
  struct process *traversalnode = processhead;

  do {
    printf("PID: %d BRST: %d RMBRST: %d STRT: %d END: %d\n",
           traversalnode->processID, traversalnode->bursttime,
           traversalnode->remainingbursttime, traversalnode->starttime,
           traversalnode->endtime);
    traversalnode = traversalnode->nextprocess;
  } while (traversalnode != processhead);
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

void roundRobin(struct process *processhead, int timequantum) {
  struct process *traversalnode = processhead;
  int clockcyclecounter = 0;

  while (burstSum(processhead)) {
    if (processhead->bursttime == processhead->remainingbursttime) {
      processhead->starttime = clockcyclecounter;
    }

    if (processhead->remainingbursttime == 0 && processhead->endtime == -1) {
      processhead->endtime = clockcyclecounter;
    }
    clockcyclecounter += processhead->remainingbursttime >= 5
                             ? 5
                             : processhead->remainingbursttime;
    int result = processhead->remainingbursttime - timequantum;
    processhead->remainingbursttime = (result > 0) ? result : 0;
    processhead = processhead->nextprocess;
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

  process0->starttime = 0;
  process1->starttime = 0;
  process2->starttime = 0;
  process3->starttime = 0;

  process0->endtime = -1;
  process1->endtime = -1;
  process2->endtime = -1;
  process3->endtime = -1;

  roundRobin(process0, 5);

  printProcessList(process0);
}
