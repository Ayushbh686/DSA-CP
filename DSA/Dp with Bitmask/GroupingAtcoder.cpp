#include<bits/stdc++.h>
using namespace std;

int n;
vector<long long> dp; //storing maximum sum for grouping for different possible sets
vector<long long> sum; //storing sums of different possible combination of available sets
vector<vector<long long>>comp;

void precomputeSums() {
    int total_masks = (1 << n);
    sum.assign(total_masks, 0);

    for (int mask = 0; mask < total_masks; mask++) {
        for (int i = 0; i < n; i++) {
            if ((mask & (1 << i)) == 0) continue;
            for (int j = i + 1; j < n; j++) {
                if ((mask & (1 << j)) == 0) continue;
                sum[mask] += comp[i][j];
            }
        }
    }
}

long long f(int mask){
    if(mask == 0) return 0;
    if(dp[mask] != LLONG_MIN) return dp[mask];
    
    for(int g = mask ; g != 0 ; g = ((g-1) & mask) ){ // to genrate all possible combinations for available bits in mask
        dp[mask] = max(dp[mask] , sum[g] + f(mask ^ g));  // exor means subtraction        
    }
    return dp[mask] ;
}

int main(){
    cin>>n;
    comp.resize(n,vector<long long>(n));
    for(int i=0 ; i<n ; i++){
        for(int j=0 ; j<n ; j++){
            cin>>comp[i][j];
        }
    }
    dp.assign(1<<n, LLONG_MIN);
    precomputeSums();
    cout<<f((1<<n) - 1)<<endl;
    return 0;
}