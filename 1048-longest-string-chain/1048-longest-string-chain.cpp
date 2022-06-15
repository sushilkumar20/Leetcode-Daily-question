class Solution {
public:
    static bool cmp(string a, string b){
        return a.size()<b.size();
    }
    
    int longestStrChain(vector<string>& words) {
        
        sort(words.begin(),words.end(),cmp);
        int n=words.size();
        map<string,int> dp;
        int mx=1;
        for(int i=0;i<n;i++)
        {
           //string curr = words[i];
            dp[words[i]]=1;
            for(int j=0;j<words[i].size();j++)
            {
                string pre = words[i].substr(0,j)+words[i].substr(j+1);
                //cout<<pre<<endl;
                if(dp.find(pre)!=dp.end())
                {
                    //cout<<words[i]<<endl;
                    dp[words[i]]=max(dp[words[i]],dp[pre]+1);
                }
            }
            
            mx=max(mx,dp[words[i]]);
        }
        
        return mx;
    }
};