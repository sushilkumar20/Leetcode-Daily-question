class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        
        int ans =0;
        int n=nums.size();
        unordered_map<int,int> mp;
        
        int sum=0;
        mp[0]=1;
        for(int i=0;i<n;i++)
        {
            sum+=nums[i];
            
            int rem = sum-goal;
            ans+=mp[rem];
            
            mp[sum]++;
            
        }
        
        return ans;
    }
};