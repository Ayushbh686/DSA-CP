// leetcode 300

class Solution {
public:
    vector<vector<int>> dp;
    int n;

    int fUpDown(vector<int>& nums, int idx, int lastIdx) {
        if (idx == n) return 0;  // Base case: no more elements to pick
        if (dp[idx][lastIdx + 1] != -1) return dp[idx][lastIdx + 1];  // Already computed

        // Option 1: Not picking this element
        int ans = fUpDown(nums, idx + 1, lastIdx);

        // Option 2: Pick this element if it forms an increasing subsequence
        if (lastIdx == -1 || nums[idx] > nums[lastIdx]) {
            ans = max(ans, 1 + fUpDown(nums, idx + 1, idx));
        }

        return dp[idx][lastIdx + 1] = ans;  // Save the result in dp table
    }

    int lengthOfLIS(vector<int>& nums) {
        n = nums.size();
        dp.clear();
        dp.resize(n, vector<int>(n + 1, -1));  // DP table resized to track up to 'n' indices
        return fUpDown(nums, 0, -1);  // Start from idx 0 and with no last picked element
    }
};
//using last idx instead of last as we are making dp array and manytimes doing dp[][last] which will give out of bound as last can many times be negative 





//METHOD 2
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return 0;
        
        vector<int> dp(n, 1);  // DP array for storing LIS at each index
        int maxLength = 1;

        for (int i = 1; i < n; i++) {
            for (int j = 0; j < i; j++) {
                if (nums[i] > nums[j]) {
                    dp[i] = max(dp[i], dp[j] + 1);
                }
            }
            maxLength = max(maxLength, dp[i]);
        }

        return maxLength;
    }
};

//o(n) sc and can write the bottom up for this easily