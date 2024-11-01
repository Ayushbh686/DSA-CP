#include<iostream>
#include<string>
using namespace std;
void permutation(string str , string s ){
    if(str.length()==0){
        cout<<s<<endl;
    }
    for(int i=0; i<str.length() ; i++){
        // string newstr="";
        // for(int j=0 ; j<str.length(); j++){
        //     if(j==i) continue;
        //     newstr+=str[j];
        // }
        //permutation(newstr ,s+str[i]);
        // better alternative than making 2 loops O(n2)
        string left = str.substr(0,i);
        string right = str.substr(i+1);
        permutation(left+right, s+str[i]);
    }
}
int main(){
    string str="abc";
    permutation(str,"");
    return 0;
}