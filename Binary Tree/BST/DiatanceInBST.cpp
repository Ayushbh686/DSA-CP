#include<iostream>
#include<queue>
#include<climits>
using namespace std;

class Node {
public:
    int val;
    Node* left;
    Node* right;

    Node(int val) {
        this->val = val;
        this->left = NULL;
        this->right = NULL;
    }
};

Node* construct(int arr[], int n) {
    if (n == 0) return NULL;

    queue<Node*> q;
    Node* root = new Node(arr[0]);
    q.push(root);

    int i = 1;
    while (!q.empty() && i < n) {
        Node* temp = q.front();
        q.pop();

        if (i < n && arr[i] != INT_MIN) {
            temp->left = new Node(arr[i]);
            q.push(temp->left);
        }
        i++;

        if (i < n && arr[i] != INT_MIN) {
            temp->right = new Node(arr[i]);
            q.push(temp->right);
        }
        i++;
    }

    return root;
}

int distanceFromRoot(Node* root, int x) {
    if (root == NULL) return 0;
    if (x == root->val) return 0;
    if (x > root->val) return 1 + distanceFromRoot(root->right, x);
    return 1 + distanceFromRoot(root->left, x);
}

int distance(Node* root, int val1, int val2) {
    if (root == NULL) return 0;

    if (root->val > val1 && root->val > val2) return distance(root->left, val1, val2);
    if (root->val < val1 && root->val < val2) return distance(root->right, val1, val2);

    // Found LCA
    return distanceFromRoot(root, val1) + distanceFromRoot(root, val2);
}

int main() {
    int arr[] = {1, 2, 3, 4, 5, INT_MIN, 6, INT_MIN, INT_MIN, 7, 8, 9};
    int n = sizeof(arr) / sizeof(arr[0]);
    Node* root = construct(arr, n);
    cout << "Distance between 2 and 6: " << distance(root, 2, 9) << endl;
    return 0;
}
