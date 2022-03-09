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
    ListNode* deleteDuplicates(ListNode* head) {
        
        ListNode* p=head;
        
        ListNode *sentinel=new ListNode(0,p);
        
        ListNode *pred=sentinel;
        
        while(p!=nullptr)
        {
            
            if(p->next!=nullptr&&p->val==p->next->val)
            {
                while(p->next!=nullptr&&p->val==p->next->val)
                {
                    p=p->next;
                }
                
                pred->next=p->next;
            }
            else
            {
                pred=pred->next;
            }
            
            p=p->next;
        }
        
        head=sentinel->next;
        
        return head;
    }
};