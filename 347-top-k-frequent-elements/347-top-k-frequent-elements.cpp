class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        
        sort(nums.begin(),nums.end());
        
        int freq = 1;
        priority_queue<pair<int,int>> q;
        for(int i=1;i<nums.size();i++)
        {
            if(nums[i]==nums[i-1])
            {
                freq++;
            }
            else
            {
                q.push({freq,nums[i-1]});
                freq=1;
            }
        }
        
        q.push({freq,nums[nums.size()-1]});
        
        
        vector<int> ans;
        
        for(int i=0;i<k;i++)
        {
            ans.push_back(q.top().second);
            q.pop();
        }
        
        return ans;
    }
};