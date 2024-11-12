/*
leetcode 1034
*/
#include <vector>
using namespace std;

class Solution {
public:
    int m, n, newColor, originalColor;

    void dfs(vector<vector<int>>& grid, int row, int col, vector<pair<int, int>>& borders) {
        if (row < 0 || row >= m || col < 0 || col >= n || grid[row][col] != originalColor) 
            return;

        // Temporarily mark the cell to avoid revisiting
        grid[row][col] = -originalColor; 

        // bool isBorder = row == 0 || row == m - 1 || col == 0 || col == n - 1;
        
        // // Check adjacent cells
        // vector<pair<int, int>> directions = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
        // for (auto [dr, dc] : directions) {
        //     int newRow = row + dr;
        //     int newCol = col + dc;
        //     if (newRow >= 0 && newRow < m && newCol >= 0 && newCol < n) {
        //         if (grid[newRow][newCol] != originalColor && grid[newRow][newCol] != -originalColor) {
        //             isBorder = true;
        //         } else if (grid[newRow][newCol] == originalColor) {
        //             dfs(grid, newRow, newCol, borders);
        //         }
        //     } else {
        //         isBorder = true;
        //     }
        // }
        
        // // If it's a border cell, add to the borders list
        // if (isBorder) {
        //     borders.push_back({row, col});
        // }

        //approach 2 (same but different type of writting) for commented part
        dfs(grid, row+1, col, borders);
        dfs(grid, row-1, col, borders);
        dfs(grid, row, col+1, borders);
        dfs(grid, row, col-1, borders);

        if( row == 0 or col == 0 or row == m-1 or col == n-1 or grid[row+1][col] != -originalColor or grid[row-1][col] != -originalColor or grid[row][col+1] != -originalColor or grid[row][col-1] != -originalColor ){
            borders.push_back({row , col});
        }
    }

    vector<vector<int>> colorBorder(vector<vector<int>>& grid, int row, int col, int color) {
        m = grid.size();
        n = grid[0].size();
        originalColor = grid[row][col];
        newColor = color;
        
        vector<pair<int, int>> borders;
        
        // Run DFS to find all borders of the component
        dfs(grid, row, col, borders);
        
        // Color only the border cells
        for (auto [r, c] : borders) {
            cout<<r<<""<<c<<endl;
            grid[r][c] = newColor;
        }
        
        // Restore other cells to their original color if temporarily marked
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == -originalColor) {
                    grid[i][j] = originalColor;
                }
            }
        }
        
        return grid;
    }
};
