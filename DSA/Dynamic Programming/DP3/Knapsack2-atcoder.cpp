#include<iostream>
#include<vector>
#include<climits>
using namespace std;

vector<vector<long long>>dp;
int n;

long long fUpDown(vector<pair<int, int>>arr , int idx , int val){ //minimum weight to get the given val
    if(val == 0) return 0;
    if(idx == n) return INT_MAX;
    if(dp[idx][val] != -1) return dp[idx][val];
    long long ans = INT_MAX;
    ans = min( fUpDown(arr , idx+1 , val) , ans ); //not pick it
    if(val >= arr[idx].second) ans = min( arr[idx].first + fUpDown(arr , idx+1 , val-arr[idx].second) , ans ); //pick it
    return dp[idx][val] = ans;
}

long long fDownTop(vector<pair<int, int>> arr, int w) {
    dp.clear();
    dp.resize(n + 1, vector<long long>(n * 1000 + 1, INT_MAX));
    
    // Base case: 0 weight for value 0
    for (int i = 0; i <= n; i++) {
        dp[i][0] = 0;
    }
    
    for (int idx = n - 1; idx >= 0; idx--) { // iterate over items
        for (int j = 0; j <= n * 1000; j++) { // iterate over values
            dp[idx][j] = dp[idx + 1][j]; // not picking the item

            if (j >= arr[idx].second) { // picking the item
                dp[idx][j] = min(dp[idx][j], dp[idx + 1][j - arr[idx].second] + arr[idx].first);
            }
        }
    }

    long long ans = 0;
    for (int i = 0; i <= n * 1000; i++) {
        if (dp[0][i] <= w) {
            ans = i;
        }
    }
    return ans;
}

int main(){
    int w;
    cin>>n>>w;
    dp.clear();
    dp.resize(n+1 , vector<long long>(n*1000 + 1 , -1));
    vector<pair<int, int>> arr(n); // weight , value
    for(int i=0 ; i<n ; i++){
        cin>>arr[i].first>>arr[i].second;
    }
    // int ans = 0;
    // for(int i=0 ; i<=n*1000 ; i++){
    //     if(fUpDown(arr , 0 , i) <= w){
    //         ans = i;
    //     }
    // }
    // cout<<ans<<endl;
    cout<<fDownTop(arr , w)<<endl;
    return 0;
}