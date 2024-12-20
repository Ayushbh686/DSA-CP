/*
leetcode 1135
connecting cities with minimum cost
There are N cities numbered from 1 to N.

You are given connections, where each connections[i] = [city1, city2, cost] represents the cost to connect city1 and city2 together.  (A connection is bidirectional: connecting city1 and city2 is the same as connecting city2 and city1.)

Return the minimum cost so that for every pair of cities, there exists a path of connections (possibly of length 1) that connects those two cities together.  The cost is the sum of the connection costs used. If the task is impossible, return -1.

*/

#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> connections;
vector<vector<int>>mstEdges;
vector<int>parent;
vector<int>Rank;
int n , e;

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

bool cmp(vector<int> e1 , vector <int> e2){
    return e1[2] < e2[2];
}

int minimumCost(){
    int minCost = 0;
    sort(connections.begin() , connections.end() , cmp);
    // vector<vector<int>> mstEdges;

    for(int i=0 ; i<e ; i++){
        if(find(connections[i][0]) != find(connections[i][1])){
            Union(connections[i][0] , connections[i][1]);
            mstEdges.push_back(connections[i]);
            minCost += connections[i][2];
        }
    }

    cout<<"Included connections are : ";
    for (auto& ele : mstEdges) {
        cout << " { " << ele[0] << "," << ele[1] << "," << ele[2] << " } ";
    }
    cout << endl;

    return minCost;
}

int main(){
    cin>>n; //number of cities
    cin>>e; //number of connections given

    for(int i=0 ; i<e ; i++){
        int x , y , wt;
        cin>>x>>y>>wt;
        connections.push_back({x,y,wt});
    }

    parent.resize(n + 1); // Ensure 1-based indexing
    Rank.resize(n + 1, 0);

    for (int i = 0; i <= n; i++) {
        parent[i] = i;
    }

    int cost = minimumCost();
    //method of finding disconnected graph thorugh dsu
    for(int i=1 ; i<n-1 ; i++){
        if(find(i) != find(i+1)) {
            cout<<"not possible to include all , so -1"<<endl;
        return 0;
        }
    }
    cout<<"total cost : "<<cost<<endl;
    return 0;
}