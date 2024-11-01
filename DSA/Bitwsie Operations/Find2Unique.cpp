//#include<bits/stdc++.h>
#include<iostream>
#include<cmath>
using namespace std;

void find_2_unique(int arr[] , int n){
    int res = 0;
    for(int i=0 ; i<n ; i++){
        res ^= arr[i];
    }
    //find the first set bit position of the res (a^b) then at that position one of a or b will have its set bit
    int temp = (res & res-1) ^ res; //gives 2^k
    int k = log2(temp);
    int res2 = 0;
    for(int i=0 ; i<n ; i++){
        if((arr[i] >> k) & 1 == 1) res2 ^= arr[i]; //getiing the product of all with its set bit at k position so only a will be res2 as only it will be unique in product
    }
    cout<<res2<<" ";// a
    res = res ^ res2;  // if a^b = c then a^c = b
    cout<<res;  // b
    return;
}

int main(){
    int arr[] = {1,2,3,4,5,4,3,2,1,6};
    int n = sizeof(arr)/sizeof(arr[0]);
    find_2_unique(arr, n);
    return 0;
}