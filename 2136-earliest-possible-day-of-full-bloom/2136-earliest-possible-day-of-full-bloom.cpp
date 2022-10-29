class Solution {
public:
    int earliestFullBloom(vector<int>& plantTime, vector<int>& growTime) {
        
        int n= plantTime.size();
        
        vector<pair<int,int>> vp;
        
        for(int i=0;i<n;i++){
            vp.push_back({growTime[i],plantTime[i]});
        }
        sort(vp.rbegin(),vp.rend());
        
        int cnt = 0;
        int tm = 0;
        
        for(int i=0;i<n;i++)
        {
            cnt=max(tm+vp[i].first+vp[i].second,cnt);
            tm +=vp[i].second; 
        }
        
        return cnt;
    }
};