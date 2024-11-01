#include<iostream>
using namespace std;

int MinNum(int n){
    if((n & n-1) == 0) return 0;
    int temp = 0 , x = n;
    while(x>0){
        temp = x ;
        x = x & x-1;
    }
    temp = temp << 1;
    return temp - n;
}

int main(){
    int n ;
    cin>>n;
    cout<<MinNum(n);
    return 0;
}
// 1 0 0 0 0 0 0 0 0 
// 0 1 0 0 1 0 1 0 0 
// 0 0 1 1 0 1 1 0 0