/*86. Partition List
https://leetcode.com/problems/partition-list/
 */

class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        
        ListNode* left = new ListNode();
        ListNode* right = new ListNode();
        ListNode* l = left;
        ListNode* r = right;
        
        while(head){
            if(head->val < x){
                left->next = head;
                left = left->next;
            }
            else {
                right->next = head;
                right = right->next;
            }
            head = head->next;
            
        }
        right->next = NULL;
        left->next = r->next;
        return l->next;
    }
};