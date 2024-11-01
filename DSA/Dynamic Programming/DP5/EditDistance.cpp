/*
leetcode 72
Given two strings word1 and word2, return the minimum number of operations required to convert word1 to word2.

You have the following three operations permitted on a word:

Insert a character
Delete a character
Replace a character
*/

class Solution {
public:

    int n1 , n2;
    vector<vector<int>> dp;

    int fUpDown(string word1, string word2 , int i , int j){ //operation for i...n1 and j...n2
        //if(i==n1 and j==n2) return 0;
        if(i==n1) return n2-j;
        if(j==n2) return n1-i;
        if(dp[i][j] != -1) return dp[i][j];

        if(word1[i] == word2[j]) return dp[i][j] = fUpDown(word1 , word2 , i+1 , j+1);
        int ans = INT_MAX;
        ans = min(ans , 1 + fUpDown(word1 , word2 , i+1 , j+1)); //replace character;
        ans = min(ans , 1 + fUpDown(word1 , word2 , i+1 , j)); //delete character;
        ans = min(ans , 1 + fUpDown(word1 , word2 , i , j+1)); //insert character;

        return dp[i][j] = ans ;
    }

    int minDistance(string word1, string word2) {
        n1 = word1.size();
        n2 = word2.size();
        // dp.clear();
        // dp.resize(n1+1 , vector<int>(n2+1 , -1));
        // return fUpDown(word1 , word2 , 0 , 0);

        //fDownTop
        dp.clear();
        dp.resize(n1+1 , vector<int>(n2+1 , 0));
        for(int i=0 ; i<n1 ; i++) dp[i][n2] = n1-i;
        for(int i=0 ; i<n2 ; i++) dp[n1][i] = n2-i;

        for(int i=n1-1 ; i>=0 ; i--){
            for(int j=n2-1 ; j>=0 ; j--){
                if(word1[i] == word2[j]) dp[i][j] = dp[i+1][j+1];
                else {
                    int ans = INT_MAX;
                    ans = min(ans , 1 + dp[i+1][j+1]);
                    ans = min(ans , 1 + dp[i+1][j]);
                    ans = min(ans , 1 + dp[i][j+1]);
                    dp[i][j] = ans;
                }
            }
        }
        return dp[0][0];
    }
};