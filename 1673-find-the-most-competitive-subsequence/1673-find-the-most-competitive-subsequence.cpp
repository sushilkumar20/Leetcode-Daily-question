class Solution {
public:
    
    void fun(vector<int> &nums ,vector<int>&ans,vector<int>&curr, int i, int k)
    {
        if(curr.size()==k)
        {
            if(ans.size()==0)
                ans=curr;
            if(ans>curr)
                ans=curr;
            
            return ;
        }
        
        if(i==nums.size())
            return ;
        
        curr.push_back(nums[i]);
        
        fun(nums,ans,curr,i+1,k);
        
        curr.pop_back();
        
        fun(nums,ans,curr,i+1,k);
    }
    vector<int> mostCompetitive(vector<int>& nums, int k) {
        
       vector<int> ans;
        
       int n=nums.size();
        
       for(int i=0;i<n;i++)
       {
           while(ans.size()&&ans.back()>nums[i]&&ans.size()+n-i>k)
               ans.pop_back();
           if(ans.size()<k)ans.push_back(nums[i]);
       }
        
        return ans;
    }
};