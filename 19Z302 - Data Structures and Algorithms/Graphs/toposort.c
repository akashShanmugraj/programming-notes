#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct node{
    int data;
    struct node* prev;
    struct node* next;
};

typedef struct node node;

void printNode(node* obj){
    printf("%d <-- %d --> %d\n",(obj->prev)->data,obj->data,(obj->next)->data);
}

node* getEnd(node* start){
    node* iter = start;
    while(1){
        if(iter->next == NULL){
            break;
        }
        iter = iter->next;
    }
    
    return iter;
}

node* insertAtEnd(node* start,int val){
    node* end = getEnd(start);
    node* new = (node*)malloc(sizeof(node));
    end->next = new;
    new->prev = end;
    new->data = val;
    new->next = NULL;
    
    return new;
}

void displayList(node* start){
    node* iter = start;
    while(1){
        printf(" %d",iter->data);
        if(iter->next == NULL){
            printf("\n");
            break;
        }
        printf(" -->");
        iter = iter->next;
    }
}

void deleteNode(node* start,node* toDelete){
    node* previous = toDelete->prev;
    node* nextobj = toDelete->next;
    printNode(previous);
    printNode(nextobj);
    free(toDelete);
}

node* searchNode(node* start,int val){
    if(start == NULL) return NULL;
    if(start->data == val) return start;
    searchNode(start->next,val);
}

node* createPath(int val){
    node* new = (node*)malloc(sizeof(node));
    new->prev = new->next = NULL;
    new->data = val;
    return new;
}

node** createAdjacencyList(int numNodes){
    node** new = (node**)malloc(sizeof(node*)*numNodes);
    for(int i = 0;i<numNodes;i++){
        new[i] = createPath(i);
    }
    return new;
}

void addDirEdge(node** adjList,int source, int destination){
    insertAtEnd(adjList[source],destination);
}

void addUndirEdge(node** adjList,int source, int destination){
    insertAtEnd(adjList[source],destination);
    insertAtEnd(adjList[destination],source);
}

void displayAdjlist(node** adjList,int numNodes){
    for(int i = 0;i<numNodes;i++){
        displayList(adjList[i]);
    }
}



void bfs(node **adjList,int start,int numNodes){
    int *visited = (int *)calloc(start, sizeof(int));
    int *queue = (int *)malloc(start * sizeof(int));
    int front = -1, rear = -1;
    queue[++rear] = start;
    visited[start] = 1;
    while (front != rear)
    {
        int u = queue[++front];
        printf("%d ", u);
        struct node *temp = adjList[u];
        while (temp)
        {
            if (!visited[temp->data])
            {
                queue[++rear] = temp->data;
                visited[temp->data] = 1;
            }
            temp = temp->next;
        }
    }
}


void dfs(node **adjList,int start,int numNodes){
    int *visited = (int *)calloc(numNodes, sizeof(int));
    int *stack = (int *)malloc(numNodes * sizeof(int));
    int top = -1;
    stack[++top] = start;
    visited[start] = 1;
    while (top != -1)
    {
        int u = stack[top--];
        printf("%d ", u);
        struct node *temp = adjList[u];
        while (temp)
        {
            if (!visited[temp->data])
            {
                stack[++top] = temp->data;
                visited[temp->data] = 1;
            }
            temp = temp->next;
        }
    }
}




void topoSort(node** adjList,int numNodes){
    int *visited = (int *)calloc(numNodes, sizeof(int));
    int *stack = (int *)malloc(numNodes * sizeof(int));
    int top = -1;
    
    int* inDegrees = (int*)calloc(numNodes,sizeof(int)); 
    for(int i = 0;i<numNodes;i++){
        node* iter = adjList[i];
        while(iter){
            inDegrees[iter->data]++;
            iter = iter->next;
        }
    }
    
    for(int i = 0;i< numNodes;i++){
        if(inDegrees[i] == 1){
            stack[++top] = i;
            visited[i] = 1;
        }
    }

    printf("top is %d\n",top);
    
    while (top != -1){
        int u = stack[top--];
        printf("%d ", u);
        struct node *temp = adjList[u];
        printf("Here\n");
        while(temp){
            inDegrees[temp->data]--;
            temp = temp->next;
        }

        for(int i = 0;i< numNodes;i++){
            if(inDegrees[i] == 0 && !visited[i]){
                stack[++top] = i;
                visited[i] = 1;
            }
        }
    }
}

int inDegree(node** adjList, int numNodes, int node) {
    int count = 0;

    for (int i = 0; i < numNodes; i++) {
        struct node* iter = adjList[i]; // Remove the redeclaration of iter here
        while (iter) {
            if (iter->data == node) {
                count++;
            }
            iter = iter->next;
        }
    }
    return count;
}


int main() {
    int numNodes = 6;

    node** adjList = createAdjacencyList(numNodes);

    addDirEdge(adjList,0,1);
    addDirEdge(adjList,0,3);
    addDirEdge(adjList,1,2);
    addDirEdge(adjList,1,5);    
    addDirEdge(adjList,1,4);
    addDirEdge(adjList,3,2);
    addDirEdge(adjList,4,5);

    displayAdjlist(adjList, numNodes);
    dfs(adjList,0,5);
    topoSort(adjList,6);
    return 0;
}
