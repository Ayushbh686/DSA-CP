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
    arr2[n-1] = -1;
    stk.push(arr1[n-1]);
    for(int i=n-2 ; i>=0 ; i--){
        while(stk.size() > 0 and arr1[i] >= stk.top()) stk.pop();
        if(stk.size()>0) arr2[i] = stk.top();
        else arr2[i] = -1;
        stk.push(arr1[i]);
    }

    for(int i=0 ; i<n ; i++){
        cout<<arr2[i]<<" ";
    }
    return 0;

}
//pop ans push method as first we pop element till the next greater element is achived in stack top and make that as ans otherwise no element greater that means stack size will be 0 so it will be -1 and then push this index and loop continues
//SC = O(N) TC = O(N) for pull opr + O(N) for push operation so finally O(N) even after nested loop
