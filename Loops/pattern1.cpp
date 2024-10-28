#include<iostream>
using namespace std;
int main(){
    int n;
    cout<<"enter the number : ";
    cin>>n;
    for (int i=0 ; i<2*n-1 ; i++){
    cout<<(char)('A'+i);
    }
    cout<<endl;
    for(int i=1 ; i<=(2*(n-1)-1) ; i++){
        int a=65;
        for(int j=1 ; j<=(n-1-i+1); j++){
            cout<<(char)(a);
            a++;
        }
        for( int j=1 ; j<=2*i-1 ; j++){
            cout<<" ";
            a++;
        }
        for(int j=1 ; j<=(n-1-i+1) ; j++){
            cout<<(char)(a);
            a++;
        }
        cout<<endl;
    }
    return 0;
} 