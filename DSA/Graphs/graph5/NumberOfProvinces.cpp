/*
leetcode 547
There are n cities. Some of them are connected, while some are not. If city a is connected directly with city b, and city b is connected directly with city c, then city a is connected indirectly with city c.

A province is a group of directly or indirectly connected cities and no other cities outside of the group.

You are given an n x n matrix isConnected where isConnected[i][j] = 1 if the ith city and the jth city are directly connected, and isConnected[i][j] = 0 otherwise.

Return the total number of provinces.
*/

class Solution {
public:

    // unordered_set<int> visited;
    // int n , provinces;

    // void dfsVisit(int x , vector<vector<int>>& isConnected){
    //     visited.insert(x);
    //     for(int i=0 ; i<n ; i++){
    //         if(isConnected[x][i] == 1 and !visited.count(i)){
    //             dfsVisit(i , isConnected);
    //         }
    //     }
    //     return;
    // }

    // int findCircleNum(vector<vector<int>>& isConnected) {
    //     n = isConnected.size();
    //     for(int i=0 ; i<n ; i++){
    //         if(!visited.count(i)){
    //             provinces++;
    //             dfsVisit(i , isConnected);
    //         }
    //     }
    //     return provinces;
    // }


    //method 2 by dsu

    vector<int>parent;
    vector<int>rank;

    int find(int x){
        if(parent[x] == x) return x;
        return parent[x] = find(parent[x]);
    }

    void Union(int x , int y){
        x = find(x);
        y = find(y);

        if(x==y) return ;
        if(rank[x] > rank[y]){
            parent[y] = x; 
        }
        else if(rank[y] > rank[x]){
            parent[x] = y;
        }
        else{
            parent[y] = x;
            rank[x]++;
        }

        return ;
    }

    int findCircleNum(vector<vector<int>>& isConnected){
        int n = isConnected.size();
        parent.resize(n);
        rank.resize(n , 0);
        for(int i=0 ; i<n ; i++) parent[i] = i;
        for(int i=0 ; i<n ; i++){
            for(int j=0 ; j<n ; j++){
                if(isConnected[i][j] == 1) Union(i,j);
            }
        }
        int ans = 0;
        for(int i=0 ; i<n ; i++){
            if(parent[i] == i) ans++;
        }
        return ans;
    }
};