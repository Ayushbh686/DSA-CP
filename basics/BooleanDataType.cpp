#include<iostream>
using namespace std;
int main(){
    bool flag = false;
    cout << flag << endl;
    flag = true; 
    cout << flag << endl;
    flag = 2 ;             // any integer other than 0 will give 1 
    cout << flag << endl;
    flag = 0;
    cout << flag << endl;
    cout << (7 > 3) << endl;
    cout << (7 < 3) << endl;
    return 0;
}