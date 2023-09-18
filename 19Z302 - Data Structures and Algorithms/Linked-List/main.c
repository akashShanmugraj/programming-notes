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
    printf("%d\n", tempnode->data);
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

struct node * insertnatpos(struct node * headpointer, int data, int position){
    int counter = 0;
    struct node * tempheadpointer = headpointer;
    while (tempheadpointer != NULL && counter != position){
        counter++;
        tempheadpointer = tempheadpointer -> next;
    }

    struct node * newconstructorlist = constructor(3, 40);
    printf("NEW-CH\n");
    printlist(newconstructorlist);
    struct node * newlisttraverser = newconstructorlist;

    while (newlisttraverser->next != NULL){
        newlisttraverser = newlisttraverser -> next;
    }
    newlisttraverser->next = tempheadpointer->next;
    tempheadpointer = newconstructorlist;
    printlist(headpointer);
    return headpointer;
}


int main(){
    struct node *HEAD = constructor(10, 20);
    printf("BEF-CH\n");
    printlist(HEAD);

    // HEAD = insertatstart(HEAD, 100);
    // printf("INS-ST-100\n");
    // printlist(HEAD);

    // HEAD = insertatend(HEAD, 200);
    // printf("INS-END-100\n");
    // printlist(HEAD);

    // HEAD = insertatpos(HEAD, 50, 11);
    // printf("INS-POS-50\n");
    // printlist(HEAD);

    insertnatpos(HEAD, 20, 3);

    return 0;
}