#include <bits/stdc++.h>
using namespace std;

// Function to find minimum number of attempts
// needed in order to find the critical floor
int solveEggDrop(int n, int k, vector<vector<int>> &memo) {

    // if value is already calculated
    if (memo[n][k] != -1) {
        return memo[n][k];
    }

    // if there is less than or equal to one floor
    if (k == 1 || k == 0)
        return k;

    // if there is only one egg
    if (n == 1)
        return k;

    // to store the minimum number of attempts
    int res = INT_MAX;

    // Consider all droppings from
    // 1st floor to kth floor
    for (int i = 1; i <= k; i++) {
        int cur = max(solveEggDrop(n - 1, i - 1, memo), 
                        solveEggDrop(n, k - i, memo));
        if (cur < res)
            res = cur;
    }

    // update the memo, and return
    return memo[n][k] = res + 1;
}

// Function to find minimum number of attempts 
// needed in order to find the critical floor
int eggDrop(int n, int k) {

    // create memo table
    vector<vector<int>> memo(n + 1, vector<int>(k + 1, -1));

    return solveEggDrop(n, k, memo);
}

int main() {
    int n = 2, k = 10;
    cout << eggDrop(n, k);
    return 0;
}