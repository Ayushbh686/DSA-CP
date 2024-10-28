#include<iostream>
#include<array>
using namespace std;
int main(){
    int arr[] = {1,2,3,4,10,4,3,2,1};
    int n = sizeof(arr)/sizeof(arr[0]);
    int res = 0;
    for(int i = 0 ; i<n ; i++){
        res ^= arr[i];
    }
    cout<<res;
    return 0;
}
// something ^ 0 = something
// same ^ same = 0