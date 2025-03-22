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