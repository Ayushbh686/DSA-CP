#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;
void substrr(string str, vector<string> &v,string ans,bool flag){
    if(str.length()==0){
        v.push_back(ans);
        return;
    }
    char ch=str[0];
    if(str.length()==1){
        substrr(str.substr(1),v,ans+ch,true);
        substrr(str.substr(1),v,ans,true);
        return;
    }
    char dh=str[1];
    if(ch==dh){
        if(flag==true) substrr(str.substr(1),v,ans+ch,true);
        substrr(str.substr(1),v,ans,false);
    }
    else{
        if(flag==true) substrr(str.substr(1),v,ans+ch,true);
        substrr(str.substr(1),v,ans,true);
    }
    return;
}
int main(){
    string s;
    getline(cin,s);
    sort(s.begin(),s.end());
    vector<string>v;
    substrr(s,v,"",true);
    for(string ele:v){
        cout<<ele<<endl;
    }
}