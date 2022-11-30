class Solution {
public:
    
    int help(int i, int prev, vector<vector<int>> &pairs, vector<vector<int>>&dp)
    {
        if(i>=pairs.size())
            return 0;
       
        if(dp[i][prev+1]!=-1)
            return dp[i][prev+1];
        
        if(prev==-1)
        {
            return dp[i][prev+1]=max(1+help(i+1,i,pairs,dp),help(i+1,prev,pairs,dp));
        }
        
        // cout<<i<<" "<<prev<<endl;
        
        int take = 0;
        int nTake =0 ;
        
        if(pairs[prev][1]<pairs[i][0])
        {
             // cout<<prev<<" "<<i<<endl;
            take = 1+help(i+1,i,pairs,dp);
        }
        
        nTake = help(i+1,prev,pairs,dp);
        
        
        return dp[i][prev+1] = max(take,nTake);
    }
    
    static bool cmp(vector<int> &a, vector<int> &b)
    {
        if(a[1]<b[1])
            return 1;
        
        return 0;
    }
    int findLongestChain(vector<vector<int>>& pairs) {
        
        sort(pairs.begin(),pairs.end(),cmp);
        
        int n = pairs.size();
        
        vector<int> dp(n,1);
        
        int mx =1;
        for(int i=1;i<n;i++)
        {
            for(int j=0;j<i;j++)
            {
                if(pairs[i][0]>pairs[j][1])
                    dp[i] = max(dp[i],1+dp[j]);
                
                mx=max(mx,dp[i]);
            }
        }
        
        return mx;
    }
};