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
    //method 2 by finding connected components by using dsu
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