class Solution {
public:
    vector<int> recoverArray(vector<int>& nums) {
        
        int n = nums.size();
        
        sort(nums.begin(),nums.end());
        
        for(int i=0;i<n;i++)
        {
            int k = nums[i]-nums[0];
            
            if(k!=0&&k%2==0)
            {
                queue<int> q;
                vector<int> ans;
                q.push(nums[0]);
                
                for(int j=1;j<n;j++)
                {
                    if(nums[j]-k==q.front())
                    {
                        q.pop();
                        
                        ans.push_back(nums[j]-k/2);
                    }else
                    {
                        q.push(nums[j]);
                    }
                }
                
                if(q.empty())
                    return ans;
            }
        }
        
        return {};
        
    }
};