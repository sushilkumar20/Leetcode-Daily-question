class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        
       sort(nums.begin(),nums.end());
        vector<vector<int>> ans;
        
        int i=0;
        int n=nums.size();
        
        if(n<=2)
            return ans;
        
        while(i<n)
        {
            int j= i+1;
            int k = n-1;
            
            while(j<k)
            {
                if(nums[i]+nums[j]+nums[k]==0)
                {
                    ans.push_back(vector<int>{nums[i],nums[j],nums[k]});
                    
                    int p=nums[j];
                    while(j<k&&nums[j]==p)
                        j++;
                    
                    p=nums[k];
                    while(j<k&&nums[k]==p)
                        k--;
                }
                else if(nums[i]+nums[j]+nums[k]>0)
                {
                    k--;
                }
                else
                    j++;
                
            }
            
            int p=nums[i];
            
            while(i<n&&nums[i]==p)
            i++;
        }
        
        return ans;
    }
};