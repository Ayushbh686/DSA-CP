/*
Problem
Roy has N coin boxes numbered from 1 to N.
Every day he selects two indices [L,R] and adds 1 coin to each coin box starting from L to R (both inclusive).
He does this for M number of days.

After M days, Roy has a query: How many coin boxes have at least X coins.
He has Q such queries.

Input:
First line contains N - number of coin boxes.
Second line contains M - number of days.
Each of the next M lines consists of two space separated integers L and R.
Followed by integer Q - number of queries.
Each of next Q lines contains a single integer X.

Output:
For each query output the result in a new line.

Constraints:
1 ≤ N ≤ 1000000
1 ≤ M ≤ 1000000
1 ≤ L ≤ R ≤ N
1 ≤ Q ≤ 1000000
1 ≤ X ≤ N
*/

#include<iostream>
#include<vector>
using namespace std;

vector<int> dp;
int n, m;

// Top-down function to calculate how many coins are in each box
int fUpDown(vector<pair<int,int>> &arr, int idx) {
    if (idx < 1) return 0;
    if (dp[idx] != -1) return dp[idx];

    // Calculate the difference based on start and end
    int startAtIdx = arr[idx].first;
    int endAtPrevIdx = arr[idx - 1].second;

    return dp[idx] = fUpDown(arr, idx - 1) + startAtIdx - endAtPrevIdx; 
}

int main() {
    // cin >> n >> m;
    
    // // dp array for number of coins in each box
    // dp.clear();
    // dp.resize(n + 2, -1); // number of boxes with i coins
    
    // // Array for the number of days where coins start and stop
    // vector<pair<int, int>> arr(n + 1, {0, 0});
    
    // // Process M days
    // for (int i = 1; i <= m; i++) {
    //     int l, r;
    //     cin >> l >> r;
    //     arr[l].first++;  // Increment at the start
    //     arr[r].second++;  // Increment at the position just after the end
    // }

    // // Call the top-down function to fill dp
    // fUpDown(arr, n);

    // // Array to count how many boxes have at least i coins
    // vector<int> count(n + 1, 0);

    // // Count the number of boxes with exactly 'dp[i]' coins
    // vector<int> freq(n + 1, 0);
    // for (int i = 1; i <= n; i++) {
    //     if (dp[i] <= n) {
    //         freq[dp[i]]++;
    //     }
    // }

    // // Now calculate how many boxes have at least 'x' coins
    // count[n] = freq[n];
    // for (int i = n - 1; i >= 1; i--) {
    //     count[i] = count[i + 1] + freq[i];
    // }

    // int q;
    // cin >> q;
    // while (q--) {
    //     int x;
    //     cin >> x;
    //     if (x > n) {
    //         cout << 0 << endl;  // No boxes can have more than N coins
    //     } else {
    //         cout << count[x] << endl;
    //     }
    // }

    // return 0;

    //fDownTop
    cin>>n>>m;
    vector<int>dp(n+2 , -1); // number of coins in ith box
    vector<pair<int, int>> arr(n+2 , {0,0}); //number of days when the filling start and stop at ith box
    for(int i=0 ; i<m ; i++){
        int l , r;
        cin>>l>>r;
        arr[l].first++;
        arr[r].second++;
    }
    dp[1] = arr[1].first;
    for(int i=2 ; i<=n ; i++){
        dp[i] = dp[i-1] + arr[i].first - arr[i-1].second;
    }

    vector<int> c(1000006 , 0); //boxes with i coins
    for(int i=0 ; i<=n ; i++){
        int coins = dp[i];
        c[coins]++;
    }

    for(int i=c.size() - 2 ; i>=0 ; i--) c[i] = c[i] + c[i+1]; //boxes with atleast i coins
    int q;
    cin>>q;
    while(q--){
        int num;
        cin>>num;
        cout<<c[num]<<endl;
    }
    return 0;
}



// method 2
// #include <iostream>
// #include <vector>
// using namespace std;

// int main() {
//     int n, m;
//     cin >> n >> m;

//     // `coins` array to store how many coins are added to each box
//     vector<int> coins(n + 2, 0);

//     // Process the M days
//     for (int i = 0; i < m; ++i) {
//         int l, r;
//         cin >> l >> r;
//         coins[l]++;       // Increment at the start of the range
//         if (r + 1 <= n) {
//             coins[r + 1]--;  // Decrement at the end+1 of the range
//         }
//     }

//     // Calculate the actual number of coins in each box
//     vector<int> boxCoins(n + 1, 0);
//     boxCoins[0] = 0;
//     for (int i = 1; i <= n; i++) {
//         boxCoins[i] = boxCoins[i - 1] + coins[i];
//     }

//     // Frequency array to count how many boxes have exactly `x` coins
//     vector<int> freq(n + 1, 0);
//     for (int i = 1; i <= n; i++) {
//         if (boxCoins[i] <= n) {
//             freq[boxCoins[i]]++;
//         }
//     }

//     // Count how many boxes have at least `x` coins
//     vector<int> count(n + 1, 0);
//     count[n] = freq[n];
//     for (int i = n - 1; i >= 1; i--) {
//         count[i] = count[i + 1] + freq[i];
//     }

//     // Process the Q queries
//     int q;
//     cin >> q;
//     while (q--) {
//         int x;
//         cin >> x;
//         if (x > n) {
//             cout << 0 << endl;  // No boxes can have more than N coins
//         } else {
//             cout << count[x] << endl;
//         }
//     }

//     return 0;
// }