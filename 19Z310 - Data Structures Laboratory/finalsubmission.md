# Laboratory Report
## 19Z310 - Data Structures Laboratory
taught by **Dr Lovelyn Rose S** and **Dr Saranya K G**, *Department of Computer Science and Engineering, PSG College of Technology*
Submitted by **Akash S** (*22z255*) on 15th December 2023


## Searching and Sorting Algorithms

### Linear Search (with time track)
```c
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int linearsearch(int *numberarray, int arraylength, int searchelement){
    for (int iterable = 0; iterable < arraylength; iterable++){
        if (*(numberarray+iterable) == searchelement){
            return iterable;
        }
    }
}

int* readFile(char filename[], int searchelement){
    FILE *fp;
    fp = fopen(filename, "r");
    
    int testcasesizevar, scanplaceholder;

    fscanf(fp, "%d", &testcasesizevar);
    
    int* testcasepointer = (int*)malloc(testcasesizevar * sizeof(int));

    for (int iterable = 0; iterable < testcasesizevar; iterable++){
        fscanf(fp, "%d", &scanplaceholder);``
        *(testcasepointer + iterable) = scanplaceholder;
    }

    fclose(fp);

    linearsearch(testcasepointer, testcasesizevar, searchelement);
    
}

int run(char filename[], int searchelement){
    printf("Scanning in `%s` for %d \n", filename, searchelement);
    clock_t start = clock();

    readFile(filename, searchelement);

    clock_t end = clock();
    double time_spent = (double)(end - start) / CLOCKS_PER_SEC;
    printf("Time spent: %f\n", time_spent);
    printf("\n\n");
}

int main() {
    run("./Testcases/1000nearlysorted1.txt", 1);
    run("./Testcases/1000nearlysorted1.txt", 1000);
    run("./Testcases/1000nearlysorted1.txt", 500);
    run("./Testcases/1000nearlysorted1.txt", 658);

    printf("\n\n");

    run("./Testcases/100K.ascending.txt", 1);
    run("./Testcases/100K.ascending.txt", 100000);
    run("./Testcases/100K.ascending.txt", 50000);
    run("./Testcases/100K.ascending.txt", 42354);

    printf("\n\n");

    run("./Testcases/100K.descending.txt", 1);
    run("./Testcases/100K.descending.txt", 100000);
    run("./Testcases/100K.descending.txt", 50000);
    run("./Testcases/100K.descending.txt", 42354);

    printf("\n\n");

    run("./Testcases/100K.random.txt", 1);
    run("./Testcases/100K.random.txt", 100000);
    run("./Testcases/100K.random.txt", 50000);
    run("./Testcases/100K.random.txt", 42354);

}
```

### Binary Search (with time track)
```c
#include<stdio.h>   
#include<time.h>
#include<stdlib.h>

int binarysearch(int* sortedarraypointer, int arraysize,  int searchelement){
    int searchstartindex = 0;
    int searchendindex = arraysize - 1;
    int mid = (searchstartindex + searchendindex)/2;
    while(searchstartindex <= searchendindex){
        if(sortedarraypointer[mid] == searchelement){
            return mid;
            break;
        }
        else if(sortedarraypointer[mid] < searchelement){
            searchstartindex = mid + 1;
        }
        else{
            searchendindex = mid - 1;
        }
        mid = (searchstartindex + searchendindex)/2;
    }
    if(searchstartindex > searchendindex){
        return -1;
    }
}

int* readFile(char filename[], int searchelement){
    FILE *fp;
    fp = fopen(filename, "r");
    
    int testcasesizevar, scanplaceholder;

    fscanf(fp, "%d", &testcasesizevar);
    
    int* testcasepointer = (int*)malloc(testcasesizevar * sizeof(int));

    for (int iterable = 0; iterable < testcasesizevar; iterable++){
        fscanf(fp, "%d", &scanplaceholder);
        *(testcasepointer + iterable) = scanplaceholder;
    }

    fclose(fp);

    binarysearch(testcasepointer, testcasesizevar, searchelement);
    
}


int run(char filename[], int searchelement){
    printf("Scanning in `%s` for %d \n", filename, searchelement);
    clock_t start = clock();

    readFile(filename, searchelement);

    clock_t end = clock(); 
    double time_spent = (double)(end - start) / CLOCKS_PER_SEC;
    printf("Time spent: %f\n", time_spent);
    printf("\n\n");
}

int main() {

    run("./Testcases/100K.ascending.txt", 1);
    run("./Testcases/100K.ascending.txt", 100000);
    run("./Testcases/100K.ascending.txt", 50000);
    run("./Testcases/100K.ascending.txt", 42354);

    printf("\n\n");


}

```


### Bubble Sort (with time track)
```c
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void bubblesort(int* numberarray, int samplelength){
    printf("    SORT START\n");
    int temp;
    int counter = 0;
    for (int i = 0; i < samplelength; i++){
        for (int j = 0; j < samplelength - i - 1; j ++){
            counter++;
            if (*(numberarray+j) > *(numberarray+j+1)){
                printf("    SWAP %d %d\r", *(numberarray+j), *(numberarray+j+1));
                temp = *(numberarray+j);
                *(numberarray+j) = *(numberarray+j+1);
                *(numberarray+j+1) = temp;
            }
        }
    }
    printf("\n");
    printf("    SORT DONE\n");
    printf("\n");
}

int* readFile(char filename[]){
    FILE *fp;
    fp = fopen(filename, "r");
    
    int testcasesizevar, scanplaceholder;

    fscanf(fp, "%d", &testcasesizevar);
    
    int* testcasepointer = (int*)malloc(testcasesizevar * sizeof(int));

    for (int iterable = 0; iterable < testcasesizevar; iterable++){
        fscanf(fp, "%d", &scanplaceholder);
        *(testcasepointer + iterable) = scanplaceholder;
    }

    fclose(fp);
    
    bubblesort(testcasepointer, testcasesizevar);
}


int run(char filename[]){
    printf("Scanning for and sorting `%s` \n", filename);
    clock_t start = clock();

    readFile(filename);

    clock_t end = clock();
    double time_spent = (double)(end - start) / CLOCKS_PER_SEC;
    printf("Time spent: %f\n", time_spent);
    printf("\n\n");
}

int main() {
    run("./Testcases/1000nearlysorted1.txt");
    run("./Testcases/1000nearlysorted2.txt");
    run("./Testcases/1000nearlysorted3.txt");\
    run("./Testcases/100K.ascending.txt");
    run("./Testcases/100K.descending.txt");
    run("./Testcases/100K.random.txt");
}
```

### Insertion Sort (with time track)

```c
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void insertionsort(int* numberarray, int samplelength){
    int variable1,variable2,key;

    for (variable1 = 1; variable1 < samplelength; variable1++){
        key = *(numberarray+variable1);
        variable2 = variable1 - 1;
        while (variable2 >= 0 && *(numberarray+variable2) > key){
            *(numberarray+variable2+1) = *(numberarray+variable2);
            variable2 = variable2 - 1;
        }
        *(numberarray+variable2+1) = key;
    }

}

int* readFile(char filename[]){
    FILE *fp;
    fp = fopen(filename, "r");
    
    int testcasesizevar, scanplaceholder;

    fscanf(fp, "%d", &testcasesizevar);
    
    int* testcasepointer = (int*)malloc(testcasesizevar * sizeof(int));

    for (int iterable = 0; iterable < testcasesizevar; iterable++){
        fscanf(fp, "%d", &scanplaceholder);
        *(testcasepointer + iterable) = scanplaceholder;
    }

    fclose(fp);
    
    insertionsort(testcasepointer, testcasesizevar);
}


int run(char filename[]){
    printf("Scanning for and sorting `%s` \n", filename);
    clock_t start = clock();

    readFile(filename);

    clock_t end = clock();
    double time_spent = (double)(end - start) / CLOCKS_PER_SEC;
    printf("Time spent: %f\n", time_spent);
    printf("\n\n");
}

int main() {
    run("./Testcases/1000nearlysorted1.txt");
    run("./Testcases/1000nearlysorted2.txt");
    run("./Testcases/1000nearlysorted3.txt");
    run("./Testcases/100K.ascending.txt");
    run("./Testcases/100K.descending.txt");
    run("./Testcases/100K.random.txt");
}
```




## Linked List

### Standard Linked List 
```c
#include <stdio.h>
#include <stdlib.h>

// node definition
struct node
{
    int data;
    struct node *next;
};

// function to get a pointer to a node
struct node *getpointer(int data)
{
    struct node *element = (struct node *)malloc(sizeof(struct node));
    element->data = data;
    element->next = NULL;
    return element;
}

// function to print the list
void printlist(struct node *headpointer)
{
    struct node *tempnode = headpointer;
    while (tempnode->next != NULL)
    {
        printf("%d-", tempnode->data);
        tempnode = tempnode->next;
    }
    printf("%d\n\n", tempnode->data);
}

// function to search an element and print its position using for loop
int search(struct node *headpointer, int data)
{
    struct node *tempnode = headpointer;
    int position = 0;
    for (; tempnode != NULL; tempnode = tempnode->next, position++)
    {
        if (tempnode->data == data)
        {
            printf("Element found at position: %d\n", position);
            return position;
        }
    }
    printf("Element not found in the list.\n");
}

int findlength(struct node * headpointer){
    struct node * listclone = headpointer;
    int counter = 0;
    while (listclone ->next != NULL){
        counter++;
        listclone = listclone -> next;
    }
    return counter;
}

// function to construct the list
struct node * constructor(int constructorlength, int constructoroffset)
{
    struct node *HEAD;
    struct node *temphead = HEAD;
    struct node *tempelement;

    int insertlimit = constructorlength;
    for (int iterable = 0; iterable < insertlimit; iterable++)
    {
        tempelement = getpointer(constructoroffset+iterable);
        if (iterable == 0)
        {
            HEAD = tempelement;
            temphead = tempelement;
        }
        else
        {
            temphead->next = tempelement;
            temphead = tempelement;
        }
        if (iterable == insertlimit - 1)
        {
            temphead->next = NULL;
        }
    }
    
    return HEAD;
}

struct node * insertatstart(struct node * headpointer, int data){
    struct node * newelement = getpointer(data);
    newelement -> next = headpointer;
    return newelement;
}

struct node * insertatend(struct node * headpointer, int data){
    struct node * temphead = headpointer;
    while(temphead -> next != NULL){
        temphead = temphead -> next;
    }
    struct node * element = getpointer(data);
    temphead -> next = element;

    return headpointer;
}

struct node * insertatpos(struct node * headpointer, int data, int position){
    int counter = 0;
    struct node * tempheadpointer = headpointer;
    while (tempheadpointer != NULL && counter != position){
        counter++;
        tempheadpointer = tempheadpointer -> next;
    }

    struct node * poselement = getpointer(tempheadpointer->data);
    poselement->next = tempheadpointer->next;
    tempheadpointer->data = data;
    tempheadpointer->next = poselement;
    
    return headpointer;
}

struct node * insertnatpos(struct node * headpointer, int offset, int position){
    int counter = 0;
    struct node * tempheadpointer = headpointer;
    struct node * prev = NULL;
    while (tempheadpointer != NULL && counter != position){
        counter++;
        prev = tempheadpointer;
        tempheadpointer = tempheadpointer -> next;
    }

    struct node * newconstructorlist = constructor(3, offset);
    printf("NEW-CH\n");
    printlist(newconstructorlist);
    struct node * newlisttraverser = newconstructorlist;

    while (newlisttraverser->next != NULL){
        newlisttraverser = newlisttraverser -> next;
    }
    newlisttraverser->next = tempheadpointer;

    if (prev != NULL) {
        prev->next = newconstructorlist;
    } else {
        headpointer = newconstructorlist;
    }

    printlist(headpointer);
    return headpointer;
}

struct node * insertnnodesbeforex(struct node * headpointer, int N, int X){
    struct node * tempheadpointer = headpointer;
    struct node * prev = NULL;
    struct node * newlist = constructor(N, 1);

    while (tempheadpointer != NULL){
        if (tempheadpointer->data == X){
            if (prev != NULL) {
                prev->next = newlist;
            } else {
                headpointer = newlist;
            }
            struct node * newlisttraverser = newlist;
            while (newlisttraverser->next != NULL){
                newlisttraverser = newlisttraverser -> next;
            }
            newlisttraverser->next = tempheadpointer;
            break;
        }
        prev = tempheadpointer;
        tempheadpointer = tempheadpointer -> next;
    }

    return headpointer;
}

struct node * insertnnodesafterx(struct node * headpointer, int N, int X){
    struct node * tempheadpointer = headpointer;
    struct node * newlist = constructor(N, 1);

    while (tempheadpointer != NULL){
        if (tempheadpointer->data == X){
            struct node * newlisttraverser = newlist;
            while (newlisttraverser->next != NULL){
                newlisttraverser = newlisttraverser -> next;
            }
            newlisttraverser->next = tempheadpointer->next;
            tempheadpointer->next = newlist;
            break;
        }
        tempheadpointer = tempheadpointer -> next;
    }

    return headpointer;
}

struct node * deleteFirstNode(struct node * start) {
    if (start == NULL)
        return NULL;
    struct node * temp = start;
    start = start->next;
    free(temp);
    return start;
}

struct node * deleteLastNode(struct node * start) {
    if (start == NULL)
        return NULL;
    if (start->next == NULL) {
        free(start);
        return NULL;
    }
    struct node * second_last = start;
    while (second_last->next->next != NULL)
        second_last = second_last->next;
    free(second_last->next);
    second_last->next = NULL;
    return start;
}

struct node * deleteNodeAfterX(struct node * start, int x) {
    struct node * temp = start;
    while (temp != NULL && temp->data != x)
        temp = temp->next;
    if (temp != NULL && temp->next != NULL) {
        struct node * node_to_delete = temp->next;
        temp->next = temp->next->next;
        free(node_to_delete);
    }
    return start;
}

struct node * deleteNodeBeforeX(struct node * start, int x) {
    if (start == NULL || start->data == x)
        return start;
    struct node * prev = NULL, * curr = start;
    while (curr != NULL && curr->data != x) {
        prev = curr;
        curr = curr->next;
    }
    if (curr != NULL && prev != NULL) {
        if (prev == start) {
            start = start->next;
        } else {
            struct node * temp = start;
            while (temp->next != prev)
                temp = temp->next;
            temp->next = prev->next;
        }
        free(prev);
    }
    return start;
}

int main(){
    struct node *HEAD = constructor(10, 5);

    printf("LEN: %d\n", findlength(HEAD));
    
    HEAD = insertatstart(HEAD, 100);
    printf("INS-ST-100\n");
    printlist(HEAD);

    HEAD = insertatend(HEAD, 200);
    printf("INS-END-200\n");
    printlist(HEAD);

    HEAD = insertatpos(HEAD, 50, 2);
    printf("INS-POS-50\n");
    printlist(HEAD);

    HEAD = insertnatpos(HEAD, 300, 1);
    printf("INS-NAT-POS-300\n");
    printlist(HEAD);
    
    HEAD = insertnnodesbeforex(HEAD, 5, 302);
    printf("INS-NBEF-POS-302\n");
    printlist(HEAD);

    HEAD = insertnnodesafterx(HEAD, 5, 300);
    printf("INS-NAF-POS-302\n");
    printlist(HEAD);
    
    HEAD = deleteFirstNode(HEAD);
    printf("DEL-FIRST\n");
    printlist(HEAD);

    HEAD = deleteLastNode(HEAD);
    printf("DEL-LAST\n");
    printlist(HEAD);

    HEAD = deleteNodeAfterX(HEAD, 50);
    printf("DEL-AFTER-50\n");
    printlist(HEAD);

    HEAD = deleteNodeBeforeX(HEAD, 301);
    printf("DEL-BEFORE-300\n");
    printlist(HEAD);
    
    
    return 0;
}
```

### Circular Linked List

```c
#include<stdio.h>
#include<stdlib.h>

struct node {
    int data;
    struct node * next;
};

struct node * getpointer(int data){
    struct node * element = (struct node *)malloc(sizeof(struct node));
    element->data = data;
    element->next = NULL; 
}

void printlist(struct node * headpointer){
    struct node * temppointer = headpointer;
    printf("%d\t", temppointer->data);
    temppointer = temppointer -> next;
    
    while (temppointer != headpointer){
        printf("%d\t", temppointer->data);
        temppointer = temppointer -> next;
    }

    printf("\n\n\n");
}

struct node * constructor(int constructorlength, int constructoroffset)
{
    struct node *HEAD;
    struct node *temphead = HEAD;
    struct node *tempelement;

    int insertlimit = constructorlength;
    for (int iterable = 0; iterable < insertlimit; iterable++)
    {
        tempelement = getpointer(constructoroffset+iterable);
        if (iterable == 0)
        {
            HEAD = tempelement;
            temphead = tempelement;
        }
        else
        {
            temphead->next = tempelement;
            temphead = tempelement;
        }
        if (iterable == insertlimit - 1)
        {
            temphead->next = HEAD;
        }
    }
    
    return HEAD;
}

struct node * insertatstart(struct node * headpointer, int data){

    // create a element with the data from HEAD itself
    struct node * newelement = getpointer(headpointer->data);

    headpointer->data = data;

    newelement->next = headpointer->next;
    headpointer->next = newelement;

    return headpointer;
}

struct node * insertatend(struct node * headpointer, int data){
    struct node * newelement = getpointer(data);
    newelement->next = headpointer;

    struct node * traversalpointer = headpointer->next;

    while(traversalpointer->next != headpointer){
        traversalpointer = traversalpointer->next;
    }

    traversalpointer->next = newelement;

    return headpointer;

}

struct node * insertatpos(struct node * headpointer, int pos, int data){
    int counter = 0;
    struct node * traverse = headpointer;
    while (counter != pos){
        traverse = traverse->next;
        counter++;
    }
    struct node * duplicatenode = getpointer(traverse->data);
    traverse->data = data;
    duplicatenode->next = traverse->next;
    traverse->next = duplicatenode;

    return headpointer;
}

struct node * insertdatabeforex(struct node * headpointer, int data, int x){
    struct node * traverse = headpointer;
    while (traverse->data != x){
        traverse = traverse-> next;
    }

    struct node * duplicatenode = getpointer(x);
    traverse->data = data;
    duplicatenode->next = traverse->next;
    traverse->next = duplicatenode;

    return headpointer;
}

struct node * insertdataafterx(struct node * headpointer, int data, int x){
    struct node * newelement = getpointer(data);
    struct node * traverse = headpointer;

    while (traverse->data != x){
            traverse = traverse->next;
    }

    newelement->next = traverse->next;
    traverse->next = newelement;

    return headpointer;
}

struct node * deleteelement(struct node * headpointer, int target){
    struct node * traverse = headpointer;

    while (traverse->next->data != target){
        traverse = traverse->next;
    }
    struct node * deletionelement = traverse->next;
    traverse->next = deletionelement->next;
    free(deletionelement);

    return headpointer;
}


int main(){
    struct node * HEAD = constructor(5, 10);
    printf("INS-100-ST\n");
    HEAD = insertatstart(HEAD, 100);
    printlist(HEAD);

    printf("INS-100-END\n");
    HEAD = insertatend(HEAD, 200);
    printlist(HEAD);

    printf("INS-300-AT-3\n");
    insertatpos(HEAD, 3, 300);
    printlist(HEAD);

    printf("INS-50-BEF-11\n");
    insertdatabeforex(HEAD, 50, 11);
    printlist(HEAD);

    printf("INS-500-AF-13\n");
    insertdataafterx(HEAD, 500, 13);
    printlist(HEAD);

    printf("DELETE-500\n");
    deleteelement(HEAD, 500);
    printlist(HEAD);
}```
### Singly Linked List
### Definition of Node
```c
struct node
{
    int data;
    struct node *next;
};
```

```c
struct node *getpointer(int data)
{
    struct node *element = (struct node *)malloc(sizeof(struct node));
    element->data = data;
    element->next = NULL;
    return element;
}
```
### Function to print contents of a Linked List
```c
void printlist(struct node *headpointer)
{
    struct node *tempnode = headpointer;
    while (tempnode->next != NULL)
    {
        printf("%d-", tempnode->data);
        tempnode = tempnode->next;
    }
    printf("%d\n\n", tempnode->data);
}
```
### Function to construct a new Linked List, returns the Head Pointer of the new list
```c
struct node * constructor(int constructorlength, int constructoroffset)
{
    struct node *HEAD;
    struct node *temphead = HEAD;
    struct node *tempelement;

    int insertlimit = constructorlength;
    for (int iterable = 0; iterable < insertlimit; iterable++)
    {
        tempelement = getpointer(constructoroffset+iterable);
        if (iterable == 0)
        {
            HEAD = tempelement;
            temphead = tempelement;
        }
        else
        {
            temphead->next = tempelement;
            temphead = tempelement;
        }
        if (iterable == insertlimit - 1)
        {
            temphead->next = NULL;
        }
    }
    
    return HEAD;
}
```
### Search function that returns the position of first occurence of element

```c
int search(struct node *headpointer, int data)
{
    struct node *tempnode = headpointer;
    int position = 0;
    for (; tempnode != NULL; tempnode = tempnode->next, position++)
    {
        if (tempnode->data == data)
        {
            printf("Element found at position: %d\n", position);
            return position;
        }
    }
    printf("Element not found in the list.\n");
}
```
### Function to insert given element (data) at the start and at the end of a Linked List
```c
struct node * insertatstart(struct node * headpointer, int data){
    struct node * newelement = getpointer(data);
    newelement -> next = headpointer;
    return newelement;
}

struct node * insertatend(struct node * headpointer, int data){
    struct node * temphead = headpointer;
    while(temphead -> next != NULL){
        temphead = temphead -> next;
    }
    struct node * element = getpointer(data);
    temphead -> next = element;

    return headpointer;
}
```
### Function to insert a given element (data) into some index of a Linked List 
```c
struct node * insertatpos(struct node * headpointer, int data, int position){
    int counter = 0;
    struct node * tempheadpointer = headpointer;
    while (tempheadpointer != NULL && counter != position){
        counter++;
        tempheadpointer = tempheadpointer -> next;
    }

    struct node * poselement = getpointer(tempheadpointer->data);
    poselement->next = tempheadpointer->next;
    tempheadpointer->data = data;
    tempheadpointer->next = poselement;
    
    return headpointer;
}
```
### Function to insert a given new Linked List into some index of a Linked List
```c
struct node * insertnatpos(struct node * headpointer, int offset, int position){
    int counter = 0;
    struct node * tempheadpointer = headpointer;
    struct node * prev = NULL;
    while (tempheadpointer != NULL && counter != position){
        counter++;
        prev = tempheadpointer;
        tempheadpointer = tempheadpointer -> next;
    }

    struct node * newconstructorlist = constructor(3, offset);
    printf("NEW-CH\n");
    printlist(newconstructorlist);
    struct node * newlisttraverser = newconstructorlist;

    while (newlisttraverser->next != NULL){
        newlisttraverser = newlisttraverser -> next;
    }
    newlisttraverser->next = tempheadpointer;

    if (prev != NULL) {
        prev->next = newconstructorlist;
    } else {
        headpointer = newconstructorlist;
    }

    printlist(headpointer);
    return headpointer;
}
```
### Function to insert a given new Linked List into before some index of a Linked List
```c
struct node * insertnnodesbeforex(struct node * headpointer, int N, int X){
    struct node * tempheadpointer = headpointer;
    struct node * prev = NULL;
    struct node * newlist = constructor(N, 1);

    while (tempheadpointer != NULL){
        if (tempheadpointer->data == X){
            if (prev != NULL) {
                prev->next = newlist;
            } else {
                headpointer = newlist;
            }
            struct node * newlisttraverser = newlist;
            while (newlisttraverser->next != NULL){
                newlisttraverser = newlisttraverser -> next;
            }
            newlisttraverser->next = tempheadpointer;
            break;
        }
        prev = tempheadpointer;
        tempheadpointer = tempheadpointer -> next;
    }

    return headpointer;
}
```
### Function to insert a given new Linked List into after some index of a Linked List
```c
struct node * insertnnodesafterx(struct node * headpointer, int N, int X){
    struct node * tempheadpointer = headpointer;
    struct node * newlist = constructor(N, 1);

    while (tempheadpointer != NULL){
        if (tempheadpointer->data == X){
            struct node * newlisttraverser = newlist;
            while (newlisttraverser->next != NULL){
                newlisttraverser = newlisttraverser -> next;
            }
            newlisttraverser->next = tempheadpointer->next;
            tempheadpointer->next = newlist;
            break;
        }
        tempheadpointer = tempheadpointer -> next;
    }

    return headpointer;
}
```



### Doubly Linked List

```c
#include <stdio.h>
#include <stdlib.h>
// Structure Declaration
struct Node {
    int data;
    struct Node *next, *previous;
};
24
 struct Node* getNode(int data);
struct Node* insertNodeAtBeginning(struct Node* start);
struct Node* insertNodeAtEnd(struct Node* start);
struct Node* insertNNodesAtBeginning(struct Node* start, int n);
struct Node* insertNNodesAtEnd(struct Node* start, int n);
struct Node* deleteNodeAtBeginning(struct Node* start);
struct Node* deleteNodeAtEnd(struct Node* start);
struct Node* insertBeforeNodeX(struct Node* start, struct Node* NodeX);
struct Node* search(struct Node* start, int data);
struct Node* insertBeforeNodeX(struct Node* start, struct Node* NodeX);
void display(struct Node* start);
int main() {
    struct Node* start;
    start = getNode(20);
    start = insertNNodesAtEnd(start, 5);
    start = insertBeforeNodeX(start, search(start, 5));
    display(start);
}
struct Node* getNode(int data) {
    struct Node* newNode = (struct Node*) malloc (sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    newNode->previous = NULL;
    return newNode;
}
struct Node* insertNodeAtEnd(struct Node* start) {
    struct Node* current = start;
    while (current->next != NULL) current = current->next;
    int data;
    printf("Enter data: ");
    scanf("%d", &data);
    struct Node* newNode = getNode(data);
25

 // Link
    current->next = newNode;
    newNode->previous = current;
    return start;
}
struct Node* insertNodeAtBeginning(struct Node* start) {
    int data;
    printf("Enter data: ");
    scanf("%d", &data);
    struct Node* newNode = getNode(data);
// Link
    start->previous = newNode;
    newNode->next = start;
    start = newNode;
    return start;
}
struct Node* insertNNodesAtBeginning(struct Node* start, int n) {
    for (int i = 0; i < n; i++) {
        start = insertNodeAtBeginning(start);
    }
    return start;
}
struct Node* insertNNodesAtEnd(struct Node* start, int n) {
    for (int i = 0; i < n; i++) {
        start = insertNodeAtEnd(start);
    }
    return start;
}
struct Node* deleteNodeAtBeginning(struct Node* start) {
    struct Node* current = start;
26

     start = start->next;
    free(current);
    return start;
}
struct Node* deleteNodeAtEnd(struct Node* start) {
    struct Node* current = start;
    while (current->next != NULL) current = current->next;
    current->previous->next = NULL;
    free(current);
    return start;
}
struct Node* search(struct Node* start, int target) {
    struct Node* current = start;
    while (current != NULL) {
        if (current->data == target) {
            return current;
}
        current = current->next;
    }
    return NULL;
}
struct Node* insertBeforeNodeX(struct Node* start, struct Node* NodeX) {
    struct Node* current = start;
    while (current->next != NodeX) {
        current = current->next;
    }
    struct Node* temp = current->next;
    int data;
    printf("Enter data: ");
    scanf("%d", &data);
    struct Node* newNode = getNode(data);
    current->next = newNode;
    newNode->previous = current;
    newNode->next = temp;
27

return start;
}
void display(struct Node* start) {
    struct Node* current = start;
    printf("\n");
    while (current != NULL) {
        printf("(%p) %d (%p) <-> ", current->previous, current->data,
current->next);
        current = current->next;
    }
    printf("NULL\n");
}

```

## Stacks

```c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Stack {
    int top;
    unsigned capacity;
    char* array;
};

struct Stack* createStack(unsigned capacity) {
    struct Stack* stack = (struct Stack*)malloc(sizeof(struct Stack));
    stack->top = -1;
    stack->capacity = capacity;
    stack->array = (char*)malloc(stack->capacity * sizeof(char));
    return stack;
}

int isEmpty(struct Stack* stack) {
    return stack->top == -1;
}

void push(struct Stack* stack, char item) {
    stack->array[++stack->top] = item;
}
 
char pop(struct Stack* stack) {
    if (!isEmpty(stack))
        return stack->array[stack->top--];
    return '$'; // '$' denotes an empty stack
}

char peek(struct Stack* stack) {
    return stack->array[stack->top];
}

int isOperand(char ch) {
    return (ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z');
}

int precedence(char op) {
    if (op == '+' || op == '-')
        return 1;
    if (op == '*' || op == '/')
        return 2;
    return 0;
}

void infixToPostfix(char* infix) {
    int length = strlen(infix);
    struct Stack* stack = createStack(length);
    int i, k;

    for (i = 0, k = -1; i < length; ++i) {
        if (isOperand(infix[i]))
            infix[++k] = infix[i];
        else if (infix[i] == '(')
            push(stack, infix[i]);
        else if (infix[i] == ')') {
            while (!isEmpty(stack) && peek(stack) != '(')
                infix[++k] = pop(stack);
            if (!isEmpty(stack) && peek(stack) != '(')
                return; // Invalid expression
            else
                pop(stack);
        }
        else {
            while (!isEmpty(stack) && precedence(infix[i]) <= precedence(peek(stack)))
                infix[++k] = pop(stack);
            push(stack, infix[i]);
        }
    }

    while (!isEmpty(stack))
        infix[++k] = pop(stack);

    infix[++k] = '\0';

    printf("Postfix expression: %s\n", infix);
}

int evaluatePostfix(char* postfix) {
    struct Stack* stack = createStack(strlen(postfix));
    int i, operand1, operand2;

    for (i = 0; postfix[i] != '\0'; ++i) {
        if (isOperand(postfix[i]))
            push(stack, postfix[i] - '0');
        else {
            operand2 = pop(stack);
            operand1 = pop(stack);
            switch (postfix[i]) {
                case '+':
                    push(stack, operand1 + operand2);
                    break;
                case '-':
                    push(stack, operand1 - operand2);
                    break;
                case '*':
                    push(stack, operand1 * operand2);
                    break;
                case '/':
                    push(stack, operand1 / operand2);
                    break;
            }
        }
    }

    return pop(stack);
}

int main() {
    char infix[100];
    
    printf("Enter infix expression: ");
    scanf("%s", infix);

    infixToPostfix(infix);

    return 0;
}
```


## Queues

### Standard Queue - Array Implementation

```c
#include<stdio.h>
#include<stdlib.h>

void enqueue(int * queueobject, int queuesize, int * rearpointer, int data){
    int targetrearpointer = (*(rearpointer) + 1)%queuesize;
    if (*(queueobject+ *(rearpointer)) != 0){

        printf("QUEUE FULL, CANNOT INS, REF %d-%d\n", *(rearpointer), targetrearpointer);
    } else {
        *(queueobject + *(rearpointer)) = data;
        *(rearpointer) = targetrearpointer;
    }
}

void dequeue(int * queueobject, int queuesize, int * frontpointer){
    if (*(queueobject + *frontpointer) == 0){
        printf("EMPTY Q NO DEQUEUE\n");
    } else {
        printf("DEQUEUE RESULT %d\n", *(queueobject + *(frontpointer)));
        *(queueobject + *(frontpointer)) = 0;
        *(frontpointer) = (*(frontpointer) + 1) % queuesize;
    }
}

void printqueue(int * queueobject, int queuesize){
    printf("Queue's contents: \n");
    for (int iterable = 0; iterable < queuesize; iterable++){
        printf("%d ", *(queueobject + iterable));
    }
    printf("\n\n");
}

int main(){
    int array[10] = {0};
    int * arraypointer = array;

    int front = 0;
    int rear = 0;


    enqueue(arraypointer, 10, &rear, 1);
    enqueue(arraypointer, 10, &rear, 2);
    enqueue(arraypointer, 10, &rear, 3);
    enqueue(arraypointer, 10, &rear, 4);
    enqueue(arraypointer, 10, &rear, 1);
    enqueue(arraypointer, 10, &rear, 2);
    enqueue(arraypointer, 10, &rear, 3);
    enqueue(arraypointer, 10, &rear, 4);
    enqueue(arraypointer, 10, &rear, 1);
    enqueue(arraypointer, 10, &rear, 2);

    printqueue(arraypointer, 10);

    dequeue(arraypointer, 10, &front);
    
    enqueue(arraypointer, 10, &rear, 3);
     
    printqueue(arraypointer, 10);

    dequeue(arraypointer, 10, &front);
    
    printqueue(arraypointer, 10);

    dequeue(arraypointer, 10, &front);
    
    printqueue(arraypointer, 10);
    
    dequeue(arraypointer, 10, &front);
    
    printqueue(arraypointer, 10);

    dequeue(arraypointer, 10, &front);
    
    printqueue(arraypointer, 10);

    dequeue(arraypointer, 10, &front);
    
    printqueue(arraypointer, 10);
    
    dequeue(arraypointer, 10, &front);
    
    printqueue(arraypointer, 10);

    dequeue(arraypointer, 10, &front);
    
    printqueue(arraypointer, 10);

    dequeue(arraypointer, 10, &front);
    
    printqueue(arraypointer, 10);
    
    dequeue(arraypointer, 10, &front);
    
    printqueue(arraypointer, 10);

    dequeue(arraypointer, 10, &front);
    
    printqueue(arraypointer, 10);
    
    dequeue(arraypointer, 10, &front);
    
    printqueue(arraypointer, 10);

}
```

### Double Ended Queue - Array Implementation
```c
#include<stdio.h>
#include<stdlib.h>

void enqueue(int * queueobject, int queuesize, int * rearpointer, int data){
    int targetrearpointer = (*(rearpointer) + 1)%queuesize;
    if (*(queueobject+ *(rearpointer)) != 0){
        printf("QUEUE FULL, CANNOT INS, REF %d-%d\n", *(rearpointer), targetrearpointer);
    } else {
        *(queueobject + *(rearpointer)) = data;
        *(rearpointer) = targetrearpointer;
    }
}

void enqueuefront(int * queueobject, int queuesize, int * frontpointer, int data) {
    int targetfrontpointer = (*(frontpointer) - 1 + queuesize) % queuesize;
    if (*(queueobject + targetfrontpointer) != 0) {
        printf("QUEUE FULL, CANNOT INS, REF %d-%d\n", *(frontpointer), targetfrontpointer);
    } else {
        *(queueobject + *(frontpointer)) = data;
        *(frontpointer) = targetfrontpointer;
    }
}

void dequeue(int * queueobject, int queuesize, int * frontpointer){
    if (*(queueobject + *frontpointer) == 0){
        printf("EMPTY Q NO DEQUEUE\n");
    } else {
        printf("DEQUEUE RESULT %d\n", *(queueobject + *(frontpointer)));
        *(queueobject + *(frontpointer)) = 0;
        *(frontpointer) = (*(frontpointer) + 1) % queuesize;
    }
}

void dequeueback(int * queueobject, int queuesize, int * rearpointer){
    int targetrearpointer = (*rearpointer - 1 + queuesize) % queuesize;
    if (*(queueobject + targetrearpointer) == 0){
        printf("EMPTY Q NO DEQUEUE\n");
    } else {
        printf("DEQUEUE BCK RESULT %d\n", *(queueobject + targetrearpointer));
        *(queueobject + targetrearpointer) = 0;
        *(rearpointer) = targetrearpointer;
    }
}

void printqueuecircle(int * queueobject, int queuesize, int frontpointer, int rearpointer){
    int radius = queuesize / 2;
    for(int i = -radius; i <= radius; i++){
        for(int j = -radius; j <= radius; j++){
            if(i*i + j*j <= radius*radius){
                int index = (j + radius + frontpointer) % queuesize;
                if(index == frontpointer && index == rearpointer){
                    printf("F%dR ", *(queueobject + index));
                } else if(index == frontpointer){
                    printf("F%d  ", *(queueobject + index));
                } else if(index == rearpointer){
                    printf(" %dR ", *(queueobject + index));
                } else {
                    printf(" %d  ", *(queueobject + index));
                }
            } else {
                printf("    ");
            }
        }
        printf("\n");
    }
}

void printqueue(int * queueobject, int queuesize, int frontpointer, int rearpointer){
    printf("Queue's contents: \n");
    for (int i = 0; i < queuesize; i++){
        if (i == frontpointer){
            printf("F->");
        }
        if (i == rearpointer){
            printf("R->");
        }
        printf("%d ", *(queueobject + i));
    }
    printf("\n\n");
    printf("Note: The queue wraps around from the end back to the start.\n");
}

int main(){
    int array[10] = {0};
    int * arraypointer = array;

    int front = 0;
    int rear = 0;


    enqueue(arraypointer, 10, &rear, 1);
    enqueue(arraypointer, 10, &rear, 2);
    enqueue(arraypointer, 10, &rear, 3);
    enqueue(arraypointer, 10, &rear, 4);
    enqueue(arraypointer, 10, &rear, 1);
    enqueue(arraypointer, 10, &rear, 2);
    enqueue(arraypointer, 10, &rear, 3);
    enqueue(arraypointer, 10, &rear, 4);
    enqueue(arraypointer, 10, &rear, 1);
    enqueue(arraypointer, 10, &rear, 2);

    printqueue(arraypointer, 10, front, rear);

    dequeue(arraypointer, 10, &front);
    
    printqueue(arraypointer, 10, front, rear);

    enqueue(arraypointer, 10, &rear, 3);
     
    printqueue(arraypointer, 10, front, rear);

    dequeueback(arraypointer, 10, &rear);

    printqueue(arraypointer, 10, front, rear);

    enqueuefront(arraypointer, 10, &front, 5);

    printqueue(arraypointer, 10, front, rear);

}
```

### Standard Queue - Linked List Implementation
```c
#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
    int key;
};

struct node *returnkeynode(struct node *queueobject, int key)
{
    struct node *traversalnode = queueobject;
    while (traversalnode != NULL)
    {
        if (traversalnode->key == key)
        {
            return traversalnode;
        }
        else
        {
            traversalnode = traversalnode->next;
        }
    }
    return NULL;
}

void printqueue(struct node *rootnode)
{
    struct node *traversalnode = rootnode;

    while (traversalnode != NULL)
    {
        printf(" %d @ (%d)  ", traversalnode->data, traversalnode->key);
        traversalnode = traversalnode->next;
    }
    printf("\n");
}

struct node *getnode(int data)
{
    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data = data;
    newnode->next = NULL;
    newnode->key = 0;
    return newnode;
}

struct node *createqueue(int length)
{
    struct node *rootnode = getnode(0);
    struct node *traversalnode = rootnode;

    for (int iterable = 0; iterable < length - 1; iterable++)
    {
        traversalnode->next = getnode(0);
        traversalnode = traversalnode->next;
        traversalnode->key = iterable + 1;
    }

    return rootnode;
}

struct node *insertat(struct node *queueobject, int data, int key)
{
    struct node *targetnode = returnkeynode(queueobject, key);
    if (targetnode != NULL)
    {
        targetnode->data = data;
    }
    return queueobject;
}

struct node *deleteat(struct node *queueobject, int key, int *returninteger)
{
    struct node *targetnode = returnkeynode(queueobject, key);
    if (targetnode != NULL)
    {
        // printf("DELTRGTVAL %d\n", targetnode->data);
        *(returninteger) = targetnode->data;
        targetnode->data = 0;
    }
    return queueobject;
}

void enqueue(struct node *queueobject, int queuelength, int *backpointer, int data, int *frontpointer)
{   
    if (*(backpointer) == queuelength - 1)
    {
        printf("Overflow\n");
    }
    else
    {
        if (*(backpointer) == -1 && *(frontpointer) == -1)
        {
            *(frontpointer) = 0;
        }
        *(backpointer) = *(backpointer) + 1;
        insertat(queueobject, data, *(backpointer));
    }
}

int dequeue(struct node *queueobject, int *frontpointer, int *(rearpointer))
{
    int deleteinteger = 0;
    if (*(frontpointer) == -1 && *(rearpointer) == -1)
    {
        printf("Underflow\n");
    }
    else
    {
        deleteat(queueobject, *(frontpointer), &deleteinteger);
        *(frontpointer) = *(frontpointer) + 1;
    }
    printf("DEL %d\n", deleteinteger);
    return deleteinteger;
}

int getfront(struct node *queueobject, int *frontpointer)
{
    return returnkeynode(queueobject, *(frontpointer))->data;
}

int isEmpty(int *frontpointer, int *rearpointer)
{   if (*(frontpointer) == *(rearpointer)){
        printf("EMTY Q\n");
    }
    return *(frontpointer) == *(rearpointer);
}

int main()
{
    // test case 1
    printf("TC1\n");
    struct node *rootnode = createqueue(10);
    int sizeofqueue = 10;

    int front = -1;
    int back = -1;

    enqueue(rootnode, sizeofqueue, &back, 5, &front);
    enqueue(rootnode, sizeofqueue, &back, 10, &front);
    printf("FRONT-%d\n", getfront(rootnode, &front));
    printqueue(rootnode);
printf("\n\n");
    // test case 2
    printf("TC2\n");
    rootnode = createqueue(10);
    sizeofqueue = 10;

    front = -1;
    back = -1;

    enqueue(rootnode, sizeofqueue, &back, 3, &front);
    enqueue(rootnode, sizeofqueue, &back, 7, &front);
    enqueue(rootnode, sizeofqueue, &back, 1, &front);
    dequeue(rootnode, &front, &back);
    printf("FRONT VAL %d\n",getfront(rootnode, &front));

    printqueue(rootnode);
printf("\n\n");

    // test case 3
    printf("TC3\n");
    rootnode = createqueue(10);
    sizeofqueue = 10;

    front = -1;
    back = -1;

    isEmpty(&front, &back);

    printqueue(rootnode);
printf("\n\n");

    // test case 4
    printf("TC4\n");
    rootnode = createqueue(10);
    sizeofqueue = 10;

    front = -1;
    back = -1;

    dequeue(rootnode, &front, &back);

    printqueue(rootnode);
printf("\n\n");

    // test case 5
    printf("TC5\n");
    rootnode = createqueue(10);
    sizeofqueue = 10;

    front = -1;
    back = -1;

    enqueue(rootnode, sizeofqueue, &back, 2, &front);
    enqueue(rootnode, sizeofqueue, &back, 4, &front);
    dequeue(rootnode, &front, &back);
    enqueue(rootnode, sizeofqueue, &back, 6, &front);
    printf("FRONT VAL %d\n",getfront(rootnode, &front));

    printqueue(rootnode);
printf("\n\n");

    // test case 6
    printf("TC6\n");
    rootnode = createqueue(10);
    sizeofqueue = 10;

    front = -1;
    back = -1;

    enqueue(rootnode, sizeofqueue, &back, 8, &front);
    dequeue(rootnode, &front, &back);
    printf("%d %d\n", front, back);
    isEmpty(&front, &back);   
}
```

## Binary Trees

### Binary Search Tree - Array Implementation
```c
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


int isValidElement(int *tree, int index, int size){
    if (index > size-1){
        return 0;
    }

    if (*(tree+index) != -1){
        printf("Tree has valid child at %d which is %d\n", index,*(tree+index));
        return 1;
    } else {
        return 0;
    }
}

int findMinimum(int *tree, int subtreeindex, int size){
    if (isValidElement(tree, 2*subtreeindex+1, size)){
        return findMinimum(tree, 2*subtreeindex + 1, size);
    }

    return *(tree + subtreeindex);
}

void fastdelete(int *tree, int index, int size){
    if (isValidElement(tree, 2*index+1, size) && isValidElement(tree, 2*index+2, size)){
        printf("Two Children\n");
    } else if (isValidElement(tree, 2*index+1, size) && !isValidElement(tree, 2*index+2, size)){
        printf("Left Child Only\n");
    } else if (!isValidElement(tree, 2*index+1, size) && isValidElement(tree, 2*index+2, size)){
        printf("Right Child Only\n");
    }else if (!isValidElement(tree, 2*index+1, size) && !isValidElement(tree, 2*index+2, size)){
        printf("No Child\n");
    }
}

void insertion(int *tree, int counter, int size, int data)
{
    if (counter >= size)
    {
        printf("Tree is full. Cannot insert %d\n", data);
        return;
    }

    if (*(tree + counter) == -1)
    {
        *(tree + counter) = data;
    }
    else if (*(tree + counter) < data)
    {
        insertion(tree, 2 * counter + 2, size, data);
    }
    else if (*(tree + counter) > data)
    {
        insertion(tree, 2 * counter + 1, size, data);
    }
    else
    {
        printf("Duplicate value %d. Not inserted.\n", data);
    }
}

void inordertraversal(int *tree, int counter, int size)
{
    if (counter >= size || tree[counter] == -1)
    {
        return;
    }

    inordertraversal(tree, 2 * counter + 1, size); // Left child
    printf("%d ", tree[counter]);                  // Current node
    inordertraversal(tree, 2 * counter + 2, size); // Right child
}

void preordertraversal(int *tree, int counter, int size)
{
    if (counter >= size || tree[counter] == -1)
    {
        return;
    }

    printf("%d ", tree[counter]);                   // Current node
    preordertraversal(tree, 2 * counter + 1, size); // Left child
    preordertraversal(tree, 2 * counter + 2, size); // Right child
}

void postordertraversal(int *tree, int counter, int size)
{
    if (counter >= size || tree[counter] == -1)
    {
        return;
    }

    postordertraversal(tree, 2 * counter + 1, size); // Left child
    postordertraversal(tree, 2 * counter + 2, size); // Right child
    printf("%d ", tree[counter]);                    // Current node
}

int main()
{
    int treearray[100] = {-1};
    int stree[] = {53, 31, 75, 28, 40, 63, 88, -1, -1, -1, 1, -1, -1, -1, -1};
    int treesize = sizeof(stree)/sizeof(int);
    int *treepointer = stree;

    fastdelete(treepointer,4,treesize);
    inordertraversal(treepointer, 0, 7);
    printf("\n");
    preordertraversal(treepointer, 0, 7);
    printf("\n");
    postordertraversal(treepointer, 0, 7);
    printf("\n");
    return 0;
}
```

### Binary Search Tree - Linked List Implementation
```c
#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *left;
    struct node *right;
};

struct node *getNode(int data)
{
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

struct node *findminimum(struct node *rootnode)
{
    if (rootnode->left != NULL)
    {
        return findminimum(rootnode->left);
    }
    return rootnode;
}

struct node *search(struct node *root, int target, int *child_side)
{
    if (root->data == target)
    {
        *child_side = 0;
        return root;
    }
    else if (root->left->data == target)
    {
        *child_side = 1;
        return root;
    }
    else if (root->right->data == target)
    {
        *child_side = 2;
        return root;
    }
    else if (target < root->data)
    {
        search(root->left, target, child_side);
    }
    else if (target > root->data)
    {
        search(root->right, target, child_side);
    }
    else
    {
    }
}

struct node *deletion(struct node *rootnode, int data)
{
    struct node *traversalpointer = rootnode;
    struct node *parentpointer = NULL;

    while (traversalpointer->data != data)
    {
        printf("%d - ", traversalpointer->data);
        if (data < traversalpointer->data)
        {
            parentpointer = traversalpointer;
            traversalpointer = traversalpointer->left;
        }
        else if (data > traversalpointer->data)
        {
            parentpointer = traversalpointer;
            traversalpointer = traversalpointer->right;
        }
    }

    printf("\nDEL DATA: %d\n", traversalpointer->data);

    if ((traversalpointer->left && !traversalpointer->right) || (!traversalpointer->left && traversalpointer->right))
    {
        if (traversalpointer->left)
        {
            printf("Left Child Only\n");
            parentpointer->left = traversalpointer->left;
        }
        else if (traversalpointer->right)
        {
            printf("Right Child Only\n");
            parentpointer->right = traversalpointer->right;
        }
        free(traversalpointer);
    }
    else if (!traversalpointer->right && !traversalpointer->left)
    {
        printf("No Child\n");
        if (parentpointer->data < data)
        {
            parentpointer->right = NULL;
            free(traversalpointer);
        }
        else if (parentpointer->data > data)
        {
            parentpointer->left = NULL;
            free(traversalpointer);
        }
    }
    else
    {
        printf("Two Children\n");
        struct node *inordersucessor = findminimum(traversalpointer->right);
        printf("INORDER SUCCESSOR IS %d\n", inordersucessor->data);
        int finder = 0;
        int *finderpointer = &finder;

        struct node *searchresult = search(rootnode, inordersucessor->data, finderpointer);

        if (*(finderpointer) == 1)
        {
            searchresult->left = NULL;
        }
        else if (*(finderpointer) == 2)
        {
            searchresult->right = NULL;
        }
        else if (*(finderpointer) == 0)
        {
            printf("UNKNOWN CASE\n");
        }

        traversalpointer->data = inordersucessor->data;
        free(inordersucessor);
    }

    return rootnode;
}

struct node *insertion(struct node *rootnode, int data)
{
    struct node *traversalpointer = rootnode;

    struct node *newnode = getNode(data);

    if (!rootnode)
    {
        return newnode;
    }
    while (traversalpointer)
    {
        if (traversalpointer->data < data && traversalpointer->right != NULL)
        {
            traversalpointer = traversalpointer->right;
        }
        else if (traversalpointer->data >= data && traversalpointer->left != NULL)
        {
            traversalpointer = traversalpointer->left;
        }
        else
        {
            break;
        }
    }

    if (traversalpointer->data < data)
    {
        traversalpointer->right = newnode;
    }
    else if (traversalpointer->data >= data)
    {
        traversalpointer->left = newnode;
    }

    return rootnode;
}

void printTree(struct node *rootnode, int level)
{
    if (rootnode == NULL)
    {
        return;
    }
    printTree(rootnode->right, level + 1);
    for (int i = 0; i < level; i++)
    {
        printf("    ");
    }
    printf("%d\n", rootnode->data);
    printTree(rootnode->left, level + 1);
}

void display_tree(struct node *root, int level)
{
    if (root == NULL)
    {
        return;
    }
    display_tree(root->right, level + 1);
    for (int i = 0; i < level; i++)
    {
        printf("|\t");
    }
    printf("|------>%d\n", root->data);
    display_tree(root->left, level + 1);
}

void inordertraversal(struct node *rootnode)
{
    struct node *traversalnode = rootnode;

    if (traversalnode->left != NULL)
    {
        inordertraversal(traversalnode->left);
    }

    printf("%d ", traversalnode->data);

    if (traversalnode->right != NULL)
    {
        inordertraversal(traversalnode->right);
    }
}

void preordertraversal(struct node *rootnode)
{
    struct node *traversalnode = rootnode;

    if (rootnode == NULL)
    {
        return;
    }
    printf("%d ", traversalnode->data);

    if (traversalnode->left != NULL)
    {
        preordertraversal(traversalnode->left);
    }

    if (traversalnode->right != NULL)
    {
        preordertraversal(traversalnode->right);
    }
}

void postordertraversal(struct node *rootnode)
{
    struct node *traversalnode = rootnode;

    if (traversalnode->left != NULL)
    {
        postordertraversal(traversalnode->left);
    }

    if (traversalnode->right != NULL)
    {
        postordertraversal(traversalnode->right);
    }

    printf("%d ", traversalnode->data);
}

void iterinorder(struct node * rootnode){
    struct node * current = rootnode;
    struct node * stack[100];

    int top = -1;

    while (current != NULL || top != -1){
        while (current != NULL){
            stack[top] = current;
            top = top + 1;
            current = current->left;
        }

        current = stack[top];
        top = top - 1;
        printf(" %d ", current->data);
        current = current->right;
    }
}

void iterpreorder(struct node * rootnode){
    if (rootnode == NULL){
        return ;
    }

    struct node * stack[100];
    int top = -1;
    stack[++top] = rootnode;

    while (top != -1){
        struct node * current = stack[top];
        top = top - 1;

        printf(" %d ", current->data);

        if (current->right != NULL){
            stack[++top] = current->right;
        }
        if (current->left != NULL){
            stack[++top] = current->left;
        }
    }
}

void iterpostorder1(struct node * rootnode){
    if (rootnode == NULL){
        return ;
    }

    struct node * stack1[100];
    struct node * stack2[100];
    int top1 = -1, top2 = -1;
    stack1[++top1] = rootnode;

    while (top1 != -1){
        struct node * current = stack1[top1--];
        stack2[++top2] = current;

        if (current->left != NULL){
            stack1[++top1] = current->left;
        }
        if (current->right != NULL){
            stack1[++top1] = current->right;
        }
    }

    while (top2 != -1){
        struct node * current = stack2[top2--];
        printf(" %d ", current->data);
    }
}

void iterpostorder2(struct node * rootnode){
    if (rootnode == NULL){
        return ;
    }

    struct node * stack[100];
    int top = -1;
    struct node * current = rootnode;
    struct node * visited = NULL;

    do {
        while (current != NULL){
            stack[++top] = current;
            current = current->left;
        }
        current = stack[top];
        if (current->right == NULL || current->right == visited){
            printf(" %d ", current->data);
            top--;
            visited = current;
            current = NULL;
        } else {
            current = current->right;
        }
    } while (top != -1);
}

int main()
{
    struct node *rootnode = NULL;

    // Inserting nodes
    rootnode = insertion(rootnode, 12);
    rootnode = insertion(rootnode, 5);
    rootnode = insertion(rootnode, 15);
    rootnode = insertion(rootnode, 3);
    rootnode = insertion(rootnode, 7);
    rootnode = insertion(rootnode, 13);
    rootnode = insertion(rootnode, 17);
    rootnode = insertion(rootnode, 16);
    rootnode = insertion(rootnode, 1);
    rootnode = insertion(rootnode, 9);
    rootnode = insertion(rootnode, 14);
    rootnode = insertion(rootnode, 20);
    rootnode = insertion(rootnode, 8);
    rootnode = insertion(rootnode, 11);
    rootnode = insertion(rootnode, 18);
    rootnode = insertion(rootnode, 6);

    printf("Before Deletion\n");
    // Printing the tree
    printTree(rootnode, 0);
    display_tree(rootnode, 0);

    deletion(rootnode, 5);
    // deletion(rootnode, 7);
    // deletion(rootnode, 18);

    printf("\n");
    printf("\n");
    printf("After Deletion\n");
    printTree(rootnode, 0);

    printf("INORDER: ");
    inordertraversal(rootnode);
    printf("\n");

    printf("PREORDER: ");
    preordertraversal(rootnode);
    printf("\n");

    printf("POSTORDER: ");
    postordertraversal(rootnode);
    printf("\n");

    return 0;
}
```

### Generating a tree from Preorder and Inorder Traversals
```c
#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *left;
    struct node *right;
};

struct node *constructtree(int inorder[], int preorder[], int start, int end);
void inorderTraversal(struct node *root);
int searchfunction(int treeobject[], int start, int end, int value);

struct node *constructtree(int inorder[], int preorder[], int start, int end)
{
    if (start > end)
        return NULL;

    static int index = 0;
    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data = preorder[index++];
    newnode->left = NULL;
    newnode->right = NULL;

    if (start == end)
        return newnode;

    int index1 = searchfunction(inorder, start, end, newnode->data);

    newnode->left = constructtree(inorder, preorder, start, index1 - 1);
    newnode->right = constructtree(inorder, preorder, index1 + 1, end);

    return newnode;
}

void inorderTraversal(struct node *root)
{
    if (root == NULL)
        return;

    inorderTraversal(root->left);
    printf("%d ", root->data);
    inorderTraversal(root->right);
}

int searchfunction(int treeobject[], int start, int end, int value)
{
    for (int iterable = start; iterable <= end; iterable++)
    {
        if (treeobject[iterable] == value)
            return iterable;
    }
    return -1;
}

int searchfunction(int treeobject[], int start, int end, int value)
{
    int iterable;
    for (iterable = start; iterable <= end; iterable++)
    {
        if (treeobject[iterable] == value)
            return iterable;
    }
    return 0;
}

struct node *constructtree(int inorder[], int preorder[], int start, int end)
{
    int index = 0;

    if (start > end)
        return NULL;

    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data = preorder[index++];
    newnode->left = NULL;
    newnode->right = NULL;

    if (start == end)
        return newnode;

    int index1 = searchfunction(inorder, start, end, newnode->data);

    newnode->left = constructtree(inorder, preorder, start, index1 - 1);
    newnode->right = constructtree(inorder, preorder, index1 + 1, end);

    return newnode;
}

void inorderTraversal(struct node *root)
{
    if (root == NULL)
        return;

    inorderTraversal(root->left);
    printf("%d ", root->data);
    inorderTraversal(root->right);
}
```

### Expression Trees
```c
#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    char data;
    struct Node* left;
    struct Node* right;
} Node;

Node* GetNode(char data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}
int isOperator(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/');
}
Node* constructExpressionTree(char postfix[]) {
    int i = 0;
    Node* stack[100];
    int top = -1;
    while (postfix[i] != '\0') {
        char symbol = postfix[i];
        if (!isOperator(symbol)) {
            stack[++top] = GetNode(symbol);
        } else {
            Node* newNode = GetNode(symbol);
            newNode->right = stack[top--];
            newNode->left = stack[top--];
            stack[++top] = newNode;
        }
        i++;
    }
    return stack[top];
}

int evaluateExpressionTree(Node* root) {
    if (root == NULL) {
        return 0;
    }
    if (!isOperator(root->data)) {
        return root->data - '0';
    } else {
        int leftValue = evaluateExpressionTree(root->left);
        int rightValue = evaluateExpressionTree(root->right);
        switch (root->data) {
            case '+':
                return leftValue + rightValue;
            case '-':
                return leftValue - rightValue;
            case '*':
                return leftValue * rightValue;
            case '/':
                if (rightValue != 0) {
                    return leftValue / rightValue;
                } else {
                    printf("Error: Division by zero.\n");
                    
                }
            default:
                printf("Error: Invalid operator.\n");
                
        }
    }
}
int main() {
    char postfixExpression[100]; 
    printf("Enter a postfix expression: ");
    scanf("%s", postfixExpression);
    Node* expressionTree = constructExpressionTree(postfixExpression);
    printf("Postfix Expression: %s\n", postfixExpression);
    printf("Result: %d\n", evaluateExpressionTree(expressionTree));
    return 0;
}
```

### AVL Trees
```c
#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *leftchild;
    struct node *rightchild;
    int height;
};

int getMaximum(int a, int b)
{
    return (a > b) ? a : b;
}

int height(struct node *node)
{
    if (node == NULL)
    {
        return 0;
    }
    return node->height;
}

int getBalanceFactor(struct node *node)
{
    if (node == NULL)
    {
        return 0;
    }
    return height(node->leftchild) - height(node->rightchild);
}

struct node *rightRotate(struct node *parent)
{
    struct node *pivot = parent->leftchild;
    parent->leftchild = pivot->rightchild;
    pivot->rightchild = parent;
    parent->height = getMaximum(height(parent->leftchild), height(parent->rightchild)) + 1;
    pivot->height = getMaximum(height(pivot->leftchild), height(pivot->rightchild)) + 1;
    return pivot;
}

struct node *leftRotate(struct node *parent)
{
    struct node *pivot = parent->rightchild;
    parent->rightchild = pivot->leftchild;
    pivot->leftchild = parent;
    parent->height = getMaximum(height(parent->leftchild), height(parent->rightchild)) + 1;
    pivot->height = getMaximum(height(pivot->leftchild), height(pivot->rightchild)) + 1;
    return pivot;
}

struct node *insert(struct node *node, int data)
{
    if (node == NULL)
    {
        struct node *temp = (struct node *)malloc(sizeof(struct node));
        temp->data = data;
        temp->leftchild = NULL;
        temp->rightchild = NULL;
        temp->height = 0;
        return temp;
    }
    if (data < node->data)
    {
        node->leftchild = insert(node->leftchild, data);
    }
    else if (data > node->data)
    {
        node->rightchild = insert(node->rightchild, data);
    }
    else
    {
        return node;
    }
    node->height = getMaximum(height(node->leftchild), height(node->rightchild));
    int balanceFactor = getBalanceFactor(node);
    if (balanceFactor > 1)
    {
        if (data < node->leftchild->data)
        {
            return rightRotate(node);
        }
        else
        {
            node->leftchild = leftRotate(node->leftchild);
            return rightRotate(node);
        }
    }
    else if (balanceFactor < -1)
    {
        if (data > node->rightchild->data)
        {
            return leftRotate(node);
        }
        else
        {
            node->rightchild = rightRotate(node->rightchild);
            return leftRotate(node);
        }
    }
    return node;
}

void printInorder(struct node *node)
{
    if (node == NULL)
    {
        return;
    }
    printInorder(node->leftchild);
    printf("%d ", node->data);
    printInorder(node->rightchild);
}

void printTree(struct node *root, int level)
{
    if (root == NULL)
    {
        return;
    }
    printTree(root->rightchild, level + 1);
    for (int i = 0; i < level; i++)
    {
        printf("|\t");
    }
    printf("|------>%d\n", root->data);
    printTree(root->leftchild, level + 1);
}

int main()
{
    struct node *root = NULL;
    // 20,10,5,30,40,25,7,35,47,59,68,23,21,2
    root = insert(root, 20);
    root = insert(root, 10);
    root = insert(root, 5);
    root = insert(root, 30);
    root = insert(root, 40);
    root = insert(root, 25);
    root = insert(root, 7);
    root = insert(root, 35);
    root = insert(root, 47);
    root = insert(root, 59);
    root = insert(root, 68);
    root = insert(root, 23);
    root = insert(root, 21);
    root = insert(root, 2);

    printf("Inorder traversal of the constructed AVL tree is \n");
    printInorder(root);

    printf("\n");

    printTree(root, 0);

    return 0;
}
```

## Heaps

### Basic Heap Functions
```c
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int percolateupmaxheap(int *maxheappointer, int heapsize, int child);

int percolateupminheap(int *minheappointer, int heapsize, int child);

int percolatedownmaxheap(int *maxheappointer, int heapsize, int parent)
{
    int leftchild = 2 * (parent) + 1;
    int rightchild = 2 * (parent) + 2;

    if (!*(maxheappointer + leftchild) && !*(maxheappointer + rightchild))
    {
        return 0;
    }

    if (leftchild >= heapsize || rightchild >= heapsize)
    {
        return 0;
    }

    if (*(maxheappointer + leftchild) > *(maxheappointer + rightchild))
    {
        *(maxheappointer + parent) = *(maxheappointer + leftchild);
        *(maxheappointer + leftchild) = -1;
        return percolatedownmaxheap(maxheappointer, heapsize, leftchild);
    }

    else if (*(maxheappointer + leftchild) < *(maxheappointer + rightchild))
    {
        *(maxheappointer + parent) = *(maxheappointer + rightchild);
        *(maxheappointer + rightchild) = -1;
        return percolatedownmaxheap(maxheappointer, heapsize, rightchild);
    }
}

int percolatedownminheap(int *minheappointer, int heapsize, int parent)
{

    int leftchild = 2 * (parent) + 1;
    int rightchild = 2 * (parent) + 2;

    if (!*(minheappointer + leftchild) && !*(minheappointer + rightchild))
    {
        return 0;
    }

    if (leftchild >= heapsize || rightchild >= heapsize)
    {
        return 0;
    }

    if (*(minheappointer + leftchild) < *(minheappointer + rightchild))
    {
        *(minheappointer + parent) = *(minheappointer + leftchild);
        *(minheappointer + leftchild) = -1;
        return percolatedownminheap(minheappointer, heapsize, leftchild);
    }

    else if (*(minheappointer + leftchild) > *(minheappointer + rightchild))
    {
        *(minheappointer + parent) = *(minheappointer + rightchild);
        *(minheappointer + rightchild) = -1;
        return percolatedownminheap(minheappointer, heapsize, rightchild);
    }
}

int completeBinaryTreeInsertion(int *array, int size, int data)
{
    for (int iterable = 0; iterable < size; iterable++)
    {
        if (*(array + iterable) == -1)
        {
            *(array + iterable) = data;
            return iterable;
        }
    }
    return -1;
}

int percolateupminheap(int *minheappointer, int heapsize, int child)
{
    int parent = (child - 1) / 2;
    int tempvar;

    // printf("CHILDVAL %d CHILD %d PARENTVAL %d PARENT %d\n", child, *(minheappointer+child), parent, *(minheappointer+parent));

    if (parent < 0)
    {
        return -1;
    }
    else
    {
        if (*(minheappointer + child) < *(minheappointer + parent))
        {
            // printf("BEFORE SWAP, PARENT %d CHILD %d\n", *(minheappointer+parent), *(minheappointer+child));
            tempvar = *(minheappointer + child);
            *(minheappointer + child) = *(minheappointer + parent);
            *(minheappointer + parent) = tempvar;
            // printf("AFTER SWAP, PARENT %d CHILD %d\n", *(minheappointer+parent), *(minheappointer+child));
            percolateupminheap(minheappointer, heapsize, parent);
        }
    }
}

int percolateupmaxheap(int *maxheappointer, int heapsize, int child)
{
    int parent = (child - 1) / 2;
    int tempvar;

    if (parent < 0)
    {
        return -1;
    }
    else
    {
        if (*(maxheappointer + child) > *(maxheappointer + parent))
        {
            // printf("BEFORE SWAP, PARENT %d CHILD %d\n", *(maxheappointer+parent), *(maxheappointer+child));
            tempvar = *(maxheappointer + child);
            *(maxheappointer + child) = *(maxheappointer + parent);
            *(maxheappointer + parent) = tempvar;
            // printf("AFTER SWAP, PARENT %d CHILD %d\n", *(maxheappointer+parent), *(maxheappointer+child));
            percolateupmaxheap(maxheappointer, heapsize, parent);
        }
    }
}

void printTree(int *tree, int index, int level, int size)
{
    if (index >= size || tree[index] == -1)
    {
        return;
    }

    printTree(tree, 2 * index + 2, level + 1, size); // Right child

    for (int i = 0; i < level; i++)
    {
        printf("    ");
    }
    printf("%d\n", tree[index]); // Current node

    printTree(tree, 2 * index + 1, level + 1, size); // Left child
}

int main()
{

    int maxheaparray[7] = {101, 57, 65, 29, -1, -1, -1};
    int *maxheappointer = maxheaparray;
    int maxheapsize = sizeof(maxheaparray) / sizeof(int);

    printf("Firstly,\n");
    printTree(maxheappointer, 0, 0, maxheapsize);

    printf("\n");

    printf("After percolateup 243, \n");
    percolateupmaxheap(maxheappointer, maxheapsize, completeBinaryTreeInsertion(maxheappointer, maxheapsize, 243));
    printTree(maxheappointer, 0, 0, maxheapsize);
    printf("\n");

    percolatedownmaxheap(maxheappointer, maxheapsize, 0);

    printf("\n");
    printf("After percolatedown, \n");
    printTree(maxheappointer, 0, 0, maxheapsize);

    printf("\n");
    printf("\n");

    int minheaparray[7] = {10, 20, 30, 40, 50, 60, 70};
    int *minheappointer = minheaparray;
    int minheapsize = sizeof(minheaparray) / sizeof(int);

    printf("Firstly,\n");
    printTree(minheappointer, 0, 0, minheapsize);

    printf("\n");
    printf("MIN-ELEMENT: %d\n", *(minheappointer));
    percolatedownminheap(minheappointer, minheapsize, 0);

    printf("\n");

    printf("Finally, \n");
    printTree(minheappointer, 0, 0, minheapsize);

    printf("\n");
    printf("\n");

    int anotherminheap[7] = {10, 15, 20, -1, -1, -1, -1};
    int *anotherminheappointer = anotherminheap;

    printf("Initially, the anotherminheap is\n");
    printTree(anotherminheappointer, 0, 0, 7);
    printf("\n");

    printf("Percolating Up 5:\n");
    percolateupminheap(anotherminheappointer, 7, completeBinaryTreeInsertion(anotherminheappointer, 7, 5));
    printTree(anotherminheappointer, 0, 0, 7);
    printf("\n");

    printf("Percolating Up 2:\n");
    percolateupminheap(anotherminheappointer, 7, completeBinaryTreeInsertion(anotherminheappointer, 7, 4));
    printTree(anotherminheappointer, 0, 0, 7);
    printf("\n");

    printf("Percolating Up 1:\n");
    percolateupminheap(anotherminheappointer, 7, completeBinaryTreeInsertion(anotherminheappointer, 7, 1));
    printTree(anotherminheappointer, 0, 0, 7);
    printf("\n");

    printf("Percolating Up 11:\n");
    percolateupminheap(anotherminheappointer, 7, completeBinaryTreeInsertion(anotherminheappointer, 7, 2));
    printTree(anotherminheappointer, 0, 0, 7);
    printf("\n");

    return 0;
}
```

### Heapsort
```c
#include <stdio.h>
#include <stdlib.h>

void printTree(int *tree, int index, int level, int size)
{
    if (index >= size || tree[index] == -1)
    {
        return;
    }

    printTree(tree, 2 * index + 2, level + 1, size); // Right child

    for (int i = 0; i < level; i++)
    {
        printf("    ");
    }
    printf("%d\n", tree[index]); // Current node

    printTree(tree, 2 * index + 1, level + 1, size); // Left child
}

void reheapify(int *heapobject, int heapsize, int pointer)
{
    int leftchild = 2 * pointer + 1;
    int rightchild = 2 * pointer + 2;

    if (leftchild >= heapsize)
    {
        return;
    }
    else if (rightchild >= heapsize)
    {
        if (*(heapobject + leftchild) > *(heapobject + pointer))
        {
            int temp = *(heapobject + leftchild);
            *(heapobject + leftchild) = *(heapobject + pointer);
            *(heapobject + pointer) = temp;
        }
    }
    else
    {
        if (*(heapobject + leftchild) >= *(heapobject + rightchild) && *(heapobject + leftchild) > *(heapobject + pointer))
        {
            int temp = *(heapobject + leftchild);
            *(heapobject + leftchild) = *(heapobject + pointer);
            *(heapobject + pointer) = temp;

            reheapify(heapobject, heapsize, leftchild);
        }
        else if (*(heapobject + leftchild) <= *(heapobject + rightchild) && *(heapobject + rightchild) > *(heapobject + pointer))
        {
            int temp = *(heapobject + rightchild);
            *(heapobject + rightchild) = *(heapobject + pointer);
            *(heapobject + pointer) = temp;

            reheapify(heapobject, heapsize, rightchild);
        }
    }
}

void heapsort(int *heapobject, int heapsize)
{
    int limit = 0;

    for (int iterable = 0; iterable < heapsize; iterable++)
    {
        // printf("SWAP %d %d\n\n", *(heapobject), *(heapobject + heapsize - 1 - iterable));

        int temp = *(heapobject);
        *(heapobject) = *(heapobject + heapsize - 1 - iterable);
        *(heapobject + heapsize - 1 - iterable) = temp;

        // printf("AFTER SWAP\n");
        // printTree(heapobject, 0, 0, heapsize);
        // printf("\n");

        reheapify(heapobject, heapsize - 1 - iterable, 0);

        // printf("AFTER SWAP, RH5\n");
        // printTree(heapobject, 0, 0, heapsize);
        // printf("\n");
        // printf("\n");
    }
}

int main()
{
    int maxheaparray[] = {94, 84, 78, 42, 40, 42, 31, 22, 2, 31};
    int *maxheappointer = maxheaparray;
    int maxheapsize = sizeof(maxheaparray) / sizeof(int);

    printf("INIT\n");
    
    printTree(maxheappointer, 0, 0, maxheapsize);
    printf("\n");
    for (int i = 0; i < maxheapsize; i++)
    {
        printf("%d-", maxheaparray[i]);
    }

    printf("\n");

    heapsort(maxheappointer, maxheapsize);
    
    printf("\n");
    
    printf("AFTER SORT\n");
    
    printTree(maxheappointer, 0, 0, maxheapsize);
    printf("\n");
    for (int i = 0; i < maxheapsize; i++)
    {
        printf("%d-", maxheaparray[i]);
    }

    printf("\n");
    return 0;
}
```

## Graphs

```c
#include <stdio.h>
#include <stdlib.h>

// Structure to represent a node in the adjacency list
struct Node {
    int data;
    struct Node* next;
};

// Structure to represent the graph
struct Graph {
    int vertices;
    struct Node** adjacencyList;
};

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to create a graph with a given number of vertices
struct Graph* createGraph(int vertices) {
    struct Graph* graph = (struct Graph*)malloc(sizeof(struct Graph));
    graph->vertices = vertices;

    // Create an array of adjacency lists
    graph->adjacencyList = (struct Node**)malloc(vertices * sizeof(struct Node*));

    // Initialize each adjacency list as empty
    for (int i = 0; i < vertices; ++i) {
        graph->adjacencyList[i] = NULL;
    }

    return graph;
}

// Function to add an edge to the graph
void addEdge(struct Graph* graph, int src, int dest) {
    // Add an edge from src to dest
    struct Node* newNode = createNode(dest);
    newNode->next = graph->adjacencyList[src];
    graph->adjacencyList[src] = newNode;

    // For undirected graphs, add an edge from dest to src as well
    newNode = createNode(src);
    newNode->next = graph->adjacencyList[dest];
    graph->adjacencyList[dest] = newNode;
}

// Function to perform Depth First Search (DFS) traversal
void DFS(struct Graph* graph, int startVertex, int visited[]) {
    // Mark the current vertex as visited
    visited[startVertex] = 1;
    printf("%d ", startVertex);

    // Traverse all the adjacent vertices
    struct Node* current = graph->adjacencyList[startVertex];
    while (current) {
        int adjacentVertex = current->data;
        if (!visited[adjacentVertex]) {
            DFS(graph, adjacentVertex, visited);
        }
        current = current->next;
    }
}

// Function to perform Breadth First Search (BFS) traversal
void BFS(struct Graph* graph, int startVertex, int visited[]) {
    // Create a queue for BFS
    struct Queue* queue = createQueue();

    // Mark the current vertex as visited and enqueue it
    visited[startVertex] = 1;
    enqueue(queue, startVertex);

    while (!isEmpty(queue)) {
        // Dequeue a vertex from the queue and print it
        int currentVertex = dequeue(queue);
        printf("%d ", currentVertex);

        // Traverse all the adjacent vertices of the dequeued vertex
        struct Node* current = graph->adjacencyList[currentVertex];
        while (current) {
            int adjacentVertex = current->data;
            if (!visited[adjacentVertex]) {
                visited[adjacentVertex] = 1;
                enqueue(queue, adjacentVertex);
            }
            current = current->next;
        }
    }
}

// Function to print the adjacency list representation of the graph
void printGraph(struct Graph* graph) {
    for (int i = 0; i < graph->vertices; ++i) {
        struct Node* current = graph->adjacencyList[i];
        printf("Adjacency list of vertex %d: ", i);
        while (current) {
            printf("%d -> ", current->data);
            current = current->next;
        }
        printf("NULL\n");
    }
}


// Function to perform topological sort using Depth First Search (DFS)
void topologicalSortDFS(struct Graph* graph, int vertex, int visited[], struct Node** stack) {
    // Mark the current vertex as visited
    visited[vertex] = 1;

    // Recur for all the adjacent vertices
    struct Node* current = graph->adjacencyList[vertex];
    while (current) {
        int adjacentVertex = current->data;
        if (!visited[adjacentVertex]) {
            topologicalSortDFS(graph, adjacentVertex, visited, stack);
        }
        current = current->next;
    }

    // Push the current vertex to the stack
    struct Node* newNode = createNode(vertex);
    newNode->next = *stack;
    *stack = newNode;
}

// Function to perform topological sort
void topologicalSort(struct Graph* graph) {
    int vertices = graph->vertices;
    int visited[vertices];
    struct Node* stack = NULL;

    // Initialize visited array
    for (int i = 0; i < vertices; ++i) {
        visited[i] = 0;
    }

    // Perform DFS for each unvisited vertex
    for (int i = 0; i < vertices; ++i) {
        if (!visited[i]) {
            topologicalSortDFS(graph, i, visited, &stack);
        }
    }

    // Print the topological order
    printf("Topological order: ");
    while (stack) {
        printf("%d -> ", stack->data);
        stack = stack->next;
    }
    printf("NULL\n");
}

// Example usage
int main() {
    int vertices = 5;
    struct Graph* graph = createGraph(vertices);

    printGraph(graph);

    addEdge(graph, 0, 1);
    addEdge(graph, 0, 4);
    addEdge(graph, 1, 2);
    addEdge(graph, 1, 3);
    addEdge(graph, 1, 4);
    addEdge(graph, 2, 3);
    addEdge(graph, 3, 4);

    printGraph(graph);

    return 0;
}
```

## Other Questions

## Jump Game(#55, M)
### **Problem Statement**
You are given an integer array `nums`. You are initially positioned at the array's first index, and each element in the array represents your maximum jump length at that position.

Return `true` if you can reach the last index, or `false` otherwise.

### **Algorithm**
1. We have the function header `bool canJump(int* nums, int numsSize)`
2. Use a integer `target` variable which is set to the last index number, `numsSize - 1`
3. Iterate through the given integer array from back. If the *sum of the current element* and its *index* is **greater than or equal** to the target, update the target to the current index.
4. Once the `target` value has reached 0, which means if it had reached the first index, then we can conclude that it is possible to jump from first element to the last element

### **Source Code**
```c
bool canJump(int* nums, int numsSize){
    int target = numsSize - 1;
    for (int iterable = numsSize - 2; iterable >= 0; iterable--){
        if (nums[iterable] + iterable >= target){
            target = iterable;
        }
    }
    return target == 0;
}
```

### **Submission Metrics**
Runtime: 48 milliseconds

Memory Usage: 8.6 MB

## Swim in Rising Water (#778,H)
### **Problem Statement**
You are given an `n x n` integer matrix `grid` where each value `grid[i][j]` represents the elevation at that point `(i, j)`.

The rain starts to fall. At time `t`, the depth of the water everywhere is `t`. You can swim from a square to another 4-directionally adjacent square if and only if the elevation of both squares individually are at most `t`. 

You can swim infinite distances in zero time. Of course, you must stay within the boundaries of the grid during your swim.

Return the least time until you can reach the bottom right square `(n - 1, n - 1)` if you start at the top left square `(0, 0)`

![](https://assets.leetcode.com/uploads/2021/06/29/swim2-grid-1.jpg)

### **Algorithm**
1. Have a `start` and `end` variable with values from `numberarray[0][0]` and `numberarray[numsize-1][numsize-1]` respectively
2. Access values of current values in all possible directions (up, down, left, right). 
3. Call the same function on the indicies of the minimumvalue of adjacent matrix
4. Maintain a array `path` containing the elements which contains all the elements already crossed
5. Have a integer variable `max`, initialized to the first element and periodically updates its value _if it crosses an element with value greater than itself_
6. After reaching bottom right element, terminate the loop / recursion and return `max`

### **Source Code**
```python
class Solution:
    def move(self, gridmatrix, xpos, ypos, pathlist):
        # find up down left and right elements and call the function on the smallest element
        up = gridmatrix[xpos-1][ypos] if xpos > 0 else 10000
        down = gridmatrix[xpos+1][ypos] if xpos < len(gridmatrix)-1 else 10000
        left = gridmatrix[xpos][ypos-1] if ypos > 0 else 10000
        right = gridmatrix[xpos][ypos+1] if ypos < len(gridmatrix[0])-1 else 10000

        # find the smallest element that hasn't been visited
        smallest = min(val for val in [up, down, left, right] if val not in pathlist)

        # find the position of the smallest element
        if smallest == up:
            xpos -= 1
        elif smallest == down:
            xpos += 1
        elif smallest == left:
            ypos -= 1
        elif smallest == right:
            ypos += 1

        # check if the smallest element is the last element
        if gridmatrix[-1][-1] in [up, down, left, right]:
            pathlist.append(gridmatrix[-1][-1])
            return pathlist
        else:
            pathlist.append(smallest)
            return self.move(gridmatrix, xpos, ypos, pathlist)

    def swimInWater(self, grid):
        path = [grid[0][0]]
        return max(self.move(grid, 0, 0, path))
```

### **Submission Metrics**
Runtime: 90 ms

Memory Usage: 16.9 MB

## Add Two Numbers (#2, M)
### **Problem Statement**
You are given two **non-empty** linked lists representing two non-negative integers. The digits are stored in **reverse order**, and each of their nodes contains a single digit. Add the two numbers and return the sum as a linked list.

You may assume the two numbers do not contain any leading zero, except the number 0 itself.

![](https://assets.leetcode.com/uploads/2020/10/02/addtwonumber1.jpg)

### **Algorithm**
1. Firstly normalize the Linked List (if two lists are of unequal size) by adding elements with `0` to the end of required list
2. Iterate through both lists simultaneously add two numbers in that element and carry forward the `carry` if necessary. 
3. Insert the sum without the carry to a new linked list
4. After iterating completely, return the third linked list containing all sum  

### **Source Code**
```c
void normalizelists(struct ListNode * listhead1, struct ListNode * listhead2){
    struct ListNode * iterableelement1 = listhead1, * iterableelement2 = listhead2;
    int lengthoflist1 = 0, lengthoflist2 = 0;

    while(iterableelement1->next != NULL || iterableelement2->next != NULL){
        if(iterableelement1->next != NULL){
            lengthoflist1++;
            iterableelement1 = iterableelement1->next;
        }
        if(iterableelement2->next != NULL){
            lengthoflist2++;
            iterableelement2 = iterableelement2->next;
        }
    }
    
    int difference = lengthoflist1 - lengthoflist2;
    struct ListNode * iterableelement = difference < 0 ? iterableelement1 : iterableelement2;

    for (int iterable = 0; iterable < abs(difference); iterable++){
        struct ListNode * newListNode = getListNode(0);
        iterableelement->next = newListNode;
        iterableelement = iterableelement->next;
    }
}

struct ListNode * addition(struct ListNode * headelement1, struct ListNode * headelement2){

    int carry = 0, arithmeticsum = 0, sum = 0;
    struct ListNode * finalAssignment  =  NULL, * assignvar = finalAssignment;
    struct ListNode * temp1 = headelement1, * temp2 = headelement2;

    while (temp1 != NULL && temp2 != NULL){
        arithmeticsum = temp1->val + temp2->val + carry;
        carry = arithmeticsum / 10;
        sum = arithmeticsum % 10;

        temp1 = temp1->next;
        temp2 = temp2->next;
        
        struct ListNode * newListNode = getListNode(sum);
        if (finalAssignment == NULL){
            finalAssignment = newListNode;
            assignvar = finalAssignment;
        } else {
            assignvar->next = newListNode;
            assignvar = assignvar->next;
        }
    }

    if(carry == 1){
        struct ListNode * newListNode = getListNode(carry);
        assignvar->next = newListNode;
        assignvar = assignvar->next;
    }

    return finalAssignment;
}

struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2){
    normalizelists(l1, l2);
    return addition(l1, l2);
}

```

### **Submission Metrics**
Runtime: 16ms

Memory Usage: 7.7 MB

## Kth Largest Element in an Array (#215, M)
### **Problem Description**
Given an integer array `nums` and an integer `k`, return the `kth` largest element in the array.

Note that it is the `kth` largest element in the sorted order, not the `kth` distinct element.

### **Algorithm**
1. Initialize an integer array `frequency` of size 20001 with all elements set to 0. This array will be used to store the frequency of each integer in the input array.

2. Iterate over the `nums` array from index 0 to `numsSize - 1`.

3. For each element in the `nums` array, calculate its index in the `frequency` array by adding 10000 to the element's value. Increment the value at that index in the `frequency` array by 1.

4. Iterate through the frequency array from back, i.e., from index 20000 to 0

5. For each element in the `frequency` array, subtract its value from `k`. If `k` is less than or equal to 0, return the integer value corresponding to the current index in the `frequency` array minus 10000.

### **Source Code**
```c
int findKthLargest(int* nums, int numsSize, int k) {
    int frequency[20001] = {0};

    for (int i = 0; i < numsSize; i++)
        frequency[nums[i] + 10000]++;

    for (int i = 20000; i >= 0; i--) {
        k -= frequency[i];
        if (k <= 0) return i - 10000;
    }

    return 0;
}
```

### **Submission Metrics**
Runtime: 69 ms

Memory Usage: 11.8 MB

## Contains Duplicate (#216, E)
### **Problem Statement**
Given an integer array `nums`, return `true` if any value appears **at least twice** in the array, and return `false` if every element is distinct.

### **Algorithm**
1. Create a Hash Map and add every element as the program encounters it
2. Record it's presence by incrementing the respective hash, i.e., its occurence
3. While checking element, if any element's respective hash value is non-zero, (was already found) then break the loop and return `True`

### **Source Code**
```java
class Solution {
    public boolean containsDuplicate(int[] nums) {
        
        if(nums==null || nums.length==0)
            return false;
        
        HashSet<Integer> hset = new HashSet<Integer>();
        
        for(int idx: nums){
            if(!hset.add(idx)){
                return true;
            }
        }
        return false;
    }
}
```

### **Submission Metrics**
Runtime: 6 ms

Memory Usage: 55.72 MB

## Maximum Depth of Binary Tree (#104, E)
### **Problem Statement**
Given the root of a binary tree, return its maximum depth.

A binary tree's maximum depth is the number of nodes along the longest path from the root node down to the farthest leaf node.


### **Source Code**
```c
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
int maxDepth(struct TreeNode* root){
    if (root == NULL){
        return 0;
    }

    int LHeight = maxDepth(root->left);
    int RHeight = maxDepth(root->right);

    if (LHeight > RHeight){
        return LHeight+1;
    } else {
        return RHeight+1;
    }
}
```
### **Submission Metrics**
Runtime: 3 ms

Memory Usage: 8.9 MB

## Invert Binary Tree (#226, E)
### **Problem Statement**
Given the root of a binary tree, invert the tree, and return its root.

### **Source Code**
```c
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
struct TreeNode* invertTree(struct TreeNode* root) {
    if (root == NULL) {
        return NULL;
    }

    struct TreeNode* temp = root->left;
    root->left = invertTree(root->right);
    root->right = invertTree(temp);

    return root;
}
```

### **Submission Metrics**
Runtime: 0 ms

Memory Usage: 6.92 MB

## Reverse Linked List (#206, E)
### **Problem Statement**
Given the `head` of a singly linked list, reverse the list, and return *the reversed list*.

### **Source Code**
```c
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode *getpointer(int data)
{
    struct ListNode *element = (struct ListNode *)malloc(sizeof(struct ListNode));
    element->val = data;
    element->next = NULL;
    return element;
}

struct ListNode *reverseList(struct ListNode *headpointer)
{
    if (headpointer == NULL){
        return NULL;
    }
    struct ListNode *reversepointer = getpointer(headpointer->val);
    while (headpointer->next != NULL)
    {
        headpointer = headpointer->next;
        struct ListNode *newelement = getpointer(headpointer->val);
        newelement->next = reversepointer;
        reversepointer = newelement;

        printf("\n\n");
    }
    return reversepointer;
}
```

### **Submission Metrics**
Runtime: 5 ms

Memory Usage: 7.5 MB

## Valid Parentheses (#20, E)
### **Problem Statement**
Given a string `s` containing just the characters `'('`, `')'`, `'{'`, `'}'`, `'['` and `']'`, determine if the input string is valid.
### **Source Code**
```python
class Solution:
    def isValid(self, s: str) -> bool:
        l = []
        for char in s:
            if char == '(' or char == '{' or char == '[':
                l.append(char)
            elif len(l) == 0:
                return False
            elif char == ')' and l[-1] == '(':
                l.pop()
            elif char == '}' and l[-1] == '{':
                l.pop()
            elif char == ']' and l[-1] == '[':
                l.pop()
            else:
                return False

        if len(l) == 0:
            return True
        else:
            return False
```
### **Submission Metrics**
Runtime: 41 ms

Memory Usage: 16.2 MB

## Best Time to Buy and Sell Stock (#121, E)
### **Problem Statement**
You are given an array `prices` where `prices[i]` is the price of a given stock on the `ith` day.

### **Source Code**
```c
int maxProfit(int* prices, int pricesSize) 
{
  int min_price = MAX_SHARE_PRICE;
  int max_profit = 0;

  for (int i = 0; i < pricesSize; i++)
  {
    /* Find new min price if applicable, otherwise calculate max profit thus far.
     * If the new max profit is greater than the previous, update the max profit.
     */
    if (prices[i] < min_price)
    {
      min_price = prices[i];
    }
    else if (prices[i] - min_price > max_profit)
    {
      max_profit = prices[i] - min_price;
    }
  }

  return max_profit;
}
```
### **Submission Metrics**
Runtime: 83 ms

Memory Usage: 1.24 MB


## Find First and Last Position of Element in Sorted Array (#34, M)
### **Problem Statement**
Given an array of integers `nums` sorted in ascending order, find the starting and ending position of a given `target` value.

### **Source Code**
```c
int *searchRange(int *nums, int numsSize, int target, int *returnSize)
{
    int lpointer = 0;
    int rpointer = numsSize - 1;

    while (lpointer <= rpointer)
    {
        int lelement = nums[lpointer];
        int relement = nums[rpointer];

        printf("lpointer: %d, rpointer: %d\n", lelement, relement);
        if (lelement == target && relement == target)
        {
            int *result = (int *)malloc(sizeof(int) * 2);
            result[0] = lpointer;
            result[1] = rpointer;
            *returnSize = 2;
            return result;
        }
        
        if (lelement != target)
        {
            lpointer++;
        }

        if (relement != target)
        {
            rpointer--;
        }

        }
int *result = (int *)malloc(sizeof(int) * 2);
    result[0] = -1;
    result[1] = -1;
    *returnSize = 2;
    return result;
}
```
### **Submission Metrics**
Runtime: 22

Memory Usage: 7.9
