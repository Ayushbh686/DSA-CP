/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

 //Approach 1 diff in len
// class Solution {
// public:
//     ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
//         int len1 = 0 , len2 = 0 ;
//         ListNode* temp1 = headA;
//         ListNode* temp2 = headB;

//         while(temp1 != NULL){
//             temp1= temp1->next;
//             len1++;
//         }

//         while(temp2 != NULL){
//             temp2= temp2->next;
//             len2++;
//         }

//         temp1 = headA;
//         temp2 = headB;

//         if(len1 > len2){
//             for(int i=1 ; i<=len1-len2; i++){
//                 temp1=temp1->next;
//             }
//         }
//         else{
//             for(int i=1 ; i<=len2-len1; i++){
//                 temp2=temp2->next;
//             }
//         }

//         while(temp1 != temp2){
//             temp1 = temp1->next;
//             temp2 = temp2->next;
//         }

//         return temp1;

//     }
// };

//approach 2 (2 ptrs)
class Solution {
    public:
        ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
            ListNode *ptr1 = headA;
            ListNode *ptr2 = headB;
            while(ptr1 != ptr2){
                if(ptr1 == NULL){
                    ptr1 = headB;
                }
                else{
                    ptr1 = ptr1 -> next;
                }
                if(ptr2 == NULL){
                    ptr2 = headA;
                }
                else{
                    ptr2 = ptr2 -> next;
                }
            }
            return ptr1;
        }
    };
    // say, A and B are the 2 linked lists and A is shorted. length of A = x+y where y is the common part. length of B = z+x+y;
    // after x+y moves of head->next, A's pointer is at the end and would start moving in B. after another z iterations, A is at the z point in the B list and B's pointer is at the start of A list. So, after another x moves they will by defination be at the same point(NULL in case of no intersection which is again sufficient for our condition).
    
    //other one is to store adress of first list nodes in hasmap and while iterating second one match if its present in hashmap