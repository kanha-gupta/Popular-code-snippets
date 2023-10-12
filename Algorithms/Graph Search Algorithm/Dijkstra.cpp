#include <iostream>
#include <vector>
#include <queue>
#include <limits>

using namespace std;

const int INF = numeric_limits<int>::max();

class Graph {
public:
    int V;
    vector<vector<pair<int, int>>> adj;

    Graph(int vertices) {
        V = vertices;
        adj.resize(V);
    }

    void addEdge(int u, int v, int weight) {
        adj[u].push_back({v, weight});
        adj[v].push_back({u, weight}); // For undirected graphs
    }

    void dijkstra(int start) {
        vector<int> distance(V, INF);
        distance[start] = 0;

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        pq.push({0, start});

        while (!pq.empty()) {
            int u = pq.top().second;
            int dist = pq.top().first;
            pq.pop();

            if (dist > distance[u]) continue;

            for (const auto& edge : adj[u]) {
                int v = edge.first;
                int weight = edge.second;

                if (distance[u] + weight < distance[v]) {
                    distance[v] = distance[u] + weight;
                    pq.push({distance[v], v});
                }
            }
        }

        // Print the shortest distances from the start node to all other nodes
        for (int i = 0; i < V; ++i) {
            cout << "Shortest distance from node " << start << " to node " << i << " is: " << distance[i] << endl;
        }
    }
};

int main() {
    int V = 6; // Number of vertices
    Graph graph(V);

    // Add edges and their weights
    graph.addEdge(0, 1, 2);
    graph.addEdge(0, 2, 4);
    graph.addEdge(1, 2, 1);
    graph.addEdge(1, 3, 7);
    graph.addEdge(2, 4, 3);
    graph.addEdge(3, 4, 1);
    graph.addEdge(3, 5, 5);
    graph.addEdge(4, 5, 2);

    int startNode = 0; // Starting node
    graph.dijkstra(startNode);

    return 0;
}
