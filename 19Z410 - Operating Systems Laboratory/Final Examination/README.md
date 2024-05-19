# Questions for Batch 2

## Question 1
Write a program to read a maximum of 15 characters from the user and print
them on the screen.

Write a program using fork() system call to create a hierarchy of 3 process such
that P2 is the child of P1 and P1 is the child of P.

Create a parent-child relationship between two processes. The parent should
print two statements:

A) Parent (P) is having ID <PID>

B) ID of P’s Child is <PID_of_Child>
The child should print two statements:

C) Child is having ID <PID>

D) My Parent ID is <PID_of_Parent>

Make use of wait() in such a manner that the order of the four statements A, B, C
and D is:

A

C

D

B

You are free to use any other relevant statement/printf as you desire and their
order of execution does not matter.

(15 marks each)
CPU Scheduling:

Write a C program for implementation of the following scheduling algorithms:

FCFS (non-preemptive)

SJF (non-preemptive)

Priority (preemptive)


## Question 2

Write a multithreaded program that calculates various statistical values for a list of
numbers. This program will be passed a series of numbers on the command line and will
then create three separate worker threads. One thread will determine the average of the
numbers, the second will determine the maximum value, and the third will determine the
minimum value. For example, suppose your program is passed the integers
90 81 78 95 79 72 85
The program will report
The average value is 82
The minimum value is 72
The maximum value is 95
The variables representing the average, minimum, and maximum values will be stored
globally. The worker threads will set these values, and the parent thread will output the
values once the workers have exited

. Implementation of Producer Consumer Problem with solution using Semaphore

Implement Banker's Algorithm

LRU Page Replacement Algorithm

FCFS Disk Scheduling Algorithm 

LOOK Disk Scheduling Algorithm
