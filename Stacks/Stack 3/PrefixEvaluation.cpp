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
    string prefix;
    cout<<"Enter prefix Expression : ";
    cin>>prefix;
    stack<int> val;
    //traverse ulta
    for(int i=prefix.size()-1 ; i>=0 ; i--){
        if(isdigit(prefix[i])){
            val.push(prefix[i] - '0');
        }
        else{
            int val1 = val.top();    //ordering of val1 and val2 changed as we traverese ulta
            val.pop();
            int val2 = val.top();
            val.pop();
            char ch = prefix[i];
            val.push(solve(val1 , val2 , ch));
        }
    }
    
    cout<<"answer is : "<<val.top();
    return 0;
}