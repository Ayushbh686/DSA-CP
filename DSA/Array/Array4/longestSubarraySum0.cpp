class Solution {
  public:
    int maxLength(vector<int>& arr) {
        int n = arr.size();
        
        vector<int>pref;
        pref.push_back(arr[0]);
        
        for(int i=1 ; i<n ; i++){
         pref.push_back(pref[i-1] + arr[i]);
        //  cout<<pref[i-1]<<" ";
        }
        // cout<<pref[n-1]<<endl;
        int ans = 0;
        unordered_map<int , int> mp;
        mp[0] = -1;
        
        for(int i=0 ; i<pref.size() ; i++){
            if(mp.find(pref[i]) == mp.end()){
                mp[pref[i]] = i;
                continue;
            } 
            // cout<<pref[i]<<" -> "<<mp[pref[i]]<<" "<<i<<endl;
            ans = max(ans , i - mp[pref[i]]);
            
        }
        
        return ans;
    }
};