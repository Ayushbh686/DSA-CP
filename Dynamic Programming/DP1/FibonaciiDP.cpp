#include<iostream>
#include<vector>
using namespace std;

vector<int> dp;

int fibo(int n){ //top down , memoziation
    if(n==0 or n==1) return n;
    if(dp[n] != -1) return dp[n]; //means the subproblem is already computed
    return dp[n] = fibo(n-1) + fibo(n-2); //storing it in dp if not solved yet
} // O(N) tc reduced from O(2^n) of rec and O(2*N) = O(N) SC

int fiboItr(int n){ // bottom up -> itr , we have to look for which subproblem must first be computed to calculate another problem maintaining order by self
    dp.clear();
    dp.resize(n+1,-1);
    dp[0]=0;
    dp[1]=1;
    for(int i=2 ; i<=n ; i++){
        dp[i] = dp[i-1] + dp[i-2];
    }
    return dp[n];
} // we can reduce sc by storing only previous 2 result and not entire array

int main(){
    int n;
    cin>>n;
    dp.clear();
    dp.resize(n+1 , -1);
    //cout<<fibo(n);
    cout<<fiboItr(n);
}