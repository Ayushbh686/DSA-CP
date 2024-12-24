/*
find permutation of a string
for a string abcd we fix letter like first we fix a and then make remaining string bcd permute and then we fix b and make acd permute and so on
*/
#include<bits/stdc++.h>
using namespace std;

void permutation(string &str , int idx){ 
    if(idx==str.size()-1) {
        cout<<str<<endl;
        return;
    }

    unordered_set<char>s; //only to handle repeated character case
    for(int i=idx ; i<str.size() ; i++){
        if(s.count(str[i])) continue; //only to handle repeated character case
        s.insert(str[i]); //only to handle repeated character case
        swap(str[idx],str[i]);
        permutation(str , idx+1);
        swap(str[idx] , str[i]); //that is backtracking in which after call we revert our changes to explore further path and not affect function calls
    } //here orignal string is passed so space complexity improved
}

int main(){
    string s;
    cin>>s;
    permutation(s , 0); //permutaion from i to ...n index
    return 0;
}