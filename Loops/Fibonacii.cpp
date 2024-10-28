#include<iostream>
using namespace std;
int main(){
    int n;
    int a=1,b=1;
    cout<<"enter the number of terms to be printed : ";
    cin>>n;
    int sum=0;
    cout<<a<<endl<<b<<endl;
    for(int i=1; i<=(n-2) ; i++){
       sum=a+b;
       a=b;
       b=sum;
       cout<<sum<<endl;
    }
    return 0;
}