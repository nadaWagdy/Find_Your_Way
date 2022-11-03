#include <iostream>
#include <vector>
#include "Graph.h"
#include <queue>
#include <list>

using namespace std;


vector<int> BellmanFordSP(vector< vector<pair<int, int> > >& adjList, int& start)
{
    cout << "\nGetting the shortest path from " << start << " to all other nodes.\n";
    vector<int> dist;

    // Initialize all source->vertex as infinite.
    int n = adjList.size();
    for (int i = 0; i < n; i++)
    {
        dist.push_back(1000000007); // Define "infinity" as necessary by constraints.
    }

    dist[start] = 0;

    // Then calculate the shortest distance using...
    // For numNodes-1...
    for (int i = 0; i < n - 1; i++)
    {
        // For each node (u)...
        for (int u = 0; u < n; u++)
        {
            // For each of it's neighbors (v)...
            for (int j = 0; j < adjList[u].size(); j++)
            {
                int v = adjList[u][j].first;
                int weight = adjList[u][j].second;

                // If the distance from source to v is bigger than dist[u] + weight of (u,v)...
                if (dist[v] > dist[u] + weight)
                {
                    // Update dist[v] to dist[u] + weight(u,V)
                    dist[v] = dist[u] + weight;
                }
            }
        }
    }
    // If there's a negative weight cycle in the graph, then report it, by...
    // For each node (u)...
        // For each of u's neighbors (v)...
            // Check if it's possible to get even better (now, that we should be at shortest)
            // If the distance from source to v is bigger than dist[u] + weight of (u,v)...
                // Report problem.

    return dist;
}

void PrintShortestPath(vector<int>& dist, int& start)
{
    cout << "\nPrinting the shortest paths for node " << start << ".\n";
    for (int i = 0; i < dist.size(); i++)
    {
        cout << "The distance from node " << start << " to node " << i << " is: " << dist[i] << endl;
    }
}


int main()
{
    vector<Edge> edges;
    // =
    // {
    //     // (x, y, w) —> edge from `x` to `y` having weight `w`
    //     {0, 1, 6}, {1, 2, 7}, {2, 0, 5}, {2, 1, 4}, {3, 2, 10}, {5, 4, 1}, {4, 5, 3}
    // };


    // total number of nodes in the graph (labelled from 0 to 5)
    int n = 6;
    int numOfEdges = 9;

    for (int i = 0; i < numOfEdges; i++)
    {
        int x, y, w;
        cin >> x >> y >> w;
        Edge temp;
        temp.src = x;
        temp.dest = y;
        temp.weight = w;
        edges.push_back(temp);
    }

    // construct graph
    Graph graph(edges, n);

    // print adjacency list representation of a graph
    graph.printGraph(n);
    int node = 0;

    vector<int> dist = BellmanFordSP(graph.adjList, node);

    PrintShortestPath(dist, node);
}