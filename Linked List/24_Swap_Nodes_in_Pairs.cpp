/*24. Swap Nodes in Pairs
https://leetcode.com/problems/swap-nodes-in-pairs/
 */
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if(head==nullptr||head->next==nullptr){
            return head;
        }
        ListNode* node1=head;
        ListNode* node2=head->next;
        ListNode* newhead=node2->next;
        
        node2->next=node1;
        node1->next=swapPairs(newhead);
        return node2;
    }
};