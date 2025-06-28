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

int main(){
    int arr[] = {1,2,3,4,5,INT_MIN, 6,INT_MIN,INT_MIN , 7,8,9};
    int n = sizeof(arr)/sizeof(arr[0]);
    Node* root = construct(arr,n);
    LevelOrderQueue(root);
    cout<<endl;
    LevelOrderQueueRtoL(root);
}