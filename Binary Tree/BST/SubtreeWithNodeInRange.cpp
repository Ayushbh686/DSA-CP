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

//alternative
// int ans = 0;
// bool helper(TreeNode* root, int low, int high) {
// if (root == NULL) return true;
// bool l = helper(root->left, low, high);
// bool r = helper(root->right, low, high);
// if (l && r && low <= root->val && root->val <= high) {
// ans++; return true;
// }
// return false;
// }
// int getCount(TreeNode* root, int low, int high) {
// int count = 0;
// helper(root, low, high);
// return count;
// }



int subtreeInRange(Node* root , int lo , int hi ){
    if(root == NULL) return 0;
    int ans = 0;
    if(root->left) ans += subtreeInRange(root->left , lo , hi );
    if(root->right) ans += subtreeInRange(root->right , lo , hi);
    if(root->val >= lo and root->val <= hi ){
        ans++;
    }
    return ans;
}

int main(){
    int arr[] = {10 , 5, 50 , 1 , INT_MIN , 40 , 100};
    int n = sizeof(arr)/sizeof(arr[0]);
    Node* root = construct(arr,n);
    cout<<subtreeInRange(root , 5 , 45);
    return 0;
}