class Solution {
public:
    int minSwaps(vector<int>& nums) {
        
        
        int mx = 0;
        int n = nums.size();
        
        for(int i=0;i<nums.size();i++)
        {
            mx+=nums[i];
        }
        
        int ans1 = nums.size();
        
        int curr = 0;
        for(int i=0;i<mx;i++)
        {
            curr+=nums[i];
        }
        
        ans1=min(ans1,mx-curr);
        
        for(int i=mx;i<n;i++)
        {
            curr-=nums[i-mx];
            curr+=nums[i];
            
            ans1=min(ans1,mx-curr);
        }
        
        // group all 0s together
        
        int z = n-mx;
        
        curr=0;
        
        for(int i=0;i<z;i++)
        {
            if(nums[i]==0)
                curr+=1;
        }
        
          ans1=min(ans1,z-curr);
        
        for(int i=z;i<n;i++)
        {
            if(nums[i-z]==0)
            curr-=1;
            
            if(nums[i]==0)
            curr+=1;
            
            ans1=min(ans1,z-curr);
        }
        
        return ans1;
    }
};