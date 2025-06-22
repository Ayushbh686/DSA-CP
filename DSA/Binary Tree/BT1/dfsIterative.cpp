#include<iostream>
#include<climits>
#include<stack>
#include<vector>
#include<algorithm>
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

void preOrderItr(Node* root ){
        if(root == NULL) return ;
        stack<Node*>stk;
        stk.push(root);
        while(!stk.empty()){
            Node* temp = stk.top();
            stk.pop();
            cout<<temp->val<<" ";
            if(temp->right) stk.push(temp->right);
            if(temp->left) stk.push(temp->left);
        }
        return ;
    }

void inOrderItr(Node* root) {
  if (root == NULL) return;
  stack<Node*> stk;
  Node* current = root;

  while (!stk.empty() || current != NULL) {
    if (current != NULL) {
      stk.push(current);
      current = current->left;
    } else {
      current = stk.top();
      stk.pop();
      cout << current->val << " ";
      current = current->right;
    }
  }
}

void postOrderItr(Node* root, vector<int> ans) { //effective using 2 storages that is one stack + one vector or one stack + one stack for reversal
        if(root == NULL) return ;
        stack<Node*>stk;
        stk.push(root);
        while(!stk.empty()){
            Node* temp = stk.top();
            stk.pop();
            ans.push_back(temp->val);
            if(temp->left) stk.push(temp->left);
            if(temp->right) stk.push(temp->right);
        }
        //root right left reverse it and get left right root which is post order
        reverse(ans.begin() , ans.end());
        for(int i=0 ; i<ans.size() ; i++) cout<<ans[i]<<" ";
        return ;
    }

void postOrderItr2(Node* root) { //using single o(n) storage one stack (it mimics recursion call for post order)
    if (!root) return;

    stack<Node*> s;
    Node* lastVisited = nullptr;

    while (!s.empty() || root) {
        
        // Keep moving to the left 
        // until we reach a null
        if (root) {
            s.push(root);
            root = root->left;
        }
        else {
            
            // Take out an item from stack
            Node* peekNode = s.top();
            
            // If the taken out item has a 
            // right child and the right child
            // is not visited, move to the right
            if (peekNode->right && lastVisited != peekNode->right) {
                root = peekNode->right;
                
            // If there is no right child
            // or the right child is already
            // visited, then add peekNode to the
            // result and remove from the stack
            } else {
                lastVisited = s.top();
                cout<<s.top()->val<<" "; //peekNode->val
                s.pop();
            }
        }
    }

    return ;
}


int main(){
    Node* a = new Node(1); // root of tree
    Node* b = new Node(2);
    Node* c = new Node(3);
    Node* d = new Node(4);
    Node* e = new Node(5);
    Node* f = new Node(6);
    Node* g = new Node(7);

    a->left = b;
    a->right = c;
    b->left = d;
    b->right = e;
    c->left = f;
    c->right = g;

    preOrderItr(a);
    cout<<endl;
    postOrderItr(a, vector<int> {} );  // Create and pass an empty vector
    cout<<endl;
    postOrderItr2(a );  // Create and pass an empty vector
    cout<<endl;
    inOrderItr(a);
    return 0;
}