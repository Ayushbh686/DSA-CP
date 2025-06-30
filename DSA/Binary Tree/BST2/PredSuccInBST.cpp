#include <iostream>
#include <vector>
using namespace std;

class Node {
public:
    int data;
    Node *left, *right;
    Node(int x) {
        data = x;
        left = right = nullptr;
    }
};

Node* rightMost(Node* node) {
    while (node->right != nullptr) {
        node = node->right;
    }
    return node;
}

Node* leftMost(Node* node) {
    while (node->left != nullptr) {
        node = node->left;
    }
    return node;
}

// Return predecessor and successor as a vector<Node*>
vector<Node*> findPreSuc(Node* root, int key) {
    Node* pre = nullptr;
    Node* suc = nullptr;
    Node* curr = root;

    while (curr != nullptr) {
        if (curr->data < key) {
            pre = curr;
            curr = curr->right;
        } else if (curr->data > key) {
            suc = curr;
            curr = curr->left;
        } else {
            if (curr->left != nullptr)
                pre = rightMost(curr->left);
            if (curr->right != nullptr)
                suc = leftMost(curr->right);
            break;
        }
    }

    return {pre, suc};  
}

int main() {
    int key = 65;

    Node* root = new Node(50);
    root->left = new Node(30);
    root->right = new Node(70);
    root->left->left = new Node(20);
    root->left->right = new Node(40);
    root->right->left = new Node(60);
    root->right->right = new Node(80);

    vector<Node*> result = findPreSuc(root, key);
    Node* pre = result[0];
    Node* suc = result[1];

    if (pre != nullptr)
        cout << pre->data << " ";
    else
        cout << -1 << " ";

    if (suc != nullptr)
        cout << suc->data << endl;
    else
        cout << -1 << endl;

    return 0;
}