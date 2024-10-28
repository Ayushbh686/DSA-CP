#include<iostream>
#include<vector>
#include<climits>
using namespace std;

vector<vector<int>> dp;

int fTopDown(vector<int>&arr , int i , int j){ //number of minimum multiplication in forming matrix from i to j
    if( (j-i) <= 1 or j >= arr.size()) return 0;
    if(dp[i][j] != -1) return dp[i][j];

    int ans = INT_MAX;
    for(int k=i+1 ; k<j ; k++){
        ans = min(ans , fTopDown(arr , i , k) + fTopDown(arr , k , j) + arr[i]*arr[k]*arr[j]);
    }
    return dp[i][j] = ans;
}

int main(){
    int n;
    cin>>n;
    vector<int>arr(n);
    for(int i=0 ; i<n ; i++){
        cin>>arr[i];
    }
    dp.clear();
    // dp.resize(n+1 , vector<int>(n+1 , -1));
    //cout<<fTopDown(arr , 0 , n-1)<<endl;

    // fDownTop
    dp.resize(n+1 , vector<int>(n+1 , 0));
    for(int len = 3; len <= n ; len++){
        for(int i=0 ; i+len-1 < n ; i++){
            int j  = i+len-1;
            dp[i][j] = INT_MAX;
            for(int k=i+1 ; k<j ; k++){
                dp[i][j] = min(dp[i][j] , dp[i][k] + dp[k][j] + arr[i]*arr[k]*arr[j]);
            }
        }
    }
    cout<<dp[0][n-1];
    return 0;
}