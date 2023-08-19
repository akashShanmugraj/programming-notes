#include<stdio.h>
#include<stdlib.h>
#include<math.h>

struct node {
    int data;
    struct node *next;
};

struct node *head = NULL;

void print(){
    struct node *temp = head;
    while(temp != NULL){
        printf("%d ", temp->data);
        temp = temp->next;
    }
}



void insert(int number, int pos){
    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data = number;
    newnode->next = NULL;
    if (pos == -1){
        if(head == NULL){
            head = newnode;
        }
        else{
            struct node *temp = head;
            while(temp->next != NULL){
                temp = temp->next;
            }
            temp->next = newnode;
        }
    } else if (pos == 0){
        newnode->next = head;
        head = newnode;
    } else {
        struct node *temp = head;
        for (int i = 0; i < pos-1; i++){
            temp = temp->next;
        }
        newnode->next = temp->next;
        temp->next = newnode;
    }
    
}
int main(){

}

void linkedlist1(){    
    struct node nodeHEAD;
    struct node nodeTAIL;
    nodeHEAD.data = 1;
    nodeTAIL.data = 2;
    struct node *nodeTAILpointer = &nodeTAIL;
    nodeHEAD.next = nodeTAILpointer;

    printf("%d\n", nodeHEAD.data);
    printf("Derefrencing nodeHEAD.next: %d\n", *(nodeHEAD.next));

}