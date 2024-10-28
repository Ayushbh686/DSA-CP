/*
You are given an integer array prices where prices[i] is the price of a given stock on the ith day, and an integer k.

Find the maximum profit you can achieve. You may complete at most k transactions: i.e. you may buy at most k times and sell at most k times.

Note: You may not engage in multiple transactions simultaneously (i.e., you must sell the stock before you buy again).


*/

class Solution {
public:
    int dp[1005][105][2];

    // Recursive function to calculate the maximum profit
    int fUpDown(vector<int>& prices, int i, int k, bool flag) {
        if (i == prices.size() || k == 0) return 0;  // Base case: out of bounds or no transactions left
        if (dp[i][k][flag] != -1) return dp[i][k][flag];  // Use memoized result if available

        int ans = fUpDown(prices, i + 1, k, flag);  // Skip the current day
        if (flag) {  // If currently holding a stock
            // Option to sell the stock
            ans = max(ans, prices[i] + fUpDown(prices, i + 1, k - 1, false));
        } else {  // If not holding a stock
            if (k > 0) {
                // Option to buy the stock
                ans = max(ans, fUpDown(prices, i + 1, k, true) - prices[i]);
            }
        }

        return dp[i][k][flag] = ans;  // Memoize the result
    }

    int maxProfit(int k, vector<int>& prices) {
        memset(dp, -1, sizeof(dp));  // Initialize the dp array with -1
        return fUpDown(prices, 0, k, false);  // Start recursion with no stock in hand
    }
};
