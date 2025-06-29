/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:

    Node* getNext(Node* root){
        if(root == NULL) return root;

        Node* temp = root->next;

        while(temp != NULL){
            if(temp->left) return temp->left;

            if(temp->right) return temp->right;

            temp = temp->next;
        }

        return NULL;
    }

    Node* connect(Node* root) {
        if(!root) return root;
        Node* rootCpy = root; //to save root to return later
        root->next = NULL;

        while(root != NULL){
            Node* q = root; //now we will populate all children of this level at once as for this level its already populated

            while(q != NULL){
                if(q->left){
                    q->left->next = q->right ? q->right : getNext(q);
                }
                if(q->right) q->right->next = getNext(q);

                q = q->next;
            }
            
            //go to next level
            if(root->left) root = root->left;
            else if(root->right) root = root->right;
            else root = root->next;
        }
        return rootCpy;
    }
};