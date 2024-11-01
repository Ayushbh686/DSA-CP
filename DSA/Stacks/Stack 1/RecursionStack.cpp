#include<iostream>
#include<stack>
using namespace std;

void displayRec(stack<int> stk){
    if(stk.size()==0) return;
    //cout<<stk.top()<<" "; //for reverse printing (top to bottom)
    int x = stk.top();
    stk.pop();
    displayRec(stk);
    //stk.push(x); // required when stack is passed by reference and its required to maintain the stack
    cout<<x<<" "; //for bottom to top printing
    return;
}

void pushAtBottom(stack<int> &stk , int val){
    if(stk.size() == 0){
        stk.push(val);
        return;
    }
    int x = stk.top();
    stk.pop();
    pushAtBottom(stk , val);
    stk.push(x);
    return;
}

void ReverseStack(stack<int> &stk){
    if(stk.size() == 1) return;
    int x = stk.top();
    stk.pop();
    ReverseStack(stk);
    pushAtBottom(stk , x);
    return;
}

int main(){
    stack<int> stk;
    stk.push(10);
    stk.push(20);
    stk.push(30);
    stk.push(40);
    stk.push(50);
    displayRec(stk);
    cout<<endl;
    pushAtBottom(stk , 5);
    displayRec(stk);
    cout<<endl;
    ReverseStack(stk);
    displayRec(stk);
    cout<<endl;
}
//stack underflow is for doing top and pop operation for empty stack
