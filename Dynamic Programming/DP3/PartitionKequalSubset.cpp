/*
leetcode 698
*/

class Solution {
public:
    vector<bool> visited;
    int n, subsetSum;

    bool fUpDown(vector<int>& nums, int idx, int currSum, int k) {
        if (k == 0) return true;  // All subsets have been formed
        if (currSum == subsetSum) return fUpDown(nums, 0, 0, k - 1);  // Form the next subset
        if (currSum > subsetSum) return false;  // Exceeded the subset target

        for (int i = idx; i < n; i++) {
            if (!visited[i] && currSum + nums[i] <= subsetSum) {
                visited[i] = true;
                if (fUpDown(nums, i + 1, currSum + nums[i], k)) return true;
                visited[i] = false;  // Backtrack
            }
        }
        return false;
    }

    bool canPartitionKSubsets(vector<int>& nums, int k) {
        n = nums.size();
        int sum = 0;
        for (int num : nums) sum += num;
        if (sum % k != 0) return false;

        subsetSum = sum / k;
        visited.resize(n, false);
        sort(nums.rbegin(), nums.rend());  // Optimization: try larger elements first
        if (nums[0] > subsetSum) return false;  // Immediate fail if any single element is too large

        return fUpDown(nums, 0, 0, k);
    }
};
//another solution with dp + bitmasking 