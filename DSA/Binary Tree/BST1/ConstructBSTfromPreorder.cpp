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

    // TreeNode* build(vector<int>& nums , int lo , int hi){
    //     if(lo>hi) return NULL;
    //     int mid = lo + (hi - lo)/2;
    //     TreeNode* root = new TreeNode(nums[mid]);
    //     root->left = build(nums , lo , mid-1);
    //     root->right = build(nums , mid+1 , hi);
    //     return root;
    // }
    //cant use it as its not required to make balanced binary search tree

    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if(root == NULL) return new TreeNode(val);
        else if(root->val < val){
            if(root->right == NULL){
                root->right = new TreeNode(val);
                return root;
            }
            else{
                insertIntoBST(root->right , val);
            }
        }

        else if(root->val > val){
            if(root->left == NULL){
                root->left = new TreeNode(val);
                return root;
            }
            else{
                insertIntoBST(root->left , val);
            }
        }
        return root;
    }

    TreeNode* bstFromPreorder(vector<int>& pre) {
        TreeNode* root = new TreeNode(pre[0]);
        for(int i=1 ; i<pre.size() ; i++){
            insertIntoBST(root , pre[i]);
        }
        return root;
    }
};
//alternative is to make the inorder by sorting preorder and use code of making bt from preorder and inorder