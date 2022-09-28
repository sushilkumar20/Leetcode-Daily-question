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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        
        
        int cnt =0;
        
        ListNode *curr = head;
        
        while(curr)
        {
            cnt++;
            curr=curr->next;
        }
        
        int fromStart = cnt - n;
        
        ListNode *prev = nullptr;
        curr = head;
        
        while(fromStart!=0)
        {
            prev= curr;
           curr = curr->next;
            fromStart --;
        }
        
        if(prev==nullptr)
        {
            head = head->next;
        }
        else
        {
            prev->next = curr->next;
        }
        
        return head;
    }
};