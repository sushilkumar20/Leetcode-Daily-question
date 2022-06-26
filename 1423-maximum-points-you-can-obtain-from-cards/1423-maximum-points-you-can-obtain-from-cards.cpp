class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        
        int n = cardPoints.size();
        int x = n-k;
        
        int sum=0;
        
        for(int i=0;i<n;i++)
            sum+=cardPoints[i];
        
        int mx=0;
        
        int kwindow=0;
        
        for(int i=0;i<x;i++)
        {
            kwindow+=cardPoints[i];
        }
        
        mx=max(mx,sum-kwindow);
        
        for(int i=x;i<n;i++)
        {
            kwindow-=cardPoints[i-x];
            kwindow+=cardPoints[i];
            mx=max(mx,sum-kwindow);
        }
        
        return mx;
    }
};