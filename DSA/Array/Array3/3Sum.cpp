class Solution {
    public:
        vector<vector<int>> threeSum(vector<int>& nums) {
            int n = nums.size();
            sort(nums.begin(), nums.end());
            set<vector<int>> set;
            vector<vector<int>> output;
            for(int i=0; i<n-2; i++){
                int low = i+1, high = n-1;
                while(low < high){
                    if(nums[i] + nums[low] + nums[high] < 0){
                        low++;
                    }
                    else if(nums[i] + nums[low] + nums[high] > 0){
                        high--;
                    }
                    else{
                        set.insert({nums[i], nums[low], nums[high]});
                        low++;
                        high--;
                    }
                }
            }
            for(auto it : set){
                output.push_back(it);
            }
            return output;
        }
    };


//method 2(HASHING)
/*
class Solution {
public:
    void twoSum(vector<int>& nums, int idx, int target, vector<vector<int>>& ans, int x) {
        unordered_set<int> seen;  // Tracks elements in the array
        unordered_set<string> added;  // Tracks unique triplets

        for(int i = idx + 1; i < nums.size(); i++) {
            int complement = target - nums[i];
            
            if(seen.count(complement)) {
                vector<int> temp = {x, nums[i], complement};
                sort(temp.begin(), temp.end());

                // Unique triplet detection using string key
                string key = to_string(temp[0]) + "," + to_string(temp[1]) + "," + to_string(temp[2]);
                if(!added.count(key)) {
                    ans.push_back(temp);
                    added.insert(key);  // Mark as added
                }
            }

            seen.insert(nums[i]); // Add current number to set
        }
    }

    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());  // Sorting for optimized duplicate check
        vector<vector<int>> ans;

        for(int i = 0; i < nums.size(); i++) {
            if(i > 0 && nums[i] == nums[i - 1]) continue;  // Skip duplicate elements
            int target = 0 - nums[i];
            twoSum(nums, i, target, ans, nums[i]);
        }

        return ans;
    }
};
*/
