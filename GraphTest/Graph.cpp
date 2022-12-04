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

void Graph::addNode(int n) {
    adjList.resize(adjList.size() + n);
    nodes_number++;
}

bool Graph::connectNode(int src, int dest, int weight) {
    // case 1: src && dest exist
    if (src < adjList.size() && dest < adjList.size() && src != dest) {
        adjList[src].push_back(make_pair(dest, weight));
        edges_number++;
        return true;
    }

    // case 2: src || dest exists
    else if (src == adjList.size() || dest == adjList.size()) {
        this->addNode(1);
        adjList[src].push_back(make_pair(dest, weight));
        edges_number++;
        return true;
    }

    // case 3: src && dest don't exist
    else if ((src == adjList.size() && dest == adjList.size() + 1) ||
        src == adjList.size() + 1 && dest == adjList.size()) {
        this->addNode(2);
        adjList[src].push_back(make_pair(dest, weight));
        edges_number++;
        return true;
    }

    // case 4: else return false
    else return false;
}

int Graph::nodes_count()
{
    return nodes_number;
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
        //adjList[node].clear(); //alternative impl not completed yet
        adjList.erase(adjList.begin() + node);
    }
    for (auto& srcs : adjList) {
      //  srcs.remove_if([](Pair x) {return x.first == 1; });
        list<Pair>::iterator edge = srcs.begin();
        while ( edge != srcs.end()) {
            if (edge->first == node) {
                found = true;
                auto temp = edge;
                edge++;
                srcs.erase(temp);
                edges_number--;
            }
            else if (edge->first > node) {
                edge->first--;
                edge++;
            }
        }
    }
    if (found)nodes_number--;
    return found;
}
int Graph::BellmanFordSP(int start,int end)
{
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
            for (auto j = adjList[u].begin(); j != adjList[u].end(); j++)
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

    return dist[end];

}
/*
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
*/

void Graph::generateRandomWeights()
{
    srand(time(0));
    int offset = -10;
    int range = 40;
    /*for (int i = 0; i < edges.size(); i++)
    {
        edges[i].weight = offset + (rand() % range);
    }*/
    for (int i = 0; i < adjList.size(); i++) 
    {
        for (auto j = adjList[i].begin(); j != adjList[i].end(); j++)
        {
            j->second = offset + (rand() % range);
        }
    }
}

void Graph::searchWeight(int n)
{
    bool flag = false;
    for (int i = 0; i < adjList.size(); i++)
    {
        for (auto j = adjList[i].begin(); j != adjList[i].end(); j++)
        {
            if (j->second == n)
            {
                cout << "This weight was found between node " << i << " And " << j->first;
                flag = true;
            }

        }
    }
    if (flag == false)
    {
        cout << "This weight was not found in the graph";
    }
}
