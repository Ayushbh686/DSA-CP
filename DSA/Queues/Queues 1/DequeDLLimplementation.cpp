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

class Deque{
public:
    Node* head;
    Node* tail;
    int size;

    Deque(){
        head = tail = NULL;
        size = 0;
    }

    void pushAtBack(int val){
        Node* temp = new Node(val);
        if(size == 0){
            head = tail = temp;
            size++;
            return;
        }
        tail->next = temp;
        temp->prev = tail;
        tail = temp;
        size++;
    }

    void PushAtFront(int val){
        Node* temp = new Node(val);
        if(size == 0) head = tail = temp;
        else{
            temp->next = head;
            head->prev = temp;
            head = temp;
        }
        size++;
    }

    void popAtFront(){
        if(size == 0) cout<<"Invalid operation\n";
        else{
            Node* temp = head;
            head = head->next;
            if(head != NULL) head->prev = NULL;
            if(head == NULL) tail = NULL;
            size--;
        }
    }

    void popAtBack(){
        if(size == 0) cout<<"Invalid operation\n";
        else{
            if(size == 1) {
                delete head; // Only one node in the list
                head = tail = NULL;
            } else {
                Node* temp = tail->prev;
                temp->next = NULL;
                tail = temp;
            }
            size--;
        }
    }

    int front(){
        if(head == NULL){
            cout<<"Empty Deque ";
            return -1000;
        }
        return head->val;
    }

    int back(){
        if(tail == NULL){
            cout<<"Enmpty Deque ";
            return -1000;
        }
        return tail->val;
    }

    void display(){
        Node* temp = head;
        while(temp != NULL){
            cout << temp->val << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

int main(){
    Deque dq;
    dq.PushAtFront(30);
    dq.PushAtFront(20);
    dq.PushAtFront(10);
    dq.pushAtBack(40);
    dq.pushAtBack(50);
    dq.display();
    dq.popAtBack();
    dq.display();
    dq.popAtFront();
    dq.display();
    cout<<dq.front()<<endl;
    cout<<dq.back()<<endl;
}