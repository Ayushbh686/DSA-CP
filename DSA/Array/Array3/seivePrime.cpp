#include<bits/stdc++.h>
using namespace std;

void SeiveMethod(int n , int m , vector<bool>&arr){
    for(int i=2 ; i<=sqrt(m) ; i++){
        if(arr[i] == true){ //if its still prime 
            for(int j=i*2; j<= m ; j+=i){
                arr[j] = false; //means not prime
            }
        }
    }
}

int main(){
    int n , m;
    cout<<"enter starting and ending number : ";
    cin>>n>>m;

    vector<bool>arr(m + 1 , true); //true means prime 

    SeiveMethod(n , m , arr);
    
    arr[0] = arr[1] = false;

    for(int i=n ; i<=m ; i++){
        if(arr[i] == true) cout<<i<<" ";
    }

    return 0;
}
