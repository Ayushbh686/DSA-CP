class Solution {

  public:
    
    int sumTotal = 0;
    
    //return minSumDiff from i...n index with accumulated sum of first subset as sumA
    int f(int i , int sumA , vector<int>&arr , vector<vector<int>>&dp){
        int n = arr.size();
        if(i>=n) return abs((sumTotal - sumA) - sumA); //abs(sumB - sumA)
        
        if(dp[i][sumA] != -1) return dp[i][sumA];
        
        int ans1 , ans2;
        
        //include arr[i] in A:-
        ans1 = f(i+1 , sumA + arr[i] , arr , dp);
        
        //include arr[i] in B:-
        ans2 = f(i+1  , sumA , arr , dp);

        
        return dp[i][sumA] = min(ans1 , ans2);

    }
  
    int minDifference(vector<int>& arr) {
        int n = arr.size();
        sumTotal = accumulate(arr.begin() , arr.end() , 0);
        vector<vector<int>>dp(n , vector<int>(sumTotal , -1));
        return f(0 , 0 , arr , dp);
    }
};
