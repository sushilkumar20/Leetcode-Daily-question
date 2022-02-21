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
    ListNode* deleteMiddle(ListNode* head) {
        
           int n=0;
        struct ListNode* start = new ListNode();
        start->next=head;
        struct ListNode* ptr=start;
        while(ptr->next != NULL)
        {
            ptr=ptr->next;
            n++;
        }
      
        if(n==0)
            return nullptr;
        if(n==1)
            return nullptr;
        struct ListNode* temp=start;
        struct ListNode* todelete=nullptr;
        for(int i=0; i<=n/2; i++)
        {
            todelete=temp;
            temp=temp->next;
        }
        
        todelete->next=todelete->next->next;
        delete(temp);
        
        return start->next;
    }
};