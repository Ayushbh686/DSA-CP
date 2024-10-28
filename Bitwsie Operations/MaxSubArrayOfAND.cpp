#include<iostream>
using namespace std;
int main(){
    int arr[] = {12,3,6,4,6,6,14,7,13,13,13,12};
    int n = 12;
    int i =0, j = 0;
    int len = 0 , maxEle = INT32_MIN;
    while(j<n){
        if(arr[j] >= maxEle) {
            maxEle = arr[j];
            j++;
            len = j-i;
        }
        else{
            j++;
            i=j;
        }
    }
    cout<<len;
    return 0;
}