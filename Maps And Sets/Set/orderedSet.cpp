#include<iostream>
#include<map>
#include<set>
using namespace std;

int main(){
    set<int> s;
    s.insert(2);
    s.insert(3);
    s.insert(1);
    //show in increasing order , if string then lexographically
    for(auto ele : s){
        cout<<ele<<" ";
    }
    return 0;
}