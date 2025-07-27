class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
    
    //method 1 (pref sum)
    //     int n = nums.size();
    //     vector<int>pref ;
    //     int sum = 0;
    //     for(int i=0 ; i<n ; i++){
    //         sum += nums[i];
    //         pref.push_back(sum);
    //     }
    //     int count = 0;
    //     for(int i=0 ; i<n ; i++){
    //         for(int j=-1 ; j<i ; j++){
    //             if(j == -1 and pref[i] == k) count++; 
    //             else if(j != -1 and pref[i] - pref[j] == k) count++;
    //         }
    //     }
    //     return count;
    //alt if positive elements = nlogn => go in prefix arrays and if pref[i] < k continue and if == k count ++ and if > k search in previous part of array of k - ele by binary search

        //method 2 (hashmap)
        int n = nums.size();
        unordered_map<int , int> mp; //pref , feq
        //making prefix sum
        for(int i=1 ; i<n ; i++){
            nums[i] += nums[i-1];
        }    
        int count = 0;
        for(int i=0 ; i<n ; i++){
            if(nums[i] == k){
                count++;
            }
            int rem = nums[i] - k;
            if(mp.find(rem) != mp.end()) count += mp[rem];
            mp[nums[i]]++;
        }
        return count;
    }
};