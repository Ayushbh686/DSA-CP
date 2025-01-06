/*
floyd warshell algo can also work on negative edges and negative cycles and detect negative cycle
*/
#include<bits/stdc++.h>
using namespace std;

int v;

int main() {
    cin >> v;
    vector<vector<int>> adj(v, vector<int>(v)); // Adjacency matrix

    // Input adjacency matrix
    for (int i = 0; i < v; i++) {
        for (int j = 0; j < v; j++) {
            cin >> adj[i][j];
            if (i != j && adj[i][j] == INT_MAX) { 
                adj[i][j] = INT_MAX; // No direct edge
            }
        }
    }

    // Initialize distance matrix
    vector<vector<int>> dist = adj;

    // Floyd-Warshall algorithm
    for (int via = 0; via < v; via++) {
        for (int i = 0; i < v; i++) {
            for (int j = 0; j < v; j++) {
                if (dist[i][via] != INT_MAX && dist[via][j] != INT_MAX) {
                    dist[i][j] = min(dist[i][j], dist[i][via] + dist[via][j]);
                }
            }
        }
    }

    // Detect negative cycle
    for (int i = 0; i < v; i++) {
        if (dist[i][i] < 0) {
            cout << "Negative cycle detected" << endl;
            return 0;
        }
    }

    // Output the distance matrix
    cout << "Distance matrix:" << endl;
    for (int i = 0; i < v; i++) {
        for (int j = 0; j < v; j++) {
            if (dist[i][j] == INT_MAX) {
                cout << "INF ";
            } else {
                cout << dist[i][j] << " ";
            }
        }
        cout << endl;
    }

    return 0;
}

//tc = v^3 , sc = v^2;
// if we apply dijkstra (no neg weights) for finding shortest path to each node from each node it will take v*(elogv)