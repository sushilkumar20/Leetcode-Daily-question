class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        
        map<int,int> mp;
        
        for(int i=0;i<matches.size();i++)
        {
            int w=matches[i][0];
            int l=matches[i][1];
            
            if(mp.find(w)==mp.end())
            {
                mp[w]=0;
            }
            
            mp[l]++;
        }
        
        vector<vector<int>> ans(2);   
        
        for(auto i:mp)
        {
            if(i.second==0)
            {
                ans[0].push_back(i.first);
            }
            else if(i.second==1)
            {
                ans[1].push_back(i.first);
            }
        }
        
        return ans;
    }
};