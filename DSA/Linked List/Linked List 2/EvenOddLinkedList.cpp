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
        ListNode* oddEvenList(ListNode* head) {
            if(head == NULL or head->next == NULL) return head;
            ListNode* curr = head ;
            ListNode* dummyO = new ListNode(-1);
            ListNode* dummyE = new ListNode(-1);
            ListNode* tempO = dummyO;
            ListNode* tempE = dummyE;
    
            while(curr != NULL){
                tempO->next = curr ;
                curr = curr->next;
                tempO = tempO->next;
                if(curr == NULL) break;
                tempE->next = curr;
                curr = curr->next;
                tempE = tempE->next;
            }
            tempO->next = dummyE->next;
            tempE->next = NULL;// very important to terminate overwise it will give heap overflow
            return dummyO -> next;
        }
    };