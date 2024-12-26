#include<bits/stdc++.h>
using namespace std;
#define mod 1000000007

int n;
vector<vector<int>>c;
int dp[22][1<<22];

int f(int i, int mask){// how many combinations for i...n mans with mask giving set of women available
    if(i==n+1){
        if(mask == 0) return 1; //no girl remaning means possible combination 
        return 0;
    }
    
    if(dp[i][mask] != -1) return dp[i][mask];
    int ans = 0;
    for(int w=1 ; w<=n ; w++){
        bool available = ((( 1 << (w-1)) & mask) == 0) ? 0 : 1; // tells if wth bit on or off
        if(available && c[i][w]){ //if women available and compatible with ith man
            ans = ((ans % mod) + ( f(i+1 , mask ^ (1 << (w-1))) % mod)) % mod ; // in f we are setting wth bit off by doing exor operation on it
        }
    }
    return dp[i][mask] = ans;
}

int main(){
    cin>>n;
    c.resize(n+1 , vector<int> (n+1)); //1 based indexing

    for(int i=1 ; i<=n ; i++){
        for(int j=1 ; j<=n ; j++){
            cin>>c[i][j];
        }
    }
    memset(dp , -1 , sizeof(dp));
    cout<<f(1, (1<<n) - 1)<<endl; 

    return 0;
}
/*
// 1 1 1 ... n times = 2^n - 1 so (1<<n) - 1 as it acts as mask which means i th bit tells us wheather ith women is available or not , so we do not required to make a set for it and can be represented as a int or string and its easy to ceate dp for this also like dp[n][2^n-1] which we cant do for sets
*/