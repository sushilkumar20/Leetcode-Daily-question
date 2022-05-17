class Solution {
public:
    int maxProfit(vector<int>& prices) {
        
        int n=prices.size();
        int prof = 0;
        int mn = prices[0];
        
        for(int i=0;i<n;i++)
        {
            if(prices[i]<mn)
            {
                mn=prices[i];
            }
            else
            {
                prof = max(prof,prices[i]-mn);
            }
        }
        
        return prof;
    }
};