/*
finding hamiltoninan cycle 
*/
#include<bits/stdc++.h>
using namespace std;

int n = 4;
int graph[4][4] = {
    {0,20,42,25},
    {20,0,30,34},
    {42,30,0,10},
    {25,34,10,0}
};
int dp[10][1<<10];

int tsp(int i , int mask){ //shortest hamiltonian cycle weight starting from i with visited nodes in mask
    //cout<<"call for "<<i<<endl;
    if(mask == (1<<n) - 1){
        return graph[i][0]; //adding reming path by connecting last vertex again to starting vertex
    }
    if(dp[i][mask] != -1) return dp[i][mask];
    int ans = INT_MAX;
    for(int w=0 ; w<n ; w++){
        bool isVisited = (mask & (1<<w)); // is w vertex visited
        if(!isVisited){
            int edge = graph[i][w];
            ans = min( ans , edge + tsp(w , (1<<w) | mask)); //marking visited the wth edge
        }
    }
    return dp[i][mask] = ans;
}

int main(){
    memset(dp , -1 , sizeof(dp));
    cout<<tsp(0,1); //mask gives the set of visited nodes so 2^n-1 means all visited and 0 means none
    return 0;
}
// tc = n^2 * 2^n as n^2^n states and each state make o(n) loop