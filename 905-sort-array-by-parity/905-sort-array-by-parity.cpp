class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        //sort(nums.begin(),nums.end());
        
        int n = nums.size();
        
        int i=0;
        
        for(int j=0;j<n;j++)
        {
            if(nums[j]%2==0)
            {
                swap(nums[j],nums[i]);
                i++;
            }
        }
        cout<<nums[0]<<endl;
        
        //sort(nums.begin(),nums.begin()+i);
        
       // sort(nums.rbegin(),nums.rend());
        
        return nums;
    }
};