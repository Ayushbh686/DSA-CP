#include <iostream>
#include <vector>
#include <stack>
using namespace std;

vector<vector<int>> adj, rev_adj;
vector<bool> visited;
stack<int> finished;
vector<vector<int>> components;

void dfs1(int u) {
    visited[u] = true;
    for (int v : adj[u]) {
        if (!visited[v])
            dfs1(v);
    }
    finished.push(u); // record finish time
}

void dfs2(int u, vector<int> &component) {
    visited[u] = true;
    component.push_back(u);
    for (int v : rev_adj[u]) {
        if (!visited[v])
            dfs2(v, component);
    }
}

void kosaraju(int n) {
    visited.assign(n, false);

    // Step 1: DFS on original graph
    for (int i = 0; i < n; ++i) {
        if (!visited[i])
            dfs1(i);
    }

    // Step 2: Transpose already done in rev_adj

    // Step 3: DFS on transposed graph in reverse finish order
    visited.assign(n, false);
    while (!finished.empty()) {
        int u = finished.top(); finished.pop();
        if (!visited[u]) {
            vector<int> component;
            dfs2(u, component);
            components.push_back(component);
        }
    }

    // Output the SCCs
    cout << "Strongly Connected Components:\n";
    for (auto &comp : components) {
        for (int node : comp)
            cout << node << " ";
        cout << endl;
    }
}

int main() {
    int n, e;
    cin >> n >> e;

    adj.resize(n);
    rev_adj.resize(n);

    for (int i = 0; i < e; ++i) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        rev_adj[v].push_back(u); // transpose
    }

    kosaraju(n);

    return 0;
}
