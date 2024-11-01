#include<iostream>
#include<climits>
using namespace std;
int main(){
    int arr[] = {7,1,2,5,8,4,9,3,6};
    int n = sizeof(arr)/sizeof(arr[0]);
    int k = 3;
    int i = 1 , j = k , maxIdx = 0 ;
    int currSum = 0;
    for(int w=0 ; w<k ; w++){
        currSum += arr[w];
    }
    int maxSum = currSum;
    //SLIDING WINDOW
    while(j<n){
        currSum = currSum + arr[j] - arr[i-1];
        //int maxSum = max(currSum , maxSum);
        if(maxSum < currSum ) {
            maxIdx = i ;
            maxSum = currSum ;
        }
        i++;
        j++;
    }
    //TC == O(n+k-1 + k) == O(n-1) == O(n)
    cout<<maxSum<<endl<<maxIdx;
}