class Solution {
public:
    static bool cmp(string &s1, string &s2)
    {
        if(s1.size()<s2.size())
            return 1;
        
        return 0;
    }
    int longestStrChain(vector<string>& words) {
        
        unordered_map<string,int> dp;
        
        sort(words.begin(),words.end(),cmp);
        
        int mx = 1;
        for(int i=0;i<words.size();i++)
        {
            dp[words[i]] = 1;
            
            for(int j=0;j<words[i].size();j++)
            {
                string s1 = words[i].substr(0,j);
                s1+=words[i].substr(j+1);
                
                if(dp.find(s1)!=dp.end())
                {
                    dp[words[i]] = max(dp[words[i]],1+dp[s1]);
                }
                
            }
            mx=max(mx,dp[words[i]]);
        }
        
        return mx;
    }
};