class Solution {
public:
    vector<int> runningSum(vector<int>& nums) {
        
        int n = nums.size();
        vector<int> sum(n);
        
        for(int i=0;i<n;i++)
        {
            if(i==0)
                sum[0]=nums[0];
            else
                sum[i] = sum[i-1]+nums[i];
        }
        
        return sum;
    }
};