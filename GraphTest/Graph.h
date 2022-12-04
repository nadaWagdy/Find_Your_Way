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
    vector<list<Pair>> adjList;
    /*--------------------------------------------------------------------
       Default constructor: Builds a Graph with the given number of edges ( n )
       Precondition:  None
       Postcondition: A Graph is created.
     --------------------------------------------------------------------*/
    Graph(vector<Edge> const& edges, int n);
    /*--------------------------------------------------------------------
      Returns the number of nodes in a graph
      Precondition:  A graph is available
      Postcondition: The number of nodes in the graph is returned.
    --------------------------------------------------------------------*/
    int nodes_count();
    /*--------------------------------------------------------------------
      Prints all the graph's source, destination and weight. Also prints the nodes and edges count.
      Precondition: None
      Postcondition: Graph's details are printed
    --------------------------------------------------------------------*/
    void printGraph();
    /*--------------------------------------------------------------------
       Connects Nodes together
       Precondition: src and dest are available
       Postcondition: 2 Nodes are connected together by a certain weight
     --------------------------------------------------------------------*/
    bool connectNode(int src, int dest, int weight);
    /*--------------------------------------------------------------------
       Adds a node to the graph
       Precondition:  None
       Postcondition: A node is created and added to the graph
     --------------------------------------------------------------------*/
    void addNode(int n);
    /*--------------------------------------------------------------------
       Erases a node
       Precondition:  None
       Postcondition: A node is deleted.
     --------------------------------------------------------------------*/
    bool erase(int node);
    /*--------------------------------------------------------------------
       Erase the connection between 2 nodes
       Precondition:  None
       Postcondition: Connection between the 2 nodes is deleted
     --------------------------------------------------------------------*/
    bool erase(int src, int dest);
    /*--------------------------------------------------------------------
       Algorithm to calculate the shortest route between 2 nodes
       Precondition:  A graph exists with nodes in it
       Postcondition: The shortest distance between the first Node and the final Node is calculated
     --------------------------------------------------------------------*/
    int BellmanFordSP(int start, int end);
    /*--------------------------------------------------------------------
       Generates random weights for each node in the graph
       Precondition:  None
       Postcondition: Random weights are generated for each node in the graph
     --------------------------------------------------------------------*/
    void generateRandomWeights();
    /*--------------------------------------------------------------------
       Searches for the given weight in the graph's nodes
       Precondition:  None
       Postcondition: If the weight is found in graph, Prints out the weight's source and destination
     --------------------------------------------------------------------*/
    void searchWeight(int n);
private:
    // a vector of vectors of Pairs to represent an adjacency list
    int nodes_number;
    int edges_number;
};
