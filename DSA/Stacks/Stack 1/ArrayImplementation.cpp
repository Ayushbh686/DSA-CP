#include<iostream>
using namespace std;

class stack{
public:
    int arr[5];
    int idx = -1;
    
    void push(int val){
        if(idx == 4) {
            cout<<"stack overflow\n";
            return;
        }
        idx++;
        arr[idx] = val;
    }

    void pop(){
        if(idx == -1) {
            cout<<"stack underflow\n";
            return;
        }
        idx--;
    }

    int top(){
        return arr[idx];
    }

    int size(){
        return idx+1;
    }

    void display(){
        for(int i=0 ; i<=idx ; i++){
            cout<<arr[i]<<" ";
        }
        return;
    }
};

int main(){
    stack stk;
    stk.pop();
    stk.push(10);
    stk.push(20);
    stk.push(30);
    stk.push(40);
    stk.pop();
    cout<<stk.size()<<endl;
    cout<<stk.top()<<endl;
    stk.push(40); 
    stk.push(50); 
    stk.push(60); 
    stk.display();
}
//vector implementation is same but there will be no overflow condition