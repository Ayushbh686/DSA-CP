#include<iostream>
#include<climits>
using namespace std;
// int maxm(int arr[],int n,int idx,int max){
//     if(idx==n) return max;
//     if(arr[idx]>max) max=arr[idx];
//     maxm(arr,n,idx+1,max);
// }
int maxm(int arr[],int n,int idx){
    if(idx==n-1) return arr[idx];
    return max(arr[idx],maxm(arr,n,idx+1));
}
int main(){
    int arr[]={2,7,1,9,10,5,9,11,45,34,28};
    int n=11;
    // cout<<maxm(arr,n,0,INT_MIN);
    cout<<maxm(arr,n,0);
}