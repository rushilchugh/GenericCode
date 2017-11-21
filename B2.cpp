//
// Created by Rushil on 11/21/2017.
//

#include <iostream>

using namespace std;

typedef struct
{
    int src, dest, weight;
} Edge;

void bellmanford(Edge edges[], int EDGES, int NODES, int src)
{
    int d[v] = {99999};
    d[0] = 0;

    for (int i = 0; i < NODES; i++)
    {
        for (int j = 0; j < EDGES; j++)
        {
            int u = edges[j].src;
            int v = edges[j].dest;
            int w = edges[j].weight;

            if (d[u] + w < d[v]) {
                d[v] = d[u] + w;
            }
        }
    }
    cout << "Shortest Distances are as Follows - ";

    for(int i = 0; i < NODES; i++)
    {
        cout << d[i] << '\t';
    }
}


int main()
{
    struct Edge edges[25];
    int NODES = 5;
    int EDGES;

    edges[0].src =
}