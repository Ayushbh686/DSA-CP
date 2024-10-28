#include<iostream>
#include<stack>
using namespace std;

void display(stack<int> stk){
    //displaying 
    stack<int> temp1;
    while(stk.size() > 0){
        temp1.push(stk.top());
        stk.pop();
    }
    cout<<endl;
    //refilling stack and displaying in bottom to top order
    while(temp1.size() > 0){
        cout<<temp1.top()<<" ";
        stk.push(temp1.top());
        temp1.pop();
    }   
}

void pushAtBottom(stack<int>& stk , int val){
    stack<int>temp;
    while(stk.size()>0){
        temp.push(stk.top());
        stk.pop();
    }
    stk.push(val);
    while(temp.size()>0){
        stk.push(temp.top());
        temp.pop();
    }
    return;
}

void pushAtIdx(stack<int>&stk , int val , int idx){
    stack<int> temp;
    while(stk.size() > idx){
        temp.push(stk.top());
        stk.pop();
    }
    stk.push(val);
    while(temp.size()>0){
        stk.push(temp.top());
        temp.pop();
    }
    return;
}


int main(){
    stack<int> stk;
    stk.push(10);
    stk.push(20);
    stk.push(30);
    stk.push(40);
    stk.push(50);
    display(stk);
    pushAtBottom(stk , 5);
    display(stk);
    pushAtIdx(stk,25,2);
    display(stk);
}