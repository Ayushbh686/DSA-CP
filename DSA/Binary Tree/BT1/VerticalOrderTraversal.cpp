// C++ code of Vertical Traversal of 
// a Binary Tree using BFS and Hash Map

#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
using namespace std;

class Node {
public:
    int data;
    Node *left, *right;
    Node(int x) {
        data = x;
        left = nullptr;
        right = nullptr;
    }
};

vector<vector<int>> verticalOrder(Node *root) {

      unordered_map<int, vector<int>> mp;
      int hd = 0;

      // Create a queue for level order traversal
      queue<pair<Node*, int>> q;
      q.push({ root, 0 });

      // mn and mx contain the minimum and maximum
      // horizontal distance from root
      int mn = 0, mx = 0;
      while (!q.empty()) {

        // Pop from queue front
        pair<Node*, int> curr = q.front();
        q.pop();

        Node* node = curr.first;
		hd = curr.second;

        // Insert this node's data in the
        // array of the 'hd' level in map
        mp[hd].push_back(node->data);

        if (node->left)
              q.push({ node->left, hd - 1 });
        if (node->right)
              q.push({ node->right, hd + 1 });

        // Update mn and mx
        mn = min(mn, hd);
        mx = max(mx, hd);
      }
  
      vector<vector<int>> res;
  
      // Traverse the map from minimum to 
      // maximum horizontal distance (hd)
      for (int i = mn; i <= mx; i++) {
          res.push_back(mp[i]);
      }
      return res;
}    

int main() {
  
    // Constructing the binary tree:
    //        1
    //       / \
    //      2   3
    //     / \ / \
    //    4  5 6  7
    //          \  \
    //           8  9
    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);
    root->right->left->right = new Node(8);
    root->right->right->right = new Node(9);
  
    vector<vector<int>> res = verticalOrder(root);
    
    for(vector<int> temp: res) {
        cout << "[ ";
        for (int val: temp) 
            cout << val << " ";
        cout << "] ";
    }
    
    return 0;
}
