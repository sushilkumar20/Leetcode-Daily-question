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
        
        int c=0;
        
        ListNode *p=l1;
        ListNode *q=l2;
        
        ListNode *t = new ListNode();
        ListNode *head =t;
        while(p!=nullptr&&q!=nullptr)
        {
            ListNode *node =new ListNode((p->val+q->val+c)%10);
            
            t->next =node;
            t=node;
             c=(p->val+q->val+c)/10;
            p=p->next;
            q=q->next;
            
           
        }
        
         while(p!=nullptr)
        {
            ListNode *node =new ListNode((p->val+c)%10);
            c=(p->val+c)/10;
            t->next =node;
            t=node;
            p=p->next;
           
            
            
        }
        
         while(q!=nullptr)
        {
            ListNode *node =new ListNode((q->val+c)%10);
            c=(q->val+c)/10;
            t->next =node;
            t=node;
            q=q->next;
           
            
            
        }
        
        if(c!=0)
        {
             ListNode *node =new ListNode(c%10);
            c=c/10;
            t->next =node;
            t=node;
            
            
        }
        return head->next;
    }
};