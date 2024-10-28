#include<iostream>
#include<vector>
#include<climits>
using namespace std;

vector<int>dp;
vector<int>h;

int fUpDown(int i){
    if(i >= h.size()-1) return 0;
    if(dp[i] != -1) return dp[i];
    int ans = INT_MAX;
    for(int j=1 ; j<=2 ; j++){
        if(i+j >= h.size()) break;
        ans = min(ans , abs(h[i+j] - h[i]) + fUpDown(i+j));
    }
    return dp[i] = ans;
}

int main(){
    int n;
    cin>>n;
    dp.clear();
    dp.resize(100005 , -1);
    h.resize(n);
    for(int i=0 ; i<n ; i++){
        cin>>h[i];
    }
    cout<<fUpDown(0)<<endl;
}