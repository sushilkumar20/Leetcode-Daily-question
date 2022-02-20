class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        
        sort(intervals.begin(),intervals.end());
        int n=intervals.size();
        
        int cnt=0;
        
        int st=intervals[0][0];
        int end=intervals[0][1];
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(i==j)
                    continue;
                if(intervals[i][0]>=intervals[j][0]&&intervals[i][1]<=intervals[j][1])
                {
                    cnt++;
                    break;
                }
            }
        }
        
        return n-cnt;
        
    }
};