class TrieNode{
    public :
     char data;
     TrieNode *children[26];
      bool isTerminal;
    TrieNode(char ch)
    {
        data = ch;
        
        for(int i=0;i<26;i++)
            children[i] =  nullptr;
        
        isTerminal = false;
    }
        
};
class WordDictionary {
public:
    TrieNode *root;
    WordDictionary() {
         root = new TrieNode('*');
    }
    void addWordUtil(string word, TrieNode *root)
    {
        if(word.size()==0)
        {
            root->isTerminal = true;
            return;
        }
        
        int ind = word[0]-'a';
        
        TrieNode*child;
        
        if(root->children[ind]==nullptr)
        {
            child = new TrieNode(word[0]);
            root->children[ind] = child;
        }
        else
            child = root->children[ind];
        
        addWordUtil(word.substr(1),child);
    }
    void addWord(string word) {
        
        addWordUtil( word, root);
    }
    
     bool searchWordUtil(string &word, TrieNode *root,int i)
    {
        if(word.size()<=i)
        {
           return root->isTerminal == true;
            
        }
         //cout<<word<<" "<<i<<endl;
        
        int ind = word[i]-'a';
        
         if(word[i]=='.')
         {
             
             for(int j=0;j<26;j++)
             {
                 if(root->children[j]!=nullptr)
                 {
                     if(searchWordUtil(word,root->children[j] ,i+1))
                         return true;
                 }
             }
             
             return false;
         }
        TrieNode*child;
        
        if(root->children[ind]==nullptr)
        {
            return false;
        }
        else
            child = root->children[ind];
        
        return searchWordUtil(word,child,i+1);
    }
    bool search(string word) {
        int i=0;
        return searchWordUtil(word,root,i);
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */