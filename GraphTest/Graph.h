#include <iostream>
#include <vector>

using namespace std;

struct Edge {
    // structure of edge with source node, destination node and weight between them
    int src, dest, weight;
};

typedef pair<int, int> Pair;

class Graph
{
public:
    // a vector of vectors of Pairs to represent an adjacency list
    vector<vector<Pair> > adjList;

    // Constructor
    Graph(vector<Edge> const& edges, int n);

    void printGraph(int n);
};
