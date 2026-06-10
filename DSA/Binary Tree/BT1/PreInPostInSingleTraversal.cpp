#include<bits/stdc++.h>
using namespace std;

struct Node {
    int val;
    struct Node *left, *right;

    Node(int val)
    {
        this->val = val;
        left = right = NULL;
    }
};

void allTraversal(Node* root){
    if(root == NULL) return;

    vector<int>pre , in , post;
    
    stack<pair<Node* , int>> stk;

    stk.push({root , 1}); 

    /*
    1 means arrived at this node first time so push it now to preorder and update value to 2 and go to left subtree like recursion of dfs
    2 means arrived after completing left subtree now update number to 3 and push in into inorder and push into stack the right subtree like normal recursion of dfs
    3 means arrived this node at end after completing the right subtree so this means pop this one and push to postorder and this is where normal recursive call ends so no more push to stack
    */

    while(!stk.empty()){
        pair<Node* , int> p = stk.top();
        stk.pop();

        if(p.second == 1){
            stk.push({p.first , 2});

            pre.push_back(p.first->val);

            if(p.first->left){
                stk.push({p.first->left , 1});
            }
        }
        else if(p.second == 2){
            stk.push({p.first , 3});

            in.push_back(p.first->val);

            if(p.first->right){
                stk.push({p.first->right , 1});
            }
        }
        else{
           post.push_back(p.first->val); 
        }
    }

    cout << "Preorder Traversal: ";
    for (int i = 0; i < pre.size(); i++) {
        cout << pre[i] << " ";
    }
    cout << "\n";

    // Printing Inorder
    cout << "Inorder Traversal: ";

    for (int i = 0; i < in.size(); i++) {
        cout << in[i] << " ";
    }
    cout << "\n";

    // Printing Postorder
    cout << "Postorder Traversal: ";

    for (int i = 0; i < post.size(); i++) {
        cout << post[i] << " ";
    }
    cout << "\n";
}

int main()
{

    // Creating the root
    struct Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);

    // Function call
    allTraversal(root);

    return 0;
}