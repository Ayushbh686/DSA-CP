#include<iostream>
using namespace std;
int fact(int n){
    if (n==0 || n==1) return 1;
    int ans=n*fact(n-1);
    return ans;
}
int main(){
    int n;
    cin>>n;
    int x=fact(n);
    cout<<x;
    return 0;
}