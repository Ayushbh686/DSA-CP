class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        // if(root == NULL or root == p or root == q) return root;
        // else if(root->val < q->val and root->val > p->val) return root;        
        // else if(root->val > q->val and root->val < p->val) return root;    
        // else if(root->val > q->val and root->val > p->val) return lowestCommonAncestor(root->left , p , q);
        // else return lowestCommonAncestor(root->right , p , q);

        //same but less lines
        if(root->val > q->val and root->val > p->val) return lowestCommonAncestor(root->left , p , q);
        else if(root->val < q->val and root->val < p->val) return lowestCommonAncestor(root->right , p , q);
        return root;
    }
};