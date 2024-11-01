#include<iostream>
// #include<stdbool.h>
using namespace std;
int main(){
    int x=10;
    if(x)                               // expression can alos be entered in if else
        cout<<"this works"<<endl;
    if(x=5)                             //assignmemt + expression
        cout<<"this works"<<endl;
    if(2+3%4)
        cout<<"this works"<<endl;
    if(-6)
        cout<<"this works"<<endl;

    cout<<(x=8)<<endl;
    bool flag =7;                     // any non zero number in bool is converted to 1
    cout<<flag;
    return 0;
    
}