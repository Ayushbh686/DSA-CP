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

int main(){
    stack<int> stk;
    stk.push(10);
    stk.push(20);
    stk.push(30);
    stk.push(40);
    stk.push(50);
    display(stk);
    //method 1 using 2 stack
    stack<int> temp1 , temp2;
    while(stk.size() > 0){
        temp1.push(stk.top());
        stk.pop();
    }
    while(temp1.size()>0){
        temp2.push(temp1.top());
        temp1.pop();
    }
    while(temp2.size() > 0){
        stk.push(temp2.top());
        temp2.pop();
    }
    display(stk);
    
}
// alternative - use ll or array for same task