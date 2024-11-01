#include<iostream>
using namespace std;

void Decimal_Binary(int n){
    string s ;
    if(n==0){
    cout<<0;
    return;
    }
    while(n > 0){
        s = (char)(n%2 + '0') + s;
        n /= 2;
    }
    cout<<s;
    return ;
}

int main(){
    int n ;
    cin>>n;
    Decimal_Binary(n);
    return 0;
}