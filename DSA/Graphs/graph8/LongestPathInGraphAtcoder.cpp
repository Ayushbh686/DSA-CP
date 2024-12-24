/*
https://atcoder.jp/contests/dp/tasks/dp_g
There is a directed graph G with N vertices and M edges. The vertices are numbered 1,2,…,N, and for each i (1≤i≤M), the i-th directed edge goes from Vertex x i to y i. 
G does not contain directed cycles.
Find the length of the longest directed path in 
G. Here, the length of a directed path is the number of edges in it.
*/

#include<bits/stdc++.h>
using namespace std;

int n,m;
vector<vector<int>>adj;
vector<int>dp;
int ans = 0;

int LongestPathDFS(int src){
    if(dp[src] != -1) return dp[src];
    int path = 0;
    for(auto ele : adj[src]){
        path = max(path , 1 + LongestPathDFS(ele));
    }
    return dp[src] = path;
}

int main(){
    cin>>n>>m;
    adj.resize(n+1);
    for(int i=0 ; i<m ; i++){
        int x , y ;
        cin>>x>>y;
        adj[x].push_back(y);
    }
    dp.resize(n+1 , -1);
    for(int i=1 ; i<=n ; i++){
       ans = max(ans,LongestPathDFS(i));
    }

    cout<<ans<<endl;
    return 0;
}
//directed graph without cycle is a tree