#include<iostream>
using namespace std;
int main(){
    int arr[]={1,2,3,4,5,6};
    int* ptr = arr;  // arr or &arr[0]
    cout<<ptr<<endl;
    for(int i=0; i<=5 ; i++){
        cout<<*ptr<<" ";
        ptr++;
    }
    cout<<endl;
    ptr = arr;
    for(int i=0 ; i<=5 ; i++){
        cout<<ptr[i]<<" ";
    }
    return 0;
}