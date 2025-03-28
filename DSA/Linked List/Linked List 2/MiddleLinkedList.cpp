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
        ListNode* middleNode(ListNode* head) {
            if(head == NULL or head->next == NULL) return head;
    
            ListNode* slow = head , *fast = head;
            while(fast != NULL and fast->next!=NULL){
                slow = slow->next;
                fast = fast->next->next;
            }
    
            return slow;
        }
    };

//if want 1st node in case of 2 middle nodes then start with fast = head->next