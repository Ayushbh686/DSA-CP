#include<iostream>
using namespace std;
int sumodd(int a,int b){
    if(a>b) return 0;
    else if(a%2==1) return a+sumodd(a+2,b);
    else return sumodd(a+1,b);
}
int main(){
    int a,b;
    cout<<"enter the a and b :";
    cin>>a>>b;
    cout<<sumodd(a,b);
    return 0;
}