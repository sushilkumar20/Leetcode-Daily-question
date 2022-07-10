class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        
        int i=0;;
        int j=0;
        
        int n = nums.size();
        int cnt=0;
        while(j<n-1)
        {
            if(nums[j]!=nums[j+1])
            {
                //cout<<j<<endl;
               nums[i]=nums[j];
                cnt++;
                i++;
            }
            j++;
        }
        
        nums[i] = nums[n-1];
        cnt++;
        return cnt;
    }
};