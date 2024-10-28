vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ans;
        TreeNode* curr = root;
        while(curr != NULL){
            if(curr->left != NULL){
                TreeNode* pred = curr->left;
                while(pred->right != NULL and pred->right != curr ){
                    pred = pred->right;
                }

                if(pred->right == NULL){ // link 
                    pred->right = curr;
                    curr = curr->left;
                }

                else{ //pred->right = curr (unlink)
                    pred->right = NULL;
                    ans.push_back(curr->val);
                    curr = curr->right;
                }
            }

            else{
                ans.push_back(curr->val);
                curr = curr->right;
            }
        }
        return ans;
    }
    //we always needed stack for inorder traversal either recursive or iterative to store the upper root so that we can come back after printing left nodes but in this method we do it by connecting every pred to its next or upper curr val so that we can go up by going right