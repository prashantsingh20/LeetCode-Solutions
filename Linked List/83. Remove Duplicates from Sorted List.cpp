/*83. Remove Duplicates from Sorted List
https://leetcode.com/problems/remove-duplicates-from-sorted-list/
 */
class Solution {
public:
   ListNode* deleteDuplicates(ListNode* head) {
        
        if(head==NULL || head->next==NULL){
            return head;
        }
        ListNode *p = head;
        set<int> s;
        while(p!=NULL){
            s.insert(p->val);
            p=p->next;
        }
        p=head;
        auto i =s.begin();
        while(i!=s.end()){
            p->val=(*i);
            i++;
            if(i==s.end()){
                continue;
            }
            p=p->next;
        }
        p->next=NULL;
        return head;
    }
};