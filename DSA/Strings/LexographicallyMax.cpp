#include<bits/stdc++.h>
using namespace std;
int main(){
    string s="i am a pwian";
    int n=s.size();
    string maxword="",word="";
    for(int i=0 ; i<n ; i++){
        if(s[i]==' '){
            maxword = max(maxword, word);
            word="";
        }
        else{
            word+=s[i];
        }
    }
    maxword = max(maxword, word);
    cout<<maxword;
}