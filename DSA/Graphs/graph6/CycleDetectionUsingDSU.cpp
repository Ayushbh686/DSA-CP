#include<bits/stdc++.h>
using namespace std;

int find(vector<int>& parent , int x){  //tc = log*n
    if(parent[x] == x) return x;
    return parent[x] = find(parent , parent[x])  ;
}

bool Union(vector<int>& parent , vector<int>& rank , int a , int b){  // tc = log*n
    //cout<<"entered union function"<<endl;
    int parA = find(parent , a);
    //cout<<"fount parent of a in union command"<<endl;
    int parB = find(parent , b);

    if(parA == parB) return true;
    //cout<<"fount parent of b in union command"<<endl;
    if(rank[parA] > rank[parB]){
        parent[parB] = parA;
        //cout<<"updated rank and parent in Union"<<endl;
    }
    else if(rank[parA] < rank[parB]){
        parent[parA] = parB;
        //cout<<"updated rank and parent in Union"<<endl;
    }
    else{
        parent[parB] = parA;
        rank[parA]++;
    }
    return false;
}


int main(){
    int n , m;
    //n->elements , m -> edges
    cin>>n>>m;

    vector<int> parent(n+1);
    vector<int> rank(n+1 , 0);

    for(int i=0 ; i<=n ; i++){
        parent[i] = i;
    }

    while(m--){
        int x , y;
        cin>>x>>y;
        bool b = Union(parent , rank , x , y);
        if(b) cout<<"cycle detected"<<endl;
    }
} //tc = O(e*log*v) == O(e) as log*v is constant almost