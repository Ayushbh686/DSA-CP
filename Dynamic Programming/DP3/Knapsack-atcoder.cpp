#include<iostream>
#include<vector>
#include<climits>
using namespace std;

vector<vector<long long>> dp;
int n; 

long long fUpDown(vector<pair<int, int>> arr , int idx , long long weight){
    if(idx >= n or weight <= 0 ) return 0; 
    if(dp[idx][weight] != -1) return dp[idx][weight];

    long long val = INT_MIN;
    val = fUpDown(arr , idx+1 , weight); //not picking it up
    if(weight - arr[idx].first >= 0) val = max(val , (long long)arr[idx].second + fUpDown(arr , idx+1 , weight - arr[idx].first)); // picking it up
    return dp[idx][weight] = val; 
}

long long fDownTop(vector<pair<int, int>> arr , int weight){
    dp.clear();
    dp.resize(n+2 , vector<long long>(weight+2 , 0));
    for(int idx = n-1 ; idx >= 0 ; idx--){ //in rec reln state depends on idx+1 state
        for(int j = 0 ; j<=weight ; j++){  // in rec reln state depends on w-1 so loop from 0 to weight
            long long ans = INT_MIN;
            ans = dp[idx+1][j]; // not pick

            if(j >= arr[idx].first){
                ans = max( ans , dp[idx+1][j-arr[idx].first] + arr[idx].second);
            }
            dp[idx][j] = ans;
        }
    }
    return dp[0][weight];
}

int main(){
    long long w;
    cin>>n>>w;
    dp.clear();
    dp.resize(n+2 , vector<long long>(w+2 , -1));
    vector<pair<int , int>> arr(n);  // weight , value
    for(int i=0 ; i<n ; i++){
        cin>>arr[i].first>>arr[i].second;
    }
    //cout<<fUpDown(arr , 0 , w);
    cout<<fDownTop(arr , w);
    return 0;
}