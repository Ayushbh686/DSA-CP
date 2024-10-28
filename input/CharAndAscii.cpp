#include<iostream>
using namespace std;
int main(){
    //char ch='1'; // number can also be input in character data type
    char ch;
    cout<<"enter the character : ";
    cin>>ch;
    int y = (int)ch;
    // cout<<(int)ch;
    cout<<"the position of letter is : "<<y-64;
}


// if( charcter and int can be compared ) ascii value of char will be compared to int value;