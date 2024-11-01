/*
leetcode 64(leetcode 63 also similar)
*/

class Solution {
public:

    vector<vector<int>> dp;
    int m , n;

    int fUpDown(vector<vector<int>>& grid , int i , int j){
        if(i>m-1 or j>n-1) return INT_MAX;
        if(i==m-1 and j == n-1) return grid[m-1][n-1];
        if(dp[i][j] != -1) return dp[i][j];

        return dp[i][j] = grid[i][j] + min(fUpDown(grid , i+1 , j) , fUpDown(grid , i , j+1));;
    }

    int minPathSum(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();
        dp.clear();
        dp.resize(m+1 , vector<int>(n+1 , -1));
        return fUpDown(grid , 0, 0);
    }
};