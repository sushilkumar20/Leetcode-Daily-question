class Solution {
public:
    void help(int i, int n, vector<int>&nums,vector<int>&curr, set<vector<int>> &st)
    {
        if(i==n)
        {
            st.insert(curr);
            return;
        }
        curr.push_back(nums[i]);
        help(i+1,n,nums,curr,st);
        curr.pop_back();
        help(i+1,n,nums,curr,st);
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        
        sort(nums.begin(),nums.end());
        set<vector<int>> st;
        
        vector<int> curr;
        
        help(0,nums.size(),nums,curr,st);
        
        vector<vector<int>> ans;
        
        for(auto i =st.begin(); i!= st.end();i++)
        {
            ans.push_back(*i);
        }
        
        return ans;
    }
};