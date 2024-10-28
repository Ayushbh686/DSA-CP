#include<iostream>
#include<map>
#include<set>
using namespace std;

int main(){
    map<string , int> mp;
    mp["ayush"] = 18;
    mp["rishav"] = 20;
    mp["sundram"] = 17;
    //show in increasing order of key , if string then lexographically
    for(auto ele : mp){
        cout<<ele.first<<" "<<ele.second<<endl;
    }
    return 0;
}