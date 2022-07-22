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
    ListNode* partition(ListNode* head, int x) {
        
        ListNode *headg = new ListNode();
        
        ListNode *curr1 = headg;
        ListNode *curr = head;
        ListNode  *prev = nullptr;
        if(curr==nullptr||curr->next == nullptr)
            return head;
        
        
        while(curr!=nullptr)
        {
            if(curr->val>=x)
            {
                if(prev == nullptr)
                {
                    ListNode* p= curr->next;
                    curr1->next = curr;
                    curr->next = nullptr;
                    curr1 = curr;
                    curr =p;
                    head = p;
                    //cout<<curr->val<<endl;
                }
                else
                {
                    prev->next = curr->next;
                    curr1->next = curr;
                    curr->next = nullptr;
                    
                    curr1= curr;
                    
                    curr=prev->next;
                
                }
            }
           else
           {
               prev = curr;
               curr=curr->next;
           }
        }
        
        
        if(prev == nullptr){
            return headg->next;
          //  cout<<1<<endl;
        }
        
        prev->next = headg->next;
        
        return head;
    }
};