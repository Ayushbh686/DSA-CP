/*
leetcode 368
*/
// class Solution {
// public:
//     vector<int> largestDivisibleSubset(vector<int>& nums) {
//         int n = nums.size();
//         if (n == 0) return {};

//         // Sort the array to ensure each element is divisible by previous ones in the subset
//         sort(nums.begin(), nums.end());
        
//         // dp[i] will store the size of the largest divisible subset ending with nums[i]
//         vector<int> dp(n, 1);
//         vector<int> previous(n, -1);  // To keep track of the subset elements
//         int maxSubsetSize = 1, maxSubsetIndex = 0;

//         for (int i = 1; i < n; i++) {
//             for (int j = 0; j < i; j++) {
//                 if (nums[i] % nums[j] == 0 && dp[i] < dp[j] + 1) {
//                     dp[i] = dp[j] + 1;
//                     previous[i] = j;
//                 }
//             }
//             if (dp[i] > maxSubsetSize) {
//                 maxSubsetSize = dp[i];
//                 maxSubsetIndex = i;
//             }
//         }

//         // Reconstruct the largest divisible subset
//         vector<int> largestSubset;
//         for (int i = maxSubsetIndex; i >= 0; i = previous[i]) {
//             largestSubset.push_back(nums[i]);
//             if (previous[i] == i) break;  // End of path
//         }
        
//         reverse(largestSubset.begin(), largestSubset.end());  // To maintain ascending order
//         return largestSubset;
//     }
// };

// top down approach
class Solution {
public:
    vector<int> nums;
    vector<vector<int>> dp; // dp[i] stores the largest subset ending at index i

    // Helper function to find the largest divisible subset ending at index 'i'
    vector<int> findLargestSubset(int i) {
        if (!dp[i].empty()) return dp[i];  // Return if already computed

        vector<int> maxSubset;
        for (int j = 0; j < i; ++j) {
            // Check if nums[i] is divisible by nums[j] and find the largest subset ending at j
            if (nums[i] % nums[j] == 0) {
                vector<int> subset = findLargestSubset(j);
                if (subset.size() > maxSubset.size()) {
                    maxSubset = subset;
                }
            }
        }

        // Add nums[i] to the largest subset ending at 'i'
        maxSubset.push_back(nums[i]);
        return dp[i] = maxSubset;  // Memoize the result
    }

    vector<int> largestDivisibleSubset(vector<int>& nums) {
        this->nums = nums;
        int n = nums.size();
        if (n == 0) return {};

        // Sort to ensure divisibility condition in increasing order
        sort(this->nums.begin(), this->nums.end());
        
        dp.resize(n);  // Initialize dp array

        vector<int> largestSubset;
        for (int i = 0; i < n; ++i) {
            vector<int> subset = findLargestSubset(i);
            if (subset.size() > largestSubset.size()) {
                largestSubset = subset;
            }
        }
        
        return largestSubset;
    }
};