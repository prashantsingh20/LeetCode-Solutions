/*25. Reverse Nodes in k-Group
https://leetcode.com/problems/reverse-nodes-in-k-group/
 */
class Solution {
public:
    ListNode* reverse(ListNode* head, int k, int times){
        if(times == 0)    return head;
        ListNode* prev = NULL, *tail = head;
        ListNode* curr = head, *nxt;
        int count = k;
        while(count-- && curr){
            nxt = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nxt;
        }
        if(curr)
            tail->next = reverse(curr, k, times-1);
        return prev;
    }
    
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(!head || !head->next || k == 1) return head;
        ListNode* temp = head;
        int len = 0;
        while(temp){
            len++; temp = temp->next;
        }
        int times = len/k;
        return reverse(head, k, times);
    }
};