
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Structure to represent a node in the adjacency list
struct Node {
    int vertex;
    struct Node* next;
};

// Structure to represent the graph
struct Graph {
    int numVertices;
    struct Node** adjList;
};

// Function to create a new node
struct Node* createNode(int v) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->vertex = v;
    newNode->next = NULL;
    return newNode;
}

// Function to create a graph with a given number of vertices
struct Graph* createGraph(int Vertices) {
    struct Graph* graph = (struct Graph*)malloc(sizeof(struct Graph));
    graph->numVertices = Vertices;

    // Create an array of adjacency lists
    graph->adjList = (struct Node**)malloc(Vertices * sizeof(struct Node*));

    // Initialize each adjacency list as empty
    int i = 0;
    for (i = 0; i < Vertices; i++)
        graph->adjList[i] = NULL;

    return graph;
}

// Function to add an edge to the graph
void addEdge(struct Graph* graph, int src, int dest) {
    // Add an edge from src to dest
    struct Node* newNode = createNode(dest);
    newNode->next = graph->adjList[src];
    graph->adjList[src] = newNode;

    // Add an edge from dest to src (assuming an undirected graph)
    newNode = createNode(src);
    newNode->next = graph->adjList[dest];
    graph->adjList[dest] = newNode;
}

// Print 
void printGraph(struct Graph* graph){
    int v;
    for(v=0;v<graph->numVertices;v++){
        struct Node *temp = graph->adjList[v];
        printf("\n Vertex %d \n:",v);
        while(temp){
            printf("%d->",temp->vertex);
            temp = temp->next;
        }
        printf("\n");
    }
}

int main()
{
    struct Graph* graph = createGraph(4);
    addEdge(graph,0,1);
    addEdge(graph,0,2);
    addEdge(graph,0,3);
    addEdge(graph,1,2);

    printGraph(graph);
    
    return 0;
}
