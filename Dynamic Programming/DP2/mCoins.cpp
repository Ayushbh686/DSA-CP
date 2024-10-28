#include<iostream>
#include<vector>
#include<climits>
using namespace std;

vector<int> dp;
int k, l;

int fUpDown(int n) {
    if (n < 0) return 1; // If we get a negative value, it implies a previous winning move
    if (dp[n] != -1) return dp[n]; // If already calculated, return the stored value
    if (n == 1 || n == k || n == l) return dp[n] = 1; // If n is 1, k, or l, Asen wins

    // The key logic: if any of the moves leads to a losing situation for the opponent
    int ans = !(fUpDown(n - 1) && fUpDown(n - k) && fUpDown(n - l));
    return dp[n] = ans;
}

int fDownUp(int n){
    dp[0] = 0;
    dp[1] = dp[k] = dp[l] = 1;
    for(int i=1 ; i<1000005 ; i++){
        if(i==1 or i==k or i==l) continue;
        dp[i] = !((i >= 1 ? dp[i-1] : 1)  && (i >= k ? dp[i-k] : 1) && (i >= l ? dp[i-l] : 1));
    } 
    return dp[n];
}

int main() {
    int m;
    cin >> k >> l >> m;
    dp.clear();
    dp.resize(1000005, -1); // Initialize dp array with -1 for up to 10^6 positions
    dp[0] = 0; // Base case: if n = 0, Asen loses
    //for(int i=1 ; i<1000005 ; i++) fUpDown(i);
    fDownUp(1000005);
    while (m--) {
        int n;
        cin >> n;
        cout << (dp[n] ? 'A' : 'B'); // Output 'A' if Asen wins, otherwise 'B'
    }
    return 0;
}
