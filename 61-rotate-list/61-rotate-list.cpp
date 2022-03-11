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
        
          ListNode* temp=head;
        
    int count=0;
     while(temp!=nullptr)
     {
         count++;
         temp=temp->next;
     }
        
        if(count==0||k==0)
            return head;
        
        k=k%count;
        
        
        while(k-->0)
        {
            ListNode* tmp=head;
           
             while(tmp->next->next!=nullptr)
                 tmp=tmp->next;
            
                  tmp->next->next=head;
                  
                  head=tmp->next;
                  tmp->next=nullptr;
        }
        
         return head;
        
        
    }
};