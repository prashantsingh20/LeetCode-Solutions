/* 19. Remove Nth Node From End of List
https://leetcode.com/problems/remove-nth-node-from-end-of-list/
*/

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        
        int len = 0;
        ListNode* temp = head;
        ListNode* temp2 = head;
        
         while( temp != NULL ){
             len++;
             temp = temp->next;
         }
            
        if(len-n == 0) return temp2->next;
        
        for(int i = 0; i< len-n-1 ; i++)
            head = head -> next;
        
        
        if(head->next->next != NULL)
            head->next = head->next->next;
        
        else
            head->next = NULL;
        
        
        return temp2;
    }
};