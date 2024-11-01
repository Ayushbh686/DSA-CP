#include<iostream>
#include<unordered_map>
using namespace std;

int main(){
    unordered_map<string , int> m; // key value pairs
    //inserting with pair
    pair<string , int> p1;
    p1.first = "Ayush";
    p1.second = 18;
    m.insert(p1);

    //direct insertion 
    m["Sundram"] = 17;
    m["rishav"] = 20;

    for(auto ele : m){ // auto ditect the type otherwise write pair<string , int> ele : m
        cout<<ele.first<<" "<<ele.second<<endl;
    }
    cout<<m.size()<<endl;
    m.erase("rishav");

    //finding by key
    if(m.find("Ayush") != m.end()) cout<<"found\n";
    else cout<<"not found\n";

    if(m.find("rishav") != m.end()) cout<<"found\n";
    else cout<<"not found\n";



    for(auto ele : m){ // auto ditect the type otherwise write pair<string , int> ele : m
        cout<<ele.first<<" "<<ele.second<<endl;
    }
    cout<<m.size()<<endl;
    cout<<m["Ayush"];
    return 0;
}