#include<iostream>
using namespace std;
bool ispow(float n){
    if(n==1) return true;
    else if(n<1) return false;
    return ispow(n/2.0);
} // alternative :- instead of taking float value just check if its even value check further and if not return false

bool isPowerOfTwo(int n) {
    if (n <= 0) return false;
    if (n == 1) return true;
    if (n % 2 != 0) return false;
    return isPowerOfTwo(n / 2);
}

int main(){
    int n;
    cin>>n;
    cout<<ispow((float)n);
    return 0;
}