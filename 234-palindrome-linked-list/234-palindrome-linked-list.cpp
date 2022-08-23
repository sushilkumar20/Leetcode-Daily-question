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
    bool isPalindrome(ListNode* head) {
        
         
        if(head == nullptr)
            return true;
        ListNode *l1 = head;
        ListNode *l2 = nullptr ;
        ListNode *temp = nullptr;
        
        while(l1 != nullptr)
        {
           ListNode *p = new ListNode(l1->val);
            
            p->next = temp;
            
            temp=p;
            
            l1=l1->next;
            if(l1==nullptr)
            {
                l2 = temp;
                break;
            }
        }
        l1=head;
        while(l1!=nullptr&&l2!=nullptr)
        {
            if(l1->val!=l2->val)
                return false;
            
            l1 = l1->next;
            l2 = l2->next;
        }
        
        if(l1==nullptr&&l2==nullptr)
            return true;
        
        
        return false;
    }
};