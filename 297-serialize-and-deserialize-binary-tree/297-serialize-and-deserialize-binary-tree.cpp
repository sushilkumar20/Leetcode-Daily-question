/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        
        string s="";
        
        queue<TreeNode*> q;
        
        if(root == nullptr)
            return s;
        
        q.push(root);
        
        s+=to_string(root->val);
        s+=",";
        while(q.size())
        {
            TreeNode *node = q.front();
            q.pop();
            
            if(node->left)
            {
                q.push(node->left);
                s+=to_string(node->left->val);
                s+=",";
            }
            else
                s+="n,";
            
             if(node->right)
            {
                q.push(node->right);
                s+=to_string(node->right->val);
                s+=",";
            }
            else
                s+="n,";
        }
        
        s.pop_back();
       // cout<<s<<endl;
        return s;
        
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        
        if(data.size()==0)
            return nullptr;
        
        vector<string> arr;
        
        string s ="";
        //cout<<data.size()<<endl;
        for(int i=0;i<data.size();i++)
        {
            if(data[i]==',')
            {
                if(s.size())
                    arr.push_back(s);
                s="";
            }
            else
                s+=data[i];
        }
        
        TreeNode *root = new TreeNode(stoi(arr[0]));
        int n= arr.size();
        int i=1;
        
        queue<TreeNode*>q;
        q.push(root);
        
        while(q.size())
        {
            TreeNode *k =q.front();
            
            q.pop();
           // cout<<i<<endl;
            if(i<n)
            {
                if(arr[i]!="n")
                {
                    TreeNode *left = new TreeNode(stoi(arr[i]));
                    k->left = left;
                    q.push(left);
                }
            }
            
            i++;
            
            if(i<n)
            {
                if(arr[i]!="n")
                {
                    TreeNode *right = new TreeNode(stoi(arr[i]));
                    k->right = right;
                    q.push(right);
                }
            }
            
            i++;
            
        }
        
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));