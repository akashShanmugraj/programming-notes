# Child Care Problem by Max Hailperin
submitted by **Akash Shanmugaraj**, 22Z255

## Problem Description

Max Hailperin's Child Care problem is a classic problem in computer science that involves scheduling tasks with dependencies. It's often used to illustrate concepts in concurrent programming and scheduling algorithms. 
In this problem, there are caregivers (tasks) and children (resources) that need care. Each caregiver can only care for a limited number of children at a time, and each child requires care from a specific caregiver. 
The challenge is to schedule the caregivers efficiently to ensure that all children receive the care they need without violating the caregivers' capacity constraints.

## Solution Intuition using Semaphores

Here's a high-level approach to solving the Child Care problem using semaphores:

1. **Identify resources and constraints:** In the Child Care problem, caregivers are resources, and children are tasks. Each caregiver has a limited capacity (number of children they can care for simultaneously), and each child requires care from a specific caregiver.

2. **Use semaphores to represent resources:** Create a semaphore for each caregiver to represent their capacity. Initialize each semaphore with the maximum number of children the caregiver can care for.

3. **Use semaphores to enforce dependencies:** Create a semaphore for each child to represent whether they are currently being cared for by a caregiver. Initialize each child semaphore to 0, indicating that they are not yet being cared for.

4. **Implement caregiver and child processes:** Each caregiver process will loop indefinitely, waiting for a child to arrive and then caring for them. Each child process will request care from the appropriate caregiver and then proceed with their task.

5. **Semaphore operations:** When a child needs care, it will wait on the semaphore corresponding to their required caregiver. If the caregiver has capacity (semaphore value > 0), the child will decrement the caregiver's semaphore to reserve their care. The caregiver will then increment the child's semaphore to indicate that they are being cared for. After the caregiver finishes caring for the child, it will increment its semaphore to release the capacity, allowing other children to be cared for.

6. **Handling caregiver capacity:** Caregivers need to track their current capacity and adjust the semaphore values accordingly. When a caregiver reaches its capacity, it will wait until a child's semaphore indicates that they have finished being cared for before accepting another child.

7. **Ensure mutual exclusion:** Use additional semaphores or mutexes to ensure mutual exclusion when accessing shared variables or updating caregiver capacities to prevent race conditions.

## Code using Java and `concurrent.Semaphore` module

Below is a code in Java that demonstrates how to use semaphores to solve a simplified version of the Child Care problem. This code assumes a single caregiver and multiple children.


### Import Statements
```java
import java.util.concurrent.Semaphore;
import java.util.Random;
import java.util.ArrayList;
```
These are the import statements. `Semaphore` is used for controlling thread access, `Random` for generating random numbers, and `ArrayList` for storing Child objects.

### Main Class Definition
```java
public class Main {
    public static void main(String[] args) {
```
This is the start of the main method definition.

### Semaphore Creation
```java
Semaphore caregiverSemaphore = new Semaphore(3);
Semaphore childSemaphore = new Semaphore(0);
```
Here, two semaphores are created. The `caregiverSemaphore` starts with 3 permits, and the `childSemaphore` starts with 0 permits.

### Caregiver Creation and Start
```java
Caregiver caregiver = new Caregiver(caregiverSemaphore, childSemaphore);
caregiver.start();
```
A `Caregiver` object is created and its thread is started.

### Child Creation and Start
```java
ArrayList<Child> children = new ArrayList<>();
for (int i = 0; i < 5; i++) {
    Child child = new Child(i, caregiverSemaphore, childSemaphore);
    children.add(child);
    child.start();
}
```
Five `Child` objects are created, added to an `ArrayList`, and their threads are started.

### Waiting for Threads to Finish
```java
try {
    for (Child child : children) {
        child.join();
    }
    caregiver.join();
} catch (InterruptedException e) {
    e.printStackTrace();
}
}
}
```
The main thread waits for all the `Child` threads and the `Caregiver` thread to finish.


### Child Class Definition and Constructor
```java
class Child extends Thread {
    public Child(int name, Semaphore caregiverSemaphore, Semaphore childSemaphore) {
        this.name = name;
        this.caregiverSemaphore = caregiverSemaphore;
        this.childSemaphore = childSemaphore;
}
```
This is the `Child` constructor. It takes a name and two semaphores as parameters.

### Child Run Method
```java
public void run() {
    try {
        System.out.println("Child " + name + " needs care.");
        caregiverSemaphore.acquire();
        System.out.println("Child " + name + " is receiving care.");
        Thread.sleep(new Random().nextInt(3000) + 1000);
        System.out.println("Child " + name + " has finished receiving care.");
        caregiverSemaphore.release();
    } catch (InterruptedException e) {
        e.printStackTrace();
    }
}
```
This is the `run` method of the `Child` class. It simulates a child needing care, receiving care, and then finishing care.

### Caregiver Class Definition and Constructor
```java
class Caregiver extends Thread {
    public Caregiver(Semaphore caregiverSemaphore, Semaphore childSemaphore) {
        this.caregiverSemaphore = caregiverSemaphore;
        this.childSemaphore = childSemaphore;
    }
```
This is the `Caregiver` constructor. It takes two semaphores as parameters.

### Caregiver Run Method
```java
public void run() {
    try {
        while (true) {
            caregiverSemaphore.acquire();
            System.out.println("Caregiver is available.");
            childSemaphore.release();
            System.out.println("Caregiver is caring for a child.");
            Thread.sleep(new Random().nextInt(3000) + 1000);
            System.out.println("Caregiver has finished caring for a child.");
        }
    } catch (InterruptedException e) {
        e.printStackTrace();
    }
}
```
This is the `run` method of the `Caregiver` class. It simulates a caregiver becoming available, caring for a child, and then finishing care.

### Code Explaination
This Java code simulates a scenario where there are multiple children and a caregiver. The children need care and the caregiver provides it. The caregiver can care for up to 3 children at a time, as indicated by the initial semaphore value of 3 for `caregiverSemaphore`.

1. **Semaphores**: Semaphores are used to control access to a common resource by multiple processes in a concurrent system such as a multitasking operating system. In this code, `caregiverSemaphore` is a semaphore that controls access to the caregiver. It's initialized with a value of 3, meaning that up to 3 children can receive care at the same time. `childSemaphore` is a semaphore that's used to synchronize the caregiver and the children, but it's not actually used in this version of the code.

2. **Child class**: This class represents a child that needs care. Each child is a thread, and when a child thread is started, it first prints a message that it needs care. Then it tries to acquire the `caregiverSemaphore`. If the semaphore is available (i.e., its value is greater than 0), the child acquires it and prints a message that it's receiving care. Then it sleeps for a random amount of time between 1 and 4 seconds to simulate the time it takes to receive care. After that, it prints a message that it has finished receiving care and releases the `caregiverSemaphore`.

3. **Caregiver class**: This class represents the caregiver. The caregiver is also a thread, and when the caregiver thread is started, it enters an infinite loop where it first tries to acquire the `caregiverSemaphore`. If the semaphore is available, the caregiver acquires it and prints a message that it's available. Then it releases the `childSemaphore` (which is not actually used in this version of the code) and prints a message that it's caring for a child. Then it sleeps for a random amount of time between 1 and 4 seconds to simulate the time it takes to provide care. After that, it prints a message that it has finished caring for a child.

4. **Main method**: This method creates the `caregiverSemaphore` and `childSemaphore`, starts the caregiver thread, creates and starts 5 child threads, and then waits for all the child threads to finish. It doesn't actually wait for the caregiver thread to finish, because the caregiver thread runs in an infinite loop.

Please note that in this version of the code, the `childSemaphore` is not actually used, and the caregiver can care for multiple children at the same time, up to the initial value of the `caregiverSemaphore`. If you want the caregiver to care for only one child at a time, you should initialize the `caregiverSemaphore` with a value of 1.

## Output

<img width="723" alt="Screenshot 2024-04-30 at 5 59 36 AM" src="https://github.com/akashShanmugraj/programming-notes/assets/65720968/03d40799-e18a-4d31-9170-73235ad1e4c5">

### Output Explaination

1. "Caregiver is available." - This is printed when the Caregiver thread starts and is ready to take care of a child.

2. "Caregiver is caring for a child." - This is printed immediately after the Caregiver becomes available.

3. "Child X needs care." - This is printed when a Child thread starts and needs care.

4. "Child X is receiving care." - This is printed when a Child thread acquires the caregiverSemaphore, meaning it's the Child's turn to be taken care of by the Caregiver.

5. "Child X has finished receiving care." - This is printed when a Child thread releases the caregiverSemaphore, meaning it has finished being taken care of.

6. "Caregiver has finished caring for a child." - This is printed when the Caregiver thread releases the childSemaphore, meaning it has finished caring for a child and is ready to care for the next one.

The order of the output can vary each time the program is run due to the nature of multithreading, where threads are scheduled to run in an order that can't be predicted. 
