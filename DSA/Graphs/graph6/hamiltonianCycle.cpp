#include<bits/stdc++.h>
using namespace std;

bool check(int idx , int v , vector<int>&path , vector<vector<int>> graph){
    int n = graph.size();

    if(graph[path[idx-1]][v] == 0) return false;

    for(int i=0 ; i<idx ; i++){
        if(path[i] == v) return false;
    }

    if(idx == n-1){
        if(graph[path[0]][v] == 0) return false;
    }

    return true;
}

bool hamCycleUtil(int idx , vector<int>&path , vector<vector<int>> graph){
    int n = graph.size();
    if(idx >= n) return true;

    for(int i=0 ; i<n ; i++){
        if(check(idx , i , path , graph)){
            path[idx] = i;
            if(hamCycleUtil(idx+1 , path , graph)) return true;
            path[idx] = -1;
        }
    }

    return false;
}

vector<int> hamCycle(vector<vector<int>> graph){
    int n = graph.size();

    vector<int>path(n , -1);
    path[0] = 0;
    bool b = hamCycleUtil(1 , path , graph);
    if(!b) path[0] = -1;
    return path;
}

int main() {
    
    // Representation of the given graph
    //    (0)-(1)-(2) 
    //     |  / \  | 
    //     | /   \ | 
    //     |/     \| 
    //    (3)-----(4)
    vector<vector<int>> graph = {
        {0, 1, 0, 1, 0}, 
        {1, 0, 1, 1, 1}, 
        {0, 1, 0, 0, 1}, 
        {1, 1, 0, 0, 1}, 
        {0, 1, 1, 1, 0}
    };

    vector<int> path = hamCycle(graph);
    
    if(path[0] == -1) {
        
        cout << "Solution does not Exist";
    }
    else {
        
        for (int i = 0; i < path.size(); i++) {
           cout << path[i] << " ";
        }

        // Print the first vertex again 
        // to complete the cycle
        cout << path[0];
    }

    return 0;
}


//better approach from general backtrack
/*
#include <iostream>
using namespace std;

const int MAX = 20;
int G[MAX][MAX];    // Adjacency matrix
int x[MAX];         // x[k] = vertex placed at position k in the path
int n;              // Number of vertices

void printSolution() {
    cout << "Hamiltonian Cycle: ";
    for (int i = 1; i <= n; i++) {
        cout << x[i] << " ";
    }
    cout << x[1] << " "; // close the cycle
    cout << endl;
}

// Problem-specific logic: find the next valid vertex for position k
void next_value(int k) {
    while (true) {
        x[k] = (x[k] + 1) % (n + 1); // try next vertex (1 to n)
        if (x[k] == 0) return; // no more vertices, backtrack

        // Check if this vertex is connected to previous one
        if (G[x[k - 1]][x[k]] == 0) continue;

        // Check if vertex is already used
        bool used = false;
        for (int j = 1; j < k; j++) {
            if (x[j] == x[k]) {
                used = true;
                break;
            }
        }
        if (used) continue;

        // If at the last position, check if it connects back to start
        if (k == n && G[x[k]][x[1]] == 0) continue;

        return; // valid vertex found
    }
}

// Generic backtracking function
void general_backtrack(int k) {
    while (true) {
        next_value(k);
        if (x[k] == 0) return;         // backtrack
        if (k == n) printSolution();   // complete cycle found
        else general_backtrack(k + 1); // go to next position
    }
}

int main() {
    cout << "Enter number of vertices: ";
    cin >> n;

    cout << "Enter adjacency matrix:\n";
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            cin >> G[i][j];

    // Start path from vertex 1
    for (int i = 1; i <= n; i++) x[i] = 0;
    x[1] = 1;

    cout << "\nHamiltonian Cycles (if any):\n";
    general_backtrack(2); // Start from position 2

    return 0;
}


*/