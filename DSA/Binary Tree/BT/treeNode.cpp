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

void displayTree(Node *root){ //pre order
    if(root == NULL) return;
    cout<<root->val<<" ";
    displayTree(root->left);
    displayTree(root->right);
    return;
}

int sum(Node *root){
    if(root == NULL) return 0;
    return root->val + sum(root->left) + sum(root->right);
}

int product(Node* root){
    if(root == NULL) return 1;
    return root->val * product(root->left) * product(root->right);
}

int size(Node *root){
    if(root == NULL) return 0;
    return 1 + size(root->left) + size(root->left);
}

int maxVal(Node* root){
    if(root == NULL) return INT_MIN;
    return max(root->val , max(maxVal(root->left) , maxVal(root->right)) );
}

int minVal(Node* root){
    if(root == NULL) return INT_MAX;
    return min(root->val , min(minVal(root->left) , minVal(root->right)) );
}

int levels(Node* root){
    if(root == NULL) return 0;
    return 1 + max(levels(root->left) , levels(root->right));
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

    displayTree(a);
    cout<<endl;
    cout<<"sum : "<<sum(a);
    cout<<endl;
    cout<<"size : "<<size(a);
    cout<<endl;
    cout<<"maximum Value : "<<maxVal(a);
    cout<<endl;
    cout<<"minimum Value : "<<minVal(a);
    cout<<endl;
    cout<<"Levels : "<<levels(a);
    cout<<endl;
    cout<<"product : "<<product(a);
}