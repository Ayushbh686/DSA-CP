#include<iostream>
#include<stack>
using namespace std;

int main(){
    int n ;
    cin>>n;
    int arr1[n] , arr2[n];
    for(int i=0 ; i<n ; i++){
        cin>>arr1[i];
    }
    stack<int> stk;
    arr2[0] = -1;
    stk.push(arr1[0]);
    for(int i=1 ; i<n ; i++){
        while(stk.size() > 0 and arr1[i] >= stk.top()) stk.pop(); //pop
        if(stk.size() > 0) arr2[i] = stk.top(); //ans
        else arr2[i] = -1;
        stk.push(arr1[i]);
    }

    for(int i=0 ; i<n ; i++){
        cout<<arr2[i]<<" ";
    }
    return 0;
}
//EVERYTHING SAME AS NEXT GREATER ELEMENT