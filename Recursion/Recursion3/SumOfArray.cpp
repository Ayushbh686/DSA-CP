#include<iostream>
using namespace std;
int sum( int arr[], int n , int idx){
    if( idx == n-1) return arr[idx];
    return arr[idx] + sum( arr, n , idx+1);
}
int main(){
    int arr[]={2,7,1,9,10,5,9,11,45,34,28};
    int n=sizeof(arr)/sizeof(arr[0]);
    cout<<sum(arr, n , 0);
}