#include<iostream>
using namespace std;
int main(){
    int arr[10];
    int* p=&arr[0];
    cout<<p<<endl;
    cout<<&arr[0]<<endl;
    cout<<++p<<endl;
    cout<<&arr[1]<<endl;
    cout<<++p<<endl;
    cout<<&arr[2]<<endl;
    cout<<++p<<endl;
    cout<<&arr[3]<<endl;
    cout<<++p<<endl;
    cout<<&arr[4]<<endl;
    return 0;
    // 0x61fee4
    // 0x61fee4
    // 0x61fee8
    // 0x61fee8
    // 0x61feec
    // 0x61feec
    // 0x61fef0
    // 0x61fef0
    // 0x61fef4
    // 0x61fef4
    cout<<arr<<endl;   // arr==&arr==&arr[0]
    cout<<&arr<<endl;
}