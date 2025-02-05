#include<bits/stdc++.h>
using namespace std;

int findEle(vector<int>&arr , int target){
    int n = arr.size();
    int lastEle = arr[n-1];

    int i=0 , j=n-1 ;
    int idx = -1;
    int lastMid = -1 , mid;
    while(i<=j){
        lastMid = mid;
        mid = (i+j)/2;
        // if(lastMid!=mid)cout<<mid<<endl;
        if(arr[mid] == target) {
            idx = mid;
            break;
        }
        else if(arr[mid] > target){
            if(target <= lastEle and arr[mid] > lastEle){
                i = mid+1;
            }
            else{
                j = mid-1;
            }
        }
        else{
            if(target > lastEle and arr[mid] <= lastEle){
                j = mid-1;
            }
            else{
                i = mid+1;
            }
        }
    }
    return idx;
}

//2nd approach
int findEle2(vector<int>& arr, int target) {
    // Initialize two pointers, lo and hi, at the start
    // and end of the array
    int lo = 0, hi = arr.size() - 1;

    while (lo <= hi) {
        int mid = lo + (hi - lo) / 2;

        // If target found, return the index
        if (arr[mid] == target)
            return mid;

        // If Left half is sorted
        if (arr[mid] >= arr[lo]) {
          
            // If the target lies within this sorted half,
            // move the hi pointer to mid - 1
            if (target >= arr[lo] && target < arr[mid])
                hi = mid - 1;
          
            // Otherwise, move the lo pointer to mid + 1
            else
                lo = mid + 1;
        }
      
        // If Right half is sorted
        else {
          
            // If the target lies within this sorted half,
            // move the lo pointer to mid + 1
            if (target > arr[mid] && target <= arr[hi])
                lo = mid + 1;
          
            // Otherwise, move the hi pointer to mid - 1
            else
                hi = mid - 1;
        }
    }
    
      // target not found
    return -1; 
}

int main(){
    int t;
    cin>>t;
    while(t--){
        int n , target;
        cin>>n>>target;
        vector<int>arr(n);

        for(int i=0 ; i<n ; i++){
            cin>>arr[i];
        }

        cout<<findEle(arr , target)<<endl; 
        // cout<<findEle2(arr , target)<<endl; 
    }

    return 0;   
}
/*
13

13 5
15 16 19 20 25 30 35 40 1 3 5 7 10

13 6
15 16 19 20 25 30 35 40 1 3 5 7 10

13 40
15 16 19 20 25 30 35 40 1 3 5 7 10

13 45
15 16 19 20 25 30 35 40 1 3 5 7 10

13 1
15 16 19 20 25 30 35 40 1 3 5 7 10

10 7
1 2 3 4 5 6 8 9 10 11

10 13
1 2 3 4 5 6 8 9 10 11

10 -3
1 2 3 4 5 6 8 9 10 11

2 1
1 2

2 2
1 2

2 3
1 2

1 1
1

1 1
2

*/

/*
10 
-1
7
-1
8
-1
-1
-1
0
1
-1
0
-1
*/
