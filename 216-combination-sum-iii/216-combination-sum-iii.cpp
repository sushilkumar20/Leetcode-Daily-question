class Solution {
public:
    void find(vector<int>arr,vector<vector<int>>&ans,vector<int>&ds,int ind,int n, int k)
    {
        if(k==ds.size())
        {
            if(n==0)
            ans.push_back(ds);
            
            return;
        }
        
        if(n<0||ds.size()>k)
            return;
        
        for(int i=ind;i<9;i++)
        {
            ds.push_back(arr[i]);
            
            find(arr,ans,ds,i+1,n-arr[i],k);
            ds.pop_back();
        }
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        
        vector<int> arr;
        for(int i=1;i<10;i++)
            arr.push_back(i);
        
        vector<vector<int>> ans;
        vector<int> ds;
        find(arr,ans,ds,0,n,k);
        
        return ans;
    }
};