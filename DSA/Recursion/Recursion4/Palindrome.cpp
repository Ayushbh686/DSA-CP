#include<iostream>
#include<string>
using namespace std;
bool isPalindrome(string s , int i , int j ){
    if(s[i]!=s[j]) return false;
    else if(i>j) return true;
    return isPalindrome(s,i+1,j-1);
}
int main(){
    string s;
    getline(cin,s);
    cout<<isPalindrome(s,0,s.length()-1);
}