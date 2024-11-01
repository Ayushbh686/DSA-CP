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

int levels(Node* root){
    if(root == NULL) return 0;
    return 1 + max(levels(root->left) , levels(root->right));
}

void nthLevel(Node* root , int level , int n){   //level order traversal using dfs
    if(root == NULL) return;
    if(level == n) {
        cout<<root->val<<" ";
        return ;
    }  // work
    nthLevel(root->left , level+1 , n); //left
    nthLevel(root->right , level +1 , n); //right
}

void nthLevelRev(Node* root , int level , int n){   //level order traversal using dfs
    if(root == NULL) return;
    if(level == n) {
        cout<<root->val<<" ";
        return ;
    }  // work
    nthLevel(root->right , level +1 , n); //right
    nthLevel(root->left , level+1 , n); //left
}

void LevelOrder(Node* root){
    int n = levels(root);
    for(int i=1 ; i<=n ; i++){
        nthLevel(root , 1 , i);
        cout<<endl;
    }
    return ;
}

void LevelOrderQueue(Node* root){ // BFS TRAVERSAL
    queue<Node*> q;
    q.push(root);
    while(!q.empty()){
        Node* temp = q.front();
        q.pop();
        cout<<temp->val<<" ";
        if(temp->left != NULL) q.push(temp->left);
        if(temp->right != NULL) q.push(temp->right);
    }
}

void LevelOrderQueueRtoL(Node* root){ // BFS TRAVERSAL
    queue<Node*> q;
    q.push(root);
    while(!q.empty()){
        Node* temp = q.front();
        q.pop();
        cout<<temp->val<<" ";
        if(temp->right != NULL) q.push(temp->right);
        if(temp->left != NULL) q.push(temp->left);
    }
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

    LevelOrder(a);
    cout<<endl;
    LevelOrderQueue(a);
    cout<<endl;
    LevelOrderQueueRtoL(a);
    return 0;
}