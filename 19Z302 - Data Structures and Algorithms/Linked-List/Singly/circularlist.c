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
}

