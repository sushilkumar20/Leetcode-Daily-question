class Solution {
public:
    bool is(string s,string &sub,map<char,set<char>> &mp)
    {
        for(int i=0;i<sub.size();i++)
        {
            if(s[i]==sub[i])
                continue;
            if(mp[sub[i]].find(s[i])!=mp[sub[i]].end())
                continue;
            return false;
        }
        return true;
            
    }
    bool matchReplacement(string s, string sub, vector<vector<char>>& mappings) {
        
        map<char,set<char>> mp;
        
        for(int i=0;i<mappings.size();i++)
        {
            mp[mappings[i][0]].insert(mappings[i][1]);
        }
        int k= sub.size();
        int n=s.size();
        for(int i=0;i<=n-k;i++)
        {
            if(is(s.substr(i,k),sub,mp))
                return true;
        }
        
        return false;
        
    }
};