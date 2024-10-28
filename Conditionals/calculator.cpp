#include<iostream>
using namespace std;
int main(){
    int a , b;
    char op;
    cout<<"Enter the problem : ";
    cin>>a>>op>>b;
    cout<<"The answer is : ";
    switch( op ){    // switch (expression){} , condition can also be input but will give error
    case '+':
        cout<<a+b;
        break;
    case '-':
        cout<<a-b;
        break;
    case '*':
        cout<<a*b;
        break;
    case '/':
        cout<<(float)a/b;
        break;
    default :
        cout<<"invalid operator" ;   
    }
    return 0;
}

// break necessary as in switch only one statement is checked and if true all the remaniing statement will be executed;
// default for none of the above;