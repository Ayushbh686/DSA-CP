#include<iostream>
using namespace std;
int main(){
    int p=5 , q = 10;
    p += q -= p;      // right to left in assignment operator
    cout<<p<<" "<<q;
    return 0;
}