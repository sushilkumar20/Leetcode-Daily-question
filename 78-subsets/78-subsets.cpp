class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        
        int n=nums.size();
        vector<vector<int>> ans;
        
        unsigned int p=pow(2,n);
        //ans.push_back({});
        for(int i=0;i<p;i++)
        {
            vector<int> temp;
            
            for(int j=0;j<n;j++)
            {
                if(i&(1<<j))
                    temp.push_back(nums[j]);
            }
            
            ans.push_back(temp);
        }
        
        return ans;
    }
};