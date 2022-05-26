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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        
        ListNode * p=l1;
        ListNode *q=l2;
        
        ListNode * prev =nullptr;
        int c = 0;
        
        while(p!=nullptr&&q!=nullptr)
        {
            int k=p->val+q->val;
            k+=c;
            
            p->val=k%10;
            c=k/10;
            
            prev =p;
            
            p=p->next;
            q=q->next;
            
        }
        
        while(p!=nullptr)
        {
            int k=p->val+c;
            p->val=k%10;
            c=k/10;
            prev=p;
            
            p=p->next;
        }
        
        while(q!=nullptr)
        {
            int k=q->val+c;
            q->val=k%10;
            c=k/10;
            if(prev==nullptr)
            {
                l1=q;
                prev=q;
            }
            else
            prev->next=q;
            prev=q;
            
            q=q->next;
        }
        
        while(c>0)
        {
            ListNode *temp = new ListNode(c%10);
            c=c/10;
            if(prev==nullptr)
            {
                prev=temp;
                l1=temp;
            }
            else
            {
                prev->next=temp;
            }
        }
        
        return l1;
    }
};