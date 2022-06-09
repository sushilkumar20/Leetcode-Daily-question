class Solution {
public:
    void help(int i, int n, vector<int>&nums,vector<int>&curr, vector<vector<int>> &ans)
    {
       ans.push_back(curr);
        
        for(int j = i;j<n;j++)
        {
            if(j!=i&&nums[j]==nums[j-1])
                continue;
            curr.push_back(nums[j]);
            help(j+1,n,nums,curr,ans);
            curr.pop_back();
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        
        sort(nums.begin(),nums.end());
        
        vector<vector<int>> ans;
        vector<int> curr;
        
        help(0,nums.size(),nums,curr,ans);
        
       
       
        return ans;
    }
};