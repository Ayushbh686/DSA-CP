// class Solution {
// public:
//     void helper(vector<vector<int>> &finalans,vector<int>ans,int idx,int n,vector<int>& nums){
//         if(idx==n){
//             finalans.push_back(ans);
//             return ;
//         }
//         helper(finalans,ans,idx+1,n,nums);
//         ans.push_back(nums[idx]);
//         helper(finalans,ans,idx+1,n,nums);
//     } 
//     vector<vector<int>> subsets(vector<int>& nums) {
//         vector<int>ans;
//         vector<vector<int>> finalans;
//         helper(finalans,ans,0,nums.size(),nums);
//         return finalans;
//     }
// };

class Solution {
    public:
        vector<vector<int>> subsets(vector<int>& nums) {
            vector<vector<int>> result;
            int n = nums.size();
            for (int i = 0; i < (1 << n); i++) {
                vector<int> subset;
                for (int j = 0; j < n; j++) {
                    if ((i & (1 << j)) > 0) {
                        subset.push_back(nums[j]);
                    }
                }
                result.push_back(subset);
            }
            return result;
        }
    };