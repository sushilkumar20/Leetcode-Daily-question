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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        
        ListNode * ans=new ListNode();
        
        ListNode *p1=ans;
        ListNode *p2=list1;
        ListNode *p3=list2;
        
        while(p2!=nullptr&&p3!=nullptr)
        {
            ListNode *x=new ListNode();
            if(p2->val>p3->val)
            {
                x->val=p3->val;
                p3=p3->next;
                p1->next=x;
                p1=x;
                
            }
            else
            {
                x->val=p2->val;
                p2=p2->next;
                p1->next=x;
                p1=x;
            }
        }
        
        while(p3!=nullptr)
        {
             ListNode *x=new ListNode();
          
                x->val=p3->val;
                p3=p3->next;
                p1->next=x;
                p1=x;
                
            
        }
        
         while(p2!=nullptr)
        {
             ListNode *x=new ListNode();
          
                x->val=p2->val;
                p2=p2->next;
                p1->next=x;
                p1=x;
                
            
        }
        
        return ans->next;
    }
};