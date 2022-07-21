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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        
        
        ListNode*p = head;
        ListNode*lst = nullptr;
        int cnt1=1;
        
        if(left==right||head==nullptr)
            return head;
        
        
        while(p)
        {
           
            if(cnt1 == left)
            {
                //cout<<p->val<<endl;
                ListNode *curr = p;
                ListNode *nxt =p->next;
                ListNode*prev = lst;
                ListNode*kk = p;
                while(curr!=nullptr&&cnt1<=right)
                {
                   // cout<<curr->val<<" "<<prev->val<<endl;
                    curr->next = prev;
                    prev=curr;
                    curr=nxt;
                    
                    if(nxt)
                    {
                        nxt=nxt->next;
                    }
                    cnt1++;
                }
                
                if(lst){
                    
                kk->next = curr;
                lst->next = prev;
                   // cout<<prev->val<<endl;
                break;
                }
                else
                {
                   kk->next = curr;
                   head =prev;
                    break;
                }
                //break;
            }
            lst=p;
            p=p->next;
            cnt1++;
        }
        
        return head;
    }
};