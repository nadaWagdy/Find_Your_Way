#include "Graph.h"

Graph::Graph(vector<Edge> const& edges, int n) {

    adjList.resize(n);

    // add edges to the directed graph
    for (auto& edge : edges)
    {
        int src = edge.src;
        int dest = edge.dest;
        int weight = edge.weight;

        // insert at the end
        adjList[src].push_back(make_pair(dest, weight));
    }
}

void Graph::printGraph(int n)
{
    for (int i = 0; i < n; i++)
    {
        // Function to print all neighboring vertices of a given vertex
        for (Pair v : adjList[i]) {
            cout << "(" << i << ", " << v.first << ", " << v.second << ") " << endl;
        }
        //cout << endl;
    }
}