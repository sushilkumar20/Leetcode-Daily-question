class TrieNode{
    public:
    
    char data;
    TrieNode *children[26];
    bool isTerminal;
    
    TrieNode(char ch)
    {
        data = ch;
        for(int i=0;i<26;i++)
            children[i]=nullptr;
        
        isTerminal = false;
    }
};

class Solution {
public:
    TrieNode *root;
    
     void insertUtil(TrieNode* root,string s)
    {
        if(s.size()==0)
        {
            root->isTerminal = 1;
            return;
        }
        
        int idx = s[0]-'a';
        
        TrieNode *child;
        
        if(root->children[idx]!=nullptr)
            child = root->children[idx];
        else
        {
            child = new TrieNode(s[0]);
            root->children[idx] = child;
        }
        
        insertUtil(child,s.substr(1));
    }
    
     bool searchUtil(TrieNode *root, string s)
    {
        if(s.size()==0)
        {
            return root->isTerminal;
        }
        
          
        int idx = s[0]-'a';
        
        TrieNode *child;
        
        if(root->children[idx]!=nullptr)
            child = root->children[idx];
        else
        {
          return false;
        }
        
        return searchUtil(child,s.substr(1));
    }
    
     bool searchPrefixUtil(TrieNode *root, string s)
    {
        if(s.size()==0)
        {
            return true;
        }
        
          
        int idx = s[0]-'a';
        
        TrieNode *child;
        
        if(root->children[idx]!=nullptr)
            child = root->children[idx];
        else
        {
          return false;
        }
        
        return searchPrefixUtil(child,s.substr(1));
    }
    
    void find(int i, int j, vector<vector<char>>& board,string &s,unordered_set<string>&st,TrieNode*root)
    {
       if(i<0||j<0||i==board.size()||j==board[0].size()||board[i][j]=='0')
           return;
        // cout<<s<<endl;
        
        int ind = board[i][j]-'a';
        if(root->children[ind]==nullptr)
            return;
        
        s+=board[i][j];
        
        root = root->children[ind];
        if(root->isTerminal)
            st.insert(s);
        
        board[i][j]='0';
        
        find(i+1,j,board,s,st,root);
        find(i-1,j,board,s,st,root);
        find(i,j+1,board,s,st,root);
        find(i,j-1,board,s,st,root);
        
        board[i][j] = s.back();
        s.pop_back();
        
    }
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        
        unordered_map<string,int> mp;
        root = new TrieNode('*');
        int cnt = 0;
        for(int i=0;i<words.size();i++){
             cnt++;
           insertUtil(root,words[i]);
        }
        
        int n = board.size();
        int m = board[0].size();
        
        unordered_set<string> ans;
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                string s="";
                find(i,j,board,s,ans,root);
            }
        }
        
        vector<string> res;
        
        for(auto j:ans)
            res.push_back(j);
        
        return res;
    }
};