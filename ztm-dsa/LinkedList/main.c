#include<stdio.h>
#include<stdlib.h>

// defining structure for induvidual elements
struct Node {
    int data;
    struct Node* next;
};

// defining the preliminary node, the HEAD
struct Node* HEAD = NULL;

// defining the ENDINSERT function
void ENDINSERT(int data, int pos) {
    printf("ENDINSERTing %d at %d\n", data, pos);
    struct Node* tempNode = (struct Node*) malloc(sizeof(struct Node));
    tempNode->data = data;
    tempNode->next = NULL;
    if (pos == -1) {
        if (HEAD -> next == NULL) {
            HEAD -> next = tempNode;
        } else {
            struct Node* iterable = HEAD;
            while (iterable->next != NULL) {
                iterable = iterable->next;
            }
            iterable->next = tempNode;
        }
    }
}
void PRINT(){
    struct Node* iterationNode = HEAD;
    printf("Inside PRINT()");
    while (iterationNode != NULL) {
        printf("%d ", iterationNode->data);
        iterationNode = iterationNode->next;
    }
}

int main(){    
    printf("Inside main()");
    ENDINSERT(2, -1);
    ENDINSERT(4, -1);
    ENDINSERT(3, -1);
    PRINT();
}