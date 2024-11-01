#include<iostream>
#include<stack>
using namespace std;
int main(){
    stack<int> stk;
    cout<<stk.size()<<endl;
    stk.push(10);
    stk.push(20);
    stk.push(30);
    stk.push(40);
    cout<<stk.size()<<endl;
    stk.pop();
    cout<<stk.size()<<endl;

    //displaying stack in top to bottom
    stack<int> temp;
    while(stk.size() > 0){
        cout<<stk.top()<<" ";
        temp.push(stk.top());
        stk.pop();
    }
    cout<<endl;
    //refilling stack in bottom to top order
    while(temp.size() > 0){
        cout<<temp.top()<<" ";
        stk.push(temp.top());
        temp.pop();
    }   
    //for reversing stack just use two extra stack or use one extra array

    cout<<endl<<stk.size();
    return 0;

}