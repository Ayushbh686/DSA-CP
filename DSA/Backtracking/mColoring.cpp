//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
  
    vector<vector<bool>> make_graph(int v, vector<pair<int, int>>& edges){
        vector<vector<bool>> graph(v , vector<bool>(v , false));
        
        for(int i=0 ; i<edges.size() ; i++){
            int x = edges[i].first;
            int y = edges[i].second;
            graph[x][y] = true;
            graph[y][x] = true;
        }
        
        return graph;
    }
  
  
    bool isSafe(int node, vector<int>&color,  vector<vector<bool>> graph, int n, int col) {
      for (int k = 0; k < n; k++) {
        if (k != node && graph[k][node] == 1 && color[k] == col) {
          return false;
        }
      }
      return true;
    }
    
    
    bool solve(int node, vector<int>&color, int m, int N, vector<vector<bool>> graph) {
      if (node == N) {
        return true;
      }
    
      for (int i = 1; i <= m; i++) {
        if (isSafe(node, color, graph, N, i)) {
          color[node] = i;
          if (solve(node + 1, color, m, N, graph)) return true;
          color[node] = 0;
        }
    
      }
      return false;
    }

 
    bool graphColoring(int v, vector<pair<int, int>>& edges, int m) {
        vector<vector<bool>> graph = make_graph(v , edges);
        
        vector<int>color(v , -1); //-t means unvisited;
        
        for(int i=0 ; i<v ; i++){
            if(color[i] == -1){
                bool flag = solve(0 , color , m  , v , graph);
                if(flag == false) return false;
            }
        }
        
        return true;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        int n, m;
        cin >> n;
        cin.ignore(); // Ignore newline after reading n
        vector<int> arr;
        string input;
        getline(cin, input); // Read the entire line for the array elements

        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number); // Populate the array with edge values
        }
        cin >> m;
        cin.ignore(); // Ignore newline after reading m

        int edges_count = arr.size();
        vector<pair<int, int>> edges(edges_count /
                                     2); // Correct size of the edges vector

        for (int i = 0; i < edges_count; i += 2) {
            int l1 = arr[i];
            int l2 = arr[i + 1];
            edges[i / 2] = {l1, l2}; // Properly assign the pair
        }

        Solution ob;
        cout << (ob.graphColoring(n, edges, m) ? "true" : "false")
             << "\n~\n"; // Call the graph coloring function
    }
    return 0;
}

// } Driver Code Ends