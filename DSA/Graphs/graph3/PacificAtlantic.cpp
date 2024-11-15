/*
leetcode 417
*/

class Solution {
public:
    int m, n;
    vector<vector<int>> result;
    vector<vector<int>> visited;

    void bfs(queue<pair<int, int>>& qu, vector<vector<int>>& heights, vector<vector<int>>& ocean) {
        while (!qu.empty()) {
            pair<int, int> tp = qu.front();
            int i = tp.first;
            int j = tp.second;
            qu.pop();

            if (ocean[i][j]) continue; // Skip if already processed
            ocean[i][j] = 1;

            if (i + 1 < m && heights[i + 1][j] >= heights[i][j] && !ocean[i + 1][j]) {
                qu.push({i + 1, j});
            }
            if (i - 1 >= 0 && heights[i - 1][j] >= heights[i][j] && !ocean[i - 1][j]) {
                qu.push({i - 1, j});
            }
            if (j + 1 < n && heights[i][j + 1] >= heights[i][j] && !ocean[i][j + 1]) {
                qu.push({i, j + 1});
            }
            if (j - 1 >= 0 && heights[i][j - 1] >= heights[i][j] && !ocean[i][j - 1]) {
                qu.push({i, j - 1});
            }
        }
    }

    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        m = heights.size();
        n = heights[0].size();
        vector<vector<int>> pacific(m, vector<int>(n, 0));
        vector<vector<int>> atlantic(m, vector<int>(n, 0));

        queue<pair<int, int>> pacQueue, atlQueue;

        // Initialize the borders for both oceans
        for (int i = 0; i < m; i++) {
            pacQueue.push({i, 0}); // Pacific (left edge)
            atlQueue.push({i, n - 1}); // Atlantic (right edge)
        }
        for (int j = 0; j < n; j++) {
            pacQueue.push({0, j}); // Pacific (top edge)
            atlQueue.push({m - 1, j}); // Atlantic (bottom edge)
        }

        // Perform BFS for both oceans
        bfs(pacQueue, heights, pacific);
        bfs(atlQueue, heights, atlantic);

        // Collect cells that can flow into both oceans
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (pacific[i][j] && atlantic[i][j]) {
                    result.push_back({i, j});
                }
            }
        }

        return result;
    }
};
//reverse think that if the water can flow form ocean to the element
//multisource bfs