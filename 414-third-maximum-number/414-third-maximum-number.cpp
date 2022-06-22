class Solution {
public:
    int thirdMax(vector<int>& nums) {
        sort(nums.rbegin(),nums.rend());
        
        int mx=nums[0];
        int ans=mx;
        int cnt=1;
        
        for(int i=1;i<nums.size();i++)
        {
              if(nums[i]!=nums[i-1])
            {
                cnt++;
                mx=nums[i];
            }
            if(cnt==3)
                return mx;
            
          
        }
        
        return ans;
    }
};