#include<iostream>
using namespace std;
// void skipch(string s,string orignal){
//     if(orignal.length()==0){
//         cout<<s;
//         return;
//     }
//     char ch=orignal[0];
//     if(ch!='a') return skipch(s+=ch , orignal.substr(1));
//     else return skipch(s , orignal.substr(1));
// }
//poor space complexity
void skipch(string s,string orignal,int idx){
    if(orignal.length()==idx){
        cout<<s;
        return;
    }
    char ch=orignal[idx];
    if(ch!='a') return skipch(s+ch , orignal , idx+1);
    else return skipch(s , orignal , idx+1);
}
int main(){
    string str="ayush bhagat";
    skipch("",str,0);
    return 0;
}