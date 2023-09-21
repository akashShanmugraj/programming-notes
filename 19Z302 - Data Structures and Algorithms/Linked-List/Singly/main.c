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