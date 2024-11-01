/*
Taro and Jiro will play the following game against each other.

Initially, they are given a sequence a=(a 1 ,a 2,…,a N ). Until a becomes empty, the two players perform the following operation alternately, starting from Taro:
Remove the element at the beginning or the end of a. The player earns x points, where x is the removed element.Let X and 
Y be Taro's and Jiro's total score at the end of the game, respectively. Taro tries to maximize 
X−Y, while Jiro tries to minimize X−Y.
Assuming that the two players play optimally, find the resulting value of 
X−Y.
*/
#include<iostream>
#include<vector>
#include<climits>
using namespace std;

vector<vector<long long>> dp; //optimal value of X-Y form i to j
int n;

long long fUpDown(vector<int>&arr , int i , int j){ // optimal value of X-Y for i to j
    if(i==j) return arr[i];
    if(dp[i][j] != -1) return dp[i][j];

    // tero will maximise x-y and therefore max of (arr[i]- .. , arr[j]- ..) and jiro minimse x-y means it will maximise y-x therefore it will maximise its profit wrt tero there here also max taken
    long long ans = max(arr[i] - fUpDown(arr , i+1 , j) , arr[j] - fUpDown(arr , i , j-1)); 
    return dp[i][j] = ans;
}

int main(){
    cin>>n;
    vector<int> arr(n);
    for(int i=0 ; i<n ; i++){
        cin>>arr[i];
    }

    // dp.clear();
    // dp.resize(n+1 , vector<long long>(n+1 , -1));
    // cout<<fUpDown(arr , 0 , n-1)<<endl;
    
    //fDownTop
    dp.clear();
    dp.resize(n+1 , vector<long long> (n+1 , 0));
    for(int i=0 ; i<n ; i++){
        dp[i][i] = arr[i];
    }
    for(int len = 2 ; len <= n ; len++){
        for(int i=0 ; i+len-1 <= n-1 ; i++){
            int j = i+len-1;
            dp[i][j] = max(arr[i] - dp[i+1][j] , arr[j] - dp[i][j-1]);
        }
    }
    cout<< dp[0][n-1] << endl;
    return 0;
}