class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        
        map<int,int> mp;
        
        int sum =0;
        int ans =0;
        for(int i=0;i<nums.size();i++)
        {
            sum+=nums[i];
            
            int req = ((sum%k+k)%k);
            mp[req]++;
        }
        
        for(auto i:mp)
        {
            ans += (i.second*(i.second-1))/2;
        }
        
        ans+=mp[0];
        
        return ans;
    }
};