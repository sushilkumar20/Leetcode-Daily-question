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
    bool hasCycle(ListNode *head) {
        
        if(head==nullptr)
            return false;
        ListNode *slow =head;
        ListNode *fast =head;
        
        do
        {
            slow=slow->next;
            fast =fast->next;
            if(fast)
                fast=fast->next;
            else
                return false;
            
            if(fast == slow)
                return true;
        }
         while(slow&&fast);
        
        return  false;
    }
};