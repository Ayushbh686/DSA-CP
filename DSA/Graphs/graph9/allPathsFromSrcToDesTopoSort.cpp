// C++ Code to count paths from source 
// to destinattion using Topological Sort
#include <bits/stdc++.h>
using namespace std;

int countPaths(int n, vector<vector<int>> &edgeList,
               int source, int destination) {

    // Create adjacency list (1-based indexing)
    vector<vector<int>> graph(n + 1);
    vector<int> indegree(n + 1, 0);

    for (auto &edge : edgeList) {
        int u = edge[0];
        int v = edge[1];
        graph[u].push_back(v);
        indegree[v]++;
    }

    // Perform topological sort using Kahn's algorithm
    queue<int> q;
    for (int i = 1; i <= n; i++) {
        if (indegree[i] == 0) {
            q.push(i);
        }
    }

    vector<int> topoOrder;
    while (!q.empty()) {
        int node = q.front();
        q.pop();
        topoOrder.push_back(node);

        for (int neighbor : graph[node]) {
            indegree[neighbor]--;
            if (indegree[neighbor] == 0) {
                q.push(neighbor);
            }
        }
    }

    // Array to store number of ways to reach each node
    vector<int> ways(n + 1, 0);
    ways[source] = 1;

    // Traverse in topological order
    for (int node : topoOrder) {
        for (int neighbor : graph[node]) {
            ways[neighbor] += ways[node];
        }
    }

    return ways[destination];
}

int main() {

    int n = 5;

    // Edge list: [u, v] represents u -> v
    vector<vector<int>> edgeList = {
        {1, 2}, {1, 3}, {1, 5},
        {2, 5}, {2, 4}, {3, 5}, {4, 3}
    };

    int source = 1;
    int destination = 5;

    cout << countPaths(n, edgeList, source, destination);

    return 0;
}