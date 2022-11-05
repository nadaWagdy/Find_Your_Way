#include "Graph.h"

Graph::Graph(vector<Edge> const& edges, int n)  : nodes_number(n) ,edges_number(0)
{
    adjList.resize(n);
    // add edges to the directed graph
    for (auto& edge : edges)
    {
        int src = edge.src;
        int dest = edge.dest;
        int weight = edge.weight;

        // insert at the end
        adjList[src].push_back(make_pair(dest, weight));
        edges_number++;
    }
}

void Graph::printGraph()
{


    for (int i = 0; i < nodes_number; i++)
    {
        // Function to print all neighboring vertices of a given vertex
        for (Pair v : adjList[i]) {
            cout << "(" << i << ", " << v.first << ", " << v.second << ") " << endl;
        }
        //cout << endl;
    }
    cout << "nodes count is : " << nodes_number << " edges count is : " << edges_number;
}

bool Graph::erase(int node)
{
    bool found = false;
    if (node >= adjList.size())return false;
    if (adjList[node].size() != 0) {
        found = true;     
        edges_number -= adjList[node].size();
        adjList[node].clear(); //alternative impl not completed yet
        //adjList.erase(adjList.begin() + node);
    }
    for (auto& srcs : adjList) {
        for (vector<Pair>::iterator edge = srcs.begin(); edge != srcs.end();edge++) {
            if (edge->first == node) {
                found = true;
                srcs.erase(edge);
                edges_number--;
                break;
            }   
        }
    }
    //if (found)nodes_number--;
    return found;
}

bool Graph::erase(int src, int dest)
{
    bool found = false;
    if (src >= adjList.size())return false;
    for (vector<Pair>::iterator edges = adjList[src].begin(); edges != adjList[src].end();edges++) {
        if (edges->first == dest) {
            found = true;
            adjList[src].erase(edges);
            edges_number--;
            break;
        }
    }
    return found;
}
