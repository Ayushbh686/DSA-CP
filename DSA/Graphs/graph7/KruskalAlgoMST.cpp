// To create the MST, always pick the edge with the smallest weight. Determine if including it will create a cycle. If so, ignore the edge. Do this until the MST is made.
// For weighted undirected graph
// For edge list -> sort by weight and for cycle checking use DSU (this is standard and most efficient approach for cycle detection here) 
// n-1 edges in MST
#include<bits/stdc++.h>
using namespace std;

int n, e;
vector<int> parent;
vector<int> Rank;
vector<vector<int>> edges;

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

bool cmp(vector<int>& e1, vector<int>& e2) {
    return e1[2] < e2[2];
}

long long kruskalAlgo() {
    sort(edges.begin(), edges.end(), cmp);
    long long mst = 0;
    vector<vector<int>> mstEdges;

    for (int i = 0; i < edges.size(); i++) {
        if (find(edges[i][0]) != find(edges[i][1])) {
            mst += edges[i][2];
            mstEdges.push_back(edges[i]);
            Union(edges[i][0], edges[i][1]);
        }
    }

    cout << "Edges included are: ";
    for (auto& ele : mstEdges) {
        cout << " { " << ele[0] << "," << ele[1] << "," << ele[2] << " } ";
    }
    cout << endl;

    return mst;
}

int main() {
    cin >> n >> e;
    parent.resize(n + 1); // Ensure 1-based indexing
    Rank.resize(n + 1, 0);

    for (int i = 0; i <= n; i++) {
        parent[i] = i;
    }

    for (int i = 0; i < e; i++) {
        int x, y, wt;
        cin >> x >> y >> wt;
        edges.push_back({x, y, wt});
    }

    cout << "Total weight " << kruskalAlgo() << endl;

    return 0;
}

// tc = (eloge + v log*v) == (eloge + v)