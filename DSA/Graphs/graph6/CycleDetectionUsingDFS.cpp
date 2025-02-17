#include<bits/stdc++.h>
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

bool has_cycle(int src , int par){
    visited.insert(src);
    for(int ele : graph[src]){
        if( visited.count(ele) and ele != par ){
            return true;
        }
        else if( !visited.count(ele)) {
            bool b = has_cycle(ele , src);
            if(b) return true;
        }
    }
    return false;
}

int main(){
    cin >> v;
    graph.resize(v);

    int e;
    cin >> e;
    while (e--) {
        int src, des;
        cin >> src >> des;
        add_edge(src, des, false); // false for undirected graph
    }

    for(int i=0 ; i<v ; i++){
        if(!visited.count(i)){
            bool b = has_cycle(i , -1 );
            if(b) cout<<"cycle detected"<<endl;
        }
    }
    return 0;
}
//tc = v+e
//if a node is visited and not your parent node and you hit again such node then cycle is detected 