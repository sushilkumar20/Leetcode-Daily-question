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
    ListNode* reverseKGroup(ListNode* head, int k) {
        
      if(head == nullptr)
          return head;
        ListNode *p= head;
        cout<<head->val<<endl;
        int c=0;
        while(p!=nullptr)
        {
            c++;
            p=p->next;
        }
        
        if(c<k)
            return head;
        
        
        ListNode *prev = nullptr;
        ListNode *curr = head;
        ListNode  *next = head->next;
        
        int cnt=0;
        
        
        
        while(curr!=nullptr && cnt<k)
        {
            curr->next = prev;
            prev = curr;
            curr = next;
            if(next)
            next = next->next;
            cnt++;
        }
        
        if(curr !=nullptr)
        {
            head->next = reverseKGroup(curr,k);
        }
        
        return prev;
        
    }
};