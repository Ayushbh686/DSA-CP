#include<iostream>
using namespace std;
int main(){
    float x;
    cout<<"enter the number : ";
    cin>>x;
    float y;
    y = x - (float)((int)x);
    if(x<0) {
        y=1+y;
    }
    cout<<"the fractional part is : "<<y;
    return 0;
}