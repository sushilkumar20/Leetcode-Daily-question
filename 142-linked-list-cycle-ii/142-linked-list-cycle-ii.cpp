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
        
        if(head ==nullptr)
            return nullptr;
        
        ListNode * slow = head;
        ListNode *fast = head;
        
        do
        {
            slow = slow->next;
            fast = fast->next;
            if(fast)
                fast=fast->next;
        }
        while(slow&&fast&&slow!=fast);
            
            if(slow == nullptr || fast == nullptr)
                return nullptr;
        
        
        slow = head;
        
        while(slow!=fast)
        {
            slow=slow->next;
            fast=fast->next;
        }
        
        return slow;
            
           
    }
};