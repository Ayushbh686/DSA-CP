//duplicate elements allowed
class Solution {
    public:
        bool search(vector<int>& nums, int t) {
            int n = nums.size();
            int l = 0 , r = n-1;
    
            while(l<=r){
                int mid = l + (r-l)/2;
                if(nums[mid] == t) return true;
                else if(nums[l] == nums[mid] and nums[mid] == nums[r]) {
                    l++;
                    r--;
                }
                else if(nums[l] <= nums[mid]){
                    if(nums[l] <= t and t <= nums[mid]) r = mid-1;
                    else l = mid+1;
                }
                else{
                    if(nums[mid] <= t and t <= nums[r]) l = mid+1;
                    else r = mid-1;
                }
            }
    
            return false;
        }
    };