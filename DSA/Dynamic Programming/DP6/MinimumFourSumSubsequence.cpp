/*
https://www.geeksforgeeks.org/minimum-sum-subsequence-least-one-every-four-consecutive-elements-picked/
Given an array arr[] of positive integers. The task is to find minimum sum subsequence from the array such that at least one value among all groups of four consecutive elements is picked. 
*/

#include<bits/stdc++.h>
using namespace std;

int minSumSubquence(vector<int>&arr , int n){
    if(n<=4){
        int ans = INT_MAX;
        for(int i=0 ; i<n ; i++){
            ans = min(ans , arr[i]);
        }
        return ans;
    }

    vector<int>dp(n,-1);//dp i gives the maximum sum Subsequence ending at arr[i] with arr[i] included like in LIS 

    dp[0] = arr[0];
    dp[1] = arr[1];
    dp[2] = arr[2];
    dp[3] = arr[3];

    for(int i=4 ; i<n ; i++){
        dp[i] = arr[i] + min({dp[i-1] , dp[i-2] , dp[i-3] , dp[i-4]}); 
    }

    return min({dp[n-1] , dp[n-2] , dp[n-2] , dp[n-4]});
}

int main(){
    int n;
    cin>>n;
    vector<int>arr(n);
    for(int i=0 ; i<n ; i++){
        cin>>arr[i];
    }

    cout<<minSumSubquence(arr , n);
    return 0;
}
//o(N) tc and sc
//space complexity can be reduced by using only four variables as only last four values are used
/*
dp[i] = arr[i] + min({dp[i-1] , dp[i-2] , dp[i-3] , dp[i-4]});
as arr[i] must be included in dp[i] and in example :-  a , b , c , d , e , f, g , h
dp[h] = will have h and include minimum of last four as only chosing one minimum of last 4 will take care of last four.
chosing one element will occur in four groups , so for the past 4 groups choosing one element minimum will suffice
for more refer gfg.
*/