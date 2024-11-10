/*
leetcode 841
There are n rooms labeled from 0 to n - 1 and all the rooms are locked except for room 0. Your goal is to visit all the rooms. However, you cannot enter a locked room without having its key.

When you visit a room, you may find a set of distinct keys in it. Each key has a number on it, denoting which room it unlocks, and you can take all of them with you to unlock the other rooms.

Given an array rooms where rooms[i] is the set of keys that you can obtain if you visited room i, return true if you can visit all the rooms, or false otherwise

*/


//dfs
// class Solution {
// public:

//     unordered_set<int> visited;
//     int n;

//     void dfs(vector<vector<int>>& rooms , int i){
//         if(visited.count(i)) return;
//         visited.insert(i);
//         for(auto key : rooms[i]){
//             if(!visited.count(key)) dfs(rooms , key);
//         }
//         return ;
//     }

//     bool canVisitAllRooms(vector<vector<int>>& rooms) {
//         n = rooms.size();
//         dfs(rooms , 0);
//         return visited.size() == n ? true : false;
//     }
// };

//bfs
class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n=rooms.size();
        vector<bool>vis(n,false);
        queue<int>q;
        q.push(0);
        vis[0]=true;
        while(!q.empty()){
            int node=q.front();q.pop();
            for(auto it:rooms[node]){
                if(!vis[it]){q.push(it);vis[it]=true;}
            }
        }
        for(int i=0;i<n;i++)if(!vis[i])return false;
        return true;
    }
};