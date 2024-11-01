#include<iostream>
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

void preorder(Node *root){ //pre order
    if(root == NULL) return;
    cout<<root->val<<" "; //root
    preorder(root->left); //left 
    preorder(root->right); //right
    return;
}

void inorder(Node *root){ 
    if(root == NULL) return;
    inorder(root->left);  //left
    cout<<root->val<<" "; //root
    inorder(root->right); //right
    return;
}

void postorder(Node *root){ 
    if(root == NULL) return;
    postorder(root->left);  //left
    postorder(root->right); //right
    cout<<root->val<<" "; //root
    return;
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

    inorder(a);
    cout<<endl; 
    preorder(a); 
    cout<<endl; 
    postorder(a); 
    
}

//can be 6 ways of work , call1 , call2 (permutation 6 ways)
//take help of euler tree for writting order without code make arrows of tree and each node has three type of arrows pre in post so write it accordingly
//tc = (o(size)) and sc = o(height) due to rec call stack and h = logn for balanced tree