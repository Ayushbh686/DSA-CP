#include<bits/stdc++.h>
using namespace std;
typedef pair<int, string> pp;

vector<vector<pp>> adj;
unordered_set<int> visited;
int n, e;
int ans = INT_MAX;

void ShortestPathDFS(int src, int des, int path, string color, int RemChanges) {
    if (src == des) {
        ans = min(ans, path);
        return;
    }
    visited.insert(src);
    for (auto ele : adj[src]) {
        // Fixing typo "ele.frist" to "ele.first"
        if (color == "red" && ele.second == "blue" && path != 0 && RemChanges == 1 && visited.count(ele.first) == 0) {
            ShortestPathDFS(ele.first, des, path + 1, ele.second, 0);
        } else if (color == ele.second && visited.count(ele.first) == 0) {
            ShortestPathDFS(ele.first, des, path + 1, ele.second, RemChanges);
        }
    }
    visited.erase(src);
    return;
}

int main() {
    cin >> n >> e;
    adj.resize(n);

    for (int i = 0; i < e; i++) {
        int x, y;
        string color;
        cin >> x >> y >> color;
        adj[x].push_back({y, color});
        adj[y].push_back({x, color});
    }

    int src, des;
    cin >> src >> des;

    ShortestPathDFS(src, des, 0, "red", 1); // src, des, length till now, previous color, how many times can I change from red to blue

    if (ans == INT_MAX) {
        cout << -1 << endl; // No valid path found
    } else {
        cout << ans << endl;
    }

    return 0;
}
// alternative(better) -> find shortest path from src to every node only using red edge , mark unreachable as INFINITY
// and find shortest distance from des to every node using blue edge only where unreachable will be marked as INFINITY so the node with minimum sum of these two distance will be intermediate node will give shortest distance and path
// BFS TWO TIMES