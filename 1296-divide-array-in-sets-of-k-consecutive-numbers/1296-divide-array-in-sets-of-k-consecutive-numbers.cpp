class Solution {
public:
    bool isPossibleDivide(vector<int>& nums, int k) {
        
        sort(nums.begin(),nums.end());
        
        map<int,int> mp;
        for(int i=0;i<nums.size();i++)
        {
            mp[nums[i]]++;
        }
        
        for(int i=0;i<nums.size();i++)
        {
            if(mp[nums[i]]==0)
                continue;
            
            int x= nums[i];
            
            for(int j=0;j<k;j++)
            {
                if(mp[x]==0)
                    return false;
                
                mp[x]--;
                x++;   
            }
            
            
        }
        
        return true;
    }
};