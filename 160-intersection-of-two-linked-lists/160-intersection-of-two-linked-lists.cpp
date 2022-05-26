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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        
        set<ListNode*> st;
        
        ListNode *p = headA;
        ListNode *q = headB;
        
        while(p!=nullptr){
            st.insert(p);
            p=p->next;
        }
        
        while(q!=nullptr)
        {
            if(st.find(q)!=st.end())
                return q;
            
            q=q->next;
        }
        
        return nullptr;
    }
};