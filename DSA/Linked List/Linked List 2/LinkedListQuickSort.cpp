#include <bits/stdc++.h>
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

// Function to partition the linked list
Node* partition(Node* head, Node* tail, Node** newHead, Node** newTail) {
    Node* pivot = tail; // Choosing pivot as the last element
    Node* prev = NULL, *curr = head, *last = pivot;
    
    Node* smallHead = NULL, *smallTail = NULL;
    Node* largeHead = NULL, *largeTail = NULL;

    // Partition the list
    while (curr != pivot) {
        Node* nextNode = curr->next;
        if (curr->val < pivot->val) {
            if (!smallHead) {
                smallHead = curr;
                smallTail = curr;
            } else {
                smallTail->next = curr;
                smallTail = curr;
            }
        } else {
            if (!largeHead) {
                largeHead = curr;
                largeTail = curr;
            } else {
                largeTail->next = curr;
                largeTail = curr;
            }
        }
        curr = nextNode;
    }

    // Connecting partitions
    if (smallTail) {
        *newHead = smallHead;
        smallTail->next = pivot;
    } else {
        *newHead = pivot;
    }

    pivot->next = largeHead;
    *newTail = (largeTail) ? largeTail : pivot;

    return pivot;
}

// Recursive QuickSort function
Node* quickSortRecur(Node* head, Node* tail) {
    if (!head || head == tail)
        return head;

    Node* newHead = NULL, *newTail = NULL;
    Node* pivot = partition(head, tail, &newHead, &newTail);

    if (newHead != pivot) {
        Node* temp = newHead;
        while (temp->next != pivot)
            temp = temp->next;
        temp->next = NULL;

        newHead = quickSortRecur(newHead, temp);
        temp = newHead;
        while (temp->next)
            temp = temp->next;
        temp->next = pivot;
    }

    pivot->next = quickSortRecur(pivot->next, newTail);
    
    return newHead;
}

// Wrapper function
Node* quickSort(Node* head) {
    if (!head) return NULL;
    Node* tail = head;
    while (tail->next) tail = tail->next;
    return quickSortRecur(head, tail);
}

// Function to print linked list
void printList(Node* head) {
    while (head) {
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
}

// Driver Code
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        Node* head = NULL, *tail = NULL;

        for (int i = 0; i < n; i++) {
            int x;
            cin >> x;
            Node* newNode = new Node(x);
            if (!head) {
                head = newNode;
                tail = newNode;
            } else {
                tail->next = newNode;
                tail = tail->next;
            }
        }

        head = quickSort(head);
        printList(head);
    }
    return 0;
}
