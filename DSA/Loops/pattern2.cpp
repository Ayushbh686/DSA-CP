#include<iostream>
using namespace std;
int main(){
    int n;
    cout<<"enter the number";
    cin>>n;
    int m=n-1;
    for(int i=1 ; i<=n-1 ; i++ )
    cout<<" ";
    cout<<"*"<<endl;
    int k=1;
    int sp=m-1;
    for(int i=1 ; i<=2*m-1 ; i++){
        for(int j=1 ; j<=sp ; j++){
          cout<<" ";
        }
        cout<<"*";
        for (int j=1 ; j<=k; j++){
            cout<<" ";
        }
        cout<<"*";
        if(i<=n-2){ sp--; 
        k+=2;}
        else {sp++ ;
        k-=2;}
        cout<<endl;
    }
    for(int i=1 ; i<=n-1 ; i++ )
    cout<<" ";
    cout<<"*"<<endl;
    return 0;
}

//coordinate system is better alternative if possible by if else 