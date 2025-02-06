//leetcode 138
class Solution {
    public:
        // Node* copyRandomList(Node* head) {
        //     if (head == nullptr) return nullptr;
    
        //     // Step 1: Create deep copy without random pointers
        //     Node* curr = head;
        //     while (curr != nullptr) {
        //         Node* copyNode = new Node(curr->val);
        //         copyNode->next = curr->next;
        //         curr->next = copyNode;
        //         curr = copyNode->next;
        //     }
    
        //     // Step 2: Set random pointers in copied list
        //     curr = head;
        //     while (curr != nullptr) {
        //         if (curr->random != nullptr) {
        //             curr->next->random = curr->random->next;
        //         }
        //         curr = curr->next ? curr->next->next : nullptr;
        //     }
    
        //     // Step 3: Separate original and copied lists
        //     Node* original = head;
        //     Node* copied = head->next;
        //     Node* copiedHead = head->next;
    
        //     while (original != nullptr) {
        //         original->next = copied->next;
        //         original = original->next;
        //         copied->next = original ? original->next : nullptr;
        //         copied = copied->next;
        //     }
        //     return copiedHead;
        // }
    
        //hashmap method
        Node* copyRandomList(Node* head) {
            Node* dummy = new Node(-1);
            Node* curr = dummy;
            Node* temp = head;
            unordered_map<Node* , Node*> mp; // orignal , copyNode
            while(temp){
                Node* copyNode = new Node(temp->val);
                curr->next = copyNode;
                mp[temp] = copyNode; 
                curr = curr->next;
                temp = temp->next;
            }
            for(auto ele : mp){
                Node* orig = ele.first;
                Node* copy = ele.second;
                copy->random = (orig->random ? mp[orig->random] : NULL);
            }
            return dummy->next;
        }
    };