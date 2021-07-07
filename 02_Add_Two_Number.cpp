/* 2. Add Two Numbers 
https://leetcode.com/problems/add-two-numbers/
*/
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2)
    {
        using Node = ListNode;
        
        Node* head = nullptr, *curr = nullptr;
        Node* curr1 = l1, *curr2 = l2;
        int sum = 0;
        while(true)
        {
            //CALCULATE SUM
            if(!curr1)
            {
                if(!curr2) { break; }
                sum = curr2->val;
            }
            else if(!curr2) { sum = curr1->val; }
            else { sum = curr1->val + curr2->val; }
            
            //ADD TO LINKED LIST
            if(sum <= 9)
            {
                if(!head)
                {
                    head = new Node(sum);
                    curr = head;
                }
                else
                {
                    curr->next = new Node(sum);
                    curr = curr->next;
                }
            }
            else
            {
                if(!head)
                {
                    head = new Node(sum - 10);
                    curr = head;
                    if(curr1->next) { curr1->next->val += 1; }
                    else { curr1->next = new Node(1); }
                }
                else
                {
                    curr->next = new Node(sum - 10);
                    curr = curr->next;
                    if(curr1->next) { curr1->next->val += 1; }
                    else { curr1->next = new Node(1); }
                }
            }
            if(curr1) { curr1 = curr1->next; }
            if(curr2) { curr2 = curr2->next; }
        }
        return head;
    }
};