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
    
}