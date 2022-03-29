class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        
        int n=nums.size();
        vector<int> arr(n);
        
        for(int i=0;i<n;i++)
        {
            arr[nums[i]-1]++;
        }
        
        for(int i=0;i<n;i++)
        {
            if(arr[i]>1)
                return i+1;
        }
        
        return n+1;
    }
};