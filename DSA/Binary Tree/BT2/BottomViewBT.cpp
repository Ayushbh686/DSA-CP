#include <iostream>
#include <queue>
#include <unordered_map>
#include <climits>
using namespace std;

class Node {
public:
    int val;
    Node* left;
    Node* right;

    Node(int val) {
        this->val = val;
        this->left = NULL;
        this->right = NULL;
    }
};

Node* construct(int arr[], int n) {
    if (n == 0) return NULL;
    
    queue<Node*> q;
    Node* root = new Node(arr[0]);
    q.push(root);
    int i = 1;

    while (!q.empty() && i < n) {
        Node* temp = q.front();
        q.pop();

        if (i < n && arr[i] != INT_MIN) {
            temp->left = new Node(arr[i]);
            q.push(temp->left);
        }
        i++;

        if (i < n && arr[i] != INT_MIN) {
            temp->right = new Node(arr[i]);
            q.push(temp->right);
        }
        i++;
    }

    return root;
}

// void BottomViewBT(Node* root) {
//     if (!root) return;

//     queue<pair<Node*, pair<int, int>>> q; // Node, {horz, vert}
//     unordered_map<int, pair<int, int>> mp; // vert level, {horz level, root->val}
//     q.push({root, {0, 0}});

//     while (!q.empty()) {
//         Node* temp = q.front().first;
//         int horz = q.front().second.first;
//         int vert = q.front().second.second;
//         q.pop();

//         if (mp.find(vert) != mp.end()) {
//             if (mp[vert].first <= horz) {
//                 mp[vert] = {horz, temp->val};
//             }
//         } else {
//             mp[vert] = {horz, temp->val};
//         }

//         if (temp->left) {
//             q.push({temp->left, {horz + 1, vert - 1}});
//         }
//         if (temp->right) {
//             q.push({temp->right, {horz + 1, vert + 1}});
//         }
//     }

//     int minLevel = INT_MAX;
//     int maxLevel = INT_MIN;
//     for (auto ele : mp) {
//         minLevel = min(minLevel, ele.first);
//         maxLevel = max(maxLevel, ele.first);
//     }

//     for (int i = minLevel; i <= maxLevel; ++i) {
//         cout << mp[i].second << " ";
//     }
// }

void BottomViewBT(Node* root){
    queue<pair<Node* , int>> q; //node , level
    unordered_map<int , int> mp; // level , root->Val
    pair<Node* , int> r;
    r.first = root;
    r.second = 0;
    q.push(r);
    while(!q.empty()){
        Node* temp = (q.front()).first;
        int level = (q.front()).second;
        q.pop();
        mp[level] = temp->val;
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

int main() {
    int arr[] = {1, 2, 3, 4, 5, INT_MIN, 6, INT_MIN, INT_MIN, 7, 8, 9, INT_MIN};
    int n = sizeof(arr) / sizeof(arr[0]);
    Node* root = construct(arr, n);
    BottomViewBT(root);
    return 0;
}
