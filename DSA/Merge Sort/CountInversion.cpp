class Solution {
  public:
  
    int MergeAndCount(int lo , int mid , int hi , vector<int>&arr){
        vector<int>help(hi-lo+1);
        int i=lo , j=mid+1 ,  k=0 , count = 0;
        
        while(i <= mid and j <= hi){
            if(arr[i] <= arr[j]){
                help[k] = arr[i];
                k++;
                i++;
            }
            else{
                help[k] = arr[j];
                k++;
                j++;
                count += (mid - i + 1);
            }
        }
        
        while(i <= mid){
            help[k] = arr[i];
            k++;
            i++;
        }
        
        while(j <= hi){
            help[k] = arr[j];
            k++;
            j++;
        }
        
        for(int i=lo ; i<=hi ; i++){
            arr[i] = help[i-lo];
        }
        
        return count;
        
    }
  
    int MergeSort(int lo , int hi , vector<int> &arr){
        int count = 0;
        if(lo >= hi) return count;
        
        int mid = (lo + hi)/2;
        
        count += MergeSort(lo , mid , arr);
        count += MergeSort(mid+1 , hi , arr);
        count += MergeAndCount(lo , mid , hi , arr);
        
        return count;
    }
  
    int inversionCount(vector<int> &arr) {
        return MergeSort(0 , arr.size() - 1 , arr);
    }
};