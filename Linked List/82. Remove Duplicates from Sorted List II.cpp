/*82. Remove Duplicates from Sorted List II
https://leetcode.com/problems/remove-duplicates-from-sorted-list-ii/
 */
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if(!head || !head->next)
            return head;
        
		// Create a dummy node ; You can give any value or no value in constructor
        ListNode* dummy = new ListNode(-101);
        dummy->next = head;
        ListNode* p = dummy;
        ListNode* curr = head;
		
		//compare from head till node values are equal
        while(curr->next && curr->val == curr->next->val)
            curr = curr->next;
        
		//This means no duplicate node found yet
        if(p->next == curr)
        {
            p = curr;
            p->next = deleteDuplicates(p->next);
            return dummy->next;
        }
        
		//If duplicate node found; recurse
        p->next = deleteDuplicates(curr->next);
        return dummy->next;
    }
};