#include<iostream>
#include<stack>
#include<queue>
using namespace std;

void display(queue<int> q){
    int n = q.size();
    for(int i=1 ; i<=n ; i++){
        int x = q.front();
        cout<<x<<" ";
        q.pop();
        q.push(x);
    }
    cout<<endl;
}

void reverse(queue<int> &q){
    stack<int> stk;
    int n = q.size();
    for(int i=1 ; i<=n ; i++){
        stk.push(q.front());
        q.pop();
    }
    while(!stk.empty()){
        q.push(stk.top());
        stk.pop();
    }
    return;
}

void reorder(queue<int> &q){
    stack<int> stk;
    int n = q.size();
    for(int i=1 ; i<= n/2 ; i++){
        stk.push(q.front());
        q.pop();
    }
    while(!stk.empty()){
        q.push(stk.top());
        stk.pop();
    }
    for(int i=1 ; i<= n/2 ; i++){
        stk.push(q.front());
        q.pop();
    }
    for(int i=1 ; i<= n/2 ; i++){
        q.push(stk.top());
        stk.pop();
        q.push(q.front());
        q.pop();
    }
    reverse(q);
    return ;
}

int main(){
    queue<int> q;
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    q.push(5); 
    q.push(6);
    q.push(7);
    q.push(8);
    q.push(9);
    q.push(10);
    display(q);
    reorder(q);
    display(q);
    return 0;
}