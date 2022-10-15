class Solution {
public:
    long long countBadPairs(vector<int>& nums) {
        
        long long n = nums.size();
        
        for(int i=0;i<n;i++)
        {
            nums[i]-=i;
        }
        
        map<int,long long> mp;
        for(int i=0;i<n;i++)
        {
            mp[nums[i]]++;
        }
        
        long long ans = (n*(n-1))/2;
        
        for(auto i: mp)
        {
            if(i.second>=2)
            {
                ans -= (i.second*(i.second-1))/2;
            }
        }
        
        return ans;
    }
    
    
};