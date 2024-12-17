/*
leetcode 210
There are a total of numCourses courses you have to take, labeled from 0 to numCourses - 1. You are given an array prerequisites where prerequisites[i] = [ai, bi] indicates that you must take course bi first if you want to take course ai.

For example, the pair [0, 1], indicates that to take course 0 you have to first take course 1.
Return the ordering of courses you should take to finish all courses. If there are many valid answers, return any of them. If it is impossible to finish all courses, return an empty array.
*/
class Solution {
public:

    vector<vector<int>> adj;
    vector<int> inDeg;
    int n , e;

    void KahnAlgoBFS(vector<int>& ans){
        queue<int>qu;
        unordered_set<int> visited;
        for(int i=0 ; i<n ; i++){
            cout<<inDeg[i]<<" ";
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
            ans.push_back(top);
        }
        return;
    }

    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        n = numCourses;
        e = prerequisites.size();
        adj.resize(n);
        inDeg.resize(n,0);
        for(auto& ele : prerequisites){
            adj[ele[1]].push_back(ele[0]);
            inDeg[ele[0]]++;
        }
        vector<int>ans;
        KahnAlgoBFS(ans);
        if(ans.size()<n) ans.clear();
        return ans;
    }
};