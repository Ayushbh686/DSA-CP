#include<iostream>
#include<math.h>
using namespace std;

int gcd(int x , int y){
    for(int i=min(x,y) ; i>=1 ; i--){
        if((x % i == 0) and (y % i == 0)) return i;
    }
    return 0;
}

int gcd2(int x , int y){
    if(y==0) return 0;
    while(x % y != 0){
        int rem = x % y;
        x = y;
        y = rem;
    }
    return y;
}

int main(){
    int x  , y;
    cin>>x>>y;
    x = abs(x);
    y = abs(y);
    cout<<gcd(x,y)<<endl;
    cout<<gcd2(max(x,y) , min(x,y))<<endl;
    return 0;
}