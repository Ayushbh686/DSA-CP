/*
Dijkstra Algo to find shortest path form source
-> vector or mapping of dist and via for every node
-> pq of pair < dist from src , node>
-> push src node in pq with <0 , src>
-> visited set in which push node which is poped out of pq which means shortest path to it is found
-> for every node in neighbour of top node of pq :-
    ->update the mapping of every node(that is not visited yet) if dist via top node is less than previous dist 
    ->push neighbouring nodes in pq if mapping updated and not visited yet
    ->pop top node and mark visited
->we get shortest dist to every node
*/


#include <bits/stdc++.h>
using namespace std;

int n , e ;
vector<vector<pair<int,int>>> adj;
unordered_set<int> visited;
vector<int>dist; // dist from src
vector<int>via; //via which node is shortest dist.

void add_edge(int u , int v , int wt){ //as its undirected and weighted graph
    adj[u].push_back({wt,v});
    adj[v].push_back({wt,u});
}

void DijkstraAlgo(int src){  // O( vlogv + elogv)
    priority_queue<pair<int,int>, vector<pair<int,int>> , greater<pair<int,int>>> pq; //min pq with <dist , node>
    dist.resize(n , INT_MAX);
    via.resize(n , src);
    pq.push({0,src});
    dist[src] = 0;
    while(!pq.empty()){  //O((v+e)logv)
        auto top = pq.top();
        if(visited.count(top.second)){
            pq.pop();
            continue;
        }
        else{ 
            visited.insert(top.second);
            pq.pop();
            //cout<<top.first<<" "<<top.second<<endl;
            for(auto ele : adj[top.second]){ 
                if(!visited.count(ele.second) and (long long)dist[ele.second] > (long long)(ele.first + dist[top.second])){
                    dist[ele.second] = ele.first + dist[top.second];
                    via[ele.second] = top.second;
                    pq.push({ele.first + top.second , ele.second});
                }
            }
        }
    }

    cout<<"shortest dist : ";
    for(int i=0 ; i<n ; i++) cout<<dist[i]<<" ";
    cout << endl;
    cout<<"via node : ";
    for(int i=0 ; i<n ; i++) cout<<via[i]<<" ";
    cout<<endl;
}

int main(){
    cin>>n>>e;
    adj.resize(n);

    for(int i=0 ; i<e ; i++){
        int x , y , wt;
        cin>>x>>y>>wt;
        add_edge(x,y,wt);
    }

    int src ;
    cin>>src;
    DijkstraAlgo(src);

    return 0;
}
//0 based indexing
// vlog + elogv
