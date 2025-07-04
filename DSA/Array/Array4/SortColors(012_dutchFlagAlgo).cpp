// When arr[mid] == 0, we swap with arr[lo] and move both lo and mid forward because everything before lo is already sorted as 0’s, and the swapped element at mid is definitely not a 0.
// But for arr[mid] == 2, after swapping with arr[hi], we only move hi back. Why? Because the swapped value at mid could be 0, 1, or 2—we haven’t checked it yet! So, we need to process mid again.

class Solution {
public:
    void sortColors(vector<int>& nums) {
        //dutch flag solution
        int lo=0;
        int mid=0;
        int n = nums.size();
        int hi=n-1;
        while(mid<=hi){
            if(nums[mid]==2){
                swap(nums[mid],nums[hi]);
                hi--;
            }
            else if(nums[mid]==0){
                swap(nums[mid],nums[lo]);
                lo++;
                mid++;
            }
            else if(nums[mid]==1){
                mid++;
            }
        }
    }
};