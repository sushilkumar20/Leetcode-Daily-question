class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        
        int smallest = INT_MAX;
        int middle = INT_MAX;
        
        int n = nums.size();
        
        for(int i=0;i<n;i++)
        {
            if(smallest>=nums[i])
            {
                smallest = nums[i];
            }
            else if(middle>=nums[i])
            {
                middle = nums[i];
            }
            else
                return 1;
        }
        
        return 0;
    }
};