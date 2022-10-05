class TrieNode{
    
    public:
    char data;
    TrieNode* children[26];
    bool isTerminal;
    TrieNode(char ch)
    {
        data = ch;
        
        for(int i=0;i<26;i++)
        {
            children[i]=nullptr;
        }
        
        isTerminal = false;
    }
    
};
class Trie {
public:
    TrieNode *root;
    Trie() {
        root= new TrieNode('*');
    }
    
    void insertUtil(TrieNode *root, string word)
    {
        if(word.size()==0)
        {
            root->isTerminal = true;
            return;
        }
        
        int ind = word[0]-'a';
        
        TrieNode *child ;
        
        if(root->children[ind]==nullptr)
        {
            child = new TrieNode(word[0]);
            root->children[ind] = child;
        }
        else
        {
            child = root->children[ind];
        }
        
        insertUtil(child,word.substr(1));
    }
    void insert(string word) {
        insertUtil(root,word);
    }
    
    bool searchUtil(string word, TrieNode *root) {
        
        if(word.size()==0)
        {
            if(root->isTerminal)
                return true;
            
            return false;
        }
        
        int ind = word[0]-'a';
        
        if(root->children[ind]==nullptr)
            return false;
        
        TrieNode *child = root->children[ind];
        
        return searchUtil( word.substr(1), child);
        
    }
    bool search(string word) {
        return searchUtil( word, root);
    }
    
     bool searchUtilPrefix(string word, TrieNode *root) {
        
        if(word.size()==0)
        {
           
          return true;
        }
       
        int ind = word[0]-'a';
      
        if(root->children[ind]==nullptr)
            return false;
       
        TrieNode *child = root->children[ind];
        
        return searchUtilPrefix( word.substr(1), child);
        
    }
    bool startsWith(string prefix) {
        return searchUtilPrefix( prefix, root);
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */