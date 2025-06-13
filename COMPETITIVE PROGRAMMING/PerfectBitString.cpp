/*
https://codeforces.com/contest/2118/problem/A
*/

#include<bits/stdc++.h>
using namespace std;

string fn(int n , int ones , int zeros){
    string s = "";
    for(int i=0 ; i<ones ; i++) s += '1';
    for(int i=0 ; i<zeros ; i++) s += '0';
    return s;
}

int main(){
    int t;
    cin>>t;
    while(t--){
        int n , k;
        cin>>n>>k;
        cout<<fn(n , k , n-k)<<endl;
    }
    return 0;
}