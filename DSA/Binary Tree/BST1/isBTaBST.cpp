// /**
//  * Definition for a binary tree node.
//  * struct TreeNode {
//  *     int val;
//  *     TreeNode *left;
//  *     TreeNode *right;
//  *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
//  *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
//  *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
//  * };
//  */
// class Solution {
// public:

//     void inOrder(TreeNode* root , TreeNode* &prev , bool &flag){
//         if(root == NULL) return;
//         inOrder(root->left , prev , flag);
//         if(prev != NULL and root->val <= prev->val){
//             flag = false;
//             return;
//         }
//         prev = root;
//         inOrder(root->right , prev , flag);

//     }

//     bool isValidBST(TreeNode* root) {
//         bool flag = true ;
//         TreeNode* prev = NULL ;
//         inOrder(root , prev , flag);
//         return flag;
//     }//can also store the inorder in an array and check if its sorted by checking every elemenet greater than previous one
// };
// //alternative (bad one) is to get maximum of left tree and minimum of right tree and check for every node 


//alternative (not much intutive but interesting (do dry run))
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
    bool isValidBST(TreeNode* root) {
        return helper(root, LONG_MIN, LONG_MAX);
    }

private:
    bool helper(TreeNode* root, long low, long high) {
        if (root == nullptr) {
            return true;
        }
        if (root->val <= low || root->val >= high) {
            return false;
        }
        return helper(root->left, low, root->val) && helper(root->right, root->val, high);
    }
};
