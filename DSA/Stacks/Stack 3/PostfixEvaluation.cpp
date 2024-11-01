#include<iostream>
#include<string>
#include<stack>
using namespace std;

int solve(int val1 , int val2 , char ch){
    if(ch == '/') return val1/val2;
    if(ch == '*') return val1*val2;
    if(ch == '+') return val1+val2;
    if(ch == '-') return val1-val2;
}

int main(){
    string postfix;
    cout<<"Enter postfix Expression : ";
    cin>>postfix;
    stack<int> val;

    for(int i=0 ; i<postfix.size() ; i++){
        if(isdigit(postfix[i])){
            val.push(postfix[i] - '0');
        }
        else{
            int val2 = val.top();
            val.pop();
            int val1 = val.top();
            val.pop();
            char ch = postfix[i];
            val.push(solve(val1 , val2 , ch));
        }
    }
    
    cout<<"answer is : "<<val.top();
    return 0;
}