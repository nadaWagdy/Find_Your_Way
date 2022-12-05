#include <iostream>
#include <vector>
#include "Graph.h"
#include <queue>
#include <list>

using namespace std;
int main()
{
    vector<Edge> edges;
    // total number of nodes in the graph (labelled from 0 to 5)
    cout << "enter the number of nodes\n";
    int n; cin >> n;
    edges.push_back({ 0, 1, 5 });
    edges.push_back({ 0, 2, 7});
    edges.push_back({ 0, 3, 2});
    edges.push_back({ 1, 3, -2});
    edges.push_back({ 2, 3, -1});
    edges.push_back({ 3, 4, 3});
    edges.push_back({ 3, 5, 8});
    edges.push_back({ 4, 5, 1});
    edges.push_back({ 5, 4, -1});


    // construct graph
    Graph graph(edges, n);
    graph.generateRandomWeights();
    // print adjacency list representation of a graph
    graph.printGraph();

    cout << "\nshortest path form node 0 to node " << graph.nodes_count() - 1 << " is:  "
        << graph.BellmanFordSP(0, graph.nodes_count() - 1) << '\n';

   
    // testing the erase and connect node methods
    int x = 15;
    graph.connectNode(1, 4);
    graph.connectNode(1, 3);
    graph.searchWeight(0);
    while (x--) {
        cout << "\nwhich src dest you want to delete if you are done enter -1 -1" << '\n';
        
        int src, dest; cin >> src >> dest;
        if (src == -1 && dest == -1)break;
        cout << graph.erase(src, dest) << '\n';
        graph.printGraph();
    }
    x = 15;
    graph.connectNode(0, 1);
    graph.connectNode(1, 5);
    graph.connectNode(3, 2);
    graph.connectNode(4, 2);
    graph.connectNode(2, 3);
    graph.connectNode(4, 5);
    graph.printGraph();
    cout << "\ngraph after being filled with random numbers\n";
    graph.generateRandomWeights();
    graph.printGraph();
    
        cout << "\nwhich node you want to delete\n";
        int node; cin >> node;
        cout << graph.erase(node) << '\n';
      
        graph.printGraph();
    



}