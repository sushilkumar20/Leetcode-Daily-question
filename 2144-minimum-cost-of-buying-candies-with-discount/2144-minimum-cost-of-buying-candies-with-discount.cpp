class Solution {
public:
    int minimumCost(vector<int>& cost) {
        
        sort(cost.begin(),cost.end());
        int ans=0;
        
        
        
       
        int j=0;
        for(int i=cost.size()-1;i>=0;i--)
        {
            j++;
            if(j%3==0)
                continue;
            else
                ans+=cost[i];
        }
        
        return ans;
    }
};