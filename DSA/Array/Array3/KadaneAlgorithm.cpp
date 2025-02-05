#include<bits/stdc++.h>
using namespace std;

int KadaneAlgo(vector<int>&arr){
    int n = arr.size();
    int maxSum = 0 , currSum = 0;

    for(int i=0 ; i<n ; i++){
        currSum += arr[i];
        //take the maximum subaary sum till now
        maxSum = max(currSum , maxSum);
        //reset it if the sum gets less than 0 so we restart array
        if(currSum < 0) currSum = 0;
    }
    return maxSum;
}

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int>arr(n);
        for(int i=0 ; i<n ; i++){
            cin>>arr[i];
        }
        cout<<KadaneAlgo(arr)<<endl;
    }
    return 0;
}

/*
5

5        
1 2 3 4 5

6
2 3 -2 -1 7 -1 

6
2 3 -4 -1 6 -1 

5
-5 -4 -1 -3 -2 

6
2 3 -6 7 -6 1

*/