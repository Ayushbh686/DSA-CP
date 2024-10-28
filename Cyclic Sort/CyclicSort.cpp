#include<iostream>
using namespace std;
int main(){
    int arr[] = {6,5,4,3,2,1};
    int n =sizeof(arr)/sizeof(arr[0]);
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    int i=0;
    while(i<n){
        int correctIdx = arr[i]-1;
        if(correctIdx == i) i++;
        else swap(arr[i],arr[correctIdx]);
    }
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
}
//max swaps = n-1
//O(n) TC , O(1) SC works only when working with integers consecutive 1....n
// LC 268 , 287