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

void ReverseK(queue<int> &q , int k){
    stack<int> stk;
    int n = q.size();
    for(int i=1 ; i<= n-k ; i++){
        stk.push(q.front());
        q.pop();
    }
    while(!stk.empty()){
        q.push(stk.top());
        stk.pop();
    }
    //reverse
    for(int i=1 ; i<= n ; i++){
        stk.push(q.front());
        q.pop();
    }
    while(!stk.empty()){
        q.push(stk.top());
        stk.pop();
    }
    return;
}

int main(){
    queue<int> q;
    q.push(10);
    q.push(20);
    q.push(30);
    q.push(40);
    q.push(50); // front(pop) 10 20 30 40 50 back(push) , in stack no front (its closed) only back for pop and push and its top
    q.push(60);
    display(q);
    ReverseK(q,3);
    display(q);
}