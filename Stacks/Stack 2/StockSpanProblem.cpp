#include<iostream>
#include<stack>
using namespace std;

int main(){
    int n ;
    cin>>n;
    int stock[n] , span[n];
    for(int i=0 ; i<n ; i++){
        cin>>stock[i];
    }
    stack<int> stk;//Similar as previous greater element just that we store previous greater index
    span[0] = 1;
    for(int i=1 ; i<n ; i++){
        while(stk.size() > 0 and stock[i] >= stock[stk.top()]) stk.pop();
        if(stk.size() > 0) span[i] = i - stk.top();
        else span[i] = i+1;
        stk.push(i);
    }

    for(int i=0 ; i<n ; i++){
        cout<<span[i]<<" ";
    }
    return 0;
}