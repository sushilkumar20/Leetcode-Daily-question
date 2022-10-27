class Solution {
public:
    int largestOverlap(vector<vector<int>>& img1, vector<vector<int>>& img2) {
        
        
        vector<pair<int,int>> vp1;
        vector<pair<int,int>> vp2;
        map<pair<int,int>,int>mp;
        for(int i=0;i<img1.size();i++)
        {
            for(int j=0;j<img1[0].size();j++)
            {
                if(img1[i][j]==1)
                {
                    vp1.push_back({i,j});
                }
                
                if(img2[i][j]==1)
                {
                    vp2.push_back({i,j});
                    // mp[{i,j}]++;
                }
            }
        }
        
        
        int ans = 0;
        for(int i=0;i<vp1.size();i++)
        {
            for(int j=0;j<vp2.size();j++)
            {
                int x = vp2[j].first-vp1[i].first;
                int y = vp2[j].second-vp1[i].second;
                
                // cout<<x<<" "<<y<<endl;
                
                mp[{x,y}]++;
                // cout<<cnt<<endl;
                // ans= max(ans,cnt);
            }
        }
        
        for(auto i:mp)
            ans=max(i.second,ans);
        return ans;
    }
};