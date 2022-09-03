class Solution {
public:
    
    void dfs(int i, string &s, int k, int n,  vector<int>&ans)
    {
        s+=to_string(i);
        
        if(s.size()==n)
        {
            ans.push_back(stoi(s));
            s.pop_back();
            return;
        }
        
        if(i+k<=9)
        {
            dfs(i+k,s,k,n,ans);
        }
        
        if(i+k!=i-k&&i-k>=0)
        {
            dfs(i-k,s,k,n,ans);
        }
        
        s.pop_back();
    }
    vector<int> numsSameConsecDiff(int n, int k) {
        
        vector<int> ans;
        
        for(int i=1;i<=9;i++)
        {
            string s = "";
            
            dfs(i,s,k,n,ans);
        }
        
        return ans;
    }
};