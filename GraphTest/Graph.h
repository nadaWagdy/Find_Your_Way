#pragma once
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

    void printGraph();


    bool erase(int node);


    //precondition: no more than 1 path from the same source to the same dest
    bool erase(int src, int dest);

private:
    int nodes_number;
    int edges_number;
};
