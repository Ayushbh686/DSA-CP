/*
find permutation of a string
for a string abcd we fix letter like first we fix a and then make remaining string bcd permute and then we fix b and make acd permute and so on
*/
#include<bits/stdc++.h>
using namespace std;

void permutation(string str , string s){
    if(str.size() == 0) {
        cout<<s<<endl;
        return;
    }
    for(int i=0 ; i<str.size() ; i++){
        string l = str.substr(0,i);
        string r = str.substr(i+1);
        permutation(l+r , s + str[i]); //space wastage as everytime we create new string copy and not passing orignal string
    }
}

int main(){
    string s;
    cin>>s;
    permutation(s , "");
    return 0;
}