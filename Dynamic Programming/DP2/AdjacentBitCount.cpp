/*
For a string of n bits x1, x2, x3 ... Xn the adjacent bit count of the string (AdjBC(x)) is given by

X1*X2 + X2*X3 + X3*X4 + ... + Xn-1 * Xn

which counts the number of times a 1 bit is adjacent to another 1 bit. For example:
AdjBC(011101101) = 3
AdjBC(111101101) = 4
AdjBC(010101010) = 0

Write a program which takes as input integers n and k and returns the number of bit strings x of n bits (out of 2ⁿ) that satisfy AdjBC(x) = k. For example, for 5 bit strings, there are 6 ways of getting AdjBC(x) = 2:
11100, 01110, 00111, 10111, 11101, 11011
*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<vector<vector<int>>> dp;

int fUpDown(int i, int curr, int l, int n, int k) { 
    // i is the current bit position, curr is the current adjacent bit count, l is the last placed bit (0 or 1), n is the total length, and k is the target adjacent bit count
    if (curr > k) return 0;  // If adjacent bit count exceeds k, return 0
    if (i == n) return curr == k ? 1 : 0; // If we reached the end and adj count equals k, it's a valid string
    
    if (dp[i][curr][l] != -1) return dp[i][curr][l];

    int ans = 0;

    // If last bit was 1, placing 1 adds to adjacent count
    if (l == 1) {
        ans += fUpDown(i + 1, curr + 1, 1, n, k); // Place 1, increase adjacent count
        ans += fUpDown(i + 1, curr, 0, n, k);     // Place 0, no increase
    } 
    // If last bit was 0, placing 1 doesn't add to adjacent count
    else {
        ans += fUpDown(i + 1, curr, 1, n, k);     // Place 1, no increase
        ans += fUpDown(i + 1, curr, 0, n, k);     // Place 0, no increase
    }

    return dp[i][curr][l] = ans;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int index, n, k;
        cin >> index >> n >> k;
        
        dp.clear();
        dp.resize(n + 1, vector<vector<int>>(k + 1, vector<int>(2, -1))); // Resizing the dp array
        
        // Call fUpDown starting at position 0, with current adjacent count 0, and last bit 0
        cout << index << " " << fUpDown(0, 0, 0, n, k) << endl; 
    }
    return 0;
}
