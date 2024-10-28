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

class LinkedList{
public:
    Node* head;
    Node* tail;
    int size;

    LinkedList(){
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
        tail = temp;
        size++;
    }

    void insertAtHead(int val){
        Node* temp = new Node(val);
        if(size == 0) head = tail = temp;
        else{
            temp->next = head;
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
            size++;
        }
    }

    int getAtIdx(int idx){
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
            delete temp; // Free the memory of the deleted node
            size--;
            if(size == 0) tail = NULL; // Update tail if the list is now empty
        }
    }

    void deleteAtTail(){
        if(size == 0) cout<<"Invalid operation\n";
        else{
            if(size == 1) {
                delete head; // Only one node in the list
                head = tail = NULL;
            } else {
                Node* temp = head;
                while(temp->next != tail){
                    temp = temp->next;
                }
                delete tail; // Free the memory of the last node
                tail = temp;
                tail->next = NULL;
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
    LinkedList ll;
    ll.insertAtTail(30);
    ll.display();
    cout << "size : " << ll.size << endl;
    ll.insertAtTail(40);
    ll.display();
    ll.insertAtTail(50);
    ll.display();
    ll.insertAtHead(20);
    ll.display();
    ll.insertAtHead(10);
    ll.display();
    cout << "size : " << ll.size << endl;    
    ll.insertAtIdx(25, 2); 
    ll.display(); 
    cout << "size : " << ll.size << endl;
    ll.insertAtIdx(35, 4);  
    ll.display();
    cout << "size : " << ll.size << endl;
    cout << "At index 4 : " << ll.getAtIdx(4) << endl;
    ll.deleteAtTail();
    ll.display();
    cout << "size : " << ll.size << endl;
    ll.deleteAtHead();
    ll.display();
    cout << "size : " << ll.size << endl;
    ll.deleteAtIdx(4);
    ll.display();
    cout << "size : " << ll.size << endl;
    return 0;
}
