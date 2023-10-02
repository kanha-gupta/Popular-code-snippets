#include <iostream>
#include <queue>
#include <unordered_set>
#include <unordered_map>
#include <vector>
using namespace std;

void bfs(const unordered_map<char, vector<char> >& graph, char start) 
{
    queue<char> q;
    unordered_set<char> visited;

    q.push(start);
    visited.insert(start);

    while (!q.empty()) {
        char node = q.front();
        q.pop();
        cout << node << ' ';

        for (char neighbor : graph.at(node)) {
            if (visited.find(neighbor) == visited.end()) {
                q.push(neighbor);
                visited.insert(neighbor);
            }
        }
    }
}

int main() {

    // Example graph represented as an adjacency list
    unordered_map<char, vector<char> > graph = {
        {'A', {'B', 'C'}},
        {'B', {'A', 'D', 'E'}},
        {'C', {'A', 'F', 'G'}},
        {'D', {'B'}},
        {'E', {'B', 'H'}},
        {'F', {'C'}},
        {'G', {'C'}},
        {'H', {'E'}}
    };

    // Starting node for BFS
    char startNode = 'A';

    cout << "BFS starting from node " << startNode << ": ";
    bfs(graph, startNode);

    return 0;
}
