#include<iostream>
#include<queue>
#include<unordered_map>
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

void TopViewBT(Node* root){
    queue<pair<Node* , int>> q; //node , vertcal level
    unordered_map<int , int> mp; // vertical level , root->Val
    pair<Node* , int> r;
    r.first = root;
    r.second = 0;
    q.push(r);
    while(!q.empty()){
        Node* temp = (q.front()).first;
        int level = (q.front()).second;
        q.pop();
        if(mp.find(level) == mp.end()) mp[level] = temp->val;
        if(temp->left){
            pair<Node* , int> p;
            p.first = temp->left;
            p.second = level - 1;
            q.push(p); 
        }
        if(temp->right){
            pair<Node* , int> p;
            p.first = temp->right;
            p.second = level + 1;
            q.push(p); 
        }
    }
    int minLevel = INT_MAX , maxLevel = INT_MIN;
    for(auto ele : mp){
        minLevel = min(minLevel , ele.first);
        maxLevel = max(maxLevel , ele.first);
    }

    for(int i=minLevel ; i<=maxLevel ; i++){
        cout<<mp[i]<<" ";
    }
    return ;
}

int main(){
    int arr[] = {1,2,3,4,5,INT_MIN, 6,INT_MIN,INT_MIN , 7,8,9,INT_MIN};
    int n = sizeof(arr)/sizeof(arr[0]);
    Node* root = construct(arr,n);
    TopViewBT(root);
}