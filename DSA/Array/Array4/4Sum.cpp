// class Solution {
// public:
//     vector<vector<int>> fourSum(vector<int>& nums, int target) {
//         int n = nums.size();
//         set<vector<int>> ans; // to prevent duplicate answers
//         if(n < 4) return {{}};

//         sort(nums.begin() , nums.end()); //nlogn

//         for(int i=0 ; i<n ; i++){//n^3 logn 
//             for(int j=i+1 ; j<n ; j++){
//                 int left = j+1;
//                 int right = n-1;

//                 while(left < right and right < n){
//                     long long sum = (long long)(nums[i]) + (long long)(nums[j]) + (long long)(nums[left]) + (long long)(nums[right]);
//                     if(sum == (long long)(target)){
//                         vector<int>temp = {nums[i] , nums[j] , nums[left] , nums[right]};
//                         ans.insert(temp);
//                         left++;
//                         right--;
//                     }

//                     else if(sum > (long long)(target)) right--;
//                     else left++;
//                 }
//             }
//         }
//         vector<vector<int>> v(ans.begin() , ans.end());

//         return v;
//     } // tc = n3 logn
// };

//o(n3) this approach skips duplicates by sorting and skipping duplicates for each a , b , c , d
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int n = nums.size();
        vector<vector<int>> ans; // to prevent duplicate answers
        if(n < 4) return {};

        sort(nums.begin() , nums.end()); //nlogn

        for(int i=0 ; i<n ; i++){//n^3 logn 
            if(i>0 and nums[i] == nums[i-1]) continue; //skip duplicate i 
            for(int j=i+1 ; j<n ; j++){

                if(j > i+1 and nums[j] == nums[j-1]) continue; // skip duplicate j

                int left = j+1;
                int right = n-1;

                while(left < right and right < n){
                    long long sum = (long long)(nums[i]) + (long long)(nums[j]) + (long long)(nums[left]) + (long long)(nums[right]);
                    if(sum == (long long)(target)){
                        vector<int>temp = {nums[i] , nums[j] , nums[left] , nums[right]};
                        ans.push_back(temp);

                        left++;
                        right--;

                        while(left < right and nums[left] == nums[left-1]) left++; // skiping rest 2 duplicates
                        while(left < right and nums[right] == nums[right+1]) right--;
                    }

                    else if(sum > (long long)(target)) right--;
                    else left++;
                }
            }
        }

        return ans;
    } // tc = n3 
};

