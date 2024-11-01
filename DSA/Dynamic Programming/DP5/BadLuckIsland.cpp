/*
The Bad Luck Island is inhabited by three kinds of species: r rocks, s scissors and p papers. At some moments of time two random individuals meet (all pairs of individuals can meet equiprobably), and if they belong to different species, then one individual kills the other one: a rock kills scissors, scissors kill paper, and paper kills a rock. Your task is to determine for each species what is the probability that this species will be the only one to inhabit this island after a long enough period of time.
codeforces-D
*/
#include<iostream>
#include<vector>
#include<climits>
#include<iomanip>
#include<cstring>
using namespace std;

double dp[105][105][105];

double fUpDownR(int r , int s , int p){
    if(r==0) return 0.0;
    if(p==0) return 1.0;
    if(s==0) return 0.0;
    if(dp[r][s][p] > -0.9) return dp[r][s][p];

    double ans = 0;
    ans += ((1.0*r*s)/((1.0)*(r*s + s*p + p*r))) * fUpDownR(r , s-1 , p);
    ans += ((1.0*p*s)/((1.0)*(r*s + s*p + p*r))) * fUpDownR(r , s , p-1);
    ans += ((1.0*r*p)/((1.0)*(r*s + s*p + p*r))) * fUpDownR(r-1 , s , p);

    return dp[r][s][p] = ans;
}

double fUpDownS(int r , int s , int p){
    if(r==0) return 1.0;
    if(p==0) return 0.0;
    if(s==0) return 0.0;
    if(dp[r][s][p] > -0.9) return dp[r][s][p];

    double ans = 0;
    ans += ((1.0*r*s)/((1.0)*(r*s + s*p + p*r))) * fUpDownS(r , s-1 , p);
    ans += ((1.0*p*s)/((1.0)*(r*s + s*p + p*r))) * fUpDownS(r , s , p-1);
    ans += ((1.0*r*p)/((1.0)*(r*s + s*p + p*r))) * fUpDownS(r-1 , s , p);

    return dp[r][s][p] = ans;
}

double fUpDownP(int r , int s , int p){
    if(r==0) return 0.0;
    if(p==0) return 0.0;
    if(s==0) return 1.0;
    if(dp[r][s][p] > -0.9) return dp[r][s][p];

    double ans = 0;
    ans += ((1.0*r*s)/((1.0)*(r*s + s*p + p*r))) * fUpDownP(r , s-1 , p);
    ans += ((1.0*p*s)/((1.0)*(r*s + s*p + p*r))) * fUpDownP(r , s , p-1);
    ans += ((1.0*r*p)/((1.0)*(r*s + s*p + p*r))) * fUpDownP(r-1 , s , p);

    return dp[r][s][p] = ans;
}

int main(){
    int r ,s , p;
    cin>>r>>s>>p;
    memset(dp , -1 , sizeof dp);
    cout<<fixed<<setprecision(9)<<fUpDownR(r , s , p)<<" ";
    memset(dp , -1 , sizeof dp);
    cout<<fixed<<setprecision(9)<<fUpDownS(r , s , p)<<" ";
    memset(dp , -1 , sizeof dp);
    cout<<fixed<<setprecision(9)<<fUpDownP(r , s , p)<<" ";
    return 0;
}