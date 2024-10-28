/*
Your task is to count the number of ways to construct sum n by throwing a dice one or more times. Each throw produces an outcome between 1 and  6.
For example, if n=3, there are 4 ways:

1+1+1
1+2
2+1
3
*/
#include<iostream>
#include<vector>
#include<algorithm>
#include<climits>
#define MOD 1000000007
using namespace std;

vector<int> dp;

int fTopDown(int sum){ //here sum means sum to be added to make required sum 
    if(sum == 0) return 1;
    if(dp[sum] != -1) return dp[sum]; //-1 means not calculated yet 
    long long ans = 0;
    for(int i=1 ; i<=6 ; i++){
        if(sum - i < 0) break;
        ans = (ans % MOD + fTopDown(sum-i) % MOD) % MOD;
    } 
    return dp[sum] = ans % MOD;
}

int fDownTop(int sum){
    dp.clear();
    dp.resize(sum+1 , -2);
    if(sum == 0) return 1;
    dp[0] = 1;
    for(int n=1 ; n<=sum ; n++){
        int ans = 0;
        for(int i=1 ; i<=6 ; i++){
            if(n-i < 0) break; 
            ans = (ans % MOD + dp[n-i] % MOD) % MOD;
        }
        dp[n] = ans % MOD;
    }
    return dp[sum];
}

int main(){
    int sum;
    cin>>sum;
    dp.resize(sum+1,-1);
    //cout<<fTopDown(sum) % MOD<<endl;
    cout<<fDownTop(sum) % MOD<<endl;
    return 0;
}