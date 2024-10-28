#include<iostream>
using namespace std;
int main(){
    int arr[]={1,2,3,4,5,10,5};
    int n = sizeof(arr)/sizeof(arr[0]);
    int preSum[n];
    preSum[0]=arr[0];
    for(int i=1 ; i<n ; i++){
        preSum[i] = arr[i] + preSum[i-1];
    }
    cout<<"pefix Sum array : ";
    for(int i=0 ; i<n ; i++){
        cout<<preSum[i]<<" ";
    }
    cout<<endl;
    int idx = -1;
    for(int i=0 ; i<n ; i++){
        if(preSum[n-1] == 2*preSum[i]){  // presum for (1..x) = presum for(x+1 .. n) use formula
            idx=i;
            break;
        }
    }
    if(idx != -1) cout<<"yes it can be partiotioned after : "<<idx;
    else cout<<"cannot be partitioned ";
    return 0;
}
//try product of array lc 238