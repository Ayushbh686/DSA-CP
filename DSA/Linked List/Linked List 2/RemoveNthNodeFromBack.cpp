/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
    public:
        ListNode* removeNthFromEnd(ListNode* head, int n) {
            // ListNode* temp = head ;
            // int size = 0;
            // while(temp!=NULL){
            //     size++;
            //     temp = temp->next;
            // }
    
            // // If the node to be removed is the head
            // if (n == size) {
            //     ListNode* newHead = head->next;
            //     delete head; // Free the memory of the old head
            //     return newHead;
            // }
    
            // temp = head;
            // int m = size - n + 1;
            // for(int i=1 ; i<m-1; i++){
            //     temp = temp->next;
            // }
            // temp -> next = temp -> next -> next;
            // return head;
    
            //Approach 2
            ListNode* fast = head;
            ListNode* slow = head;
            //fast ko n+1 steps aage le jao 
    
            for(int i=1 ; i<=n+1 ; i++){
                if(fast == NULL) return head->next;
                fast = fast->next;
            }
            //slow aur fast ko saath le jao jab tak fast null na ho
            while(fast!=NULL){
                slow = slow->next;
                fast = fast->next;
            }
            slow->next = slow->next->next;
            return head;
        }
    };