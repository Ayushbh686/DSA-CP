#include<iostream>
#include<string>
#include<stack>
using namespace std;

string solve(string val1 , string val2 , char ch){
    return val1 + ch + val2;
}

int main(){
    string prefix;
    cout<<"Enter prefix Expression : ";
    cin>>prefix;
    stack<string> infix;
    //traverse ulta
    for(int i=prefix.size()-1 ; i>=0 ; i--){
        if(isdigit(prefix[i])){
            infix.push(string(1,prefix[i]));
        }
        else{
            string val1 = infix.top();    //ordering of val1 and val2 changed as we traverese ulta
            infix.pop();
            string val2 = infix.top();
            infix.pop();
            char ch = prefix[i];
            infix.push(solve(val1 , val2 , ch));
        }
    }
    
    cout<<"answer is : "<<infix.top();
    return 0;
}