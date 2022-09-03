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
        
        vector<int> ans = {1,2,3,4,5,6,7,8,9};
        
        for(int i=2;i<=n;i++)
        {
            vector<int> temp;
            
            for(auto x:ans)
            {
                int y = x%10;
                
                if(y+k<=9)
                {
                    temp.push_back(x*10+y+k);
                }
                
                if(k>0&&y-k>=0)
                {
                    temp.push_back(x*10+y-k);
                }
            }
            
            ans=temp;
        }
        
        return ans;
    }
};