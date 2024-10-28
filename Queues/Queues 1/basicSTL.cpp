#include<iostream>
#include<queue>
#include<stack>
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

void reverse(queue<int>& q){
    stack<int> stk;
    while(!q.empty()){
        stk.push(q.front());
        q.pop();
    }
    while(!stk.empty()){
        q.push(stk.top());
        stk.pop();
    }
}

int main(){
    queue<int> q;
    q.push(10);
    q.push(20);
    q.push(30);
    q.push(40);
    q.push(50); // front(pop) 10 20 30 40 50 back(push) , in stack no front (its closed) only back for pop and push and its top
    cout<<q.size()<<endl;
    cout<<q.front()<<endl; 
    cout<<q.back()<<endl;
    display(q);
    reverse(q);
    display(q);
    q.pop();
    cout<<q.size()<<endl;
    cout<<q.front()<<endl; 
    cout<<q.back()<<endl;
    display(q);
    return 0;
}