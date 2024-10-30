/*
leetcode 718
*/
class Solution {
public:

    vector<vector<int>> dp;
    int n1 , n2;
    int res = 0;

    int fUpDown(vector<int>& nums1 , vector<int>& nums2 , int i , int j){ //max length of subarr from i to n1 and j to n2 and starting with i and j
        if(i==n1 or j==n2) return 0;
        if(dp[i][j] != -1) return dp[i][j];

        int ans = 0;
        if(nums1[i] == nums2[j]) {
            ans = 1 + fUpDown(nums1 , nums2 , i+1 , j+1);
            res = max(ans , res);
        }
        fUpDown(nums1 , nums2 , i+1 , j);
        fUpDown(nums1 , nums2 , i , j+1);
        return dp[i][j] = ans;
    }

    int findLength(vector<int>& nums1, vector<int>& nums2) {
        n1 = nums1.size();
        n2 = nums2.size();
        // dp.clear();
        // dp.resize(n1+1 , vector<int>(n2+1 , -1));
        // fUpDown(nums1 , nums2 , 0 , 0);

        //fDownTop
        dp.clear();
        dp.resize(n1+1 , vector<int>(n2+1 , 0));
        for(int i=n1-1 ; i>=0 ; i--){
            for(int j=n2-1 ; j>=0 ; j--){
                int ans = 0;
                if(nums1[i] == nums2[j]) {
                    ans = 1 + dp[i+1][j+1];
                    res = max(ans , res);
                }   
                dp[i][j] = ans;
            }
        }
        return res;
    }
};