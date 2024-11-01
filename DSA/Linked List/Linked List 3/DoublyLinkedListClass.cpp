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

class DLL{
public:
    Node* head;
    Node* tail;
    int size;

    DLL(){
        head = tail = NULL;
        size = 0;
    }

    void insertAtTail(int val){
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

    void insertAtHead(int val){
        Node* temp = new Node(val);
        if(size == 0) head = tail = temp;
        else{
            temp->next = head;
            head->prev = temp;
            head = temp;
        }
        size++;
    }

    void insertAtIdx(int val , int idx){
        if(idx < 0 || idx > size) cout<<"Invalid operation\n";
        else if(idx == 0) insertAtHead(val);
        else if(idx == size) insertAtTail(val);
        else{
            Node* temp = new Node(val);
            Node* temp2 = head;
            for(int i = 1; i <= idx - 1; i++){
                temp2 = temp2->next;
            } 
            temp->next = temp2->next;
            temp2->next = temp;
            temp->prev = temp2;
            temp->next->prev = temp;
            size++;
        }
    }

    int getAtIdx(int idx){ // other option is if the idx is greater then size/2 then traverse from tail to index
        if(idx < 0 || idx >= size) {
            cout<<"Invalid operation\n";
            return -1000;
        }
        else if(idx == 0) return head->val;
        else if(idx == size - 1) return tail->val;
        else{
            Node* temp = head;
            for(int i = 0; i < idx; i++){
                temp = temp->next;
            }
            return temp->val;
        }
    }

    void deleteAtHead(){
        if(size == 0) cout<<"Invalid operation\n";
        else{
            Node* temp = head;
            head = head->next;
            if(head != NULL) head->prev = NULL;
            if(head == NULL) tail = NULL;
            size--;
        }
    }

    void deleteAtTail(){
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

    void deleteAtIdx(int idx){
        if(size == 0) cout<<"Invalid operation\n";
        else if(idx < 0 || idx >= size) cout<<"Invalid operation\n";
        else if(idx == 0) deleteAtHead();
        else if(idx == size - 1) deleteAtTail();
        else{
            Node* temp = head;
            for(int i = 1; i <= idx - 1; i++){
                temp = temp->next;
            }
            Node* nodeToDelete = temp->next;
            temp->next = nodeToDelete->next;
            delete nodeToDelete; // Free the memory of the deleted node
            temp->next->prev = temp;
            size--;
        }
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
    DLL list;
    list.insertAtTail(10);
    list.insertAtTail(20);
    list.insertAtTail(30);
    list.insertAtTail(40);
    list.display();
    list.insertAtHead(5);
    list.display();
    list.deleteAtHead();
    list.display();
    list.deleteAtTail();
    list.display();
    list.deleteAtIdx(1);
    list.display();
    list.insertAtTail(90);
    cout<<list.getAtIdx(1);
}