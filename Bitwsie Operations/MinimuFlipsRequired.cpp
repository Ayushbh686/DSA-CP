#include<iostream>
using namespace std;

int Minimum_Flips(int x , int y){
    int temp = x ^ y; // xor gives 1 for bits requiring flips
    //count setbits of temp
    // int res = 0;
    // while(temp>0){
    //     res ++;
    //     temp = temp & temp - 1;
    // }
    // return res;
    return __builtin_popcount(temp);
}

int main(){
    int x , y;
    cin>>x>>y;
    cout<<Minimum_Flips(x , y);
    return 0;
}