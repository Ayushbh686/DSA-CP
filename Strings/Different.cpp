#include<iostream>
#include<string>
using namespace std;
int main(){
    string str;
    cout<<"enter the string : ";
    getline(cin,str);
    int n=str.length();
    int count = 0;
    if(n==1){
        cout<<0;
        return 0;
    }
    for(int i=0 ; i<n ; i++){
        if(str[i]!=str[i-1] && str[i]!=str[i+1]) count++;
    }
    cout<<count;
}
//can be more explanatory by makin seprate case for i==0 , i==n-1