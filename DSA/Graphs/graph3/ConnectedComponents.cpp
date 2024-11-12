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

void dfs(int src){
    visited.insert(src);
    for(auto el : graph[src]){
        if(not visited.count(el)){
            dfs(el);
        }
    }
    return ;
}

int components(){
    int results = 0;
    for(int el = 0 ; el < v ; el++){
        if(not visited.count(el)){
            results++;
            dfs(el);
        }
    }
    return results;
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

    cout<<components()<<endl;

    return 0;
}
