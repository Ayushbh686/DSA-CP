#include <iostream>
#include <vector>
#include <list>
#include <unordered_set>
#include <queue>
#include <climits>
using namespace std;

vector<list<int>> graph;  // Unweighted graph representation
unordered_set<int> visited;
int v;

void add_edge(int src, int des, bool is_directed = false) {
    graph[src].push_back(des);
    if (!is_directed) {
        graph[des].push_back(src);
    }
}

void bfs(int src, vector<int>& dist) {
    queue<int> qu;
    visited.clear();
    dist[src] = 0;
    visited.insert(src);
    qu.push(src);

    while (!qu.empty()) {
        int curr = qu.front();
        cout << "Visiting node: " << curr << endl;
        qu.pop();

        for (auto neighbor : graph[curr]) {
            if (visited.find(neighbor) == visited.end()) {
                qu.push(neighbor);
                visited.insert(neighbor);
                dist[neighbor] = dist[curr] + 1;
            }
        }
    }
}

int main() {
    cin >> v;
    graph.resize(v);

    int e;
    cin >> e;
    while (e--) {
        int src, des;
        cin >> src >> des;
        add_edge(src, des, false); // false for undirected graph
    }

    int src;
    cin >> src;

    vector<int> dist(v, INT_MAX);
    bfs(src, dist);

    cout << "Shortest distances from source " << src << ":\n";
    for (int i = 0; i < v; i++) {
        cout << "Node " << i << " is at distance " << dist[i] << endl;
    }

    return 0;
}
