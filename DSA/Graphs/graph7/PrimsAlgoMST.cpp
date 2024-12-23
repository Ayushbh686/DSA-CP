/*
prims algo in english:
-> create a pq of pairs with <wt , node>
-> push the first node with wt 0 and mark visited
-> create a set of visited set 
-> create a mapping of weight and parent of each node
-> for top node , check if its visited or not 
-> if visited:-
    -> pop and continue
-> if not visited:-
    -> mark it visited and update the mapping 
    -> for all neighbour of this node , push inly unvisited and with better mapping into the pq 
    ->pop 
*/

#include <bits/stdc++.h>
using namespace std;

int n , e , Mst = 0;
vector<vector<pair<int,int>>> adj;
unordered_set<int> visited;

void add_edge(int u , int v , int wt){ //as its undirected and weighted graph
    adj[u].push_back({wt,v});
    adj[v].push_back({wt,u});
}

void PrimsAlgoMst(int src){
    priority_queue<pair<int,int>, vector<pair<int,int>> , greater<pair<int,int>>> pq; //min pq
    vector<int> parent(n+1,-1);
    vector<int> weight(n+1,INT_MAX);
    parent[src] = -1;
    weight[src] = 0;
    pq.push({0,src});

    while(visited.size() != n){
        auto top = pq.top();
        if(visited.count(top.second)){
            pq.pop();
            continue;
        }
        else{ //edge is included in mst only in this case
            visited.insert(top.second);
            pq.pop();
            //cout<<top.first<<" "<<top.second<<endl;
            Mst += top.first;
            for(auto ele : adj[top.second]){
                if(!visited.count(ele.second) and weight[ele.second] > ele.first){
                    parent[ele.second] = top.second;
                    weight[ele.second] = ele.first;
                    pq.push({ele.first , ele.second});
                }
            }
        }
    }

    cout << "MST Weight: " << Mst << endl;
    cout << "Parent Array: ";
    for (int i = 1; i <= n; ++i) {
        cout << parent[i] << " ";
    }
    cout << endl;
}

int main(){
    cin>>n>>e;
    adj.resize(n+1);

    for(int i=0 ; i<e ; i++){
        int x , y , wt;
        cin>>x>>y>>wt;
        add_edge(x,y,wt);
    }

    int src ;
    cin>>src;
    PrimsAlgoMst(src);

    return 0;
}
// 1 based indexing
// we use priority queue to get the minimum weight edge from the pq that why we got logn for extracting minimum weight edge