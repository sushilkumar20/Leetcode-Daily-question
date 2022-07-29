class Solution {
public:
    vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
        
        
        vector<string> ans;
        
        for(int i=0;i<words.size();i++)
        {
            if(pattern.size()!=words[i].size())
                continue;
            
            map<char,char> mp;
            map<char,char> mp1;
            bool ok = true;
            
            for(int j=0;j<pattern.size();j++)
            {
                if(mp.find(pattern[j])==mp.end()&&mp1.find(words[i][j])==mp1.end())
                {
                    mp[pattern[j]] = words[i][j];
                    mp1[ words[i][j]] = pattern[j];
                }
                else
                {
                   // cout<<words[i]<<" "<<words[i][j]<<endl;
                    if(mp1.find(words[i][j])==mp1.end())
                    {
                        ok=false;
                        break;
                    }
                    
                    if(mp.find(pattern[j])==mp.end())
                    {
                        ok=false;
                        break;
                    }
                    if(mp[pattern[j]]!=words[i][j])
                    {
                        ok=false;
                        break;
                    }
                    
                    if(mp1[words[i][j]]!=pattern[j])
                    {
                        ok=false;
                        break;
                    }
                }
            }
            
            if(ok)
                ans.push_back(words[i]);
        }
        
        return ans;
    }
};