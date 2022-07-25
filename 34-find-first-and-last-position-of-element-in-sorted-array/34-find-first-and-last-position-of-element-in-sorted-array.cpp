class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        
         int l=-1;
        int r=-1;
        if(nums.size()==0)
            return vector<int>{-1,-1};
        int i=0;
        int j=nums.size()-1;
        
        while(i<=j)
        {
            int mid=(i+j)/2;
            
            if(nums[mid]==target)
            {
                l=mid;
                j=mid-1;
                continue;
            }
            
            if(nums[mid]>target)
            {
                j=mid-1;
            }
            else
            {
                i=mid+1;
            }
        }
        
        i=0;
        j=nums.size()-1;
        
         while(i<=j)
        {
            int mid=(i+j)/2;
            
            if(nums[mid]==target)
            {
                r=mid;
                i=mid+1;
                continue;
            }
            
            if(nums[mid]>target)
            {
                j=mid-1;
            }
            else
            {
                i=mid+1;
            }
             
             
        }
        
        return vector<int>{l,r};
    }
};