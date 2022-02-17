class Solution {
public:
    void find(int j,vector<vector<int>>&ans,vector<int>&ds,int ind,int n, int k)
    {
        if(k==ds.size())
        {
            if(n==0)
            ans.push_back(ds);
            
            return;
        }
        
        if(n<0||ds.size()>k)
            return;
        
        for(int i=j;i<=9;i++)
        {
            ds.push_back(i);
            
            find(i+1,ans,ds,j,n-i,k);
            ds.pop_back();
        }
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        
       
        
        vector<vector<int>> ans;
        vector<int> ds;
        find(1,ans,ds,0,n,k);
        
        return ans;
    }
};