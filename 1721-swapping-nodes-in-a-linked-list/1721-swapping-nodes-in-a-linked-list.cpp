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
    ListNode* swapNodes(ListNode* head, int k) {
        
       ListNode *x = head;
        ListNode *y = head;
        ListNode *z = head;
        
        
        int n = k;
        
        
        k--;
       
        while(k>0)
        {
            x = x->next;
            k--;
        }
        int p = 0;
        
        
        while(z->next!=NULL)
        {
            z = z->next;
            p++;
        }
        
         int d = p-(n-1); 
        
        while(d>0)
        {
            y = y->next;
            d--;
        }
        
        //swap 
        int temp = x->val;
        x->val = y->val;
        y->val = temp;
        
        return head;
        
        
    }
};