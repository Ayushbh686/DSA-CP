/*
Taro's summer vacation starts tomorrow, and he has decided to make plans for it now.
The vacation consists of 
N days. For each i (1≤i≤N), Taro will choose one of the following activities and do it on the i-th day:
A: Swim in the sea. Gain a i  points of happiness.
B: Catch bugs in the mountains. Gain b i points of happiness.
C: Do homework at home. Gain c i points of happiness.
As Taro gets bored easily, he cannot do the same activities for two or more consecutive days.
Find the maximum possible total points of happiness that Taro gains.
*/
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

vector<vector<int>>dp;
vector<vector<int>>act; //activity happiness day wise for a b c

int fUpDown(int n , int i) {// n day , i activity
    if(n==0) return dp[n][i] = act[n][i];
    if(dp[n][i] != -1) return dp[n][i];
    int ans;
    if(i==0) ans = act[n][i] + max(fUpDown(n-1 , 1) , fUpDown(n-1 , 2));
    if(i==1) ans = act[n][i] + max(fUpDown(n-1 , 0) , fUpDown(n-1 , 2));
    if(i==2) ans = act[n][i] + max(fUpDown(n-1 , 0) , fUpDown(n-1 , 1));
    return dp[n][i] = ans;
}

int fDownUp(int n){
    dp.clear();
    dp.resize(n+1,vector<int> (3,-1));
    if(n==0) return max({ act[0][0] , act[0][1] , act[0][2]});
    dp[0][0] = act[0][0];
    dp[0][1] = act[0][1];
    dp[0][2] = act[0][2];
    for(int i=1 ; i<=n ; i++){
        dp[i][0] = act[i][0] + max(dp[i-1][1] , dp[i-1][2]);
        dp[i][1] = act[i][1] + max(dp[i-1][0] , dp[i-1][2]);
        dp[i][2] = act[i][2] + max(dp[i-1][0] , dp[i-1][1]);
    }
    return max({dp[n][0] , dp[n][1] , dp[n][2]});
}

int main(){
    int n;
    cin>>n;
    act.resize(n,vector<int> (3));
    dp.resize(n,vector<int> (3,-1));
    for(int i=0 ; i<n ; i++){
        for(int j=0 ; j<3 ; j++){
            cin>>act[i][j];
        }
    }
    //cout<<max(fUpDown(n-1,0) , max( fUpDown(n-1,1) , fUpDown(n-1,2) ) )<<endl;
    cout<<fDownUp(n-1)<<endl;
    return 0;
}