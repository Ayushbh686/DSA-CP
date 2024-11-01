#include<iostream>
using namespace std;
int Brian_kernigal_method(int n){
    int temp = 0 ;
    while(n>0){
        temp = n ;
        n = n & n-1;
    }
    return temp ; //temp will be last second value of n before becoming 0 as that will be maximum power of 2
}

int Method2(int n){
    n = n | n >> 1;
    n = n | n >> 2;
    n = n | n >> 4;
    n = n | n >> 8;
    n = n | n >> 16;  // sets all the bits to 1 which is 2^(x+1)-1
    //n = n | n >> 32;
    n = (n + 1)/2; 
    return n;
}

int main(){
    int n ;
    cin>>n;
    cout<<Brian_kernigal_method(n)<<endl;
    cout<<Method2(n);
    return 0;
}