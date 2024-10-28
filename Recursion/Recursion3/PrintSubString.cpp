#include<iostream>
#include<vector>
using namespace std;
void substrr(string s,string str,int idx, vector <string>&v){
    if(idx==str.length()){
        v.push_back(s);
        return ;
    }
    char ch=str[idx];
    substrr(s+ch,str,idx+1,v);//not s+=ch as this modifies the existing string but s+ch makes the new string 
    substrr(s,str,idx+1,v);
}
int main(){
    string str="abcd";
    vector<string>v;
    substrr("",str,0,v);
    for(string ele: v){
        cout<<ele<<endl;
    }
    return 0;
}