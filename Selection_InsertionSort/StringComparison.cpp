#include<iostream>
#include<string>
using namespace std;
int main(){
    string s="ybcd";
    string t="mbcd";
    cout<<s.compare(t);
    //s.compare--> s-t --> for the first different element
    //0 if similar , +ve if s>t , -ve if s<t
    //in my compiler its 1, 0 , -1
}