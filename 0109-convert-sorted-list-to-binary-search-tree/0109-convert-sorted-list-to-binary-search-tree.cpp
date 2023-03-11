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
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* sortedListToBST(ListNode* head) {
        
        if(head==nullptr)
        {
            return nullptr;
        }
        
        if(head->next == nullptr)
        {
            TreeNode *p= new TreeNode(head->val);
            return p;
        }
    
        ListNode *slow = head;
        ListNode *fast = head;
        ListNode* q;
        while(fast!=nullptr&&fast->next  != nullptr )
        {
            q=slow;
            slow = slow->next;
            fast = fast->next;
            if(fast!=nullptr)
                fast=fast->next;
        }
       
        TreeNode *p = new TreeNode(slow->val);
        p->right = sortedListToBST(slow->next);
        
        q->next = nullptr;
        p->left = sortedListToBST(head);
        return p;
    }
};