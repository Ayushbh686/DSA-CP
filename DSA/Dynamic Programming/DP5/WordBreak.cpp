/*
leetcode 139
Given a string s and a dictionary of strings wordDict, return true if s can be segmented into a space-separated sequence of one or more dictionary words.

Note that the same word in the dictionary may be reused multiple times in the segmentation.
*/
// class Solution {
// public:
//     vector<vector<int>> dp;
//     unordered_set<string> wordSet;
//     int n;

//     bool fUpDown(string &s, int i, int j) {
//         if (i > j) return true; // Empty substring is considered valid
//         if (dp[i][j] != -1) return dp[i][j]; // Use memoized result
        
//         // Check if the whole substring s[i..j] is in wordDict
//         if (wordSet.count(s.substr(i, j - i + 1))) return dp[i][j] = 1;

//         // Try partitioning the substring s[i..j] at different points
//         for (int k = i; k < j; k++) {
//             // Check if both s[i..k] and s[k+1..j] can be segmented
//             if (fUpDown(s, i, k) && fUpDown(s, k + 1, j)) {
//                 return dp[i][j] = 1;
//             }
//         }
//         return dp[i][j] = 0; // No valid segmentation found
//     }

//     bool wordBreak(string s, vector<string>& wordDict) {
//         n = s.size();
//         wordSet = unordered_set<string>(wordDict.begin(), wordDict.end());
//         dp.assign(n, vector<int>(n, -1)); // Initialize dp with -1 for uncomputed values

//         return fUpDown(s, 0, n - 1);
//     }
// };


//more efficient n2
class Solution {
public:
    vector<int> dp; // Memoization array
    unordered_set<string> wordSet;
    int n;
    
    bool fUpDown(const string& s, int i) {
        if (i == n) return true; // If we've reached the end, it's a valid segmentation
        if (dp[i] != -1) return dp[i]; // Return memoized result if computed
        
        // Try every substring starting from index `i`
        for (int j = i + 1; j <= n; j++) {
            string word = s.substr(i, j - i);
            if (wordSet.count(word) && fUpDown(s, j)) {
                return dp[i] = 1; // Memoize and return true
            }
        }
        return dp[i] = 0; // Memoize and return false if no valid segmentation found
    }

    bool wordBreak(string s, vector<string>& wordDict) {
        //top down
        // n = s.size();
        // wordSet = unordered_set<string>(wordDict.begin(), wordDict.end());
        // dp.resize(n, -1); // Initialize dp with -1 for uncomputed values
        // return fUpDown(s, 0);

        //bottom up
        int n = s.size();
        unordered_set<string> wordSet(wordDict.begin(), wordDict.end());
        vector<bool> dp(n + 1, false);
        dp[0] = true;  // Base case: empty string is always "breakable"
        
        for (int i = 1; i <= n; i++) {
            for (int j = 0; j < i; j++) {
                if (dp[j] && wordSet.find(s.substr(j, i - j)) != wordSet.end()) {
                    dp[i] = true;
                    break;
                }
            }
        }
        
        return dp[n];
    }
};
