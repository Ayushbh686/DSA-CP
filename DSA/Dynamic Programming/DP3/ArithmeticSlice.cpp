/*
leetcode 413
*/

// class Solution {
// public:
//     vector<int> dp;

//     // Recursive function with memoization to calculate slices ending at index i
//     int fTopDown(vector<int> &nums, int i) {
//         // Base case: If less than 3 elements, no slice can be formed
//         if (i < 2) return 0;

//         // If already computed, return cached result
//         if (dp[i] != -1) return dp[i];

//         // Check if nums[i-2], nums[i-1], nums[i] form an arithmetic slice
//         if (nums[i] - nums[i-1] == nums[i-1] - nums[i-2]) {
//             // If they do, count 1 slice and continue checking
//             dp[i] = 1 + fTopDown(nums, i-1);
//         } else {
//             // Otherwise, reset the count
//             dp[i] = 0;
//         }

//         return dp[i];
//     }

//     int numberOfArithmeticSlices(vector<int>& nums) {
//         int n = nums.size();
//         if (n < 3) return 0;  // Fewer than 3 elements cannot form an arithmetic slice

//         dp.clear();
//         dp.resize(n, -1);  // Initialize dp array to -1 for memoization

//         int totalSlices = 0;

//         // Start from index 2 because the minimum length of an arithmetic slice is 3
//         for (int i = 2; i < n; ++i) {
//             totalSlices += fTopDown(nums, i);
//         }

//         return totalSlices;
//     }
// };

//2 pointer
class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        if(nums.size() <= 2)return 0;
        int count = 0, ans = 0;
        for(int i = 0; i < nums.size() - 2; i++){
            if(nums[i+1] - nums[i] == nums[i+2] - nums[i+1]){
                count++;
            }
            else{
                ans += ((count * (count+1)) / 2);
                count = 0;
            }
            
        }
        if(count) ans += ((count * (count+1)) / 2);
        return ans;
    }
};