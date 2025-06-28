/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    //method 1 (storing in array)
    // void preOrder(TreeNode* root , vector<TreeNode*> &nodes){
    //     if(root == NULL) return;
    //     nodes.push_back(root);
    //     preOrder(root->left , nodes);  
    //     preOrder(root->right , nodes);
    //     return;  
    // }

    // void flatten(TreeNode* root) {
    //     vector<TreeNode*> nodes;
    //     preOrder(root , nodes);

    //     for(int i=0 ; i<nodes.size() ; i++){
    //         nodes[i]->left = NULL;
    //         if(i != nodes.size()-1) nodes[i]->right = nodes[i+1];
    //         else nodes[i]->right = NULL;
    //     }

    //     return ;
    // }


    //method 2(iterative , stack)
    //void flatten(TreeNode* root) {
    //     if (root == NULL) return;

    //     stack<TreeNode*> stk;
    //     stk.push(root);

    //     while (!stk.empty()) {
    //         TreeNode* curr = stk.top();
    //         stk.pop();

    //         if (curr->right) {
    //             stk.push(curr->right);
    //         }
    //         if (curr->left) {
    //             stk.push(curr->left);
    //         }

    //         if (!stk.empty()) {
    //             curr->right = stk.top();
    //         }

    //         curr->left = NULL;
    //     }
    // }

    //method 3 recurisve method 
    // void flatten(TreeNode* root){
    //     if(root == NULL) return ;
    //     TreeNode* l = root->left;
    //     TreeNode* r = root->right;
    //     root->left = NULL;
    //     root->right = NULL;
    //     flatten(l);
    //     flatten(r);
    //     root->right = l;
    //     TreeNode* temp = root;
    //     while(temp->right){
    //         temp = temp->right;
    //     }
    //     temp->right = r;
    //     return;
    // }


    //method 4(morris traversal) (no space complexity , best one)
    void flatten(TreeNode* root){
        if(root == NULL) return ;
        TreeNode* curr = root;

        while(curr != NULL){
            if(curr->left){
                TreeNode* pred = curr->left;
                while(pred->right) pred = pred->right;
                pred->right = curr->right;
                curr->right = curr->left;
                curr->left = NULL; 
            }
            curr = curr->right;
        }
        return;
    }
};