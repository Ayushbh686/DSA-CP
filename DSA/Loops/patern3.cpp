#include<iostream>
using namespace std;
int main(){
    int n;
    cout<<"enter the number : ";
    cin>>n;
    int m= 2*n+1;
    for(int i=0 ; i<m ; i++){
        for(int j=0; j<m ; j++){
            if((i+j)==n || i==(n) || j==(n) || (i+j)==((m-1)/2) || i+j==(3*n) || i-j==(m-1)/2 || j-i==(m-1)/2)
            cout<<"*";
            else cout<<" ";
        }
        cout<<endl;
    }
    return 0;
}