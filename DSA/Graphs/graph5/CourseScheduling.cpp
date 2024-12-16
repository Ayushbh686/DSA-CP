//leetcode 207
/*
There are a total of numCourses courses you have to take, labeled from 0 to numCourses - 1. You are given an array prerequisites where prerequisites[i] = [ai, bi] indicates that you must take course bi first if you want to take course ai.

For example, the pair [0, 1], indicates that to take course 0 you have to first take course 1.
Return true if you can finish all courses. Otherwise, return false.
*/
Class solution{
    int n ;
    vector<vector<int>> adj;
    vector<int>visited;

    bool dfsVisit(int x){
        visited[x] = 0;
        for(int ele : adj[x]){
            if(visited[ele] == 0) return false;
            if(visited[ele] == -1 and !dfsVisit(ele)) return false;
        }
        visited[x] = 1;
        return true;
    }

    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        n = numCourses;
        adj.resize(n);
        for( auto& ele : prerequisites ){
            adj[ele[1]].push_back(ele[0]);
        }

        visited.resize(n,-1);
        for(int i=0 ; i<n ; i++){
            if(visited[i] == -1) {
                if(!dfsVisit(i)) return false;
            }
        }
        return true;
    }
}