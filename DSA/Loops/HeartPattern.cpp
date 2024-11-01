//DIL

#include<iostream>
using namespace std;
int main(){
    cout<<"       *******             *******"<<endl;
    for(int i = 2 ; i <= 7 ; i++ ){
        for(int k=(8-i); k>=1 ; k--){
            cout<<" ";
        }
        for(int l=1; l<=(2*i+5) ; l++){
            cout<<"*";
        }
        for(int m=(15-2*i) ; m>=1 ; m--){
            cout<<" ";
        }
        for(int l=1; l<=(2*i+5) ; l++){
            cout<<"*";
        }
        cout<<endl;
    }

cout<<" ******************* *******************"<<endl;

    for(int i=1 ; i<=3 ; i++){ 
    for(int j=1; j<=41 ; j++){
        cout<<"*";
    }
    cout<<endl;
    }

    for(int i = 1; i<=19; i++){
        for(int k=1; k<=i ; k++){
            cout<<" ";
        }
        for(int j=1; j<=(41-2*i) ; j++){
            cout<<"*";
        }
        cout<<endl;
    }
    return 0;
}