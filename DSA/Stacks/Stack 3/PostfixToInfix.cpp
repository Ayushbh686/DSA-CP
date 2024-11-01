#include<iostream>
#include<stack>
#include<string>
using namespace std;
 
string solve(string val1 , string val2 , char ch){
    return val1 + ch + val2;
}

int main(){
    string postfix;
    cout<<"enter the postfix expression : ";
    cin>>postfix;
    stack<string> infix;

    for(int i=0 ; i<postfix.size() ; i++){
        if(isdigit(postfix[i])){
            infix.push(string(1,postfix[i]));
        }
        else{
            string val2 = infix.top();
            infix.pop();
            string val1 = infix.top();
            infix.pop();
            char ch = postfix[i];
            infix.push(solve(val1 , val2 , ch));
        }
    }

    cout<<"infix expression is : "<<infix.top();
}
//bracket will not come when converted to infix so ans might differ