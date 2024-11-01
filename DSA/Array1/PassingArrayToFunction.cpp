#include<iostream>
using namespace std;
void display(int a[] , int size){   // int a[] is equal to int* ptr
    for(int i=0 ; i<=size-1 ; i++){
        cout<<a[i]<<" ";
    }
    cout<<endl;
    return;
}
void change(int *b , int size){    // int b[] is equal to int* ptr
    b[0]=9;
    b[1]=10;
    return ;
}
int main(){
    int arr[8]={1,2,3,4,5,6,7,8};
    int size = sizeof(arr)/sizeof(arr[0]);
    cout<<size<<endl;
    display(arr , size);    //array is always passed by refrence through the function here arr is acctualy a pointer pointing array
    change(arr , size);
    display(arr , size);
    return 0;
}