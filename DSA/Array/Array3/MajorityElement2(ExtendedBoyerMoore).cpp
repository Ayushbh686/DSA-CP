class Solution {
public:
    //sorting O(NlogN)
    // vector<int> majorityElement(vector<int>& nums) {
    //     int n = nums.size();

    //     sort(nums.begin() , nums.end());
    //     vector<int>ans;
    //     int count = 1;

    //     for(int i=0 ; i<n ; i++){

    //         if(i>0 and nums[i] != nums[i-1]){
    //             // if(count > n/3) ans.push_back(nums[i]);
    //             count = 1;
    //         }
            
    //         if(i>0 and nums[i] == nums[i-1]) count++;

    //         if(count > n/3 ){ //directly jump to next element to prevent same element getting pushed multiple time 
    //             ans.push_back(nums[i]);
    //             int x = nums[i] , j;
    //             for(j=i ; j<n ; j++){
    //                 if(nums[j] != x) break;
    //             }
    //             i = j-1;
    //         }
    //     }

    //     return ans;
    // }


    //boyer moore algo O(N) tc and O(1) SC
    vector<int> majorityElement(vector<int>& nums) {
        int n = nums.size();

        int el1 = INT_MIN , el2 = INT_MIN;
        int cnt1 = 0 , cnt2 = 0;

        for(int i=0 ; i<n ; i++){
            if(cnt1 == 0 and el2 != nums[i]){
                el1 = nums[i];
                cnt1++;
            }
            else if(cnt2 == 0 and el1 != nums[i]){
                el2 = nums[i];
                cnt2++;
            }
            else if(nums[i]== el1){
                cnt1++;
            }
            else if(nums[i]== el2){
                cnt2++;
            }
            else {
                cnt1--;
                cnt2--;
            }
        }

        vector<int> ls; // list of answers

        // Manually check if the stored elements in
        // el1 and el2 are the majority elements:
        cnt1 = 0, cnt2 = 0;
        for (int i = 0; i < n; i++) {
            if (nums[i] == el1) cnt1++;
            if (nums[i] == el2) cnt2++;
        }

        int mini = int(n / 3) + 1;
        if (cnt1 >= mini) ls.push_back(el1);
        if (cnt2 >= mini) ls.push_back(el2);

        // Uncomment the following line
        // if it is told to sort the answer array:
        // sort(ls.begin(), ls.end()); //TC --> O(2*log2) ~ O(1);

        return ls;

    }
};