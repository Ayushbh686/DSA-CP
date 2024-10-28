#include<iostream>
using namespace std;

class Node {
public:
    int val;
    Node* next;
    Node(int val) {
        this->val = val;
        this->next = NULL;
    }
};

class Stack {
public:
    Node* head;
    int size;

    Stack() {
        head = NULL;
        size = 0;
    }

    void push(int val) {
        Node* temp = new Node(val);
        temp->next = head;
        head = temp;
        size++;
    }

    void pop() {
        if (head == NULL) {
            cout << "stack underflow\n";
            return;
        }
        Node* temp = head;
        head = head->next;
        delete temp;
        size--;
    }

    int top() {
        if (head == NULL) {
            cout << "stack underflow\n";
            return -1; // Return an invalid value or handle error appropriately
        }
        return head->val;
    }

    int getSize() {
        return size;
    }

    void print(Node *temp){
        if(temp == NULL) return;
        print(temp->next);
        cout<<temp->val<<" ";
    }

    void display() {
        Node* temp = head;
        print(temp);
        cout<<endl;
        return;
    }
};

int main() {
    Stack stk;
    stk.pop();
    stk.push(10);
    stk.push(20);
    stk.push(30);
    stk.push(40);
    stk.push(50);
    cout << stk.top() << endl;
    cout << stk.getSize() << endl;
    stk.display();
    stk.pop();
    stk.display();
    cout<<stk.size;
}
