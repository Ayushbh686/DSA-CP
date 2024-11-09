#include <iostream>
#include <vector>
#include <list>
#include <unordered_set>
using namespace std;

vector<list<pair<int, int>>> graph; 
unordered_set<int> visited; 
vector<vector<int>> result;
int v;

void add_edge(int src, int des, int wt, bool is_directed = false) {
    graph[src].push_back({des, wt});
    if (!is_directed) { // Only add the reverse edge if it's undirected
        graph[des].push_back({src, wt});
    }
}

void dfs(int src, int des , vector<int>&path) {
    if (src == des) {
        path.push_back(src);
        result.push_back(path); //creates a copy and push back to result array
        path.pop_back(); //no effect on result array
        return;
    }
    visited.insert(src);
    path.push_back(src);
    for (auto &neighbour : graph[src]) {
        if (!visited.count(neighbour.first)) {
            dfs(neighbour.first, des , path) ;
        }
    }
    path.pop_back();
    visited.erase(src);
    return ;
}

void allPath(int src, int des) {
    visited.clear();
    vector<int> temp;
    dfs(src, des , temp);
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
    allPath(src , des);
    for(auto path : result){
        for(auto el : path){
            cout<<el<<" ";
        }
        cout<<endl;
    }
    return 0;
}
