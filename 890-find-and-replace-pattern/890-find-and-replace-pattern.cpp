class Solution {
public:
    vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
        
        vector<string> ans;
        
        for(int i=0;i<words.size();i++)
        {
            bool ok=true;
            
            map<char,char>mp1;
            map<char,char> mp2;
            for(int j=0;j<words[i].size();j++)
            {
                if(mp1.find(words[i][j])==mp1.end()&&mp2.find(pattern[j])==mp2.end())
                {
                    mp1[words[i][j]]=pattern[j];
                    mp2[pattern[j]]=words[i][j];
                }
                else
                   {
                       if(mp1[words[i][j]]!=pattern[j]||mp2[pattern[j]]!=words[i][j])
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