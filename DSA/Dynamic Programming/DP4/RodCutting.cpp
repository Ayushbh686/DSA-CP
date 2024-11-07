/*
Given a rod of length n inches and an array of prices that includes prices of all pieces of
size smaller than n. Determine the maximum value obtainable by cutting up the rod and
selling the pieces.
*/
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int n;
vector<int>dp;

int fUpDown(vector<int> prices , int i){ //gives maximum price for cutting and selling nth inch
    if(i==0) return 0;
    if(dp[i] != -1) return dp[i];
    
    int ans = 0;
    for(int j=1 ; j<i ; j++){
        ans = max( ans , prices[j] + fUpDown(prices , i-j));
    }
    return dp[i] = ans;
}

int main(){
    cin>>n;
    dp.resize(n+1 , -1);
    vector<int>prices(n);
    for(int i=1 ; i<n ; i++) cin >> prices[i]; // prices[i] gives price for ith inch
    cout<<fUpDown(prices , n)<<endl;
}