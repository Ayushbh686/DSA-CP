#include<iostream>
#include<string>
#include<cmath>
using namespace std;
int reverse(int n){
    if(n==0) return 0;
    string s = to_string(n);
    int x = s.length();
    int r = n%10;
    return  r*pow(10,x-1) + reverse(n/10) ;
}

int main(){
    int n;
    cout<<"enter the number :- ";
    cin>>n;
    cout<<reverse(n);
    return 0;
}