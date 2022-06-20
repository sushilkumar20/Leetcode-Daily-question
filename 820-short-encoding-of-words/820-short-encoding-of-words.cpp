class Solution {
public:
    int minimumLengthEncoding(vector<string>& words) {
        
        set<string> st;
        
        for(int i=0;i<words.size();i++)
        {
            st.insert(words[i]);
        }
        
        for(auto word : words)
        {
            for(int i=1;i<word.size();i++)
            {
                if(st.find(word.substr(i))!=st.end())
                {
                    st.erase(word.substr(i));
                }
            }
        }
        
        int cnt=0;
        
        for(auto i=st.begin();i!=st.end();i++)
        {
            cnt+=(*i).size();
        }
        
        cnt+=st.size();
        
        return cnt;
    }
};