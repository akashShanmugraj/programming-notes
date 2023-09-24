#include<stdio.h>
#include<stdlib.h>

struct node {
    struct node * previous;
    int data;
    struct node * next;
};


struct node * getnode(int data){
    struct node * element = (struct node *)malloc(sizeof(struct node));
    element->data = data;
    element->next = NULL;
    element->previous = NULL;

    return element;
}

void traverseright(struct node * HEADPOINTER){
    printf("TVRSE R\t\t");
    struct node * traversalpointer = HEADPOINTER;
    printf("%d\t", traversalpointer->data);
    while (traversalpointer->next != NULL){
        traversalpointer = traversalpointer->next;
        printf("%d\t", traversalpointer->data);
    }
    printf("\n\n");
}

void traverseleft(struct node * TAILPOINTER){
    printf("TVRSE L\t\t");
    struct node * traversalpointer = TAILPOINTER;
    printf("%d\t", traversalpointer->data);

    while (traversalpointer->previous != NULL){
        traversalpointer = traversalpointer->previous;
        printf("%d\t", traversalpointer->data);
    }
    printf("\n\n");
}

struct node * insertatstart(struct node * HEAD);


int main(){
    struct node * HEAD = getnode(10);
    struct node * E1 = getnode(20);
    struct node * E2 = getnode(30);
    struct node * E3 = getnode(40);
    struct node * E4 = getnode(50);

    HEAD->next = E1;
    E1->next = E2;
    E2->next = E3;
    E3->next = E4;

    E4->previous = E3;
    E3->previous = E2;
    E2->previous = E1;
    E1->previous = HEAD;

    traverseright(HEAD);
    traverseleft(E4);
}