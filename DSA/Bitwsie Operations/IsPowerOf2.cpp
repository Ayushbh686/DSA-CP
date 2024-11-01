#include<iostream>
using namespace std;

bool Power_2(int n){
    // if(__builtin_popcount(n) == 1) return true;
    // else return false; 
    if( (n & n-1) == 0) return true;
    else return false;
}

int main(){
    int n;
    cin>>n;
    cout<<Power_2(n);
    return 0;
}