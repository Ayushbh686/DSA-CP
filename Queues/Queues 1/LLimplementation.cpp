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

class Queue {
public:
    Node* head;
    Node* tail;
    int size;

    Queue() {  // Constructor should be named Queue
        head = tail = NULL;
        size = 0;
    }

    void push(int val) {
        Node* temp = new Node(val);
        if (size == 0) {
            head = tail = temp;
        } else {
            tail->next = temp;
            tail = temp;
        }
        size++;
    }

    void pop() {
        if (size == 0) {
            cout << "Queue Empty\n";
        } else {
            Node* temp = head;
            head = head->next;
            delete temp; // Free the memory of the deleted node
            size--;
            if (size == 0) tail = NULL; // Update tail if the list is now empty
        }
    }

    int front() {
        if (head == NULL) {
            cout << "Empty List ";
            return -1000;
        }
        return head->val;
    }

    int back() {
        if (tail == NULL) {
            cout << "Empty List ";
            return -1000;
        }
        return tail->val;
    }

    void display() {
        Node* temp = head;
        while (temp != NULL) {
            cout << temp->val << " ";
            temp = temp->next;
        }
        cout << endl;
    }

    int getSize() {
        return size;
    }
};

int main() {
    Queue q;
    cout << q.getSize() << endl; // Access size through a function
    q.push(10);
    q.push(20);
    q.push(30);
    q.push(40);
    q.push(50);
    q.push(60); // front(pop) 10 20 30 40 50 back(push) , in stack no front (its closed) only back for pop and push and its top
    q.display();
    cout << q.front() << endl;
    cout << q.back() << endl;
    cout << q.getSize() << endl;
    q.pop();
    q.display();
    q.push(10); // problem here thats the limitation of array implementation (wasting of space cant push further if back reaches at limit) but not in LL implementation
    cout << q.front() << endl;
    cout << q.back() << endl;
    cout << q.getSize() << endl;
    q.pop();
    q.pop();
    q.pop();
    q.pop();
    q.pop();
    q.display();
    cout << q.getSize() << endl;
    q.push(70);
    q.display();
    return 0;
}
