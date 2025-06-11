class Solution {
    public:
        int maxProduct(vector<int>& arr) {
            int n = arr.size();
            int maxProd = INT_MIN;
            int prod = 1;
    
            //prefix maximum 
            for(int i=0 ; i<n ; i++){
                prod *= arr[i];
                maxProd = max(prod , maxProd);
                if(prod == 0) prod = 1;
            }
    
            prod = 1;
            //suffix maximum 
            for(int i=n-1 ; i>=0 ; i--){
                prod *= arr[i];
                maxProd = max(prod , maxProd);
                if(prod == 0) prod = 1;
            }        
    
            return maxProd;
        }
    };



//approach 2 ( striver )



#include<bits/stdc++.h>
using namespace std;

int maxProductSubArray(vector<int>& nums) {
    int prod1 = nums[0],prod2 = nums[0],result = nums[0];
    
    for(int i=1;i<nums.size();i++) {
        int temp = max({nums[i],prod1*nums[i],prod2*nums[i]});
        prod2 = min({nums[i],prod1*nums[i],prod2*nums[i]});
        prod1 = temp;
        
        result = max(result,prod1);
    }
    
    return result;
}

int main() {
    vector<int> nums = {1,2,-3,0,-4,-5};
    cout<<"The maximum product subarray: "<<maxProductSubArray(nums);
    return 0;
}


