/*
leetcode 2316
You are given an integer n. There is an undirected graph with n nodes, numbered from 0 to n - 1. You are given a 2D integer array edges where edges[i] = [ai, bi] denotes that there exists an undirected edge connecting nodes ai and bi.

Return the number of pairs of different nodes that are unreachable from each other.
*/

class Solution {
public:

    int n , components;
    vector<int>parents;
    vector<int>size;

    int find(int x){
        if(parents[x] == x) return x;
        return parents[x] = find(parents[x]);
    }

    void Union(int x , int y){
        x = find(x);
        y = find(y);

        if(x==y) return;
        parents[x] = y;
        size[y] += size[x];
        components--;
        return ;
    }

    long long countPairs(int n, vector<vector<int>>& edges) {
        this->n = n;
        if(edges.size() == 0) return ((long long)n * (long long)(n-1))/2;
        components = n;
        parents.resize(n);
        size.resize(n , 1);
        for(int i=0 ; i<n ; i++) parents[i] = i;

        for(int i=0 ; i<edges.size() ; i++){
            Union(edges[i][0] , edges[i][1]);
        }

        long long pairs = 0;
        for(int i=0 ; i<n ; i++){
            if(parents[i] == i){
                for(int j = i+1 ; j<n ; j++){
                    if(parents[j] == j){
                        pairs += (long long)size[i]* (long long)size[j];
                    }
                }
            }
        }
        return pairs;
    }
};
//count components and size and then calculate pairs