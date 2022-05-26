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
        
        ListNode *prev = nullptr;
        ListNode *p=list1;
        ListNode *q=list2;
        
        while(p!=nullptr&&q!=nullptr)
        {
            if(p->val>q->val)
            {
                ListNode * temp=q;
                temp=temp->next;
                
                
                q->next=p;
                
                
                if(prev){
                    prev->next=q;
                    prev=q;
                }
                else
                {
                    list1 = q;
                    prev = q;
                }
                
                q= temp;
                
            }
            else
            {
                prev = p;
                p=p->next;
            }
        }
        
        while(q!=nullptr)
        {
                ListNode * temp=q;
                temp=temp->next;
                
                
                q->next=p;
                
                if(prev){
                    prev->next=q;
                    prev=q;
                }
            else
            {
                list1 = q;
                prev = q;
            }
                
                q = temp;
        }
        
        return list1;
    }
};