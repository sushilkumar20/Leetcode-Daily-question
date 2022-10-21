class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        
        map<int,vector<int>> mp;
        
        for(int i=0;i<nums.size();i++)
        {
            if(mp.find(nums[i])==mp.end())
                mp[nums[i]].push_back(i);
            else
            {
                if(i-mp[nums[i]].back()<=k)
                    return 1;
                mp[nums[i]].push_back(i);
            }
        }
        
        return 0;
    }
};