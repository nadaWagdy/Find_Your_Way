#include "Graph.h"

Graph::Graph(vector<Edge> const& edges, int n)  : nodes_number(n) ,edges_number(0)
{
    adjList.resize(n);

    for (auto& edge : edges)
    {
        int src = edge.src;
        int dest = edge.dest;
        int weight = edge.weight;


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
    else if ((src == adjList.size() && dest < adjList.size())
        ||  (dest == adjList.size() && src < adjList.size())) {
        this->addNode(1);
        adjList[src].push_back(make_pair(dest, weight));
        edges_number++;
        return true;
    }

    // case 3: src && dest don't exist
    else if ((src == adjList.size() && dest == adjList.size() + 1)
        ||    src == adjList.size() + 1 && dest == adjList.size()) {
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
        for (Pair v : adjList[i]) {
            cout << "(" << i << ", " << v.first << ", " << v.second << ") " << endl;
        }
    }
    cout << "nodes count is : " << nodes_number << " edges count is : " << edges_number;
}

bool Graph::erase(int node)
{
    if (node >= adjList.size() || node < 0)return false;
    edges_number -= adjList[node].size();
    adjList.erase(adjList.begin() + node); //remove the node from the vector
    for (auto& srcs : adjList) {
        list<Pair>::iterator edge = srcs.begin();
        while ( edge != srcs.end()) {
            if (edge->first == node) {
                auto temp = edge;
                edge++;
                srcs.erase(temp); //remove any edge that its source is the node
                edges_number--;
            }
            else if (edge->first > node) {
                edge->first--; // decrement any node value more than the node number
                edge++;
            }
            else {
                edge++;
            }
        }
    }
    nodes_number--;
    return true;
}

int Graph::BellmanFordSP(int start,int end)
{
    vector<int> dist;
    int n = adjList.size();

    for (int i = 0; i < n; i++)
    {
        dist.push_back(1000000007); 
    }

    dist[start] = 0;


    for (int i = 0; i < n - 1; i++)
    {
        for (int u = 0; u < n; u++)
        {
            for (auto j = adjList[u].begin(); j != adjList[u].end(); j++)
            {
                int v = j->first;
                int weight = j->second;

                if (dist[v] > dist[u] + weight)
                {
                    dist[v] = dist[u] + weight;
                }
            }
        }
    }

    return dist[end];

}

bool Graph::erase(int src, int dest)
{
    if (src >= adjList.size() || src < 0 || dest >= adjList.size() || dest < 0)return false;
    list<Pair>::iterator destination = adjList[src].begin();
    while (destination!=adjList[src].end())
    {
        if (destination->first == dest) {
            edges_number--;
            adjList[src].erase(destination);
            return true;
        }
        destination++;
    }
    return false;
}

void Graph::generateRandomWeights()
{
    srand(time(0));
    int offset = -10;
    int range = 40;

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
                cout << "This weight was found between node " << i << " And " << j->first << '\n';
                flag = true;
            }

        }
    }
    if (flag == false)
    {
        cout << "This weight was not found in the graph";
    }
}

bool Graph::empty()
{
    return (nodes_number==0);
}

