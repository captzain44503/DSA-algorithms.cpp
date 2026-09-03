#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Graph {
    int vertices;
    vector<vector<int>> adjList;

public:
    Graph(int v) {
        vertices = v;
        adjList.resize(v);
    }

    void addEdge(int u, int v) {
        adjList[u].push_back(v);
        adjList[v].push_back(u); // undirected graph
    }

    void bfs(int start) {
        vector<bool> visited(vertices, false);
        queue<int> q;
        visited[start] = true;
        q.push(start);

        cout << "BFS from " << start << ": ";
        while (!q.empty()) {
            int node = q.front();
            q.pop();
            cout << node << " ";

            for (int neighbor : adjList[node]) {
                if (!visited[neighbor]) {
                    visited[neighbor] = true;
                    q.push(neighbor);
                }
            }
        }
        cout << "\n";
    }

    void dfsUtil(int node, vector<bool>& visited) {
        visited[node] = true;
        cout << node << " ";
        for (int neighbor : adjList[node]) {
            if (!visited[neighbor])
                dfsUtil(neighbor, visited);
        }
    }

    void dfs(int start) {
        vector<bool> visited(vertices, false);
        cout << "DFS from " << start << ": ";
        dfsUtil(start, visited);
        cout << "\n";
    }
};

int main() {
    Graph g(6);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 3);
    g.addEdge(2, 4);
    g.addEdge(3, 5);
    g.addEdge(4, 5);

    g.bfs(0);
    g.dfs(0);

    return 0;
}
