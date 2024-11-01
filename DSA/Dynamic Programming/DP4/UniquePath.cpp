/*
leetcode 63 
*/

class Solution {
public:

    vector<vector<long long>> dp;
    int n  , m;

    int fUpDown(vector<vector<int>>&obstacleGrid , int i , int j){
        if(i>m-1 or j>n-1) return 0;
        if(obstacleGrid[i][j] == 1 ) return 0;
        if(i==m-1 and j == n-1) return 1;
        if(dp[i][j] != -1) return dp[i][j];

        int ans = fUpDown(obstacleGrid , i+1 , j) + fUpDown(obstacleGrid , i , j+1);
        return dp[i][j] = ans;
    }

    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        m = obstacleGrid.size();
        n = obstacleGrid[0].size();
        // dp.clear();
        // dp.resize(m+1 , vector<long long>(n+1 , -1));
        // return fUpDown(obstacleGrid , 0 , 0);

        //fTopDown
        dp.clear();
        dp.resize(m+2 , vector<long long> (n+2 , 0));
        if(obstacleGrid[m-1][n-1] == 1) return 0;
        dp[m-1][n-1] = 1;
        for(int i=m-1 ; i>=0 ; i--){
            for(int j=n-1 ; j>=0 ; j--){
                if(i==m-1 and j==n-1) continue;
                if(obstacleGrid[i][j] == 1) {
                    dp[i][j] = 0;
                }
                else{
                    dp[i][j] = dp[i+1][j] + dp[i][j+1];
                }
            }
        }
        return dp[0][0];
    }
};