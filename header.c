#include "header.h"
#include <stdlib.h>

struct __station* create_station(int v) 
{
    struct __station* newNode = malloc(sizeof(struct __station));
    newNode->station_id = v;
    newNode->next = NULL;
    return newNode;
}


struct Network* createANetwork(int N) 
{
    struct Network* graph = malloc(sizeof(struct Network));
    graph->total_stations = N;
    graph->adjLists = malloc(N * sizeof(struct __station*)); 
    int i;
    for (i = 0; i < N; i++)
        graph->adjLists[i] = NULL;
    return graph;
}

void addEdge(struct Network* graph, int s, int d, int w) 
{
    struct __station* newNode = create_station(d);
    newNode->next = graph->adjLists[s];
    graph->adjLists[s] = newNode;
    graph->adjLists[s]->weight=w;
  
    newNode = create_station(s);
    newNode->next = graph->adjLists[d];
    graph->adjLists[d] = newNode;
    graph->adjLists[d]->weight=w;
}

void printNetwork(struct Network* graph) 
{
    int v;
    for (v = 0; v < graph->total_stations; v++) 
    {
        struct __station* temp = graph->adjLists[v];
        printf("\n Station %d: ", v);
        while (temp) 
        {
            printf("%d -> %d(%d)   ", v,temp->station_id,temp->weight);
            temp = temp->next;
        }
    printf("\n");
    }
}
