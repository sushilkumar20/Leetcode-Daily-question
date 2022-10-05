class Solution {
public:
    bool matchReplacement(string s, string sub, vector<vector<char>>& mappings) {
        
        int m = sub.size();
        map<char,set<char>> mp;
        
        for(int i=0;i<mappings.size();i++)
        {
            mp[mappings[i][0]].insert(mappings[i][1]);
        }
        
        for(int i=0;i<=s.size()-m;i++)
        {
            bool ok=true;
            for(int j=i;j<i+m;j++)
            {
                //cout<<j-i<<" "<<j<<endl;
                if(sub[j-i]==s[j])
                    continue;
                if(mp[sub[j-i]].find(s[j])==mp[sub[j-i]].end())
                {
                    ok=false;
                    break;
                }
            }
            
            if(ok)
                return ok;
        }
        
        return false;
    }
};