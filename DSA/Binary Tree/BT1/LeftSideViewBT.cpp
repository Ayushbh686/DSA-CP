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

void LeftView(Node* root , vector<int> &ans , int level){
    if(root == NULL) return ;
    if(level == ans.size()) ans.push_back(root->val);
    LeftView(root->left , ans , level+1);
    LeftView(root->right , ans , level+1);
    return ;
}

int main(){
    int arr[] = {1,2,3,4,5,INT_MIN, 6,INT_MIN,INT_MIN , 7,8,9};
    int n = sizeof(arr)/sizeof(arr[0]);
    Node* root = construct(arr,n);
    vector<int> ans;
    LeftView(root, ans , 0);
    for(int i=0 ; i<ans.size() ; i++) cout<<ans[i]<<" ";
    return 0;
}