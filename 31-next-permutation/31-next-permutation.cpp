class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        
         vector<pair<int,int>> brr;
        int k=0;
        for(int i=nums.size()-2;i>=0;i--)
        {
            for(int j=i+1;j<nums.size();j++)
            {
                if(nums[i]<nums[j])
                {
                    brr.push_back({nums[j],j});
                }
            }
            
            if(brr.size()!=0)
            {
                sort(brr.begin(),brr.end());
                
                int temp=nums[i];
                nums[i]=brr[0].first;
                nums[brr[0].second]=temp;
                sort(nums.begin()+i+1,nums.end());
                break;
            }
        }
        
        
        
        if(brr.size()==0)
            sort(nums.begin(),nums.end());
    }
};