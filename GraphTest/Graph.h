#pragma once
#include <iostream>
#include <vector>
#include<list>
using namespace std;

struct Edge {
    // structure of edge with source node, destination node and weight between them
    int src, dest, weight;
};

typedef pair<int, int> Pair;

class Graph
{
public:
    vector<list<Pair> > adjList;

    // Constructor
    Graph(vector<Edge> const& edges, int n);
    int nodes_count();
    void printGraph();

    bool connectNode(int src, int dest, int weight);
    void addNode(int n);

    bool erase(int node);


    //precondition: no more than 1 path from the same source to the same dest
    bool erase(int src, int dest);

    int BellmanFordSP(int start, int end);

    void generateRandomWeights();
private:
    // a vector of vectors of Pairs to represent an adjacency list
    int nodes_number;
    int edges_number;
};
