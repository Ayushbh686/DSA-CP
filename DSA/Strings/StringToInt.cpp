#include<iostream>
#include<string>
using namespace std;
int main(){
    string s;
    cout<<"enter the string : ";
    cin>>s;
    int n=0;
    cout<<s.length()<<" "<<s.size()<<endl;
    for(int i=0;i<=s.length()-1;i++){
        int k=(int)(s[i]-'0');
        n=((n+k)*10);
    }
    n/=10;
    cout<<n;
}