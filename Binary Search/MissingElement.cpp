#include<iostream>
using namespace std;
int main(){
    int arr[]={1,2,3,5,6,8,10};
    int n=7;
    int lo=0;
    int hi=n-1;
    int ans=-1;
    while(hi>=lo){
        int mid=lo+(hi-lo)/2;
        if(arr[mid]==mid){
            lo=mid+1;
        }
        else{
            ans=mid;
            hi=mid-1;
        }
    }
    cout<<ans;
    return 0;
}