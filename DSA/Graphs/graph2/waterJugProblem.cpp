#include <bits/stdc++.h>
using namespace std;

int m, n, d;
vector<vector<int>> visited;

int dfs(int x, int y) {
    // Debug print to trace function calls
    cout << "Visiting state: (" << x << ", " << y << ")\n";

    // If target amount `d` is achieved in either jug
    if (x==d or y==d) return 0;

    // Out-of-bounds check
    if (x < 0 || x > m || y < 0 || y > n) return 9999;

    // If this state has been visited, return its cached result
    if (visited[x][y] != -1) return visited[x][y];

    // Mark the state as visited to avoid revisiting
    visited[x][y] = 9999;

    int ans = 9999;

    // Perform all possible operations:
    // 1. Empty Jug 1
    if (x > 0) ans = min(ans, 1 + dfs(0, y));
    // 2. Empty Jug 2
    if (y > 0) ans = min(ans, 1 + dfs(x, 0));
    // 3. Fill Jug 1
    if (x < m) ans = min(ans, 1 + dfs(m, y));
    // 4. Fill Jug 2
    if (y < n) ans = min(ans, 1 + dfs(x, n));
    // 5. Pour Jug 1 -> Jug 2
    if (x > 0 && y < n) {
        int pour1to2 = min(x, n - y);
        ans = min(ans, 1 + dfs(x - pour1to2, y + pour1to2));
    }
    // 6. Pour Jug 2 -> Jug 1
    if (y > 0 && x < m) {
        int pour2to1 = min(y, m - x);
        ans = min(ans, 1 + dfs(x + pour2to1, y - pour2to1));
    }

    // Cache the result for this state
    return visited[x][y] = ans;
}

int bfs(){
    
}

int main() {
    cin >> m >> n >> d;


    // Resize the visited array and initialize with -1
    visited.resize(m + 1, vector<int>(n + 1, -1));

    // Start the DFS from the initial state (0, 0)
    int result = dfs(0, 0);

    // Output the result
    if (result == 9999) cout << -1 << endl;
    else cout << result << endl;

    return 0;
}
