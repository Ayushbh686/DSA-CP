#include<bits/stdc++.h>
using namespace std;

bool rec(int i , string s , unordered_set<string>dict_set , vector<int>&dp){
    int n = s.size();

    if(i >= n) return true;
    if(dp[i] != -1) return dp[i];

    string str = "";
    for(int idx = i ; idx < n ; idx++){
        str += s[idx];
        if(dict_set.find(str) != dict_set.end() && rec(idx+1 , s , dict_set , dp)){
            return dp[i] = true;
        }
    }

    return dp[i] = false;
}

bool wordBreak(string s , vector<string>&dict){
    int n = s.size();

    unordered_set<string>dict_set(dict.begin() , dict.end());

    vector<int>dp(n , -1);
    
    return rec(0 , s , dict_set , dp);
}

int main(){
    string s;
    cin>>s;

    int n;
    cin>>n;
    vector<string>dict(n);
    for(int i=0 ; i<n ; i++){
        cin>>dict[i];
    }
    
    cout<<wordBreak(s , dict)<<endl;

    return 0;
}
//tc = o(n2) and sc = o(n)