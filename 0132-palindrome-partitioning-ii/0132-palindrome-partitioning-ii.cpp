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
        int min_cost = INT_MAX;
        string temp = "";
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
        

        vector<int> dp(s.size(),-1);
        
        return fun(0,s,dp)-1;
    }
};