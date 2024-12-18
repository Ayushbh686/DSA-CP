#include<bits/stdc++.h>
using namespace std;

vector<list<int>> graph;  // Unweighted graph representation
unordered_set<int> visited;
vector<int> parent;
int v;

void add_edge(int src, int des, bool is_directed = false) {
    graph[src].push_back(des);
    if (!is_directed) {
        graph[des].push_back(src);
    }
}

void has_cycle_DFS(){
    queue<int> qu;
    qu.push(0);
    visited.insert(0);
    while(!qu.empty()){
        int top = qu.front();
        qu.pop();
        for(int ele : graph[top]){
            if(visited.count(ele) and ele != parent[top]){
                cout<<"cycle detected"<<endl;
                return;
            }
            else if(!visited.count(ele)){
                visited.insert(ele);
                qu.push(ele);
                parent[ele] = top;
            }
        }
    }
    cout<<"no cycle detected"<<endl;
    return;
}

int main(){
    cin >> v;
    graph.resize(v);
    parent.resize(v,-1);
    int e;
    cin >> e;
    while (e--) {
        int src, des;
        cin >> src >> des;
        add_edge(src, des, false); // false for undirected graph
    }

    has_cycle_DFS();
    return 0;
}
//tc = v+e
//if a node is visited and not your parent node and you hit again such node then cycle is detected 