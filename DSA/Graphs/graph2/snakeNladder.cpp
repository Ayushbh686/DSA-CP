// leetcode 909

// class Solution {
// public:
//     int snakesAndLadders(vector<vector<int>>& board) {
//         int n = board.size();
//         vector<int> vis(n * n + 1, 0); // 1D visited array for board indices
//         queue<pair<int, int>> qu; // {current position, steps}
        
//         qu.push({1, 0}); // Start from square 1 with 0 steps
//         vis[1] = 1;

//         while (!qu.empty()) {
//             auto [curr, steps] = qu.front();
//             qu.pop();

//             // If we reach the last square
//             if (curr == n * n) return steps;

//             for (int dice = 1; dice <= 6; ++dice) {
//                 int next = curr + dice;
//                 if (next > n * n) break;

//                 // Convert 1D index to 2D board position
//                 int r = (next - 1) / n;
//                 int c = (next - 1) % n;
//                 if (r % 2 == 1) c = n - 1 - c; // Handle reverse rows
//                 r = n - 1 - r; // Reverse row index to match board

//                 // If there's a snake or ladder, jump
//                 if (board[r][c] != -1) next = board[r][c];

//                 // If not visited, push into the queue
//                 if (!vis[next]) {
//                     vis[next] = 1;
//                     qu.push({next, steps + 1});
//                 }
//             }
//         }
        
//         return -1; // If no path to the last square
//     }
// };


class Solution {
public:
    int get_board_value(const vector<vector<int>>& board, int pos) {
        int n = board.size();
        int row = (pos - 1) / n;
        int col = (pos - 1) % n;
        if (row % 2 == 0) {
            return board[n - 1 - row][col];
        } else {
            return board[n - 1 - row][n - 1 - col];
        }
    }

    void dfs(const vector<vector<int>>& board, int curr, int &target, vector<int>& visited, int moves) {
        if (curr == target) return;
        int n = board.size();

        for (int i = 1; i <= 6; ++i) {
            int next_pos = curr + i;
            if (next_pos <= target) {
                int final_pos = get_board_value(board, next_pos);
                if (final_pos == -1) {
                    final_pos = next_pos;
                }
                if (moves + 1 < visited[final_pos]) {
                    visited[final_pos] = moves + 1;
                    dfs(board, final_pos, target, visited, moves + 1);
                }
            }
        }
    }

    int snakesAndLadders(vector<vector<int>>& board) {
        int n = board.size();
        int target = n * n;
        vector<int> visited(target + 1, INT_MAX);
        visited[1] = 0;

        dfs(board, 1, target, visited, 0);

        return visited[target] == INT_MAX ? -1 : visited[target];
    }
};