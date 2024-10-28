#include<iostream>
#include<string>
using namespace std;
int maze(int m,int n){   // alternatively take 4 arguments starting row ,coloumns and current rows and coloumns for 1,1 to m,n
    // my solution m,n to 1,1
    if(n<=0 || m<=0) return 0;
    if(n==1 || m==1) return 1;
    return maze(m-1,n)+ maze (m,n-1);
}
void print(int m,int n,string s){
    if(n<=0 || m<=0) return;
    // if(n==1){
    //      cout<<s<<string(m-1,'D')<<endl;
    //      return;
    // }
    // if(m==1){
    //      cout<<s<<string(n-1,'R')<<endl;
    //      return;
    // }
    //alternatively make conditon n==1 and m==1 instead of above 2 and print string s
    if(n==1 && m==1) cout<<s<<endl;
    print(m-1,n,s+'D');
    print(m,n-1,s+'R');
    return ;
}
int main(){
    int m,n;
    cout<<"enter the number of rows and coloumns : ";
    cin>>m>>n;
    cout<<maze(m,n)<<endl;
    print(m,n,"");
    return 0; 
}