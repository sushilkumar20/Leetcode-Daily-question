class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        
        sort(points.begin(),points.end());
        
        int x;
        int y;
        
        int cnt=0;
        
        x=points[0][0];
        y=points[0][1];
        
        cnt+=1;
        for(int i=1;i<points.size();i++)
        {
            if(points[i][0]>y)
            {
                cnt++;
                x=points[i][0];
                y=points[i][1];
            }
            else
            {
                x=max(x,points[i][0]);
                y=min(y,points[i][1]);
            }
        }
        
        return cnt;
    }
};