#include<iostream>
#include<queue>
#include<climits>
using namespace std;

class Node{
public:
    int val;
    Node* left ;
    Node* right ;

    Node(int val){
        this->val = val;
        this->left = NULL;
        this->right = NULL;
    }
};

Node* construct(int arr[],int n){
    queue<Node*> q;
    int i=1 , j = 2;
    Node* root = new Node(arr[0]);
    q.push(root);
    while(q.size()>0 ){
        Node* temp = q.front();
        q.pop();
        if(i<n and arr[i]!=INT_MIN) {
            temp->left = new Node(arr[i]);
            q.push(temp->left);
        }
        else temp->left = NULL;
        if(j<n and arr[j]!=INT_MIN) {
            temp->right = new Node(arr[j]);
            q.push(temp->right);
        }
        else temp->right = NULL;
        i+=2;
        j+=2;
        if(i>n and j>n) break;
    }
    return root;
}

void leftBoundary(Node* root){
    if(root == NULL) return ;
    if(root->left == NULL and root->right == NULL) return ;
    cout<<root->val<<" ";
    leftBoundary(root->left);
    if(root->left == NULL) leftBoundary(root->right);
    return ;
}

void leafNode(Node* root){
    if(root == NULL) return ;
    if(root->left == NULL and root->right == NULL) cout<<root->val<<" ";
    leafNode(root->left);
    leafNode(root->right);
    return ;
}

void rightBoundary(Node* root){
    if(root == NULL) return ;
    if(root->left == NULL and root ->right == NULL) return;
    rightBoundary(root->right);
    if(root->right == NULL) rightBoundary(root->left);
    cout<<root->val<<" ";
    return ;
}

void boundaryTraversal(Node* root){
    leftBoundary(root);
    leafNode(root);
    rightBoundary(root);
    return ;
}

int main(){
    int arr[] = {1,2,3,4,5,INT_MIN, 6,INT_MIN,INT_MIN , 7,8,9};
    int n = sizeof(arr)/sizeof(arr[0]);
    Node* root = construct(arr,n);
    boundaryTraversal(root);
    return 0;
}

//iterative version

/*
                            
#include <iostream>
#include <vector>

using namespace std;

// Node structure for the binary tree
struct Node {
    int data;
    Node* left;
    Node* right;
    // Constructor to initialize
    // the node with a value
    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    // Function to check
    // if a node is a leaf
    bool isLeaf(Node* root) {
        return !root->left && !root->right;
    }

    // Function to add the
    // left boundary of the tree
    void addLeftBoundary(Node* root, vector<int>& res) {
        Node* curr = root->left;
        while (curr) {
            // If the current node is not a leaf,
            // add its value to the result
            if (!isLeaf(curr)) {
                res.push_back(curr->data);
            }
            // Move to the left child if it exists,
            // otherwise move to the right child
            if (curr->left) {
                curr = curr->left;
            } else {
                curr = curr->right;
            }
        }
    }

    // Function to add the
    // right boundary of the tree
    void addRightBoundary(Node* root, vector<int>& res) {
        Node* curr = root->right;
        vector<int> temp;
        while (curr) {
            // If the current node is not a leaf,
            // add its value to a temporary vector
            if (!isLeaf(curr)) {
                temp.push_back(curr->data);
            }
            // Move to the right child if it exists,
            // otherwise move to the left child
            if (curr->right) {
                curr = curr->right;
            } else {
                curr = curr->left;
            }
        }
        // Reverse and add the values from
        // the temporary vector to the result
        for (int i = temp.size() - 1; i >= 0; --i) {
            res.push_back(temp[i]);
        }
    }

    // Function to add the
    // leaves of the tree
    void addLeaves(Node* root, vector<int>& res) {
        // If the current node is a
        // leaf, add its value to the result
        if (isLeaf(root)) {
            res.push_back(root->data);
            return;
        }
        // Recursively add leaves of
        // the left and right subtrees
        if (root->left) {
            addLeaves(root->left, res);
        }
        if (root->right) {
            addLeaves(root->right, res);
        }
    }

    // Main function to perform the
    // boundary traversal of the binary tree
    vector<int> printBoundary(Node* root) {
        vector<int> res;
        if (!root) {
            return res;
        }
        // If the root is not a leaf,
        // add its value to the result
        if (!isLeaf(root)) {
            res.push_back(root->data);
        }

        // Add the left boundary, leaves,
        // and right boundary in order
        addLeftBoundary(root, res);
        addLeaves(root, res);
        addRightBoundary(root, res);

        return res;
    }
};

// Helper function to
// print the result
void printResult(const vector<int>& result) {
    for (int val : result) {
        cout << val << " ";
    }
    cout << endl;
}

int main() {
    // Creating a sample binary tree
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);

    Solution solution;

    // Get the boundary traversal
    vector<int> result = solution.printBoundary(root);

    // Print the result
    cout << "Boundary Traversal: ";
    printResult(result);

    return 0;
}
                            
                        
*/