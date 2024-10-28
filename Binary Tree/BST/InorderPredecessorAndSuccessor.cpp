#include<iostream>
#include<climits>
#include<queue>
using namespace std;

class Node{
public:
    int val;
    Node* left;
    Node* right;

    Node(int val){
        this->val = val;
        this->left = NULL;
        this->right = NULL;
    }
};

Node* construct(int arr[], int n){
    queue<Node*> q;
    int i=1, j = 2;
    Node* root = new Node(arr[0]);
    q.push(root);
    while(q.size() > 0){
        Node* temp = q.front();
        q.pop();
        if(i < n && arr[i] != INT_MIN) {
            temp->left = new Node(arr[i]);
            q.push(temp->left);
        }
        else temp->left = NULL;
        if(j < n && arr[j] != INT_MIN) {
            temp->right = new Node(arr[j]);
            q.push(temp->right);
        }
        else temp->right = NULL;
        i += 2;
        j += 2;
        if(i >= n && j >= n) break;
    }
    return root;
}

int predecessor(Node* root, int val){
    if(root == NULL) return 0;
    if(root->val == val){
        if(root->left == NULL) return root->val;
        Node* pred = root->left;
        while(pred->right != NULL) pred = pred->right;
        return pred->val;
    }
    if(root->val > val) return predecessor(root->left, val);
    else return predecessor(root->right, val);
}

int successor(Node* root, int val){
    if(root == NULL) return 0;
    if(root->val == val){
        if(root->right == NULL) return root->val;
        Node* succ = root->right;
        while(succ->left != NULL) succ = succ->left;
        return succ->val;
    }
    if(root->val > val) return successor(root->left, val);  // Corrected line
    else return successor(root->right, val);                // Corrected line
}

int main(){
    int arr[] = {4, 2, 6, 1, 3, 5, 7};
    int n = sizeof(arr)/sizeof(arr[0]);
    Node* root = construct(arr, n);
    cout << predecessor(root, 2) << endl;
    cout << successor(root, 2) << endl;
}
