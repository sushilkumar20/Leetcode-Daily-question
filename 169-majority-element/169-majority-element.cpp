class Solution {
public:
    int majorityElement(vector<int>& nums) {
        
        int x=0;
        int cnt=0;
        
        for(int i=0;i<nums.size();i++)
        {
            if(cnt==0)
            {
                x=nums[i];
                cnt=1;
            }
            else if(x==nums[i])
            {
                cnt++;
            }
            else
            {
                cnt--;
            }
        }
        
        return x;
    }
};