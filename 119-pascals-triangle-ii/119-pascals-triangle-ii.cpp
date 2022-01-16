class Solution {
public:
    vector<int> getRow(int rowIndex) {
        
          vector<vector<int>> ans;
        int n=rowIndex;
        vector<int> p;
        p.push_back(1);
        ans.push_back(p);
        for(int i=1;i<=n;i++)
        {
            vector<int> q;
            for(int j=0;j<i+1;j++)
            {
                if(j==0||j==i)
                {
                    q.push_back(1);
                }
                else
                {
                    q.push_back(ans[i-1][j-1]+ans[i-1][j]);
                }
                    
            }
            ans.push_back(q);
        }
        
        return ans[rowIndex];
    }
};