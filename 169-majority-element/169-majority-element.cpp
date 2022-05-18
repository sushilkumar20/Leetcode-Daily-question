class Solution {
public:
    int majorityElement(vector<int>& nums) {
        
        int x =nums[0];
        int cnt=1;
        
        for(int i=1;i<nums.size();i++)
        {
            if(nums[i]==x)
                cnt++;
            else
            {
               if(cnt==0)
               {
                   x=nums[i];
                   cnt++;
               }
                cnt--;
            }
        }
        
        return x;
    }
};