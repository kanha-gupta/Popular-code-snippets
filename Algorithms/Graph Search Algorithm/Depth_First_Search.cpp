#include <iostream>
#include <vector>
#include <stack>

using namespace std;

class Graph {
private:
    int V;
    vector<vector<int>> adjList;

public:
    Graph(int vertices) : V(vertices) {
        adjList.resize(V);
    }

    void addEdge(int u, int v) {
        adjList[u].push_back(v);
    }

    void DFS(int startVertex) {
        vector<bool> visited(V, false);
        stack<int> stack;

        stack.push(startVertex);
        visited[startVertex] = true;

        cout << "Depth-First Traversal starting from vertex " << startVertex << ":\n";

        while (!stack.empty()) {
            int currentVertex = stack.top();
            stack.pop();
            cout << currentVertex << " ";

            for (int neighbor : adjList[currentVertex]) {
                if (!visited[neighbor]) {
                    stack.push(neighbor);
                    visited[neighbor] = true;
                }
            }
        }

        cout << endl;
    }
};

int main() {
    Graph g(6); // Graph with 6 vertices

    // Adding edges to the graph
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 3);
    g.addEdge(2, 4);
    g.addEdge(2, 5);

    // Starting DFS from vertex 0
    g.DFS(0);

    return 0;
}
