#include<iostream>
using namespace std;
int main(){
    int n;
    int c=0;
    int sum=0;
    int r;
    cout<<"enter the number : ";
    cin>>n;
    int a = n;
    for( ; n!=0 ; ){
       r=n%10;
       n/=10;
       sum+=r;
       c++;

    }
    if(a==0) cout<<"the number of digits is : 0";
    else cout<<"the number of digits is : "<<c<<endl;
    cout<<"the sum of digits is : "<<sum;

    return 0;
}