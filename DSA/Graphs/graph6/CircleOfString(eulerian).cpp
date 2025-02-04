/*
Given an array of strings, find if the given strings can be chained to form a circle. A string X can be put before another string Y in circle if the last character of X is same as first character of Y.
*/

#include<bits/stdc++.h>
using namespace std;
#define M 26

void dfs(vector<vector<int>>graph , vector<int>mark , int s , vector<bool>&visited){
    if(visited[s]) return;
    visited[s] = true;
    // cout<<"visited "<<s<<endl;
    for(int i=0 ; i<graph[s].size() ; i++){
        if(!visited[graph[s][i]]) {
            dfs(graph , mark , graph[s][i] , visited);
        }
    }
    return;
}

bool isConnected(vector<vector<int>>graph , vector<int>mark , int s){
    vector<bool>visited(M , false);
    dfs(graph , mark , s , visited);

    for(int i=0 ; i<M ; i++){
        if(mark[i] and !visited[i]){
            return false;
        }
    }

    return true;
}

int isCircle(vector<string>arr){
    //we have to check if we can arrange strings to form circle
    //first check if graph has equal in and out degree and that graph is strongly connected (we can reach any vertex from any other vertex)
    //for checking strongly connected component we can check that graph is connected as we already checked that each vertex has equal in and out deg
    int n = arr.size();
    vector<int>mark(M , false);
    vector<int>in(M , 0);
    vector<int>out(M , 0);
    vector<vector<int>>graph(M , vector<int>());

    for(int i=0 ; i<n ; i++){
        int l = arr[i].front() - 'a';
        int r = arr[i].back() - 'a';

        mark[l] = true;
        mark[r] = true;

        graph[l].push_back(r);

        in[r]++;
        out[l]++;
    }

    //in and out deg check
    for(int i=0 ; i<M ; i++){
        if(mark[i] and in[i] != out[i]) return 0;
    }
    // cout<<"got passed in and out"<<endl;
    //is graph connected 
    return isConnected(graph , mark , arr[0].front() - 'a');
}

int main(){
    vector<string>arr = {"for", "geek", "rig", "kaf"};
    cout<<isCircle(arr)<<endl;
    return 0;
}