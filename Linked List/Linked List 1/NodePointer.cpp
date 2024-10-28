#include<iostream>
using namespace std;

class Node{
public:
    int val;
    Node* next;
    Node(int val){
        this->val = val;
        this->next = NULL;
    }
};

void display(Node *head){
    Node* temp = head;
    while(temp != NULL){
        cout<<temp->val<<" ";
        temp = temp->next;
    }
    cout<<endl;
    return;
}

void display_Rec(Node *head){  // Iterative is better as SC is O(n) (call stacka and local variable created)
    if(head==NULL) {
        cout<<endl;
        return;
    }
    cout<<head->val<<" ";
    display_Rec(head->next);
    return;
}

void reverse_display(Node* head){
    if(head==NULL) {
        //cout<<endl;
        return;
    }
    reverse_display(head->next);
    cout<<head->val<<" ";
    return;
}

int size(Node *head){
    int n = 0;
    while(head != NULL){
        n++;
        head = head->next;
    }
    return n;
}

void insertAtEnd(Node* head, int val){
    Node* temp = new Node(val);
    while(head->next != NULL){
        head = head->next;
    }
    head->next = temp;
    return;
}

void insertAtStart(Node** head , int val){ // double ptr approach otherwise we have to return node* from function having the new node of ll
    Node* temp = new Node(val);
    temp->next = *head;
    *head = temp;
    return;
}

int main(){
    Node* a = new Node(10);
    Node* b = new Node(20);
    Node* c = new Node(30);
    Node* d = new Node(40);
    Node* temp = a; // shallow copy
    a->next = b;
    b->next = c;
    c->next = d;
    // while(temp!=NULL){
    //     cout<<temp->val<<" ";
    //     temp = temp->next;
    // }
    // cout<<"\nd = "<<a->next->next->next->val;
    display(a); // give the address of 1st node
    insertAtEnd(a,50);
    display_Rec(a);
    insertAtStart(&a,5);
    display_Rec(a);
    cout<<"size = "<<size(a)<<endl; // size of ll
    reverse_display(a);
    cout<<"\nsize = "<<size(a); // size of ll
    return 0;
}