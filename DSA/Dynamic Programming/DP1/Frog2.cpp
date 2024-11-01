#include<iostream>
#include<vector>
#include<climits>
using namespace std;

vector<int> dp;
vector<int> h;
int k;

int f(int i) {
    if (i == h.size() - 1) return 0;
    if (dp[i] != -1) return dp[i];

    int ans = INT_MAX;
    for (int j = 1; j <= k; j++) {
        if (i + j < h.size()) {
            ans = min(ans, abs(h[i] - h[i + j]) + f(i + j));
        }
    }
    return dp[i] = ans;
}

int fDownUp(){
    dp.clear();
    dp.resize(100005,INT_MAX);
    dp[n-1] = 0;
    for(int i = h.size()-1 ; i >= 0 ; i--){
        for(int j = 1 ; j <= k ; j++){
            if(i+j >= h.size()) break;
            dp[i] = min(dp[i] , abs(h[i+j]-h[i]) + dp[i+j]);
        }
    }
    return dp[0];
}

int main() {
    int n;
    cin >> n >> k;
    h.resize(n);
    dp.resize(n, -1);  // Resize dp to match the size of the input n
    for (int i = 0; i < n; i++) {
        cin >> h[i];
    }
    //cout<<f(0)<<endl;
    cout<<fDownUp()<<endl;
    return 0;
}
