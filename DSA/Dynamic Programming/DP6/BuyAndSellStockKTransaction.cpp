#include <bits/stdc++.h>
using namespace std;

// Utility function to calculate maximum profit
int maxProfitUtil(int i, int k, int buy, vector<vector<vector<int>>> &memo, vector<int> &prices)
{

    // Base case: if no transactions left
    // or end of price list is reached
    if (k <= 0 || i >= prices.size())
        return 0;

    if (memo[i][k][buy] != -1)
        return memo[i][k][buy];

    int result = 0, profit = 0;

    // If we are in a 'buy' state
    if (buy)
    {

        // Calculate profit by either buying
        // at current price or skipping
        profit = maxProfitUtil(i + 1, k, 0, memo, prices) - prices[i];
        result = max(result, profit);
    }
    else
    {

        // If in a 'sell' state, calculate profit
        // by selling at current price
        profit = prices[i] + maxProfitUtil(i + 1, k - 1, 1, memo, prices);
        result = max(result, profit);
    }

    // Consider the option to skip the current
    // price
    profit = maxProfitUtil(i + 1, k, buy, memo, prices);
    result = max(result, profit);
    return memo[i][k][buy] = result;
}

// Function to return max profit from k
// transation
int maxProfit(vector<int> &prices, int k)
{
    int n = prices.size();

    // Initilize 3D vector for memoization
    vector<vector<vector<int>>> memo(n + 1, vector<vector<int>>(k + 1, vector<int>(3, -1)));

    // Start from first price, in 'buy' state
    return maxProfitUtil(0, k, 1, memo, prices);
}

int main()
{
    int k = 2;
    vector<int> prices = {10, 22, 5, 80};
    cout << maxProfit(prices, k) << endl;

    return 0;
}