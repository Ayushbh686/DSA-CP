/*
leetcode 994
*/
class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int time = 0;
        int freshCount = 0, rottenCount = 0;
        queue<pair<int, int>> qu; // Queue to track rotten oranges

        // Initialize the queue and count fresh oranges
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 2) {
                    qu.push({i, j});
                    rottenCount++;
                } else if (grid[i][j] == 1) {
                    freshCount++;
                }
            }
        }

        // If there are fresh oranges but no rotten ones, return -1
        if (freshCount > 0 && rottenCount == 0) return -1;

        // Perform BFS to rot the fresh oranges
        while (!qu.empty()) {
            int size = qu.size();
            bool rotted = false; // Track if any fresh orange rotted in this iteration

            for (int k = 0; k < size; k++) {
                auto tp = qu.front();
                int i = tp.first, j = tp.second;
                qu.pop();

                // Check all 4 adjacent cells
                if (i + 1 < m && grid[i + 1][j] == 1) {
                    qu.push({i + 1, j});
                    grid[i + 1][j] = 2;
                    freshCount--;
                    rotted = true;
                }
                if (i - 1 >= 0 && grid[i - 1][j] == 1) {
                    qu.push({i - 1, j});
                    grid[i - 1][j] = 2;
                    freshCount--;
                    rotted = true;
                }
                if (j + 1 < n && grid[i][j + 1] == 1) {
                    qu.push({i, j + 1});
                    grid[i][j + 1] = 2;
                    freshCount--;
                    rotted = true;
                }
                if (j - 1 >= 0 && grid[i][j - 1] == 1) {
                    qu.push({i, j - 1});
                    grid[i][j - 1] = 2;
                    freshCount--;
                    rotted = true;
                }
            }

            // If at least one orange rotted in this iteration, increment time
            if (rotted) time++;
        }

        // If there are still fresh oranges, return -1
        return (freshCount == 0) ? time : -1;
    }
};
