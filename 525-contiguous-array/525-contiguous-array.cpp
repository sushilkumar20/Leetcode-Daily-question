class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        
       map<int,int> mp;
        
        int mx=0;
        
        int cnt=0;
        
        mp[cnt]=-1;
        
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i])
                cnt++;
            else
                cnt--;
            
            if(mp.find(cnt)!=mp.end())
            {
                mx=max(i-mp[cnt],mx);
            }
            else
                mp[cnt]=i;
        }
        
        return mx;
        
    }
};