/*
leetcode 1143 , atcoder F
You are given strings s and t. Find one longest string that is a subsequence of both s and t.
*/
#include<iostream>
#include<vector>
#include<string>
using namespace std;

vector<vector<int>> dp;
string ans;

int fUpDown(string &s1, string &s2, int i, int j, string output) { 
    if (i >= s1.size() || j >= s2.size()) {
        if (output.size() > ans.size()) ans = output; // Store the LCS if it's longer
        return 0;
    }
    if (dp[i][j] != -1) return dp[i][j];
    
    if (s1[i] == s2[j]) {
        output += s1[i]; // Append instead of prepend to maintain order
        dp[i][j] = 1 + fUpDown(s1, s2, i+1, j+1, output);
    } 
    else {
        int l1 = fUpDown(s1, s2, i+1, j, output);
        int l2 = fUpDown(s1, s2, i, j+1, output);
        dp[i][j] = max(l1, l2);
    }

    if (output.size() > ans.size()) ans = output; // Check the LCS after updating

    return dp[i][j];
}

int main() {
    string s1, s2;
    cin >> s1 >> s2;
    int n1 = s1.size();
    int n2 = s2.size();
    dp.clear();
    dp.resize(n1, vector<int>(n2, -1));
    string output;
    fUpDown(s1, s2, 0, 0, output);
    cout << ans << endl;
    return 0;
}
