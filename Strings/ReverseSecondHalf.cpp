#include<iostream>
#include<string>
#include<sstream>
using namespace std;
int main(){
    string s;
    cout<<"enter the string: ";
    getline(cin,s);
    int n=s.length();
    for(int i=n/2, j=n-1 ; i<=j ; i++,j--){
        int temp=s[i];
        s[i]=s[j];
        s[j]=temp;
    }
    cout<<"resulting array is : "<<s;
}