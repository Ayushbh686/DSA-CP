#include<iostream>
#include<climits>
#include<queue>
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

Node* minm(Node* root){
    if(root == NULL or root->left == NULL) return root;
    return minm(root->left);
}

Node* maxm(Node* root){
    if(root == NULL or root->right == NULL) return root;
    return maxm(root->right);
}

int main(){
    int arr[] = {4 , 2 , 6 , 1 , 3 , 5 , 7};
    int n = sizeof(arr)/sizeof(arr[0]);
    Node* root = construct(arr,n);
    Node* minNode = minm(root);
    Node* maxNode = maxm(root);
    cout<<minNode->val<<" "<<maxNode->val;
}