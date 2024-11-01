/*
leetcode 1092
Given two strings str1 and str2, return the shortest string that has both str1 and str2 as subsequences. If there are multiple valid strings, return any of them.

A string s is a subsequence of string t if deleting some number of characters from t (possibly 0) results in the string s
*/


class Solution {
public:

    vector<vector<int>> dp;

    int fUpDown(string &s1, string &s2, int i, int j) { 
        if (i >= s1.size() || j >= s2.size()) return 0;

        if (dp[i][j] != -1) return dp[i][j]; // Memoized result

        // Case when characters match
        if (s1[i] == s2[j]) {
            return dp[i][j] = 1 + fUpDown(s1, s2, i + 1, j + 1);
        } else {
            // Explore both options (excluding current characters from either string)
            int option1 = fUpDown(s1, s2, i + 1, j);
            int option2 = fUpDown(s1, s2, i, j + 1);
            return dp[i][j] = max(option1, option2);
        }
    }

    // Function to construct the longest common subsequence from the dp array
    void constructLCS(string &s1, string &s2, int i, int j, string &output) {
        while (i < s1.size() && j < s2.size()) {
            // If characters match, include it in the LCS
            if (s1[i] == s2[j]) {
                output += s1[i];
                i++;
                j++;
            } else {
                // If not, move in the direction of the larger LCS
                if (dp[i+1][j] >= dp[i][j+1]) {
                    output += s1[i];
                    i++;
                }
                else {
                    output += s2[j];
                    j++;
                }
            }
        }
        while(i <= s1.size() - 1){
            output += s1[i];
            i++;
        }
        while(j <= s2.size() - 1){
            output += s2[j];
            j++;
        }
    }

    string shortestCommonSupersequence(string str1, string str2) {
        int n1 = str1.size();
        int n2 = str2.size();
        dp.clear();
        dp.resize(n1+1 , vector<int>(n2+1 , -1));
        fUpDown(str1 , str2 , 0 , 0);
        string output;
        constructLCS(str1 , str2 , 0 , 0 , output);
        return output;
    }
};
