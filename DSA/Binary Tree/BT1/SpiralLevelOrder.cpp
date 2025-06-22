#include <iostream>
#include <vector>
#include <deque>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int x) {
        data = x;
        left = nullptr;
        right = nullptr;
    }
};

vector<int> findSpiral(Node* root)
{
    vector<int> res;
    if (!root) return res;

    deque<Node*> dq;
    dq.push_back(root);

    bool reverse = true;

    while (!dq.empty()) {
        int n = dq.size();

        while (n--) {
            
            // Push right first if reverse is true
            if (reverse) {
                Node* curr = dq.back();
                dq.pop_back();
                res.push_back(curr->data);

                if (curr->right) dq.push_front(curr->right);
                if (curr->left)  dq.push_front(curr->left);
            }
            
            // Else push left first
            else {
                Node* curr = dq.front();
                dq.pop_front();
                res.push_back(curr->data);

                if (curr->left)  dq.push_back(curr->left);
                if (curr->right) dq.push_back(curr->right);
            }
        }

        reverse = !reverse;
    }

    return res;
}

int main()
{
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(7);
    root->left->right = new Node(6);
    root->right->left = new Node(5);
    root->right->right = new Node(4);

    vector<int> res = findSpiral(root);

    for (int x : res)
        cout << x << "  ";

    return 0;
}