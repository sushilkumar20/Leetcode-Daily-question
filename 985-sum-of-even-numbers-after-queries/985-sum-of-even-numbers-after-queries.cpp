class Solution {
public:
    vector<int> sumEvenAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        
        int sum = 0;
        
        int n = nums.size();
        for(int i=0;i<n;i++)
        {
            if(nums[i]%2==0)
            sum+=nums[i];
        }
        
        vector<int> ans;
        
        for(int i=0;i<queries.size();i++)
        {
            int temp = nums[queries[i][1]];
            int ind = queries[i][1];
            int val = queries[i][0];
            
            nums[ind] += val;
            
            if(temp%2)
            {
                if(nums[ind]%2==0)
                {
                    sum+=nums[ind];
                }
            }
            else
            {
                sum-= temp;
                
                if(nums[ind]%2==0)
                {
                    sum += nums[ind];
                }
                
            }
            
            ans.push_back(sum);
        }
        
        return ans;
    }
};