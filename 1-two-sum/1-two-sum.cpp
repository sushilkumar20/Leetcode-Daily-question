class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        
        vector<int> ans;
        
        map<int,int> mp;
        
        for(int i=0;i<nums.size();i++)
        {
            int rem=target-nums[i];
            if(mp.find(rem)!=mp.end())
            {
                return vector<int>{mp[rem],i};
            }
            mp[nums[i]]=i;
        }
return ans;
    }
};