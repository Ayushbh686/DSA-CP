/*
Given an array of integers nums containing n + 1 integers where each integer is in the range [1, n] inclusive.

There is only one repeated number in nums, return this repeated number.

You must solve the problem without modifying the array nums and using only constant extra space.
*/
//do not use exor as possible case can be {3 3 3 3 3}
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int slow = nums[0];
        int fast = nums[0];
        do {
            slow = nums[slow];
            fast = nums[nums[fast]];
        } while (slow != fast);
        fast = nums[0];
        while (slow != fast) {
            slow = nums[slow];
            fast = nums[fast];
        }
        return slow;
    }
    //like linkedlist cycle 
};
/*
// like the cyclic sorting
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int n=nums.size();
        int i =0;
        while(i<n){
            int correctIdx=nums[i]-1;
            if(correctIdx == i) i++;
            else if(nums[correctIdx] == nums[i]) return nums[i];
            else swap(nums[correctIdx] , nums[i]);
        }
        return nums[n-1];
    }
};
*/