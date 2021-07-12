/* 21. Merge Two Sorted Lists
https://leetcode.com/problems/merge-two-sorted-lists/
*/
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        
        ListNode* temp = new ListNode(0);
        ListNode* new_node = temp;
        
        while(l1 && l2){
            if(l1->val < l2->val){
                new_node->next = l1;
                l1 = l1->next;
            }
            else {
                new_node->next = l2;
                l2 = l2->next;
            }
            new_node = new_node->next;
        }
        
        if(l1)
            new_node->next=l1;
        else
            new_node->next=l2;
        
        return temp->next;
    }
};