#include<iostream>
using namespace std;
int pow(int a,int b){
    if(b==0) return 1;
    int ans = pow(a,b/2);
    if(b%2==1) return ans*ans*a;
    return ans*ans;
}
int main(){
    int a,b;
    cout<<"enter the base and exponent : ";
    cin>>a>>b;
    cout<<pow(a,b);
    return 0;
}