#include<iostream>
#include<vector>
using namespace std;
int main(){
    vector<int>v;
    v.push_back(6);
    cout<<v.size()<<" "<<v.capacity()<<endl;
    v.push_back(2);
    cout<<v.size()<<" "<<v.capacity()<<endl;
    v.push_back(9);
    cout<<v.size()<<" "<<v.capacity()<<endl;
    // v.push_back(8);
    //v.push_back(5);
    //v[3] = 5 not recomended as capacity varries 
    v[3]=5; // does not increase size or capacity
    cout<<v.size()<<" "<<v.capacity()<<endl;
    cout<<v[2]<<" "<<v[3];
    // cout<<v[3];      
}