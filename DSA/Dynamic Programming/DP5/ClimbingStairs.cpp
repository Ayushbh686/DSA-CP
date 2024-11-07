/*
leetcode 70
You are climbing a staircase. It takes n steps to reach the top.
Each time you can either climb 1 or 2 steps. In how many distinct ways can you climb to the top?
*/

class Solution {
public:
    // int climbStairs(int n) {//down top dp with 2 variables 
    //     if(n <= 1) return 1;
    //     int ans = 0;
    //     int prev2 = 1 , prev1 = 1; // ways for 0 and 1 rem steps , for 0 its one as we already reached
    //     for(int i=2 ; i<=n ; i++){
    //         ans = prev1 + prev2;
    //         prev2 = prev1;
    //         prev1 = ans;
    //     }
    //     return ans;
    // }

    vector<int>dp;

    int fTopDown(int n){
        if(n==0 or n==1) return dp[n] = 1;
        if(dp[n] != -1) return dp[n];
        int ans = fTopDown(n-1) + fTopDown(n-2);
        return dp[n] = ans;
    }

    int climbStairs(int n) {//top down dp 
        dp.clear();
        dp.resize(n+1,-1);
        dp[0] = dp[1] = 1;
        return fTopDown(n);
    }
};