class Solution {
public:
    static bool cmp(string &s1,string &s2)
    {
        if(s1.size()<s2.size())
            return 1;
        
        return 0;
    }
    
    bool compare(string s1, string s2)
    {
        if(s2.size()+1!=s1.size())
            return 0;
        
        int first =0;
        int second =0;
        
        while(first<s1.size())
        {
            if(s1[first]==s2[second])
            {
                first++;
                second++;
            }
            else
            {
                first++;
            }
        }
        
        if(first==s1.size()&&second==s2.size())
            return 1;
        
        return 0;
    }
    int longestStrChain(vector<string>& words) {
        
        int n = words.size();
        vector<int> dp(n,1);
    
        
        sort(words.begin(),words.end(),cmp);
        
        for(int i=1;i<n;i++)
        {
          for(int j=0;j<i;j++)
          {
              if(compare(words[i],words[j])&&dp[i]<dp[j]+1)
              {
                  dp[i]=dp[j]+1;
              }
          }
        }
        
        int mx = dp[0];
        
        for(int i=1;i<n;i++)
            mx=max(mx,dp[i]);
        
        return mx;
    }
};