/*
leetcode 947
On a 2D plane, we place n stones at some integer coordinate points. Each coordinate point may have at most one stone.

A stone can be removed if it shares either the same row or the same column as another stone that has not been removed.

Given an array stones of length n where stones[i] = [xi, yi] represents the location of the ith stone, return the largest possible number of stones that can be removed.
*/

class Solution {
public:

/*
    //method 1 finding connected compnents using dfs (can use bfs also)
    int n , components = 0;
    unordered_set<int>visited;
    vector<vector<int>> adj; //adj[i] points to ith stone whose coordinates can be accessed from stones[i]

    void dfsVisit(int x){
        visited.insert(x);
        for(auto ele : adj[x]){
            if(!visited.count(ele)){
                dfsVisit(ele);
            }
        }
        return;
    }

    int removeStones(vector<vector<int>>& stones) {
        n = stones.size();
        adj.resize(n);

        for(int i=0 ; i<n ; i++){
            for(int j=i+1 ; j<n ; j++){
                if(stones[i][0] == stones[j][0] or stones[i][1] == stones[j][1]){
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }

        for(int i=0 ; i<n ; i++){
            if(!visited.count(i)){
                components++;
                dfsVisit(i);
            }
        }

        return n - components; // as for each component , its all stones can be removed except for the root one so one stone unremoved left per component as every component can be taken as a tree in which only root node will be left unremoved and rest can be removed starting from leaf node as they are always connected to atleast one 
    }

*/
    //method 2 by finding connected components by using dsu O(n2)
    int n , components;
    vector<int>parent;

    int find(int x){
        if(parent[x] == x) return x;
        return parent[x] = find(parent[x]);
    }

    void Union(int x , int y){
        x = find(x);
        y = find(y);

        if(x==y) return;
        parent[x] = y;
        components--;
        return ;
    }

    int removeStones(vector<vector<int>>& stones) {
        n = stones.size();
        components = n;
        parent.resize(n);
        for(int i=0 ; i<n ; i++) parent[i] = i;
        
        for(int i=0 ; i<n ; i++){
            for(int j = i+1 ; j<n ; j++){
                if(stones[i][0] == stones[j][0] or stones[i][1] == stones[j][1]){
                    Union(i,j);
                }
            }
        }

        return n - components;
    }
};


//best apporach using dsu in o(n)
#include <bits/stdc++.h>
using namespace std;


class DisjointSet {
    vector<int> rank, parent, size;
public:
    DisjointSet(int n) {
        rank.resize(n + 1, 0);
        parent.resize(n + 1);
        size.resize(n + 1);
        for (int i = 0; i <= n; i++) {
            parent[i] = i;
            size[i] = 1;
        }
    }

    int findUPar(int node) {
        if (node == parent[node])
            return node;
        return parent[node] = findUPar(parent[node]);
    }

    void unionByRank(int u, int v) {
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);
        if (ulp_u == ulp_v) return;
        if (rank[ulp_u] < rank[ulp_v]) {
            parent[ulp_u] = ulp_v;
        }
        else if (rank[ulp_v] < rank[ulp_u]) {
            parent[ulp_v] = ulp_u;
        }
        else {
            parent[ulp_v] = ulp_u;
            rank[ulp_u]++;
        }
    }

    void unionBySize(int u, int v) {
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);
        if (ulp_u == ulp_v) return;
        if (size[ulp_u] < size[ulp_v]) {
            parent[ulp_u] = ulp_v;
            size[ulp_v] += size[ulp_u];
        }
        else {
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v];
        }
    }
};
class Solution {
public:
    int maxRemove(vector<vector<int>>& stones, int n) {
        int maxRow = 0;
        int maxCol = 0;
        for (auto it : stones) {
            maxRow = max(maxRow, it[0]);
            maxCol = max(maxCol, it[1]);
        }
        DisjointSet ds(maxRow + maxCol + 1);
        unordered_map<int, int> stoneNodes;
        for (auto it : stones) {
            int nodeRow = it[0];
            int nodeCol = it[1] + maxRow + 1;
            ds.unionBySize(nodeRow, nodeCol);
            stoneNodes[nodeRow] = 1;
            stoneNodes[nodeCol] = 1;
        }

        int cnt = 0;
        for (auto it : stoneNodes) {
            if (ds.findUPar(it.first) == it.first) {
                cnt++;
            }
        }
        return n - cnt;
    }
};

int main() {

    int n = 6;
    vector<vector<int>> stones = {
        {0, 0}, {0, 2},
        {1, 3}, {3, 1},
        {3, 2}, {4, 3}
    };

    Solution obj;
    int ans = obj.maxRemove(stones, n);
    cout << "The maximum number of stones we can remove is: " << ans << endl;
    return 0;
}
