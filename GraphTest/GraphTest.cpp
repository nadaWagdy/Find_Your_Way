#include <iostream>
#include <vector>
#include "Graph.h"
#include <queue>
#include <list>

using namespace std;


vector<int> BellmanFordSP(vector< list<pair<int, int> > >& adjList, int& start)
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
            for (auto j = adjList[u].begin() ; j != adjList[u].end(); j++)
            {
                int v = j->first;
                int weight = j->second;

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
    //=
     //{
         // (x, y, w) —> edge from `x` to `y` having weight `w`
         //{0, 1, 6}, {1, 2, 7}, {2, 0, 5}, {2, 1, 4}, {3, 2, 10}, {5, 4, 1}, {4, 5, 3}
     //};


    // total number of nodes in the graph (labelled from 0 to 5)
    int n; cin >> n;
    int numOfEdges; cin >> numOfEdges;

    edges.push_back({ 0, 1, });
    edges.push_back({ 0, 2, });
    edges.push_back({ 0, 3, });
    edges.push_back({ 1, 3, });
    edges.push_back({ 2, 3, });
    edges.push_back({ 3, 4, });
    edges.push_back({ 3, 5, });
    edges.push_back({ 4, 5, });
    edges.push_back({ 5, 4, });


    // construct graph
    Graph graph(edges, n);

    graph.generateRandomWeights();


    // print adjacency list representation of a graph
    graph.printGraph();
    
    cout << "\nshortest path form node 0 to node " << graph.nodes_count()-1 << " is:  "
        << graph.BellmanFordSP(0, graph.nodes_count()-1) << '\n';
    graph.erase(1);
    cout << "\nerase node 1\n";
    graph.printGraph();
    cout << "\nshortest path form node 0 to node " << graph.nodes_count()-1 << " is:  "
        << graph.BellmanFordSP(0, graph.nodes_count()-1) << '\n';

    //vector<int> dist = BellmanFordSP(graph.adjList, node);

    //PrintShortestPath(dist, node);
}