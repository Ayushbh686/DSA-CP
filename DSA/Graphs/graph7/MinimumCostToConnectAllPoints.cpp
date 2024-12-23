/*
leetcode 1584
You are given an array points representing integer coordinates of some points on a 2D-plane, where points[i] = [xi, yi].

The cost of connecting two points [xi, yi] and [xj, yj] is the manhattan distance between them: |xi - xj| + |yi - yj|, where |val| denotes the absolute value of val.

Return the minimum cost to make all points connected. All points are connected if there is exactly one simple path between any two points.
*/
class Solution {
public:

    int n;
    vector<int>parent;
    vector<int>Rank;
    vector<vector<int>>edges;

    int find(int x) {
        if (parent[x] == x) return x;
        return parent[x] = find(parent[x]);
    }

    void Union(int a, int b) {  // tc = log*n
        int parA = find(a);
        int parB = find(b);

        if (parA == parB) return;
        
        if (Rank[parA] > Rank[parB]) {
            parent[parB] = parA;
        } else if (Rank[parA] < Rank[parB]) {
            parent[parA] = parB;
        } else {
            parent[parB] = parA;
            Rank[parA]++;
        }
    }

    static bool cmp(vector<int> &e1 , vector<int> &e2){
        return e1[2] < e2[2];
    }

    int minCostConnectPoints(vector<vector<int>>& points) {
        n = points.size();
        Rank.resize(n,0);
        parent.resize(n);
        for(int i=0 ; i<n ; i++) parent[i] = i;

        for(int i=0 ; i<n ; i++){
            for(int j=i+1 ; j<n ; j++){
                int dist = abs(points[i][0] - points[j][0]) + abs(points[i][1] - points[j][1]);
                edges.push_back({i,j,dist});
            }
        }

        sort(edges.begin() , edges.end() , cmp);
        /*sort(edges.begin(), edges.end(), [](vector<int>& e1, vector<int>& e2) {
            return e1[2] < e2[2];
        });
        if cmp not defined static then use this lambda function
        */ 
        int cost = 0;
        for(int i=0 ; i<edges.size() ; i++){
            if(find(edges[i][0]) != find(edges[i][1])){
                cost += edges[i][2];
                Union(edges[i][0] , edges[i][1]);
            }
        }

        return cost;
    }
};