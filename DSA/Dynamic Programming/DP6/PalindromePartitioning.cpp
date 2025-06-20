int n = s.length();
    vector<vector<bool>> isPal(n, vector<bool>(n, false));

    // Precompute palindrome substrings
    for (int len = 1; len <= n; ++len) {
        for (int i = 0; i + len - 1 < n; ++i) {
            int j = i + len - 1;
            if (s[i] == s[j]) {
                if (len <= 2) isPal[i][j] = true;
                else isPal[i][j] = isPal[i+1][j-1];
            }
        }
    }

    vector<int> dp(n+1, 0);  // dp[i] = min cuts for s[i..n-1]
    dp[n] = -1;              // No cut needed beyond end

    for (int i = n-1; i >= 0; --i) {
        int minCuts = INT_MAX;
        for (int j = i; j < n; ++j) {
            if (isPal[i][j]) {
                minCuts = min(minCuts, 1 + dp[j+1]);
            }
        }
        dp[i] = minCuts;
    }

    return dp[0];