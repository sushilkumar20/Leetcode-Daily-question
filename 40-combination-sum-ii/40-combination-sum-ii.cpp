class Solution {
public:
    void findCombination(int ind, int target,vector<int>&arr,vector<vector<int>> &ans,vector<int>&ds,set<vector<int>> &st)
    {
       
            if(target==0)
            {
               // sort(ds.begin(),ds.end());
                ans.push_back(ds);
                return;
            }
           
        if(target<0)
            return;
        
         int i=ind;
         int sum=0;
         int n=arr.size();
         while(i<n)
         {
             int val=arr[i];
             int cnt=0;
             int p=i;
              
             while(p<n&&arr[p]==val)
             {
                 p++;
             }
             while(i<n&&val==arr[i])
             {
                cnt++;
               
                 ds.push_back(arr[i]);
                findCombination(p,target-arr[i]*cnt,arr,ans,ds,st);
                i++;
                
             }
             
             for(int j=0;j<cnt;j++)
                 ds.pop_back();
         }
        
        
        
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        
        sort(candidates.begin(),candidates.end());
        vector<vector<int>>ans;
        vector<int> ds;
        set<vector<int>> st;
        findCombination(0,target,candidates,ans,ds,st);
          
        
      
        return ans;
    }
};