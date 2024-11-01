#include<iostream>
#include<string>
#include<stack>
using namespace std;

int priority(char symbol){
    if(symbol == '/' or symbol == '*') return 2;
    else return 1;
}

int solve(int val1 , char symbol , int val2){
    if(symbol == '/') return val1/val2;
    if(symbol == '*') return val1*val2;
    if(symbol == '+') return val1+val2;
    if(symbol == '-') return val1-val2;
}

int main(){
    string str;
    cout<<"enter the expression : ";
    cin>>str;
    stack<int> val;
    stack<char>op;
    for(int i=0 ; i<str.size() ; i++){
        //if its number push directly
        if(str[i] >= '0' and str[i] <= '9'){
            val.push((int)str[i] - (int)'0');
        }

        else{
            //if stack empty then push as it is or jyada priority wala upar rahega kyuki woh pehle evaluate hota hai
            if(op.empty() or priority(op.top()) < priority(str[i])){
                op.push(str[i]);
            }
            //agar less or equal priority wala aaya toh usse pehele uske pehele ke bade walo ko evaluate karo
            else{
                while(!op.empty() and priority(op.top()) >= priority(str[i])){
                    int val2 = val.top();
                    val.pop();
                    int val1 = val.top();
                    val.pop();
                    char symbol = op.top();
                    op.pop();
                    val.push(solve(val1 , symbol , val2));
                }
                op.push(str[i]);
            }
        }
    }
    while(!op.empty()){
        int val2 = val.top();
        val.pop();
        int val1 = val.top();
        val.pop();
        char symbol = op.top();
        op.pop();
        val.push(solve(val1 , symbol , val2));
    }

    cout<<"answer is : "<<val.top();
    return 0;
}