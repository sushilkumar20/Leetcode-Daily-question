class Solution {
public:
    bool isPal(string &s)
    {
        int i=0;
        int j=s.size()-1;
        
        while(i<j)
        {
            if(s[i]!=s[j])
                return false;
            
            i++;
            j--;
        }
        
        return 1;
    }
    int fun(int i, string s, vector<int>&dp)
    {
        if(i==s.size())
            return 0;
        if(dp[i]!=-1)
            return dp[i];
       string temp ="";
          int min_cost = INT_MAX;
        for(int j=i;j<s.size();j++)
        {
            temp.push_back(s[j]);
          
            if(isPal(temp))
            {
                int cost = 1+fun(j+1,s,dp);
                min_cost  =min(min_cost,cost);
            }
        }
        
        return dp[i] = min_cost;
    }
    int minCut(string s) {
        
        int n = s.size();
        vector<int> dp(s.size()+1);
         
       
        
        for(int i=n-1;i>=0;i--)
        {
            int min_cost = INT_MAX;
             string temp = "";
           for(int j=i;j<s.size();j++)
           {
                temp.push_back(s[j]);
                if(isPal(temp))
                {
                    int cost = 1 +dp[j+1];
                    min_cost = min(min_cost,cost); 
                }
           }
            dp[i] = min_cost;
        }
        
        return dp[0]-1;
    }
};