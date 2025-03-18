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
    
        ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
            //Approach 2(O(1) sc)
            ListNode* dummyHead = new ListNode(-1);
            ListNode* temp = dummyHead;
    
            while (list1 != nullptr && list2 != nullptr) {
                if (list1->val <= list2->val) {
                    temp->next = list1;
                    list1 = list1->next;
                } else {
                    temp->next = list2;
                    list2 = list2->next;
                }
                temp = temp->next;
            }
    
            // Attach remaining nodes from list1 or list2
            if (list1 != nullptr) {
                temp->next = list1;
            } else {
                temp->next = list2;
            }
    
            ListNode* result = dummyHead->next;
            delete dummyHead;
            return result;
        }
    
        ListNode* mergeSort(ListNode* head){
            if(head == NULL or head->next == NULL) return head;
            ListNode* a = head ,*b = head;
            while(b->next != NULL and b->next->next!=NULL){
                a=a->next;
                b=b->next->next;
            }
            b=a->next;
            a->next=NULL;
            head = mergeSort(head);
            b = mergeSort(b);
            head = mergeTwoLists(head,b);
            return head;
        }
    
        ListNode* sortList(ListNode* head) {
            head = mergeSort(head);
            return head;
        }
    };
    //best merge sort sorting techique as it do in O(nlogn) tc and O(1) sc