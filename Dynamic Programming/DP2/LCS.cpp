#include<iostream>
#include<vector>
#include<string>
using namespace std;

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
            if (dp[i+1][j] >= dp[i][j+1]) i++;
            else j++;
        }
    }
}

string fDownUp(string &s1, string &s2){
    string output;
    int n1 = s1.size();
    int n2 = s2.size();
    dp.clear();
    dp.resize(n1+1 , vector<int>(n2+1,0));
    
    // Fill dp table iteratively
    for (int i = 1; i <= n1; i++) {
        for (int j = 1; j <= n2; j++) {
            if (s1[i - 1] == s2[j - 1]) {
                dp[i][j] = 1 + dp[i - 1][j - 1]; // Characters match, add 1 to the LCS length
            } else {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]); // Otherwise, take the max of either option
            }
        }
    }

    // Now that the dp table is complete, we need to backtrack to construct the LCS
    int i = n1, j = n2;

    // Backtrack from dp[n1][n2] to reconstruct the LCS string
    while (i > 0 && j > 0) {
        if (s1[i - 1] == s2[j - 1]) {
            // If characters match, it's part of the LCS
            output = s1[i - 1] + output;
            i--;
            j--;
        } else {
            // Otherwise, move in the direction of the larger value
            if (dp[i - 1][j] > dp[i][j - 1]) {
                i--;
            } else {
                j--;
            }
        }
    }

    return output;
}

int main() {
    string s1, s2;
    cin >> s1 >> s2;
    int n1 = s1.size();
    int n2 = s2.size();
    
    // Initialize dp array
    dp.clear();
    dp.resize(n1, vector<int>(n2, -1));

    // // Calculate the length of the longest common subsequence
    // fUpDown(s1, s2, 0, 0);

    // // Construct the LCS string based on dp array
    // string output;
    // constructLCS(s1, s2, 0, 0, output);
    
    // // Output the result 
    // cout << output << endl; 

    cout<<fDownUp(s1 , s2 )<<endl;
    return 0;
}
