/*23. Merge k Sorted Lists
https://leetcode.com/problems/merge-k-sorted-lists/
 */
class Solution {
public:
    
    ListNode* solve(vector<ListNode*>& lists,int l,int r)
    {
        if(l+1==r) return lists[l];
        int m=(l+r)/2;
        return mergeTwoLists(solve(lists,l,m),solve(lists,m,r));
    }
    
    ListNode* mergeKLists(vector<ListNode*>& lists) 
    {
        if(lists.size()==0) return NULL;
		
        return solve(lists,0,lists.size());
    }
	
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode *h1=l1,*h2=l2,*ret=l1,*temp;
        
        if(l1==NULL) return l2;
        if(l2==NULL) return l1;
        
        if(h1->val > h2->val)
        {
            ret=l2; swap(h1,h2);
        }
        while(h2)
        {
            if( (h1->next && h1->next->val>h2->val) || (h1->next ==NULL) )
            {
                temp=h2->next;
                h2->next=h1->next;
                h1->next=h2;
                h2=temp;
            }
            h1=h1->next;
        }
        return ret;
    }
    
};