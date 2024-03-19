#include <stdio.h>
#include <stdlib.h>
#include <sys/signal.h>

// Process Control Block (processBlock) Structure
struct processBlock {
  int procId;
  int cpuBurst;
  int waitingTime;
  struct processBlock *next;
  struct processBlock *prev;
};

void printProcessBlock(struct processBlock *targetprocessblock) {
  printf("Process ID: %d \nCPU Burst Time: %d\nWaiting Time: %d\n",
         targetprocessblock->procId, targetprocessblock->cpuBurst,
         targetprocessblock->waitingTime);
}

// Function that creates a new processBlock with given procID and cpuBurst
// and returns a pointer to the newly created processBlock

struct processBlock *createprocessBlock(int procId, int cpuBurst) {
  struct processBlock *newprocessBlock =
      (struct processBlock *)malloc(sizeof(struct processBlock));
  newprocessBlock->procId = procId;
  newprocessBlock->cpuBurst = cpuBurst;
  newprocessBlock->waitingTime = 0;
  newprocessBlock->next = NULL;
  newprocessBlock->prev = NULL;
  return newprocessBlock;
}

// Function to insert a processBlock at the end of a DLL
void insertEndDLL(struct processBlock **head, struct processBlock **tail,
                  struct processBlock *newprocessBlock) {
  if (*head == NULL) {
    *head = newprocessBlock;
    *tail = newprocessBlock;
    (*head)->next = newprocessBlock; // Circular linking
    (*head)->prev = newprocessBlock;
  } else {
    (*tail)->next = newprocessBlock;
    newprocessBlock->prev = *tail;
    newprocessBlock->next = *head; // Circular linking
    (*head)->prev = newprocessBlock;
    *tail = newprocessBlock;
  }
}

// Function to calculate average waiting time and average turnaround time
void calculateAverages(struct processBlock *head, float *avgwaitingTime,
                       float *avgTurnaroundTime) {
  float totalwaitingTime = 0;
  float totalTurnaroundTime = 0;
  int numProcesses = 0;
  struct processBlock *current = head;
  do {
    totalwaitingTime += current->waitingTime;
    totalTurnaroundTime += current->waitingTime + current->cpuBurst;
    numProcesses++;
    current = current->next;
  } while (current != head);
  *avgwaitingTime = totalwaitingTime / numProcesses;
  *avgTurnaroundTime = totalTurnaroundTime / numProcesses;
}

// First Come First Serve (FCFS) Scheduling using Circular DLL
void FCFS(struct processBlock *head) {
  float avgwaitingTime, avgTurnaroundTime;
  struct processBlock *current = head;
  int currentTime = 0;
  do {
    current->waitingTime = currentTime;
    currentTime += current->cpuBurst;
    current = current->next;
  } while (current != head);
  calculateAverages(head, &avgwaitingTime, &avgTurnaroundTime);
  printf("Average Waiting Time: %.2f\n", avgwaitingTime);
  printf("Average Turnaround Time: %.2f\n", avgTurnaroundTime);
}

// Round Robin (RR) Scheduling using Circular Doubly Linked List
void roundRobin(struct processBlock *head, int quantum) {
  struct processBlock *current = head;
  int remainingProcesses =
      0; // Counter to track remaining processes with burst time > 0
  // Calculate the total number of processes
  struct processBlock *temp = head;
  do {
    remainingProcesses++;
    temp = temp->next;
  } while (temp != head);
  int currentTime = 0;
  // Process the list until all processes complete their CPU bursts
  while (remainingProcesses > 0) {
    if (current->cpuBurst <= quantum) {
      // If the remaining burst time of the current process is less than or
      // equal to the quantum
      currentTime += current->cpuBurst;
      current->waitingTime = currentTime - current->cpuBurst;
      currentTime++; // To account for context switch
      current->cpuBurst = 0;
      remainingProcesses--; // Decrement remainingProcesses as this process has
      // completed its burst
    } else {
      // If the remaining burst time of the current process is greater than the
      // quantum
      currentTime += quantum;
      current->waitingTime = currentTime - quantum;
      currentTime++; // To account for context switch
      current->cpuBurst -= quantum;
    }
    // Move to the next process in the circular list
    current = current->next;
  }
  // Calculate averages
  float avgwaitingTime, avgTurnaroundTime;
  calculateAverages(head, &avgwaitingTime, &avgTurnaroundTime);
  printf("Average Waiting Time: %.2f\n", avgwaitingTime);
  printf("Average Turnaround Time: %.2f\n", avgTurnaroundTime);
}

int main() {
  // Example input
  int processId[] = {1, 2, 3, 4};
  int cpuBurst[] = {10, 20, 15, 25};
  int numProcesses = sizeof(processId) / sizeof(processId[0]);
  // Create processBlocks and insert into DLL for FCFS
  struct processBlock *head_FCFS = NULL;
  struct processBlock *tail_FCFS = NULL;
  for (int i = 0; i < numProcesses; i++) {
    struct processBlock *newprocessBlock =
        createprocessBlock(processId[i], cpuBurst[i]);
    insertEndDLL(&head_FCFS, &tail_FCFS, newprocessBlock);
  }
  // Run FCFS scheduling
  printf("FCFS Scheduling:\n");
  FCFS(head_FCFS);
  // Create processBlocks and insert into DLL for Round Robin
  struct processBlock *head_RR = NULL;
  struct processBlock *tail_RR = NULL;
  for (int i = 0; i < numProcesses; i++) {
    struct processBlock *newprocessBlock =
        createprocessBlock(processId[i], cpuBurst[i]);
    insertEndDLL(&head_RR, &tail_RR, newprocessBlock);
  }
  // Run Round Robin scheduling with a quantum of 10
  printf("\nRound Robin Scheduling:\n");
  roundRobin(head_RR, 10);
  return 0;
}
