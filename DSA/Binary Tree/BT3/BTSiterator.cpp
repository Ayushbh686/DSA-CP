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
class BSTIterator {
public:

    stack<TreeNode*>st;

    void PushAllLeft(TreeNode* root){
        while(root){
            st.push(root);
            root = root->left;
        }
        return ;
    }

    BSTIterator(TreeNode* root) {
        PushAllLeft(root);
    }
    
    int next() {
        TreeNode* node = st.top();
        st.pop();

        if (node->right != nullptr) {
            PushAllLeft(node->right);
        }

        return node->val;
    }
    
    bool hasNext() {
        return !(st.empty());
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */