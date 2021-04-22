#include"header.h"
#include<stdio.h>

int main() 
{
    struct Network* graph = createANetwork(7);
    addEdge(graph, 0, 1, 10);
    addEdge(graph, 1, 2, 7);
    addEdge(graph, 1, 3, 5);
    addEdge(graph, 3, 2, 6);
    addEdge(graph, 5, 2, 6);
    addEdge(graph, 4, 2, 9);
    addEdge(graph, 5, 4, 2);
    addEdge(graph, 4, 6, 1);
    printNetwork(graph);
    return 0;
}
