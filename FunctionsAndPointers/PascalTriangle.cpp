#include<iostream>
using namespace std;

int fact(int n){

    if(n==1 || n==0) return 1;
    else return n*fact(n-1);
}

int combination(int n, int r){
    return fact(n)/(fact(r)*fact(n-r));
}
int main(){
    int n; 
    cout<<"enter the number of lines : ";
    cin>>n;
    // int sp=n-1;
    // for(int i=0 ; i<n ; i++){
    //     for(int k=0; k<(n-1-i) ; k++){
    //         cout<<" ";
    //     }
    //     for(int j=0; j<=i; j++){
    //         cout<<combination(i,j)<<" ";
    //     }
    //     // sp--;
    //     cout<<endl;
    // }

    //alternative 
    for(int i=0 ; i<n ; i++){
        int c=1;
        for(int k=0; k<(n-1-i) ; k++){
             cout<<" ";
        }
        for(int j=0; j<=i ; j++){
            cout<<c<<" ";
            c=c*(i-j)/(j+1);
        }
        cout<<endl;
    }

    return 0;
}

//The same function name can be used for different functions without any conflict if
//and only if they either have different data types for arguments or different number
//of arguments. Same function names cannot be used if functions differ only by their
//return type because the compiler would not then know which function is to be used.