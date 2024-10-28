/*
a number n can be either n-1 or n/2 or n/3 if divisible , find minimum number of steps to reudce n to 1
*/
#include<iostream>
#include<vector>
#include<climits>
#include<algorithm>
using namespace std;

vector<int> dp;

int fRec(int n){
    if(n==1) return 0;
    if(n==2 or n==3) return 1;
    return 1 + min({ fRec(n-1) ,  n%2 ? INT_MAX : fRec(n/2) , n%3 ? INT_MAX : fRec(n/3) });
}

int fTopDown(int n){
    if(n==1) return 0;
    if(n==2 or n==3) return 1;
    if(dp[n] != -1) return dp[n]; // steps for nth num is already computed
    //if not computed compute it
    return dp[n] = 1 + min({ fTopDown(n-1) ,  n%2 ? INT_MAX : fTopDown(n/2) , n%3 ? INT_MAX : fTopDown(n/3) });
}

int fDownTop(int n){
    if(n==1) return 0;
    if(n==2 or n==3) return 1;
    dp.clear();
    dp.resize(n+1 , -1);
    dp[1] = 0 ; 
    dp[2] = 1;
    dp[3] = 1;
    for(int i=4 ; i<=n ; i++){
        dp[i] = 1 + min({ dp[i-1] , i%2 ? INT_MAX : dp[i/2] , i%3 ? INT_MAX : dp[i/3] });
    }
    return dp[n];
}

int main(){
    int n;
    cin>>n;
    dp.clear();
    dp.resize(n+1 , -1);
    cout<<fRec(n)<<endl;
    cout<<fTopDown(n)<<endl;
    cout<<fDownTop(n)<<endl;
    return 0;
}