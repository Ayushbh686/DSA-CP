/*
leetcode 96
*/
class Solution {
public:

    vector<int> dp;

    int fUpDown(int n){
        if(n==0 or n==1) return 1;
        if(n==2) return 2;
        if(dp[n] != -1) return dp[n];

        int ans = 0;
        for(int i=1 ; i<=n ; i++){ //making ith node as root node
            ans += fUpDown(i-1)*fUpDown(n-i); // arranging remaing nodes into subtree
        }
        return dp[n] = ans;
    }

    int numTrees(int n) {
        // dp.clear();
        // dp.resize(n+1 , -1);
        // return fUpDown(n);

        //fDownTop
        dp.clear();
        dp.resize(n+1 , 0);
        dp[0] = 1;
        dp[1] = 1;
        for(int i=2 ; i<=n ; i++){
            dp[i] = 0;
            for(int j=1 ; j<=i ; j++){
                dp[i] += dp[j-1]*dp[i-j];
            }
        }
        return dp[n];
    }
};
//type of catalyn number :- leetcode 96 