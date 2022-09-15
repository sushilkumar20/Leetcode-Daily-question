class Solution {
public:
    
    bool dfs(int i, int sz, string &s,  set<string> &st,vector<vector<int>> &dp)
    {
        if(i==s.size())
        {
            if(st.find(s.substr(i-sz+1,sz))!=st.end())
            {
                return true;
            }
            return false;
        }
        if(dp[i][sz]!=-1)
            return dp[i][sz];
        if(st.find(s.substr(i-sz+1,sz))!=st.end())
        {
           return dp[i][sz]=dfs(i+1,1,s,st,dp)||dfs(i+1,sz+1,s,st,dp);
        }
        return dp[i][sz]=dfs(i+1,sz+1,s,st,dp);
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        
        set<string> st;
        
        int n = s.size();
        for(int i=0;i<wordDict.size();i++)
            st.insert(wordDict[i]);
        
        vector<vector<int>> dp(n+1,vector<int>(n+1,-1));
        return dfs(0,1,s,st,dp);
    }
};