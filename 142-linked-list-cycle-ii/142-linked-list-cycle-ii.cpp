/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        
        if(head==nullptr||head->next==nullptr)
            return nullptr;
        ListNode *fast=head;
        ListNode *slow=head;
        
        slow=head->next;
        fast=head->next->next;
        while(fast&&fast->next)
        {
            if(fast==slow)
                break;
            slow=slow->next;
            fast=fast->next->next;
        }
        
        if(fast!=slow)
            return nullptr;
        
        slow=head;
        
        while(fast!=slow)
        {
            fast=fast->next;
            slow=slow->next;
        }
        return slow;
    }
};