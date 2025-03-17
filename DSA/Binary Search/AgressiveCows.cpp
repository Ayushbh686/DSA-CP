#include<bits/stdc++.h>
using namespace std;

bool check(int x , vector<int>&arr , int n , int c){
    int curr = 1 , i=1 , last = 0;
    while(i<n){
        if(arr[i]-arr[last] >= x){
            last = i;
            curr++;
        }
        i++;
    }

    return curr >= c;
}

int fn(vector<int>&arr , int n , int c){
    //sort the arr[]:
    sort(arr.begin(), arr.end());

    int low = 1, high = arr[n - 1] - arr[0];
    //apply binary search:
    while (low <= high) {
        int mid = (low + high) / 2;
        if (check(mid ,arr, n, c) == true) {
            low = mid + 1;
        }
        else high = mid - 1;
    }
    return high;
}

int main(){
    int t;
    cin>>t;
    while(t--){
        int n , c;
        cin>>n>>c;
        vector<int>arr(n);
        
        for(int i=0 ; i<n ; i++) cin>>arr[i];

        cout<<fn(arr , n , c)<<endl;

    }
    return 0;
}