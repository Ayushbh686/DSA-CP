
#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int data;
    Node* npx;

    Node(int x) {
        data = x;
        npx = nullptr;
    }
};

// XOR function to get XOR of two pointers
Node* XOR(Node* a, Node* b) {
    return reinterpret_cast<Node*>(reinterpret_cast<uintptr_t>(a) 
           ^ reinterpret_cast<uintptr_t>(b));
}

// Function to insert a node at the front of the list
Node* insert(Node* head, int data) {
  
    // Create a new node with the given data
    Node* new_node = new Node(data);

    // Make the new node's npx point to the head
    new_node->npx = XOR(head, nullptr);

    // Update npx of the head if it's not NULL
    if (head != nullptr) {
        Node* next = XOR(head->npx, nullptr);
        head->npx = XOR(new_node, next);
    }

    // Return the new node as the new head
    return new_node;
}

// Function to retrieve the list as a vector
vector<int> getList(Node* head) {
    vector<int> vec;
    Node* curr = head;
    Node* prev = nullptr;
    Node* next;

    while (curr != nullptr) {
        // Add current node's data to vector
        vec.push_back(curr->data);

        // Calculate the next node using XOR
        next = XOR(prev, curr->npx);

        // Update previous and current nodes
        prev = curr;
        curr = next;
    }

    return vec;
}

int main() {
 
   // Create a hard-coded linked list:
   // 40 <-> 30 <-> 20 <-> 10 (since we insert at the
    // front)
    Node* head = nullptr;

    head = insert(head, 10);
    head = insert(head, 20);
    head = insert(head, 30);
    head = insert(head, 40);

    vector<int> list = getList(head);
  
    for(int i = 0; i < list.size(); ++i) {
        cout<< list[i] <<" ";
    }
    cout << endl;
  
    for(int i = list.size() - 1; i >= 0; --i) {
        cout<< list[i] <<" ";
    }
    cout << endl;

    return 0;
}