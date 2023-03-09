/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        
        map<ListNode*,int> mp;
        
        ListNode *p = head;
        
        while(p!=nullptr)
        {
            if(mp.find(p)!=mp.end())
                return p;
            mp[p]++;
            p=p->next;
        }
        
        return nullptr;
    }
};