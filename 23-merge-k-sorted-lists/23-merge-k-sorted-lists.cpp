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
    ListNode* merge2List(ListNode* l1,ListNode*l2)
    {
       
        ListNode* head=new ListNode();
        ListNode *p=head;
        while(l1!=nullptr&&l2!=nullptr)
        {
           
            
            
            if(l1->val>l2->val)
            {
                
                p->next=l2;
                p=p->next;
              
                l2=l2->next;
            }
            else
            {
                
                p->next=l1;
                p=p->next;
                
                l1=l1->next;
            }
        }
        
        while(l1!=nullptr)
        {
            
            
                p->next=l1;
                p=p->next;
                l1=l1->next;
            
        }
        
        while(l2!=nullptr)
        {
                p->next=l2;
                p=p->next;
                l2=l2->next;
            
        }
        
        return head->next;
    }
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        
        if(lists.size()==0)
            return nullptr;
        while(lists.size()>1)
        {
            ListNode *l1=lists.back();
            lists.pop_back();
            ListNode *l2=lists.back();
            lists.pop_back();
            
            ListNode *n= merge2List( l1,l2);;
            
            
            
            //cout<<n->val<<endl;
            lists.push_back(n);
                
        }
        
        return lists[0];
    }
};