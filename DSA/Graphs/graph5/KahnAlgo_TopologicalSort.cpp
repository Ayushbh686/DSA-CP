#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> adj;
vector<int> inDeg;
int n , e;

void KahnAlgoBFS(){
    queue<int>qu;
    unordered_set<int> visited;
    for(int i=0 ; i<n ; i++){
        //cout<<inDeg[i]<<" ";
        if(inDeg[i] == 0) {
            qu.push(i);
            visited.insert(i);
        }
    }
    cout<<endl;
    while(!qu.empty()){
        int top = qu.front();
        for(int ele : adj[top]){
            if(!visited.count(ele)){
                inDeg[ele]--;
                if(inDeg[ele] == 0){
                    qu.push(ele);
                    visited.insert(ele);
                } 
            }
        }
        qu.pop();
        cout<<top<<" ";
    }
    return;
}

int main(){
    cin>>n; //number of vertices;
    adj.resize(n);
    inDeg.resize(n,0);
    cin>>e; //number of edges; (directed)
    for(int i=0 ; i<e ; i++){
        int x , y; //edge x->y
        cin>>x>>y;
        adj[x].push_back(y);
        inDeg[y]++;
    }

    KahnAlgoBFS();
    //if less than n nodes printed that means there is an Directed cyclic graph in it
    return 0;
}
//not required to count visited nodes but its just additional 