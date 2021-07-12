/*61. Rotate List
https://leetcode.com/problems/rotate-list/
 */
class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if(!head || !head->next) return head;
        ListNode* res = head;
        int len=0;
        while(res) {
            len++;
            if(!res->next) break;
            res=res->next;
        }
        res->next=head;
        len=len-k%len;
        res=head;
        for(int i=1; i<len; i++) {
            res=res->next;
        }
        head=res->next;
        res->next=nullptr;
        return head;
    }
};