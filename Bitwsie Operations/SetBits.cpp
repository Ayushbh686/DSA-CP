#include<iostream>
using namespace std;

int Setbits(int n){
    return __builtin_popcount(n);
}

int Brian_kernigal_algo(int n){ // every integer n and n-1 has some fixed bits and some flipped bits starting from its first set bit from right side so & operation removes one set bits in the result(from fliped region)
    int res= 0;
    while( n>0 ){
        res++;
        n = n & n-1;
    }
    return res;
    //O(logn) in worst case but more fast in case of long bits number like long long 64 bits , int 32 bits
}
//alternative is calculate binary and count O(logn)
int main(){
    int n ;
    cin>>n;
    cout<<Setbits(n)<<endl;
    cout<<Brian_kernigal_algo(n);
    return 0;
}