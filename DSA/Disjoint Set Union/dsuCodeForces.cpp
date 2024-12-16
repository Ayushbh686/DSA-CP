//codeforces https://codeforces.com/edu/course/2/lesson/7/1/practice/contest/289390/problem/B
/*Implement disjoint sets union data structure. You have to perform queries of two types:

union u
 v
 — unite two sets that contain u
 and v
, respectively;
get v
 — find the set to which v
 belongs to, find the minimal and the maximal element of the set, and the total number of elements in it.

*/

#include<iostream>
#include<vector>
using namespace std;

int n , m;

int find(vector<int>& parent , int x){  //tc = log*n
    if(parent[x] == x) return x;
    return parent[x] = find(parent , parent[x])  ;
}

void Union(vector<int>& parent , vector<int>& size , vector<int>& maxm , vector<int>& minm , int a , int b){  // tc = log*n
    //cout<<"entered union function"<<endl;
    int parA = find(parent , a);
    //cout<<"fount parent of a in union command"<<endl;
    int parB = find(parent , b);
    //cout<<"fount parent of b in union command"<<endl;
    if(parA == parB) return ;

    if(size[parA] >= size[parB]){
        size[parA] += size[parB];
        minm[parA] = min(minm[parA] , minm[parB]);
        maxm[parA] = max(maxm[parA] , maxm[parB]);
        parent[parB] = parA;
    }
    else{
        size[parB] += size[parA];
        minm[parB] = min(minm[parA] , minm[parB]);
        maxm[parB] = max(maxm[parA] , maxm[parB]);
        parent[parA] = parB;
    }
}

int main(){
    //n->elements , m -> queries
    cin>>n>>m;

    vector<int> parent(n+1);
    vector<int> size(n+1 , 1);
    vector<int> maxm(n+1 , 0);
    vector<int> minm(n+1 , 0);

    for(int i=1 ; i<=n ; i++){
        parent[i] = i;
        maxm[i] = i;
        minm[i] = i;
    }

    while(m--){
        string str;
        cin>>str;
        //cout<<str<<endl;
        if(str == "union"){
            int x , y;
            cin>>x>>y;
            Union(parent , size , maxm , minm , x , y);
        }
        else if(str == "get"){
            int x;
            cin>>x;
            int par = find(parent  ,x);
            cout<<minm[par]<<" "<<maxm[par]<<" "<<size[par]<<endl;
        }
    }
}