/*Given N friends, each one can remain single or can be paired up with some other friend. Each friend can be paired only once. Find out the total number of ways in which friends can remain single or can be paired up.*/

#include<iostream>
#include<vector>
using namespace std;

int f(int n){
    if(n==1 or n==2) return n;
    return f(n-1) + (n-1) * f(n-2); // f(n-1) in case if nth friend stays single than remaing n-1 will arrange themselves and f(n-2) in case if wants to pair it has (n-1) options to pair and f(n-2) for remaing n-2 elements
}

int main(){
    int n;
    cin>>n;
    cout<<f(n)<<endl;
    return 0;
}