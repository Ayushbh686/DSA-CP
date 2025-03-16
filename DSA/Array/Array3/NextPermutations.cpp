class Solution {
    public:
    
        void rev(vector<int>& nums , int i , int j){
            while(i<=j){
                swap(nums[i] , nums[j]);
                i++;
                j--;
            }
            return ;
        }
    
        void nextPermutation(vector<int>& nums) {
            int n = nums.size();
            int idx ;
    
            for(int i=n-1 ; i>=0 ; i--){
                if(i == 0) idx = 0;
                else if(nums[i-1] < nums[i]){
                    idx = i;
                    break;
                }
            }
            // cout<<idx<<endl;
            if(idx == 0){
                rev(nums , 0 , n-1);
                return ;
            }
    
            rev(nums , idx , n-1);
            int nextMax = 0;
            for(int i=idx ; i<=n-1 ; i++){
                if(nums[i] > nums[idx-1]){
                    nextMax = i;
                    break;
                }
            }
            swap(nums[idx-1] , nums[nextMax]);
            return ;
        }
    };