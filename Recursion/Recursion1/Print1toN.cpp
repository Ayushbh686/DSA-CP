#include<iostream>
using namespace std;
void print(int n,int i){
    if(n<i) return ;
    cout<<i<<endl;
    print(n,i+1);
    return;
}
int main(){
    int n;
    cin>>n;
    print(n,1);
    return 0;
}