class Solution {
public:
     vector<vector<vector<int>>> dp;
    int fun(vector<int>&one, vector<int> &zero, int m,int n, int i)
    {
        if(i<=0){
            
            return 0;
        }
        
        if(dp[i][m][n] != -1)
            return dp[i][m][n];
        
        if(zero[i-1]<=m&&one[i-1]<=n)
        {
            
            dp[i][m][n] = max(fun(one,zero,m,n,i-1), 1+fun(one,zero,m-zero[i-1],n-one[i-1],i-1));
        }
        else
        {
             dp[i][m][n] = fun(one,zero,m,n,i-1);
        }
        
        return dp[i][m][n];
    }
    int findMaxForm(vector<string>& strs, int m, int n) {
        
        int sz = strs.size();
        vector<int> zero;
        vector<int> one;
        
        for(int i=0;i<strs.size();i++)
        {
            int z=0;
            int o=0;
            
            for(int j=0;j<strs[i].size();j++)
            {
                if(strs[i][j] == '0')
                    z++;
                else
                    o++;
            }
            
            zero.push_back(z);
            one.push_back(o);
        }
         int curr=0;
        int ans=0;
        
dp.resize(strs.size()+2, vector<vector<int>>(m+2, vector<int>(n+2, -1)));           
        
        return  fun(one,zero,m,n,sz);;
        
    }
};