/*
leetcode 785
There is an undirected graph with n nodes, where each node is numbered between 0 and n - 1. You are given a 2D array graph, where graph[u] is an array of nodes that node u is adjacent to. More formally, for each v in graph[u], there is an undirected edge between node u and node v. The graph has the following properties:

There are no self-edges (graph[u] does not contain u).
There are no parallel edges (graph[u] does not contain duplicate values).
If v is in graph[u], then u is in graph[v] (the graph is undirected).
The graph may not be connected, meaning there may be two nodes u and v such that there is no path between them.
A graph is bipartite if the nodes can be partitioned into two independent sets A and B such that every edge in the graph connects a node in set A and a node in set B.

Return true if and only if it is bipartite.
*/

class Solution {
public:

    queue<int> qu;
    vector<int>color;
    vector<vector<int>>graph;
    int n;

    bool bfs(int src){
        qu.push(src);
        color[src] = 0;
        while(!qu.empty()){
            int top = qu.front();
            qu.pop();
            for(auto ele : graph[top]){
                if(color[ele] == color[top]) return false;
                if(color[ele] != -1) continue;
                color[ele] = !color[top];
                qu.push(ele);
            }
        }
        bool flag = true;
        for(int i=0 ; i<n ; i++){
            if(color[i] == -1) {
                flag = bfs(i);
            }
        }
        return flag;
    }

    bool isBipartite(vector<vector<int>>& graph) {
        this->graph = graph;
        n = graph.size();
        color.resize(n,-1); //-1 not visited yet , 0 means one setA and 1 means set B (if something in the queue means its visited once and colored also , poped out of queue means its neighbur processed)

        return bfs(0);
    }
};