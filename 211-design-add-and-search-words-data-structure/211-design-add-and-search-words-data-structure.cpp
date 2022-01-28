class WordDictionary {
public:
    map<int,vector<string>> mp;
    WordDictionary() {
       //st.insert()
    }
    
    void addWord(string word) {
        mp[(int)word.size()].push_back(word);
    }
    
    bool search(string word) {
        
        for(auto i:mp[word.size()])
        {
            bool ok=true;
           
            for(int j=0;j<i.size();j++)
            {
                if(word[j]=='.')
                    continue;
                if(word[j]!=i[j]){
                    ok=false;
                    break;
                }
            }
            if(ok)
                return true;
        }
        
        return false;
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */