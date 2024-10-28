#include<iostream>
using namespace std;

int flipBits(int n){
    int temp = n;
    n = n | n >> 1;
    n = n | n >> 2;
    n = n | n >> 4;
    n = n | n >> 8;
    n = n | n >> 16;  // sets all the bits to 1 which is 2^(x+1)-1
    // all bits become 1
    return n ^ temp; // every bit is xor with 1 
}

int main(){
    int n ;
    cin>>n;
    cout<<flipBits(n);
    return 0;
}