#ifndef GRAPH_H
#define GRAPH_H


/*
  Basical adjacency list and adjacency matrix implementation

  Pros: Saves space O(|V|+|E|) . In the worst case, there can be C(V, 2) number of edges in a graph thus consuming O(V^2) space. Adding a vertex is easier.

  Cons: Queries like whether there is an edge from vertex u to vertex v are not efficient and can be done O(V).

*/

//linkedlist node
struct AdjListNode {
  int dest;
  struct AdjListNode* next;
};

// A structure to represent an adjacency liat
struct AdjList {
  struct AdjListNode* head;  // pointer to head node of list
};

// A structure to represent a graph. A graph is an array of adjacency lists.
// Size of array will be V (number of vertices in graph)
struct Graph {
  int V;
  struct AdjList* array;
};

// A utility function to create a new adjacency list node
struct AdjListNode* newAdjListNode (int dest);

// A utility function that creates a graph of V vertices
struct Graph* createGraph (int V);

// Adds an edge to an undirected graph
void addEdge (struct Graph* graph, int src, int dest);

// A utility function to print the adjacenncy list representation of graph
void printGraph (struct Graph* graph);

#endif
