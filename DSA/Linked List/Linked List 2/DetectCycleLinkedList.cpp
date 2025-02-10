#include<bits/stdc++.h>
using namespace std;

class Node{
public:
    int val;
    Node* next;
    Node(int x){
        this->val = x;
        this->next = NULL;
    }
};

void getCycle(Node* head){
    if(head == NULL){
        cout<<"EMPTY LIST"<<endl;
        return;
    }
    Node* slow = head;
    Node* fast = head;

    bool isCycle = false;
    while(fast->next != NULL and fast->next->next != NULL){
        fast = fast->next->next;
        slow = slow->next;

        if(fast == slow){
            isCycle = true;
            break;
        }
    }

    if(isCycle == false){
        cout<<"NO CYCLE"<<endl;
        return;
    }

    cout<<"CYCLE DETECTED , ";
    
    //gettingCycle starting point
    fast = head;
    while(fast != slow){
        fast = fast->next;
        slow = slow->next;
    }

    cout<<"START POINT :- "<<fast->val<<", ";

    int count = 0;
    do{
        fast = fast->next;
        count++;
    }while(fast != slow);

    cout<<"LENGTH :- "<<count<<endl;
    return ;
}

int main(){
    Node* a = new Node(10);
    Node* b = new Node(20);
    Node* c = new Node(30);
    Node* d = new Node(40);
    Node* e = new Node(50);
    Node* f = new Node(60);
    Node* g = new Node(70);

    a->next = b;
    b->next = c;
    c->next = d;
    d->next = e;
    e->next = f;
    f->next = g;
    g->next = NULL;

    getCycle(a);
    return 0;
}