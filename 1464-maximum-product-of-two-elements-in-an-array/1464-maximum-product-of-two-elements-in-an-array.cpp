class Solution {
public:
    int maxProduct(vector<int>& nums) {
        
        int j=0;
        int mx=nums[0];
        
        for(int i=0;i<nums.size();i++)
        {
            if(mx<nums[i])
            {
                mx=nums[i];
                j=i;
            }
        }
        
        int k=0;
        mx=0;
        
        for(int i=0;i<nums.size();i++)
        {
            if(i==j)
                continue;
            if(mx<nums[i])
            {
                mx=nums[i];
                k=i;
            }
        }
        
        return (nums[j]-1)*(nums[k]-1);
            
    }
};