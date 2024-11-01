class Solution {
public:
    vector<int> dp;
    int f(vector<int> nums , int i){
        if(i==nums.size() - 1) return nums[i];
        if(i==nums.size() - 2) return max(nums[i+1] ,nums[i]);
        if(dp[i] != -1) return dp[i];
        return dp[i] = max(nums[i] + f(nums , i+2) , 0 + f(nums , i+1)); // either we loot current house or not so choose max of two cases 
    }

    int fDownUp(vector<int> nums){
        int n = nums.size();
        dp[n-1] = nums[n-1];
        if(n-2 >= 0) dp[n-2] = max(nums[n-2] , nums[n-1]);
        for(int i = n-3 ; i>=0 ; i--){
            dp[i] = max(0 + dp[i+1] , nums[i] + dp[i+2]);
        }
        return dp[0];
    }

    int rob(vector<int>& nums) {
        dp.clear();
        dp.resize(nums.size(),-1);
        return fDownUp(nums);
        //return f(nums , 0); // i is state of problem means subproblem or the variable which define the subproblem
    }
};
