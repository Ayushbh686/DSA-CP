/*
https://www.spoj.com/problems/ACODE/
same as decode ways on leetcode 91
*/
#include<iostream>
#include<vector>
#include<climits>
#define ll long long int
using namespace std;

vector<ll> dp;

ll fUpDown(string &str , int i){  // posiible decodings from 0 to i
    if(i<=0) return 1;
    if(dp[i] != -1) return dp[i];

    ll ans = 0;
    if(str[i]-'0' > 0) ans += fUpDown(str , i-1);
    if(str[i-1] - '0' > 0 and (str[i-1] - '0')*10 + (str[i] - '0') <= 26){
        ans += fUpDown(str , i-2);
    }
    return dp[i] = ans;
}

ll fDownTop(string &str){
    int n = str.size();
    dp.clear();
    dp.resize(n+1 , 0);
    if(str[0] != '0') dp[0] = 1;
    if(n>1){
       if(str[1] != '0') dp[1] += dp[0];
       if(str[0]-'0' > 0 and (str[0]-'0')*10 + (str[1]-'0') <= 26) dp[1]++;
    }
    for(int i=2 ; i<n ; i++){
        ll ans = 0;
        if(str[i]-'0' > 0) ans += dp[i-1];
        if(str[i-1] - '0' > 0 and (str[i-1] - '0')*10 + (str[i] - '0') <= 26){
            ans += dp[i-2];
        } 
        dp[i] = ans;
    }
    return dp[n-1];
}

int main(){
    string str;
    cin>>str;
    while(str[0] != '0'){
        int n = str.size();
        // dp.clear();
        // dp.resize(n+1 , -1);
        // cout<<fUpDown(str , n-1)<<endl;
        cout<<fDownTop(str)<<endl;
        cin>>str;
    }
    return 0;
}