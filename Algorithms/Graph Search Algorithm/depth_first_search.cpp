#include <iostream>
#include <vector>
#include <stack>

using namespace std;

class Graph {
    int V; // Number of vertices
    vector<vector<int>> adj; // Adjacency list

public:
    Graph(int v) : V(v), adj(v) {}

    // Function to add an edge to the graph
    void addEdge(int v, int w) {
        adj[v].push_back(w);
    }

    // Depth-First Search
    void DFS(int startVertex) {
        vector<bool> visited(V, false); // Mark all vertices as not visited
        stack<int> stack;

        // Push the start vertex onto the stack
        stack.push(startVertex);

        while (!stack.empty()) {
            // Pop a vertex from the stack and print it
            int currentVertex = stack.top();
            stack.pop();

            if (!visited[currentVertex]) {
                cout << currentVertex << " ";
                visited[currentVertex] = true;
            }

            // Push all adjacent vertices that have not been visited onto the stack
            for (int neighbor : adj[currentVertex]) {
                if (!visited[neighbor]) {
                    stack.push(neighbor);
                }
            }
        }
    }
};

int main() {
    Graph g(7); // Create a graph with 7 vertices

    // Add edges to the graph
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 3);
    g.addEdge(1, 4);
    g.addEdge(2, 5);
    g.addEdge(2, 6);

    cout << "Depth-First Traversal (starting from vertex 0): ";
    g.DFS(0);

    return 0;
}
