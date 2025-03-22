class Solution {
    public:
        void comb(vector<vector<int>> &res,vector<int> v, vector<int> candidates, int n , int idx,int target){
            if(target<0) return ;
            if(target == 0){
                res.push_back(v);
                return ;
            }
            
            for (int i =idx ; i<n ; i++){
                v.push_back(candidates[i]);
                comb(res,v,candidates,n,i,target-candidates[i]);
                v.pop_back();
            }
        }
        vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
             vector<vector<int>> res;
             vector<int> v;
             comb(res, v, candidates,candidates.size() ,0 ,target);
             return res;
        }
    };