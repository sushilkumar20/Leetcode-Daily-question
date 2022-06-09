class Solution {
public:
    void help(int i, int target, vector<int> &curr, vector<int>& candidates, vector<vector<int>> &ans)
    {
        if(target<0)
            return;
        if(target == 0)
        {
            ans.push_back(curr);
            return;
        }
        if(i==candidates.size())
        {
           return; 
        }
        
        curr.push_back(candidates[i]);
        help(i,target-candidates[i],curr,candidates,ans);
        curr.pop_back();
        help(i+1,target,curr,candidates,ans);
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        
        vector<vector<int>> ans;
        
        vector<int> curr;
        
        help(0,target,curr,candidates,ans);
        
        return ans;
    }
};