#include<bits/stdc++.h>
using namespace std;

int n , e;
int src , des;
vector<vector<int>> adj;
vector<int>visited;

void AllNodesInShortestPath(){
    unordered_set<int>visited;
    unordered_set<int>Nodes;
    queue<int>qu;
    qu.push(src);
    while(!qu.empty()){
        int top = qu.front();
        visited.insert(top);
        for(auto ele : adj[top]){
            if(!visited.count(ele)){
                qu.push()
            }
        }
    }
}

int main(){
    cin>>n>>e;
    adj.resize(n);
    for(int i=0 ; i<e ; i++){
        int x , y;
        cin>>x>>y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    cin>>src>>des;
    AllNodesInShortestPath();
    return 0;
}
/*
alternative -> TWO TIMES BFS .
first find shotest distance via bfs from src to des and then calculate shortest distance from src and des to every node seprately and the nodes with sum equal to the shortest distance will be the required nodes
*/
