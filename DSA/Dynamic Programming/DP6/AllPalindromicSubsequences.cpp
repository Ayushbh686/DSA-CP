#include <bits/stdc++.h>
using namespace std;

// Recursive utility function to count palindromic subsequences
// in the substring s[i..j] using memoization to store results
int countPSUtil(string &s, int i, int j, vector<vector<int>> &memo){

    // Base case: if the starting index exceeds the ending index
    if (i > j)
        return 0;

    // Base case: if there is only one character, it's a palindrome
    if (i == j)
        return 1;

    // Return the already computed subproblem if it exists
    if (memo[i][j] != -1)
        return memo[i][j];

    if (s[i] == s[j]){

        // Count palindromes by including both characters
        // and counting palindromes in the remaining substrings
        memo[i][j] = 1 + countPSUtil(s, i + 1, j, memo) +
                     countPSUtil(s, i, j - 1, memo);
                     //The overlap (count(i+1, j-1)) is not subtracted, because it is transformed into new palindromes by wrapping it with s[i] and s[j].
    }
    else{

        // If characters are different, count palindromes by excluding
        // one character from either end and subtracting the overlap
        memo[i][j] = countPSUtil(s, i + 1, j, memo) +
                     countPSUtil(s, i, j - 1, memo) -
                     countPSUtil(s, i + 1, j - 1, memo);
    }

    // Return the computed result for the substring s[i..j]
    return memo[i][j];
}

// Function to count the number of palindromic subsequences
// in a given string
int countPS(string s){
    int n = s.size();

    // Create a memoization table initialized to -1
    vector<vector<int>> memo(n, vector<int>(n, -1));
    return countPSUtil(s, 0, n - 1, memo);
}

int main(){
    string s = "geeksforgeeks";
    cout << countPS(s);
}