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
    ListNode* swapPairs(ListNode* head) {
        int cnt=0;
        
        ListNode *p=head;
        if(p==nullptr||p->next==nullptr)
        {
            return p;
        }
        ListNode *q=p->next;
        
        ListNode *head1=p;
        ListNode* prev=new ListNode();
        while(q!=nullptr)
        {
            p->next=q->next;
            q->next=p;
            prev->next=q;
            prev=p;
            cnt++;
            if(cnt==1)
                head1=q;
            ListNode *temp=p;
            if(temp->next!=nullptr){
                p=temp->next;
                //cout<<p->val<<endl;
            }
            else
                break;
            if(temp->next->next!=nullptr)
            {
                q=temp->next->next;
                //cout<<q->val<<endl;
            }
            else
                break;
            
        }
        
        return head1;
    }
};