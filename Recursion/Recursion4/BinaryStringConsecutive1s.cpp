#include<iostream>
using namespace std;
void binarystr(string s, int n){
    if(s.size()==n){                              
        cout<<s<<endl;
        return;
    }
    binarystr(s+'0',n);
    if(s.size()==0 || s[s.size()-1]=='0') binarystr(s+'1',n);
}
int main(){
    int n;                                                     
    cin>>n;
    binarystr("",n);
    return 0;
}
// f(n) = f(n-1) + f(n-2) where f(1) = 2, f(2) = 3 and f(n) gives number of binary string without consecutive one of length n
//this is equivalent to fiboncci and can prove this relation by intution