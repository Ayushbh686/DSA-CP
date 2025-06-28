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

    int dfs(TreeNode* root , int &ans){
        if(root == NULL) return 0;
        int l = dfs(root->left , ans);
        int r = dfs(root->right , ans);
        ans = max({ans , root->val + l + r , root->val + l , root->val + r , root->val});
        return max({root->val , root->val + l , root->val + r});
    }

    int maxPathSum(TreeNode* root) {
        int ans = INT_MIN;
        dfs(root , ans);
        return ans;
    }
};


//method 2

// class Solution {
//     /*int ans = INT_MIN;
//     int dfs(TreeNode* root){
//         if(!root) return 0;
//         int leftsum = dfs(root->left);
//         int rightsum = dfs(root->right);
//         ans = max({
//             ans, root->val + leftsum + rightsum, root->val+leftsum, root->val+rightsum, root->val});
//         return max({root->val + leftsum , root->val + rightsum, root->val, 0});
//     }*/
//     int ans = INT_MIN;
//     int dfs(TreeNode* root){
//         if(!root) return 0;
//         int leftsum = max(0, dfs(root->left));
//         int rightsum = max(0, dfs(root->right));
//         ans = max(ans, root->val + leftsum + rightsum);
//         return root->val + max(leftsum , rightsum);
//     }
// public:
//     int maxPathSum(TreeNode* root) {
//         dfs(root);
//         return ans;
//     }
// };
