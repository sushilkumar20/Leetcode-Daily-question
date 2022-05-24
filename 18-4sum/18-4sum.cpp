class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        
        sort(nums.begin(),nums.end());
        int n = nums.size();
        vector<vector<int>> ans;
        
        for(int i=0;i<n;i++)
        {
           // cout<<i<<endl;
            for(int j = i+1;j<n;j++)
            {
                int l = j+1;
                int h = n-1;
                
                int sum1 = nums[i]+nums[j];
                int rem = target - sum1;
                while(l<h)
                {
                   if(rem>nums[l]+nums[h])
                   {
                       l++;
                   }
                    else if(rem<nums[l]+nums[h])
                    {
                        h--;
                    }
                    else
                    {
                        ans.push_back({nums[i],nums[j],nums[l],nums[h]});
                        l++;
                        h--;
                        while(l<h&&nums[l]==nums[l-1])
                        {
                            l++;
                        }
                        
                         while(l<h&&nums[h]==nums[h+1])
                        {
                            h--;
                        }
                    }
                }
                
                bool ok=false;
                while(j<n-1&&nums[j]==nums[j+1])
                {
                    j++;
                    ok=true;
                }
                
               
                    
            }
                
               bool ok=false;
                while(i<n-1&&nums[i]==nums[i+1])
                {
                    i++;
                  
                }
           
            
        }
        
        return ans;
    }
};