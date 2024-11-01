#include<iostream>
using namespace std;
int sumOfDigits(int n ){
    if(n==0) return 0;
    int r = n % 10;
    return r+sumOfDigits(n/10);
}

int main(){
    int n;
    cout<<"enter the value of n :-";
    cin>>n;
    cout<<sumOfDigits(n);
}