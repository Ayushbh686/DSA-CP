#include<iostream>
#include<string>
#include<stack>
using namespace std;

int priority(char symbol){
    if(symbol == '/' or symbol == '*') return 2;
    else return 1;
}

string solve(char ch , string val1 , string val2){
    return ch + val1 + val2;
}

int main(){
    string str;
    cout<<"enter the expression : ";
    cin>>str;
    stack<string> prefix;
    stack<char> op;
    for(int i=0 ; i<str.size() ; i++){
        //if its number push directly
        if(str[i] >= '0' and str[i] <= '9'){
            prefix.push(string(1, str[i]));
        }

        else{
            //agar closing bracket aaye toh jab tak openeing bracket nahi aata tab tak solve karo
            if(str[i] ==')'){
                while(op.top() != '('){
                    string val2 = prefix.top();
                    prefix.pop();
                    string val1 = prefix.top();
                    prefix.pop();
                    char symbol = op.top();
                    op.pop();
                    prefix.push(solve(symbol,val1,val2));
                }
                op.pop();
            }

            //agar openeing bracket ho toh hamesha push hoga aur uska agla operand bhi hamesha push hoga , it can be merged in next condition but for simplicity we taking it different case
            else if(op.empty() or str[i] == '(' or op.top() == '('){
                op.push(str[i]);
            }

            //if stack empty or opening bracket then push as it is or jyada priority wala upar rahega kyuki woh pehle evaluate hota hai
            else if(op.empty() or priority(op.top()) < priority(str[i])){
                op.push(str[i]);
            }

            //agar less or equal priority wala aaya toh usse pehele uske pehele ke bade walo ko evaluate karo
            else{
                while(!op.empty() and priority(op.top()) >= priority(str[i])){
                    string val2 = prefix.top();
                    prefix.pop();
                    string val1 = prefix.top();
                    prefix.pop();
                    char symbol = op.top();
                    op.pop();
                    prefix.push(solve(symbol,val1,val2));
                }
                op.push(str[i]);
            }
        }
    }
    while(!op.empty()){
        string val2 = prefix.top();
        prefix.pop();
        string val1 = prefix.top();
        prefix.pop();
        char symbol = op.top();
        op.pop();
        prefix.push(solve(symbol,val1,val2));
    }

    cout<<"answer is : "<<prefix.top();
    return 0;
}