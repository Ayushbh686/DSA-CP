#include<iostream>
using namespace std;
int main(){
    int x;
    x = 8 < 6 ? 10 : 1 != 2 < 5 ? 20 : 30;
    cout<<"value of x is "<<x<<endl;
    cout<<(5 > 3 ? 10 : 30)<<endl;
    return 0;
}

// ternary is short form of if else (condition ? true : false)