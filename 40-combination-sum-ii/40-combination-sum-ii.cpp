class Solution {
public:
    
    void help(int i, vector<int> &candidates, int target,  vector<vector<int>> &ans, vector<int> &curr)
    {
        if(target==0)
        {
            ans.push_back(curr);
            return;
        }
        if(target<0)
            return;
        
        if(i == candidates.size())
            return;
        
        for(int j= i;j<candidates.size();j++)
        {
            if(j!=i&&candidates[j]==candidates[j-1])
                continue;
             curr.push_back(candidates[j]);
             help(j+1,candidates,target-candidates[j],ans,curr);
             curr.pop_back();
        }
       
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        
        sort(candidates.begin(),candidates.end());
        vector<vector<int>> ans;
        vector<int> curr;
        
        help(0,candidates,target,ans,curr);
        
        return ans;
    }
};