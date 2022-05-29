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
    ListNode* rotateRight(ListNode* head, int k) {
        
        if(head==nullptr||head->next==nullptr)
            return head;
         int size =0;
        
        ListNode * p=head;
        ListNode *prev=nullptr;
        while(p!=nullptr)
        {
            size++;
            prev =p;
            p=p->next;
        }
        
        k=k%size;
        
        if(k==0)
            return head;
        
        int rem = size-k;
        ListNode *q =head;
        
        while(rem-->0)
        {
            p=q;
            q=q->next;
            
        }
        
        p->next=nullptr;
        prev->next = head;
        head =q;
        return head;
        
        
    }
};