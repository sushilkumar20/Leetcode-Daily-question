class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int sum=0;
        int n=nums.size();
        vector<int> pref(n);
        map<int,int> mp;
        mp[0]=1;
        int ans=0;
        for(int i=0;i<n;i++)
        {
            sum+=nums[i];
            
            ans+=mp[sum-k];
            mp[sum]++;
        }
        
     
      
        
        return ans;
    }
};