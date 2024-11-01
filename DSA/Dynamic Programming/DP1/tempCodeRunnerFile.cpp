int fDownTop(int sum){
//     dp.clear();
//     dp.resize(sum+1 , -2);
//     if(sum == 0) return 0;
//     dp[0] = 0;
//     for(int n=1 ; n<=sum ; n++){
//         int result = INT_MAX;
//         for(int i=0 ; i<coins.size() ; i++){
//             if(n-coins[i] < 0) continue; 
//             result = min(result , dp[n-coins[i]]);
//         }
//         if(result == INT_MAX) dp[n] = INT_MAX;
//         else dp[n] = 1 + result;
//     }
//     return dp[sum];
// }