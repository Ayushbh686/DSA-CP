#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int minProduct(vector<int>arr){
    int n = arr.size();
    sort(arr.begin() , arr.end());
    if(arr[0] >= 0) return arr[0];
    int prod = 1;
    int lastNeg = 0; 
    for(int i=0 ; i<n ; i++){
        if(arr[i] != 0) prod *= arr[i];
        if(i < n-1 and arr[i] < 0 and arr[i+1] >= 0) lastNeg = i;
    }
    if(prod > 0){
        prod /= arr[lastNeg];
    }
    return prod;
}

int main(){
    cout<<minProduct({-2 , -3 , 1 , 4 , -2 , -5});
    return 0;
}