class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
       sort(nums.begin(),nums.end());
        
        int diff=INT_MAX;
        
        for(int i=0;i<nums.size()&&diff!=0;i++)
        {
            for(int j=i+1;j<nums.size();j++)
            {
                int sum=nums[i]+nums[j];
                
                auto k=lower_bound(nums.begin()+j+1,nums.end(),target-sum)-nums.begin();
                
                int hi=k;
                int lo=hi-1;
                
                if(hi<nums.size()&&abs(target-(sum+nums[k]))<abs(diff))
                    diff=(target-(sum+nums[k]));
                
                if(lo>j&&abs(target-(sum+nums[lo]))<abs(diff))
                      diff=(target-(sum+nums[lo]));
                
            }
        }
        
        return target-diff;
        
        
    }
};