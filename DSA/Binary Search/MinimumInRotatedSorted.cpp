class Solution {
    public:
        int findMin(vector<int>& nums) {
            int n = nums.size();
            int l = 0 , r = n-1;
            if(nums[l] < nums[r]) return nums[l];
            int mid;
            while(l<=r){
                mid = l + (r-l)/2;
                cout<<nums[mid]<<endl;
                if(nums[l] < nums[r]) return nums[l];
                if(mid > 0 and mid < n-1 and nums[mid] < nums[mid+1] and nums[mid] < nums[mid-1]) return nums[mid];
                else if(nums[mid] < nums[l]) r = mid-1;
                else l = mid+1;
            }
            return nums[mid];
        }
    }; // finding always in unsorted part


//other logical method 
int findMin(vector<int>& arr) {
    int low = 0, high = arr.size() - 1;
    int ans = INT_MAX;
    while (low <= high) {
        int mid = (low + high) / 2;
        //search space is already sorted
        //then arr[low] will always be
        //the minimum in that search space:
        if (arr[low] <= arr[high]) {
            ans = min(ans, arr[low]);
            break;
        }

        //if left part is sorted:
        if (arr[low] <= arr[mid]) {
            // keep the minimum:
            ans = min(ans, arr[low]);

            // Eliminate left half:
            low = mid + 1;
        }
        else { //if right part is sorted:

            // keep the minimum:
            ans = min(ans, arr[mid]);

            // Eliminate right half:
            high = mid - 1;
        }
    }
    return ans;
}