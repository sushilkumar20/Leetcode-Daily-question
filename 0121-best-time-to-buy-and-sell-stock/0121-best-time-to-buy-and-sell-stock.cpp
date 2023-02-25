class Solution {
public:
    int maxProfit(vector<int>& prices) {
        
        int n = prices.size();
        int mnB = prices[0];
        
        int ans = 0;
        for(int i=1;i<n;i++)
        {
            mnB = min(mnB,prices[i]);
            ans = max(ans,prices[i]-mnB);
        }
        
        return ans;
    }
};