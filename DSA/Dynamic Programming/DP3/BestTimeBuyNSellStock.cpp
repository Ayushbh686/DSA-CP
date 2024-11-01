/*
leetcode 714
You are given an array prices where prices[i] is the price of a given stock on the ith day, and an integer fee representing a transaction fee.

Find the maximum profit you can achieve. You may complete as many transactions as you like, but you need to pay the transaction fee for each transaction.

Note:

You may not engage in multiple transactions simultaneously (i.e., you must sell the stock before you buy again).
The transaction fee is only charged once for each stock purchase and sale.
*/
class Solution {
public:

    int fee;
    vector<vector<int>> dp;

    int fUpDown(vector<int>& prices , int i , bool flag){
        if(i>=prices.size()) return 0;
        if(dp[i][flag] != -1) return dp[i][flag];
        int profit = 0;
        if(flag){
            profit = fUpDown(prices , i+1 , false) + prices[i] - fee;
            profit = max(profit , fUpDown(prices , i+1 , true));
        }
        else {
            profit = fUpDown(prices , i+1 , true) - prices[i];
            profit = max(profit , fUpDown(prices , i+1 , false));
        }

        return dp[i][flag] = profit;
    }

    int maxProfit(vector<int>& prices, int fee) {
        this->fee = fee;
        dp.clear();
        dp.resize(prices.size() + 1 , vector<int>(2 , -1));
        return fUpDown(prices , 0 , false);
    }
};
/* f(ith day , flag hold or not) = {
    if( flag == true) max( f(ith , flag) , )
}
*/