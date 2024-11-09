#include <iostream>
#include <vector>
#include <list>
#include <unordered_set>
using namespace std;

vector<list<pair<int, int>>> graph; 
unordered_set<int> visited; 
int v;

void add_edge(int src, int des, int wt, bool is_directed = false) {
    graph[src].push_back({des, wt});
    if (!is_directed) { // Only add the reverse edge if it's undirected
        graph[des].push_back({src, wt});
    }
}

bool dfs(int src, int des) {
    if (src == des) return true;
    visited.insert(src);
    for (auto &neighbour : graph[src]) {
        if (!visited.count(neighbour.first)) {
            if (dfs(neighbour.first, des)) return true;
        }
    }
    return false;
}

bool anyPath(int src, int des) {
    visited.clear();
    return dfs(src, des); 
}

int main() {
    cin >> v;
    graph.resize(v);
    int e;
    cin >> e;
    while (e--) {
        int src, des, wt;
        cin >> src >> des >> wt;
        add_edge(src, des, wt); // Default is undirected graph
    }
    int src, des;
    cin >> src >> des;
    cout << (anyPath(src, des) ? "Path exists" : "No path") << endl;

    // for dfs of whole graph
    //for(int i=0 ; i<v ; i++) if(not visited.count(i) ) dfs(i);  and here dfs function will be different in which it will go on till there is no unvisited neighbour left for i 
    return 0;
}
//TC = O(V + E)