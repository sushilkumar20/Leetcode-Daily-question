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
    ListNode* partition(ListNode* head, int x) {
        
       ListNode *beforeHead = new ListNode();
       ListNode *before = beforeHead;
       
        ListNode *afterHead = new ListNode();
        ListNode *after = afterHead;
        
        
        while(head!=nullptr)
        {
            if(head->val>=x)
            {
                after->next = head;
                after = after->next;
            }
            else
            {
                before->next = head;
                before = before->next;
            }
            
            head=head->next;
        }
        
        after->next = nullptr;
        
        before->next = afterHead->next;
        
        return beforeHead->next;
        
    }
};