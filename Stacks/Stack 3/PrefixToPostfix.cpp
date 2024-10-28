#include<iostream>
#include<string>
#include<stack>
using namespace std;

string solve(string val1 , string val2 , char ch){
    return val1 + val2 + ch;
}

int main(){
    string prefix;
    cout<<"Enter prefix Expression : ";
    cin>>prefix;
    stack<string> postfix;
    //traverse ulta
    for(int i=prefix.size()-1 ; i>=0 ; i--){
        if(isdigit(prefix[i])){
            postfix.push(string(1,prefix[i]));
        }
        else{
            string val1 = postfix.top();    //ordering of val1 and val2 changed as we traverese ulta
            postfix.pop();
            string val2 = postfix.top();
            postfix.pop();
            char ch = prefix[i];
            postfix.push(solve(val1 , val2 , ch));
        }
    }
    
    cout<<"answer is : "<<postfix.top();
    return 0;
}
