#include<iostream>
using namespace std;
void swap(int &a, int &b){
    int temp= a;
    a=b;
    b=temp;
    return;
}

void swap2(int *a , int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
    return;
}

int main(){
    int a , b;
    cin>>a>>b;
    swap(a,b);
    cout<<a<<" "<<b<<endl;
    swap2(&a,&b);
    cout<<a<<" "<<b;
    // int x=5;
    // int* y=&x;
    // int** z=&y;
    // int*** w=&z;
    // ***w=6;
    // cout<<x;
    return 0;
}



//Alternative is pass adresss through int data type and operating on *a, *b
