#include<bits/stdc++.h>
using namespace std;

int maxProdCut(int i , vector<int>&dp){
    if(i==0 or i==1) return 0;

    if(dp[i] != -1) return dp[i];

    int ans = 0;
    for(int j=1 ; j<i ; j++){
        ans = max({ ans , j * maxProdCut(i-j , dp) , j * (i-j) });
    }

    return dp[i] = ans;
}

int main(){
    int n ;
    cin>>n;
    vector<int>dp(n+1,-1);
    cout<<maxProdCut(n , dp);
    return 0;
}