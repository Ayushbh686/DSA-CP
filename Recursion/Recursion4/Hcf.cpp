#include<iostream>
using namespace std;
// int hcf(int a,int b,int i){  TC  => O(min(a,b))
//     if(i<2) return 1; 
//     if(a%i==0 && b%i==0) return i;
//     return hcf(a,b,i-1);
// }
int hcf(int a,int b){
    if(a==0) return b;
    return hcf(b%a,a);
}
int main(){
    int a, b;
    cin>>a>>b;
    cout<<hcf(a,b);
    return 0;
}