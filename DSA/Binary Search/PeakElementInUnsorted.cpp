class Solution {
    public:
        int findPeakElement(vector<int>& nums) {
            int n = nums.size();
            if(n==1) return 0;
    
            if(nums[0] > nums[1]) return 0;
            if(nums[n-1] > nums[n-2]) return n-1;
    
            int l = 1 , r = n-2 , mid;
    
            while(l<=r){
                mid = l + (r-l)/2;
                if(nums[mid] > nums[mid+1] and nums[mid] > nums[mid-1]) return mid;
                else if(nums[mid+1] > nums[mid]) l = mid+1; //  as here peak is sure to be in right side as at somepoint this values greater than mid will decrease and that will be our peak
                else r = mid-1;
            }
    
            return nums[mid];
        }
    };