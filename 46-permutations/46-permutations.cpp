class Solution {
public:
    
    void help(int i, vector<int>& nums, vector<int> &curr, vector<vector<int>> &ans)
    {
        if(curr.size()==nums.size())
        {
            ans.push_back(curr);
            return;
        }
        

        
        for(int j=0;j<nums.size();j++)
        {
            bool ok=false;
            for(int k=0;k<curr.size();k++)
            {
                if(curr[k]==nums[j])
                {
                    ok=true;
                    break;
                }
            }
            
            if(ok)
                continue;
            
            curr.push_back(nums[j]);
            help(j+1,nums,curr,ans);
            curr.pop_back();
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        
        vector<int> curr;
        
        help(0,nums,curr,ans);
        
        return ans;
    }
};