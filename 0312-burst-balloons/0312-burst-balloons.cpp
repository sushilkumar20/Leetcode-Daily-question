class Solution {
public:
    int help(int i, int j, vector<int>& nums, vector<vector<int>> &dp)
    {
        if(i>j)
            return 0;
        if(dp[i][j]!=-1)
            return dp[i][j];
        
        int max_cost = 0;
        
        for(int k=i;k<=j;k++)
        {
           int cost = nums[i-1]*nums[k]*nums[j+1];
           cost += help(i,k-1,nums,dp)+help(k+1,j,nums,dp);
            
            max_cost = max(max_cost,cost);
        }
        
        return dp[i][j] = max_cost;
    }
    int maxCoins(vector<int>& nums) {
        
         int n = nums.size();
        nums.push_back(1);
        nums.insert(nums.begin(),1);
        vector<vector<int>> dp(nums.size()+1,vector<int>(nums.size()+1,0));
        
       
        
        for(int i=n;i>=1;i--)
        {
           
            
            for(int j=i;j<=n;j++)
            {
                 int max_cost = 0;
                
                for(int k=i;k<=j;k++)
                {
                    int cost = nums[i-1]*nums[k]*nums[j+1]+dp[i][k-1]+dp[k+1][j];
                    
                    max_cost = max(max_cost,cost);
                }
                
                dp[i][j] = max_cost;
            }
        }
        
        return dp[1][n];
    }
};