#include<iostream>
using namespace std;

class Node {
public:
    int val;
    Node* next;
    Node* prev;
    Node(int val) {
        this->val = val;
        this->next = NULL;
        this->prev = NULL;
    }
};

void display(Node* head) {
    Node* temp = head;
    while (temp != NULL) {
        cout << temp->val << " ";
        temp = temp->next;
    }
    cout << endl;
}

void dispayRevRec(Node* head){ //O(n) call stack always for rec thats why wedont prefer it and also in doubly ll its not required due to prev pointer
    if(head == NULL) return;
    dispayRevRec(head->next);
    cout<<head->val<<" ";
    return;
}

void displayRev(Node* tail){
    while(tail != NULL){
        cout<<tail->val<<" ";
        tail = tail->prev;
    }
    return;
}

int main() {
    Node a(10);
    Node b(20);
    Node c(30);
    Node d(40);
    Node e(50);
    
    a.next = &b;
    b.next = &c;
    c.next = &d;
    d.next = &e;
    
    b.prev = &a;
    c.prev = &b;
    d.prev = &c;
    e.prev = &d;
    
    display(&a);
    dispayRevRec(&a);
    cout<<endl;
    displayRev(&e);
    return 0;
}
