/*
Let N be a positive odd number.There are N coins, numbered 1,2,…,N. For each i (1≤i≤N), when Coin i is tossed, it comes up heads with probability pi and tails with probability 1−pi​ .
Taro has tossed all the N coins. Find the probability of having more heads than tails.
*/
#include<iostream>
#include<vector>
#include<climits>
#include<iomanip>
using namespace std;

vector<vector<double>> dp;
vector<double> prob;
int n;

double fUpDown(int i , int x){ //probability for x head from 0 .. to i
    if(x == 0) return 1.0;
    if(i == -1) return 0.0;
    if(dp[i][x] > -0.9) return dp[i][x]; // there is a precision issue when dealing with decimal number so == might give inaccurate result but > will work fine

    double ans = (double)prob[i] * fUpDown(i-1,x-1) + (double)(1-prob[i]) * fUpDown(i-1,x);
    return dp[i][x] = ans; 
}

int main(){
    cin>>n;
    prob.resize(n , -1);
    for(int i=0 ; i<n ; i++){
        cin>>prob[i];
    }
    dp.clear();
    dp.resize(n+1 , vector<double> ((n+1)/2 + 1 , -1));
    cout<<fixed<<setprecision(9)<<fUpDown(n-1 , (n+1)/2 )<<endl; //precesion upto 9 digits
    return 0;
}