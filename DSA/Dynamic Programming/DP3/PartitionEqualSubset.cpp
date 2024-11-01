/*
leetcode 416
*/

class Solution {
public:

    vector<vector<int>> dp;

    bool fUpDown(vector<int>& nums , int i , int k){ // is there a subset in i..n-1 for sum k
        if(k==0) return true;
        if(i==nums.size()) return false;
        if(dp[i][k] != -1) return dp[i][k];

        if(nums[i] <= k){
            //include or exclude 
            return dp[i][k] = fUpDown(nums , i+1 , k-nums[i]) or fUpDown(nums , i+1 , k);
        }
        else {
            // always exclude no other option
            return dp[i][k] = fUpDown(nums , i+1 , k);
        }
        return false;
    }

    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int s = 0;
        for(int i=0 ; i<nums.size() ; i++) s += nums[i];
        if(s%2 != 0) return false;
        // dp.clear();
        // dp.resize(n+1 , vector<int> (s/2+1 , -1));
        //return fUpDown(nums , 0 , s/2);

        //fDownTop
        dp.clear();
        dp.resize(n+1 , vector<int>(s/2 + 2 , 0));
        for(int i=n-1 ; i>=0 ; i--) dp[i][0] = true;
        for(int i=n-1 ; i>=0 ; i--){
            for(int k=1 ; k <= s/2 ; k++){
                if(nums[i] <= k){
                    //include or exclude 
                    dp[i][k] = dp[i+1][k-nums[i]] or dp[i+1][k];
                }
                else {
                    // always exclude no other option
                    dp[i][k] = dp[i+1][k];
                }
            }
        }
        return dp[0][s/2];
    }
};