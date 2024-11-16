/*
leetcode 934
You are given an n x n binary matrix grid where 1 represents land and 0 represents water.

An island is a 4-directionally connected group of 1's not connected to any other 1's. There are exactly two islands in grid.

You may change 0's to 1's to connect the two islands to form one island.

Return the smallest number of 0's you must flip to connect the two islands.
*/

// class Solution {
// public:

//     int m , n , startColor , color;

//     void dfs(vector<vector<int>>& grid , int sr , int sc ){
//         if(sr < 0 or sr > m-1 or sc < 0 or sc > n-1) return ;
//         if(grid[sr][sc] != startColor) return;
//         if(grid[sr][sc] == color) return;
//         grid[sr][sc] = color;
//         dfs(grid , sr+1 , sc);
//         dfs(grid , sr-1 , sc);
//         dfs(grid , sr , sc+1);
//         dfs(grid , sr , sc-1);
//         return;
//     }

//     vector<vector<int>> floodFill(vector<vector<int>>& grid, int sr, int sc, int color) {
//         startColor = grid[sr][sc];
//         this->color = color;
//         dfs(grid , sr , sc);
//         return grid;
//     }

//     int bfs(vector<vector<int>>& grid , int sr , int sc){
//         queue<pair<int,int>> qu; //for 1st island border(-1)
//         for(int i=0 ; i<m ; i++){
//             for(int j=0 ; j<n ; j++){
//                 if(grid[i][j] == -1){
//                     qu.push({i,j});
//                 }
//             }
//         }
//         int steps = 0;
//         while(!qu.empty()){
//             int size = qu.size();
//             for(int k=0 ; k<size ; k++){
//                 auto [i,j] = qu.front();
//                 qu.pop();
//                 vector<pair<int , int>> dir = {{1,0} , {-1,0} , {0,1} , {0,-1}};
//                 for(auto [di,dj] : dir){
//                     int newRow = i+di;
//                     int newCol = j+dj;
//                     if(newRow < 0 or newRow >= m or newCol < 0 or newCol >= n or grid[newRow][newCol] == -1 or grid[newRow][newCol] == 2) continue;
//                     if(grid[newRow][newCol] == 1) return steps;
//                     qu.push({newRow , newCol});
//                     grid[newRow][newCol] = 2; // 2 means bridge made
//                 }
//             }
//             steps++;
//         }
//         return steps;
//     }

//     int shortestBridge(vector<vector<int>>& grid) {
//         m = grid.size();
//         n = grid[0].size();
//         int steps = 0;
//         for(int i=0 ; i<m ; i++){
//             for(int j=0 ; j<n ; j++){
//                 if(grid[i][j] == 1){
//                     floodFill(grid , i , j , -1); // marking 1st island different so that it doesnt get confused with second one in bfs
//                     steps = bfs(grid  , i , j);
//                     return steps;
//                 }
//             }
//         }
//         return steps;
//     }
// };


//same approach , just by chatGpt(some contant time improvement)
class Solution {
public:
    int m, n;

    void dfs(vector<vector<int>>& grid, int sr, int sc, queue<pair<int, int>>& qu) {
        if (sr < 0 || sr >= m || sc < 0 || sc >= n || grid[sr][sc] != 1) return;
        grid[sr][sc] = -1; // Mark as visited
        qu.push({sr, sc}); // Push border cells to the queue
        dfs(grid, sr + 1, sc, qu);
        dfs(grid, sr - 1, sc, qu);
        dfs(grid, sr, sc + 1, qu);
        dfs(grid, sr, sc - 1, qu);
    }

    int bfs(vector<vector<int>>& grid, queue<pair<int, int>>& qu) {
        int steps = 0;
        int dir[] = {0, 1, 0, -1, 0};

        while (!qu.empty()) {
            int size = qu.size();
            for (int k = 0; k < size; k++) {
                auto [i, j] = qu.front();
                qu.pop();

                for (int d = 0; d < 4; d++) {
                    int newRow = i + dir[d];
                    int newCol = j + dir[d + 1];
                    if (newRow < 0 || newRow >= m || newCol < 0 || newCol >= n) continue;
                    if (grid[newRow][newCol] == 1) return steps; // Found second island
                    if (grid[newRow][newCol] == 0) {
                        grid[newRow][newCol] = -1; // Mark as visited
                        qu.push({newRow, newCol});
                    }
                }
            }
            steps++;
        }
        return -1; // Should never reach here
    }

    int shortestBridge(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();
        queue<pair<int, int>> qu;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) {
                    dfs(grid, i, j, qu); // DFS marks the first island and initializes BFS queue
                    return bfs(grid, qu); // Directly call BFS
                }
            }
        }
        return -1; // Should never reach here
    }
};