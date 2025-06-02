/*
cses https://cses.fi/problemset/task/1634
Consider a money system consisting of n coins. Each coin has a positive integer value. Your task is to produce a sum of money x using the available coins in such a way that the number of coins is minimal.
For example, if the coins are \{1,5,7\} and the desired sum is 11, an optimal solution is 5+5+1 which requires 3 coins.
same as leetcode 322
*/
#include<iostream>
#include<vector>
#include<algorithm>
#include<climits>
using namespace std;

vector<int> coins;
vector<int> dp;

int fTopDown(int sum){ //here sum means sum to be added to make required sum 
    if(sum == 0) return 0;
    if(dp[sum] != -2) return dp[sum]; //-2 means not calculated yet 
    int ans = INT_MAX;
    for(int i=0 ; i<coins.size() ; i++){
        if(sum - coins[i] < 0) continue;
        ans = min(ans , fTopDown(sum - coins[i]));
    }
    if(ans == INT_MAX) return dp[sum] = INT_MAX; //infinity means calculated and not possible 
    return dp[sum] = 1 + ans;
}

int fDownTop(int sum){
    dp.clear();
    dp.resize(sum+1 , -2);
    if(sum == 0) return 0;
    dp[0] = 0;
    for(int n=1 ; n<=sum ; n++){
        int result = INT_MAX;
        for(int i=0 ; i<coins.size() ; i++){
            if(n-coins[i] < 0) continue; 
            result = min(result , dp[n-coins[i]]);
        }
        if(result == INT_MAX) dp[n] = INT_MAX;
        else dp[n] = 1 + result;
    }
    return dp[sum];
}

int main(){
    int n,sum;
    cin>>n>>sum;
    coins.resize(n);
    dp.resize(sum+1,-2);
    for(int i=0 ; i<n ; i++) cin>>coins[i];
    if(fDownTop(sum) == INT_MAX) cout<<-1<<endl;
    else cout<<fDownTop(sum)<<endl;
    // if(fTopDown(sum) == INT_MAX) cout<<-1<<endl;
    // else cout<<fTopDown(sum)<<endl;
    return 0;
}
//greedy not correct as in example [1,5,7] , sum = 11
// another example that greedy not correct [25,10,5] , sum = 30