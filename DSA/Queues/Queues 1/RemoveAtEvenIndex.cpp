#include<iostream>
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

void removeAtEven(queue<int>& q){
    int n = q.size();
    for(int i=0 ; i<n ; i++){
        if(i%2 == 0) q.pop();
        else{
            q.push(q.front());
            q.pop();
        }
    }
    return ;
}

int main(){
    queue<int> q;
    q.push(10);
    q.push(20);
    q.push(30);
    q.push(40);
    q.push(50);
    q.push(60); // front(pop) 10 20 30 40 50 back(push) , in stack no front (its closed) only back for pop and push and its top
    display(q);
    removeAtEven(q);
    display(q);
    return 0;
}