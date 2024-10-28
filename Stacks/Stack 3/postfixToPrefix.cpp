#include<iostream>
#include<stack>
#include<string>
using namespace std;
 
string solve(string val1 , string val2 , char ch){
    return ch + val1 + val2;
}

int main(){
    string postfix;
    cout<<"enter the postfix expression : ";
    cin>>postfix;
    stack<string> prefix;

    for(int i=0 ; i<postfix.size() ; i++){
        if(isdigit(postfix[i])){
            prefix.push(string(1,postfix[i]));
        }
        else{
            string val2 = prefix.top();
            prefix.pop();
            string val1 = prefix.top();
            prefix.pop();
            char ch = postfix[i];
            prefix.push(solve(val1 , val2 , ch));
        }
    }

    cout<<"prefix expression is : "<<prefix.top();
}
//bracket will not come when converted to prefix so ans might differ