#include<iostream>
#include<unordered_set>
using namespace std;

int main(){
    unordered_set<int> s; //unique elements
    s.insert(1);
    s.insert(2);
    s.insert(3);
    s.insert(4);
    s.insert(5);
    s.insert(6);
    s.insert(7);
    cout<<s.size()<<endl;
    s.erase(7);
    cout<<s.size()<<endl;


    int target = 7;
    if(s.find(target) != s.end()) cout<<"exists"<<endl;  // if equal to end means not found
    else cout<<"does not exists"<<endl;

    //for each traversing
    for(int ele : s){
        cout<<ele<<" ";
    }
    cout<<endl;
}