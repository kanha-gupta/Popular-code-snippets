#include <iostream>
#include <vector>
#include <set>
#include <limits>

using namespace std;

const int INF = numeric_limits<int>::max();

struct Edge
{
    int to, weight;
};

void dijkstra(vector<vector<Edge>> &graph, int source, vector<int> &distance)
{
    int n = graph.size();
    distance.assign(n, INF);
    distance[source] = 0;

    set<pair<int, int>> q;
    q.insert({0, source});

    while (!q.empty())
    {
        int u = q.begin()->second;
        q.erase(q.begin());

        for (const Edge &edge : graph[u])
        {
            int v = edge.to;
            int w = edge.weight;

            if (distance[u] + w < distance[v])
            {
                q.erase({distance[v], v});
                distance[v] = distance[u] + w;
                q.insert({distance[v], v});
            }
        }
    }
}

int main()
{
    int n = 6; // Number of nodes
    vector<vector<Edge>> graph(n);

    // Adding edges to the graph
    graph[0].push_back({1, 2});
    graph[0].push_back({2, 4});
    graph[1].push_back({2, 1});
    graph[1].push_back({3, 7});
    graph[2].push_back({4, 3});
    graph[3].push_back({4, 2});
    graph[3].push_back({5, 1});
    graph[4].push_back({5, 5});

    int source = 0; // Source node

    vector<int> distance;
    dijkstra(graph, source, distance);

    for (int i = 0; i < n; i++)
    {
        cout << "Shortest distance from node " << source << " to node " << i << ": " << distance[i] << endl;
    }

    return 0;
}
