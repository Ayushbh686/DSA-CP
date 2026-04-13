class Solution {
public:
    int n;
    string s;
    vector<vector<bool>> dp;

    void fn(int idx, vector<string>& temp, vector<vector<string>>& res) {
        if (idx == n) {
            res.push_back(temp);
            return;
        }

        for (int i = idx; i < n; i++) {
            if (dp[idx][i]) {
                temp.push_back(s.substr(idx, i - idx + 1));
                fn(i + 1, temp, res);
                temp.pop_back();
            }
        }
    }

    vector<vector<string>> partition(string s) {
        this->s = s;
        n = s.size();
        
        // DP precompute for every posiible substring if thats palindrome or not
        dp.resize(n, vector<bool>(n, false));

        for (int i = n - 1; i >= 0; i--) {
            for (int j = i; j < n; j++) {
                if (s[i] == s[j] && (j - i < 2 || dp[i + 1][j - 1])) {
                    dp[i][j] = true;
                }
            }
        }

        vector<vector<string>> res;
        vector<string> temp;
        fn(0, temp, res);
        return res;
    }
};