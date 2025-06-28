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
    int widthOfBinaryTree(TreeNode* root) {
        queue<pair<TreeNode*, long long>> qu;
        qu.push({root , 0});
        long long ans = 0;
        while(!qu.empty()){
            long long size = qu.size();
            long long first , last ;
            long long start = qu.front().second;
            /*
            we will measure each level starting from 0 eg:-
            0
            0 1
            0 1 2 3
            0 1 2 3 4 5 6 7


            otherwise if we do simple wuthout subtracting from start it will go overflow
            0 
            1 2
            3 4 5 6
            7 8 9 10 11 12 13 14
            */
            for(long long i=0 ; i<size ; i++){
                TreeNode* curr = qu.front().first;
                long long level = qu.front().second - start;
                qu.pop();

                if(i==0) first = level;
                if(i==size-1) last = level;

                if(curr->left) qu.push({curr->left , 2*level + 1});
                if(curr->right) qu.push({curr->right , 2*level + 2});
            }
            ans = max(ans , last - first + 1);
        }

        return ans;
    }
};