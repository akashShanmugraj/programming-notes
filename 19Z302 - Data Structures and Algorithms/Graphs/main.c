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
