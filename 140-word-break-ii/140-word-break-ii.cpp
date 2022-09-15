class Solution {
public:
    void dfs(int i, int sz, string &s,  set<string> &st, vector<string> &ans, vector<string> &curr)
    {
        if(i>s.size())
            return;
        
        if(i==s.size())
        {
            if(st.find(s.substr(i-sz+1,sz))!=st.end())
            curr.push_back(s.substr(i-sz+1,sz));
            else
                return;
            string s1="";
            if(curr.size())
            {
                for(int j=0;j<curr.size();j++){
                    s1+=curr[j];
                    s1+=" ";
                }
                s1.pop_back();
                ans.push_back(s1);
            }
            curr.pop_back();
            return;
        }
        
        if(st.find(s.substr(i-sz+1,sz))!=st.end())
        {
            curr.push_back(s.substr(i-sz+1,sz));
            dfs(i+1,1,s,st,ans,curr);
            curr.pop_back();
            
            dfs(i+1,sz+1,s,st,ans,curr);
        }
        else
        {
             dfs(i+1,sz+1,s,st,ans,curr);
        }
        
    }
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        
        set<string> st;
        
        for(int i=0;i<wordDict.size();i++)
            st.insert(wordDict[i]);
        
        vector<string> ans;
        vector<string> curr;
        dfs(0,1,s,st,ans,curr);
        
        return ans;
    }
};