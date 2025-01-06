/*
can find shortest path in negative weight which dijkstra cant and can detect negative cycle as there is no shortest path in graph with negative cycle
proof of bellman ford in image.png
*/


//belman works in directed graph but can be implemented in undirected by making edges two sided
#include<bits/stdc++.h>
using namespace std;

int n , m;
vector<vector<int>>edges;
vector<int>dist;

int main(){
    cin>>n>>m;
    dist.resize(n , INT_MAX);

    for(int i=0 ; i<m ; i++){
        int x , y , wt;
        cin>>x>>y>>wt;
        edges.push_back({x,y,wt});
    }

    // cout<<"started"<<endl;
    int src ;
    cin>>src;
    dist[src] = 0;
    for(int i=1 ; i<n ; i++){  //n-1 do relaxation of all edges
    // cout<<i<<endl;
        for(auto edge : edges){
            int u = edge[0];
            int v = edge[1];
            int wt = edge[2];
            if(dist[u] != INT_MAX and dist[u] + wt < dist[v]){
                dist[v] = dist[u] + wt;
            }
        }
    }


    //nth relaxation to check if contains negative cycle
    for(auto edge : edges){
            int u = edge[0];
            int v = edge[1];
            int wt = edge[2];
            if(dist[u] != INT_MAX and dist[u] + wt < dist[v]){
                cout<<"negative cycle is contained so no shortest path";
                return 0;
            }
    }

    cout<<"distance :"<<endl;
    for(int i=0 ; i<n ; i++){
        cout<<i<<" : "<<dist[i]<<endl;
    }
    return 0;
}

//O(V*E) Time and O(V) Space