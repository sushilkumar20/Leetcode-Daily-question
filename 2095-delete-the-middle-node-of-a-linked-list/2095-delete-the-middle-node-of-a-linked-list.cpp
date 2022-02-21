/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* deleteMiddle(ListNode* head) {
        
           
        int n=0;
         if(head==nullptr||head->next==nullptr)
             return nullptr;
        struct ListNode* fast=head;
        struct ListNode* slow=head;
        ListNode* prev;
        while(fast!=nullptr&&fast->next != NULL)
        {
            prev=slow;
            fast=fast->next->next;
            slow=slow->next;
        }
        
        prev->next=prev->next->next;
        
        delete(slow);
       
        return head;
    }
};